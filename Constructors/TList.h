/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#ifndef _TLIST_H
#define _TLIST_H

#include "TNode.h"

struct TList {
public:
	TList();

	TList(const TList &listCopy);

	unsigned int Size() const;

	//adds at the end
	int Push(const char * psz);

	//nullptr if empty
	const char * First() const;

	//nullptr if empty
	const char * Next();

	//removes at the beginning. nullptr if empty
	const char * Pop();

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