/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#ifndef _TNODE_H
#define _TNODE_H

#include "TElement.h"

struct TNode {
public:
	TNode(TElement * element);

	TElement * getElement();

	TNode * getNextNode();					//returns m_nextNode if exists, nullptr if not

	void setNextNode(TNode * next);

private:
	TElement * m_element;
	TNode * m_nextNode;
};

#endif