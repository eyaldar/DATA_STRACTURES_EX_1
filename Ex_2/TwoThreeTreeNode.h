#ifndef __TWO_THREE_TREE_NODE_H__
#define __TWO_THREE_TREE_NODE_H__

#include "TreeKey.h"
#include "TreeNode.h"

#include <iostream>

class TwoThreeTree;

class TwoThreeTreeNode : public TreeNode{
friend TwoThreeTree;
public:
	TwoThreeTreeNode()
		: left(NULL), mid(NULL), right(NULL) {}

	TwoThreeTreeNode* Insert(const TreeKey& key, const std::string& data); 
	void Delete(const TreeKey& data);

	virtual TreeNode* Find(const TreeKey& key) const;

	virtual bool IsLeaf() const;

	virtual void PrintKeys() const;
	virtual void PrintData() const;

	virtual ~TwoThreeTreeNode();

protected:
	TreeNode *left, *mid, *right;
	TreeKey min1, min2, min3;

	TwoThreeTreeNode* SplitTreeNode(const TreeKey& key, TreeNode* newNode);

	void FixChildrenOrder();
private:
	template <typename T>
	void Swap(T& first, T& second)
	{
		T temp = first;
		first = second;
		second = temp;
	}
};

#endif