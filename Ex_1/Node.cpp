#include "Node.h"

template <typename ItemType>
void Node<ItemType>::InsertAfter(Node<ItemType>* newNode)
{
	newNode->m_next = m_next;
	m_next = newNode;
}

template <typename ItemType>
Node<ItemType>* Node<ItemType>::DeleteAfter()
{
	Node<ItemType>* temp = m_next;

	if(next == NULL) 
		return NULL;

	m_next = temp->m_next;
	return temp;
}