/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma once

#include "TNode.h"

struct TList {
public:
	TList();

	unsigned int Size();

	int Push(const char * psz);	//adds at the end

	const char * First();

	const char * Next();

	const char * Pop();			//removes at the beginning

	void Reset();

	~TList();

private:
	TNode * m_firstNode;
	TNode * m_currentNode;
	TNode * m_lastNode;
	unsigned int m_size;

	void deleteAllNodes();		//shared code between Reset() and ~TList()
};