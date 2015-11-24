/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#include "TNode.h"

TNode::TNode(TElement * content) {
	m_element = content;
	m_nextNode = nullptr;
}

TElement * TNode::getElement()
{
	return m_element;
}

TNode * TNode::getNextNode( )
{
	return m_nextNode;
}

void TNode::setNextNode(TNode * next) {
	m_nextNode = next;
}
