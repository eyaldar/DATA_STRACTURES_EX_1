#include "TwoThreeTreeLeaf.h"

#include "FileManager.h"

using namespace std;

// Returns the leaf's key as minimum since it's its only value
TreeKey& TwoThreeTreeLeaf::GetMinimum()
{
	return key;
}

// Check whether the leaf's key equals to the given key
// In case it does - return the leaf, otherwise - returns NULL
TreeNode* TwoThreeTreeLeaf::Find(const TreeKey& key) const
{
	if(this->key == key)
		return (TreeNode*)this;

	return NULL;
}

// Prints the leaf's key
void TwoThreeTreeLeaf::PrintKeys() const
{
	FileManager::GetInstance().WriteTreeKeyToFile(key);
}

// Prints the leaf's data
void TwoThreeTreeLeaf::PrintData() const
{
	FileManager::GetInstance().WriteStringToFile(data);
}

// Returns true as this class represents a leaf node
bool TwoThreeTreeLeaf::IsLeaf() const
{
	return true;
}