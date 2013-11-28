#include "Stack.h"

void Stack::MakeEmpty()
{
	Node* temp;

	while(top != NULL)
	{
		temp = top;
		top->SetNext(top->GetNext());
		delete temp;
	}
}

bool Stack::IsEmpty()
{
	return top == NULL;
}

void Stack::Push(ItemType item)
{
	top = new Node(item, top);
}

ItemType Stack::Pop()
{
	if(IsEmpty())
	{
		throw "Error! failed to perform Pop operation because stack is empty!";
	}

	Node* temp = top;
	ItemType item = top->GetData();
	top = top->GetNext();
	delete temp;

	return item;
}