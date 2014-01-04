#ifndef __TWO_THREE_TREE_LEAF_H__
#define __TWO_THREE_TREE_LEAF_H__

#include "TreeKey.h"
#include "TreeNode.h"
#include <iostream>

class TwoThreeTreeLeaf : public TreeNode{
public:
	TwoThreeTreeLeaf(const TreeKey& key, const std::string& data)
	: key(key), data(data) {}

	virtual TreeNode* Find(const TreeKey& key) const;

	virtual bool IsLeaf() const;
	virtual TreeKey& getMinimum();

	virtual void PrintKeys() const;
	virtual void PrintData() const;

	virtual ~TwoThreeTreeLeaf() {}
protected:
	TreeKey key;
	std::string data;
};

#endif