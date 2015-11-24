/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#ifndef _TLIST_H
#define _TLIST_H

#include "TNode.h"

struct TList {
public:
	TList();

	unsigned int Size();

	//adds at the end
	int Push(TElement * elem);

	//nullptr if empty
	TElement * First();

	//nullptr if empty
	TElement * Next();

	//removes at the beginning. nullptr if empty
	TElement * Pop();

	void Reset();

	~TList();

private:
	TNode * m_firstNode;
	TNode * m_currentNode;
	TNode * m_lastNode;
	unsigned int m_size;

	void deleteAllNodes();		//shared code between Reset() and ~TList()
};

#endif