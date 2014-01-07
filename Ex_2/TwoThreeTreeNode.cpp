#include "TwoThreeTreeNode.h"

#include "TwoThreeTreeLeaf.h"
#include <map>

using namespace std;

// Returns the minimum value of this node's immediate children
TreeKey& TwoThreeTreeNode::GetMinimum()
{
	return min1;
}

// Inserts the given key + data into its right place according to the 2-3 Tree algorithm
// In case split is required - returns the newly created sibling after split.
// NOTE: The method will throw an exception in case the key already exists
TwoThreeTreeNode* TwoThreeTreeNode::Insert(const TreeKey& key, const std::string& data)
{
	TwoThreeTreeNode* newSibling = NULL;

	if(left->IsLeaf())
	{
		TreeNode* foundNode = Find(key);

		if(foundNode != NULL)
		{
			throw "Key already exists!";
		}

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
			newSibling = SplitTreeNode(node->GetMinimum(), node);
		}
	}
	else if(mid != NULL && key >= min2)
	{
		TwoThreeTreeNode* node = ((TwoThreeTreeNode*)mid)->Insert(key, data);

		if(node != NULL)
		{
			if(right != NULL)
			{
				newSibling = SplitTreeNode(node->GetMinimum(), node);
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
				newSibling = SplitTreeNode(node->GetMinimum(), node);
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

// Splits a 2-3 node into 2 separate nodes according to the 2-3 insertion algorithm
// the given node (newNode) is the new tree node to add (which caused the need of a split)
// Returns a another new sibling of this node
TwoThreeTreeNode* TwoThreeTreeNode::SplitTreeNode(const TreeKey& key, TreeNode* newNode)
{
	TwoThreeTreeNode* newSibling = new TwoThreeTreeNode();

	newSibling->min1 = min3;
	newSibling->left = right;
	right = NULL;

	newSibling->min2 = key;
	newSibling->mid = newNode;

	// Check whether the new key is smaller this node's mid node as the newSibling is always to the right
	if(min2 > key)
	{
		Swap(min2, newSibling->min2);
		Swap(mid, newSibling->mid);
	}

	FixChildrenOrder();
	newSibling->FixChildrenOrder();

	return newSibling;
}

// Deletes the given key from the 2-3 tree node according to the 2-3 deletion algorithm
// In case merge is required - returns this, otherwise - return NULL
TwoThreeTreeNode* TwoThreeTreeNode::Delete(const TreeKey& key)
{
	if(left->IsLeaf())
	{
		TreeNode* node = Find(key);

		if(right == node)
		{
			delete right;
			right = NULL;
		}
		else if(mid == node)
		{
			Swap(mid, right);
			Swap(min2, min3);

			delete right;
			right = NULL;
		}
		else if(left == node)
		{
			Swap(left, mid);
			Swap(min1, min2);
			Swap(mid, right);
			Swap(min2, min3);

			delete right;
			right = NULL;
		}
	}
	else if(right != NULL && key >= min3)
	{
		TwoThreeTreeNode* node = ((TwoThreeTreeNode*)right)->Delete(key);

		if(node == NULL)
		{
			min3 = right->GetMinimum();
		}
		else
		{
			TwoThreeTreeNode* midNode = (TwoThreeTreeNode*)mid;
			if(midNode->right != NULL)
			{
				Swap(node->mid, midNode->right);
				Swap(node->min2, midNode->min3);

				node->FixChildrenOrder();
			}
			else
			{
				Swap(node->left, midNode->right);
				Swap(node->min1, midNode->min3);

				delete right;
				right = NULL;
			}
		}
	}
	else if(mid != NULL && key >= min2)
	{
		TwoThreeTreeNode* node = ((TwoThreeTreeNode*)mid)->Delete(key);

		if(node == NULL)
		{
			min2 = mid->GetMinimum();
		}
		else
		{
			TwoThreeTreeNode* leftNode = (TwoThreeTreeNode*)left;

			if(leftNode->right != NULL)
			{
				Swap(node->mid, leftNode->right);
				Swap(node->min2, leftNode->min3);

				node->FixChildrenOrder();
			}
			else
			{
				Swap(leftNode->right, node->left);
				Swap(leftNode->min3, node->min1);

				delete mid;
				mid = NULL;

				Swap(mid, right);
				Swap(min2, min3);
			}
		}
	}
	else if(left != NULL)
	{
		TwoThreeTreeNode* node = ((TwoThreeTreeNode*)left)->Delete(key);

		if(node == NULL)
		{
			min1 =left->GetMinimum();
		}
		else
		{
			TwoThreeTreeNode* midNode = (TwoThreeTreeNode*)mid;

			if(midNode->right != NULL)
			{
				Swap(node->mid, midNode->left);
				Swap(node->min2, midNode->min1);

				Swap(midNode->left, midNode->mid);
				Swap(midNode->min1, midNode->min2);

				Swap(midNode->mid, midNode->right);
				Swap(midNode->min2, midNode->min3);
			}
			else
			{
				Swap(midNode->right, node->left);
				Swap(midNode->min3, node->min1);

				midNode->FixChildrenOrder();

				delete left;
				left = NULL;

				Swap(left, mid);
				Swap(min1, min2);

				Swap(mid, right);
				Swap(min2, min3);
			}
		}
	}

	if(mid == NULL)
		return this;

	return NULL;
}

// Finds the given key in the 2-3 Tree node
// in case the key is found - returns its tree node (with satellite data)
// otherwise the key is not found - returns NULL
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

// Prints all the keys on this 2-3 tree node
void TwoThreeTreeNode::PrintKeys() const
{
	if(left != NULL)
	{
		left->PrintKeys();
	}
	if(mid != NULL)
	{
		mid->PrintKeys();
	}
	if(right != NULL)
	{
		right->PrintKeys();
	}
}

// Prints all the data on this 2-3 tree node
void TwoThreeTreeNode::PrintData() const
{
	if(left != NULL)
	{
		left->PrintData();
	}
	if(mid != NULL)
	{
		mid->PrintData();
	}
	if(right != NULL)
	{
		right->PrintData();
	}
}

// Returns false as this class represents a non-leaf node
bool TwoThreeTreeNode::IsLeaf() const
{
	return false;
}

// This method assures the immediate children of the 2-3 tree node are ordered.
void TwoThreeTreeNode::FixChildrenOrder()
{
	// Has 3 children
	if (right != NULL)
	{
		// uses STL's Map to sort the 3 children
		map<TreeKey, TreeNode*> orderedChildren;

		orderedChildren[min1] = left;
		orderedChildren[min2] = mid;
		orderedChildren[min3] = right;

		// Uses the iterator to iterate through the sorted children
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
	// Has 2 children
	if (mid != NULL)
	{
		// Check whether order of children is correct
		if (min2 < min1)
		{
			Swap(min1, min2);
			Swap(left, mid);
		}
	}
}