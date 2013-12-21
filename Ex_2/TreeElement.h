#ifndef __TREE_ELEMENT_H__
#define __TREE_ELEMENT_H__

#include <string>

typedef int TreeKey;

struct TreeElement{
	TreeKey key;
	std::string data;
};

#endif