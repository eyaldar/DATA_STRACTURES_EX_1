#include "TwoThreeTreeNode.h"

#include "TwoThreeTreeLeaf.h"
#include <map>

using namespace std;

TreeKey& TwoThreeTreeNode::getMinimum()
{
	return min1;
}

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
			newSibling = SplitTreeNode(node->getMinimum(), node);
		}
	}
	else if(mid != NULL && key >= min2)
	{
		TwoThreeTreeNode* node = ((TwoThreeTreeNode*)mid)->Insert(key, data);

		if(node != NULL)
		{
			if(right != NULL)
			{
				newSibling = SplitTreeNode(node->getMinimum(), node);
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
				newSibling = SplitTreeNode(node->getMinimum(), node);
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
			min3 = right->getMinimum();
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
			min2 = mid->getMinimum();
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
			min1 =left->getMinimum();
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