#ifndef __STACK_H__
#define __STACK_H__

// The stack is implemented using a linked list of Nodes
#include "Node.h"

// Summary:
//		Represents a  implemention of a dynamic Stack data structure.
// 
// Template types:
//	 ItemType:
//		The type of the data inside the stack.
template <typename ItemType>
class Stack{
public:
	// Summary:
	//		Default constructor for the Node class
	Stack() 
	: top(NULL) {}

	// Summary:
	//		Default destructor for the Node class
	~Stack() 
	{
		MakeEmpty();
	}

	// Summary:
	//		Clear the stack of items.
	void MakeEmpty();

	// Summary:
	//		Determines whether the stack is empty or not.
	//
	// Returns:
    //		Whether the stack is empty or not.
	bool IsEmpty();

	// Summary:
	//		Pushes item to the top of the stack.
	//
    // Parameters:
    //   item:
    //		The item to push.
	void Push(ItemType item);

	// Summary:
	//		Returns the item currently at top of the stack and remove it from the stack.
	//
	// Returns:
    //		The item currently at top of the stack
	ItemType Pop();

private:
	Node<ItemType>* top; //Points to top of stack.
};

template <typename ItemType>
void Stack<ItemType>::MakeEmpty()
{
	Node<ItemType>* temp;

	while(top != NULL)
	{
		temp = top;
		top->SetNext(top->GetNext());
		delete temp;
	}
}

template <typename ItemType>
bool Stack<ItemType>::IsEmpty()
{
	return top == NULL;
}

template <typename ItemType>
void Stack<ItemType>::Push(ItemType item)
{
	top = new Node<ItemType>(item, top);
}

template <typename ItemType>
ItemType Stack<ItemType>::Pop()
{
	if(IsEmpty())
	{
		throw "Error! failed to perform Pop operation because stack is empty!";
	}

	Node<ItemType>* temp = top;
	ItemType item = top->GetData();
	top = top->GetNext();
	delete temp;

	return item;
}

#endif