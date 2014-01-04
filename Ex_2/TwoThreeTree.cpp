#include "TwoThreeTree.h"

#include "TwoThreeTreeLeaf.h"

using namespace std;

void TwoThreeTree::Insert(TreeKey key, std::string data)
{
	if(root->left == NULL)
	{
		root->left = new TwoThreeTreeLeaf(key, data);
		root->min1 = key;
	}
	else if(root->mid == NULL)
	{
		root->mid = new TwoThreeTreeLeaf(key, data);
		root->min2 = key;

		root->FixChildrenOrder();
	}
	else
	{
		TwoThreeTreeNode* newNode = root->Insert(key, data);

		if(newNode != NULL)
		{
			TwoThreeTreeNode* oldRoot = root;
			
			root = new TwoThreeTreeNode();

			root->min1 = oldRoot->min1;
			root->left = oldRoot;

			root->min2 = newNode->min1;
			root->mid = newNode;

			root->FixChildrenOrder();
		}
	}
}

void TwoThreeTree::Delete(TreeKey key)
{
	TwoThreeTreeNode* node = root->Delete(key);

	if(node != NULL && node->left != NULL && !node->left->IsLeaf())
	{
		root = (TwoThreeTreeNode*)node->left;
		
		node->left = NULL;
		delete node;
	}
}

void TwoThreeTree::PrintKeys() const
{
	root->PrintKeys();

	cout << endl;
}

void TwoThreeTree::PrintData() const
{
	root->PrintData();

	cout << endl;
}