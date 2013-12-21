#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__

#include "TreeElement.h"

#include <iostream>

class TreeNode{
public:
	virtual void Insert(TreeElement& data); 
	virtual void Delete(TreeElement& data);
	virtual TreeNode* Find(const TreeKey& key);

	virtual bool IsLeaf();

	virtual void PrintKeys();
	virtual void PrintData();
private:
	TreeElement element;
};

#endif