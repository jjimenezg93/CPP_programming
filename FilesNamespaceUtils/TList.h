/*
Juli�n Jim�nez Gonz�lez
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

	void deleteAllNodes();		//reutilizaci�n de c�digo en Reset() y ~TList()

	~TList();

private:
	TNode * m_firstNode;
	TNode * m_currentNode;
	TNode * m_lastNode;
	unsigned int m_size;
};