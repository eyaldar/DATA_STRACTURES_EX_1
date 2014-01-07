#include "TwoThreeTree.h"

#include "TwoThreeTreeLeaf.h"
#include "FileManager.h"

using namespace std;

// Inserts the given key + data into its right place according to the 2-3 Tree algorithm
// NOTE: The method will throw an exception in case the key already exists
void TwoThreeTree::Insert(TreeKey key, std::string data)
{
	// Check whether the tree is empty
	if(root->left == NULL)
	{
		root->left = new TwoThreeTreeLeaf(key, data);
		root->min1 = key;
	}
	// Check whether the tree has only one left leaf
	else if(root->mid == NULL)
	{
		TreeNode* foundNode = Find(key);

		if(foundNode != NULL)
		{
			throw "Key already exists";
		}

		root->mid = new TwoThreeTreeLeaf(key, data);
		root->min2 = key;

		// Rearrange immediate children to maintain 2-3 correct order
		root->FixChildrenOrder();
	}
	// Otherwise use standard 2-3 tree insertion algorithm
	else
	{
		TwoThreeTreeNode* newNode = root->Insert(key, data);

		// Check whether insertion caused a split
		if(newNode != NULL)
		{
			// creates a new root and add it's children
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

// Deletes a given key from the 2-3 tree according to the 2-3 Tree algorithm
// NOTE: In case the key wasn't found - does nothing
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

// Returns the 2-3 Tree node for a given key,
// for further information, see TwoThreeNode::Find method.
// NOTE: In case the node wasn't found - returns NULL
TreeNode* TwoThreeTree::Find(const TreeKey& key)
{
	return root->Find(key);
}

// Prints all the keys of the 2-3 tree
void TwoThreeTree::PrintKeys() const
{
	root->PrintKeys();

	FileManager::GetInstance().WriteNewLine();
}

// Prints all the data of the 2-3 tree
void TwoThreeTree::PrintData() const
{
	root->PrintData();

	FileManager::GetInstance().WriteNewLine();
}