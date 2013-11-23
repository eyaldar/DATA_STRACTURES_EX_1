#include "Stack.h"

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
void Stack<ItemType>::IsEmpty()
{
	return top == NULL;
}

template <typename ItemType>
void Stack<ItemType>::Push(ItemType item)
{
	top = new Node<ItemType>(item, top);
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
	top->SetNext(top->GetNext());
	delete temp;

	return item;
}