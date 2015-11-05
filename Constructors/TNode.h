#pragma once

struct TNode {
public:
	TNode(const char * string);

	TNode(const TNode &node);

	const char * getString();			//retorna m_string

	TNode * getNextNode();					//retorna puntero al siguiente nodo si existe (m_nextNode), nullptr si no

	void setNextNode(TNode * next);

private:
	const char * m_string;
	TNode * m_nextNode;
};