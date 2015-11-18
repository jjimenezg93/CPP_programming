/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <stdio.h>
#include "TList.h"

TList::TList() {
	m_firstNode = nullptr;
	m_currentNode = nullptr;
	m_lastNode = nullptr;
	m_size = 0;
}

unsigned int TList::Size() {
	return m_size;
}

int TList::Push(const char * newNodeValue) {
	TNode * newNode;
	newNode = new TNode(newNodeValue);
	if (m_size == 0) {
		m_firstNode = newNode;
		m_currentNode = newNode;
		m_lastNode = newNode;
		m_size++;
		return 0;
	} else if (m_size > 0) {
		m_lastNode->setNextNode(newNode);
		m_lastNode = newNode;
		m_size++;
		return 0;
	} else {
		return 1;
	}
}

const char * TList::First() {
	if (m_firstNode != nullptr)
		return m_firstNode->getString();
	else {
		const char * ret = nullptr;
		return ret;
	}
}

const char * TList::Next() {
	if (m_currentNode != nullptr) {
		if (m_currentNode->getNextNode() != nullptr) {
			m_currentNode = m_currentNode->getNextNode();
		} else if (m_currentNode == m_lastNode) {
			m_currentNode = m_firstNode;
		}
		return m_currentNode->getString();
	} else {
		const char * ret = nullptr;
		return ret;
	}
}

const char * TList::Pop() {
	if (m_firstNode != nullptr) {
		TNode * nodeToDelete = m_firstNode;
		const char * stringRet = nodeToDelete->getString();
		if (m_firstNode->getNextNode() != nullptr) {
			m_firstNode = m_firstNode->getNextNode();
			m_currentNode = m_firstNode;
		} else {
			m_firstNode = nullptr;
			m_currentNode = nullptr;
			m_lastNode = nullptr;
		}
		delete nodeToDelete;
		m_size--;
		return stringRet;
	} else
		return nullptr;
}

void TList::Reset() {
	this->deleteAllNodes();
}

TList::~TList() {
	printf_s("Deleting list...\n");
	this->deleteAllNodes();
}

void TList::deleteAllNodes() {
	unsigned int size = m_size;
	if (m_firstNode != nullptr) {
		TNode * nodeDelete = m_firstNode;
		for (unsigned short int i = 0; i < size; i++) {
			m_firstNode = m_firstNode->getNextNode();
			delete nodeDelete;
			nodeDelete = m_firstNode;
		}
	}
	m_size = 0;
	m_currentNode = m_firstNode;
	m_lastNode = m_firstNode;
}