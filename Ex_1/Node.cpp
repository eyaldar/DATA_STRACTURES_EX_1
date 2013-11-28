#include "Node.h"

void Node::InsertAfter(Node* newNode)
{
	newNode->m_next = m_next;
	m_next = newNode;
}

Node* Node::DeleteAfter()
{
	Node* temp = m_next;

	if(m_next == NULL) 
		return NULL;

	m_next = temp->m_next;
	return temp;
}