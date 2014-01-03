#include "TwoThreeTreeNode.h"

#include "TwoThreeTreeLeaf.h"
#include <map>

using namespace std;

TwoThreeTreeNode* TwoThreeTreeNode::Insert(const TreeKey& key, const std::string& data)
{
	TwoThreeTreeNode* newSibling = NULL;

	if(left->IsLeaf())
	{
		if(right == NULL)
		{
			right = new TwoThreeTreeLeaf(key, data);
			min3 = key;

			FixChildrenOrder();
		}
		else
		{
			TreeNode* newNode = new TwoThreeTreeLeaf(key, data);
			newSibling = SplitTreeNode(key, newNode);
		}
	}
	else if(right != NULL && key >= min3)
	{
		TwoThreeTreeNode* node = ((TwoThreeTreeNode*)right)->Insert(key, data);

		if(node != NULL)
		{
			newSibling = SplitTreeNode(((TwoThreeTreeNode*)right)->min1, node);
		}
	}
	else if(mid != NULL && key >= min2)
	{
		TwoThreeTreeNode* node = ((TwoThreeTreeNode*)mid)->Insert(key, data);

		if(node != NULL)
		{
			if(right != NULL)
			{
				newSibling = SplitTreeNode(((TwoThreeTreeNode*)mid)->min1, node);
			}
			else
			{
				right = node;
				min3 = node->min1;
				FixChildrenOrder();
			}
		}
	}
	else if(left != NULL)
	{
		TwoThreeTreeNode* node = ((TwoThreeTreeNode*)left)->Insert(key, data);

		if(node != NULL)
		{
			if(right != NULL)
			{
				newSibling = SplitTreeNode(((TwoThreeTreeNode*)left)->min1, node);
			}
			else
			{
				right = node;
				min3 = node->min1;
				FixChildrenOrder();
			}
		}
	}

	return newSibling;
}

TwoThreeTreeNode* TwoThreeTreeNode::SplitTreeNode(const TreeKey& key, TreeNode* newNode)
{
	TwoThreeTreeNode* newSibling = new TwoThreeTreeNode();

	newSibling->min1 = min3;
	newSibling->left = right;
	right = NULL;

	newSibling->min2 = key;
	newSibling->mid = newNode;

	if(min2 > key)
	{
		Swap(min2, newSibling->min2);
		Swap(mid, newSibling->mid);
	}

	FixChildrenOrder();
	newSibling->FixChildrenOrder();

	return newSibling;
}

void TwoThreeTreeNode::Delete(const TreeKey& data)
{
}

TreeNode* TwoThreeTreeNode::Find(const TreeKey& key) const
{
	if(right != NULL && key >= min3)
	{
		return right->Find(key);
	}
	else if(mid != NULL && key >= min2)
	{
		return mid->Find(key);
	}
	else if(left != NULL)
	{
		return left->Find(key);
	}

	return NULL;
}

TwoThreeTreeNode::~TwoThreeTreeNode()
{
	delete left;
	delete mid;
	delete right;
}

void TwoThreeTreeNode::PrintKeys() const
{
}

void TwoThreeTreeNode::PrintData() const
{
}

bool TwoThreeTreeNode::IsLeaf() const
{
	return false;
}

void TwoThreeTreeNode::FixChildrenOrder()
{
	if (right != NULL)
	{
		map<TreeKey, TreeNode*> orderedChildren;

		orderedChildren[min1] = left;
		orderedChildren[min2] = mid;
		orderedChildren[min3] = right;

		map<TreeKey, TreeNode*>::iterator curr = orderedChildren.begin();

		min1 = curr->first;
		left = curr->second;

		curr++;

		min2 = curr->first;
		mid = curr->second;

		curr++;

		min3 = curr->first;
		right = curr->second;
	}
	if (mid != NULL)
	{
		if (min2 < min1)
		{
			Swap(min1, min2);
			Swap(left, mid);
		}
	}
}