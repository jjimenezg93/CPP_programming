
#include "TNode.h"

TNode::TNode(const char * string) {
	m_string = string;
	m_nextNode = nullptr;
}

TNode::TNode(const TNode &nodeToCopy) = default;

const char * TNode::getString( )
{
	return m_string;
}

TNode * TNode::getNextNode( )
{
	return m_nextNode;
}

void TNode::setNextNode(TNode * next) {
	m_nextNode = next;
}
