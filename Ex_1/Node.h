#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include "ItemType.h"

// Summary:
//		Represents a part of implemention of a dynamic Linked List data structure.
//		the aforementioned Linked List is composed of Node elements
class Node {
public:
	// Summary:
	//		Default constructor for the Node class
	Node() 
	: m_next(NULL) {}

	// Summary:
	//		Default constructor for the Node class
	//
	// Parameters:
    //   data:
    //		the data of the new node.
	//   ptr:
    //		the point to the next node in list.
	Node(ItemType data, Node* nextPtr = NULL)
		: m_data(data), m_next(nextPtr) {}

	// Summary:
	//		Default destructor for the Node class
	~Node() {}

	// Summary:
	//		Returns the data of the current node.
	//
	// Returns:
    //		The data of the current node.
	ItemType GetData()
	{
		return m_data;
	}

	// Summary:
	//		sets the given value as the data of the current node.
	//
    // Parameters:
    //   newNode:
    //		The new data.
	void SetData(ItemType data)
	{
		m_data = data;
	}

	// Summary:
	//		Returns the next node, on which the current node points.
	//
	// Returns:
    //		The next node, on which the current node points.
	Node* GetNext(void)
	{
		return m_next;
	}

	// Summary:
	//		Sets the given pointer as the next node of the current node.
	//
    // Parameters:
    //   next:
    //		The given pointer to set the next node of the current node.
	void SetNext(Node* next)
	{
		m_next = next;
	}

	// Summary:
	//		Insert new node after current node
	//
    // Parameters:
    //   newNode:
    //		The node to add.
	void InsertAfter(Node* newNode);

	// Summary:
	//		Deletes node after current node.
	//
	// Returns:
    //		The next node.
	Node* DeleteAfter();

private:
	ItemType m_data; 			// data field.
	Node* m_next;		// points to next node in list
};

#endif