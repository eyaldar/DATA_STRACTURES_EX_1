#include "TwoThreeTreeLeaf.h"

using namespace std;

TreeKey& TwoThreeTreeLeaf::getMinimum()
{
	return key;
}

TreeNode* TwoThreeTreeLeaf::Find(const TreeKey& key) const
{
	if(this->key == key)
		return (TreeNode*)this;

	return NULL;
}

void TwoThreeTreeLeaf::PrintKeys() const
{
	cout << key;
}

void TwoThreeTreeLeaf::PrintData() const
{
	cout << data.c_str();
}

bool TwoThreeTreeLeaf::IsLeaf() const
{
	return true;
}