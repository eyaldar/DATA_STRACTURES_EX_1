#include "TreeNode.h"

using namespace std;

bool TreeNode::IsLeaf()
{
	return true;
}

void TreeNode::Insert(TreeElement& data)
{
	throw "Not implemented!";
}

void TreeNode::Delete(TreeElement& data)
{
	throw "Not implemented!";
}

TreeNode* TreeNode::Find(const TreeKey& key)
{
	if(this->element.key == key)
		return this;

	return NULL;
}

void TreeNode::PrintKeys()
{
	cout << element.key;
}

void TreeNode::PrintData()
{
	cout << element.data;
}