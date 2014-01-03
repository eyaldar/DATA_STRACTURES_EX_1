#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__

#include "TreeKey.h"

#include <iostream>

class TreeNode{
public:
	TreeNode() {}

	virtual TreeNode* Find(const TreeKey& key) const=0;

	virtual bool IsLeaf() const = 0;

	virtual void PrintKeys() const = 0;
	virtual void PrintData() const = 0;

	virtual ~TreeNode() {}
protected:
};

#endif