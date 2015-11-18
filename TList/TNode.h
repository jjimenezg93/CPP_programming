/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma once

struct TNode {
public:
	TNode(const char * string);

	const char * getString();

	TNode * getNextNode();					//returns m_nextNode if exists, nullptr if not

	void setNextNode(TNode * next);

private:
	const char * m_string;
	TNode * m_nextNode;
};