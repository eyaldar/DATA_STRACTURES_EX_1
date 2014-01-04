#include "TwoThreeTreeLeaf.h"

#include "FileManager.h"

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
	FileManager::GetInstance().WriteTreeKeyToFile(key);
}

void TwoThreeTreeLeaf::PrintData() const
{
	FileManager::GetInstance().WriteStringToFile(data);
}

bool TwoThreeTreeLeaf::IsLeaf() const
{
	return true;
}