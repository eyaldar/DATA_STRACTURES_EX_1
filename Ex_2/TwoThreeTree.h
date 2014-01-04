#ifndef __TWO_THREE_TREE_H__
#define __TWO_THREE_TREE_H__

#include "TreeKey.h"
#include "TreeNode.h"

#include "TwoThreeTreeNode.h"

#include <iostream>

class TwoThreeTree{
public:
	TwoThreeTree() 
	{
		root = new TwoThreeTreeNode();
	}

	void Insert(TreeKey key, std::string data); 
	void Delete(TreeKey key);
	TreeNode* Find(const TreeKey& key);

	void PrintKeys() const;
	void PrintData() const;

	~TwoThreeTree()
	{
		delete root;
	}

protected:
	TwoThreeTreeNode *root;
};

#endif