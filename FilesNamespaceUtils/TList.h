/*
Julián Jiménez González
*/

#pragma once
#include "TNode.h"

struct TList {
public:

	TList();

	unsigned int Size();

	int Push(const char * psz);

	const char * First();

	const char * Next();

	const char * Pop();

	void Reset();

	void deleteAllNodes();		//reutilización de código en Reset() y ~TList()

	~TList();

private:
	TNode * m_firstNode;
	TNode * m_currentNode;
	TNode * m_lastNode;
	unsigned int m_size;
};