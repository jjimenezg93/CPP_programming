/*
	Juli�n Jim�nez Gonz�lez
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

int TList::Push(const char * newNodeValue) {		//a�ade al final
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
		const char * ret = "List is empty";
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
		const char * ret = "List is empty";
		return ret;
	}
}

const char * TList::Pop() {				//quita al principio
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
		return "List is empty";
}

void TList::Reset() {		//comparte el c�digo con ~TList(), pero el destructor hace m�s cosas que limpiar los nodos
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

TList::~TList() {
	printf_s("Deleting list...\n");
	this->deleteAllNodes();
}

int main() {
	TList *list = new TList();
	printf_s("list.First() = %s\n", list->First());
	printf_s("list.Pop() = %s\n", list->Pop());

	list->Push("Hola");
	printf_s("Pushed \"Hola\"!\n");
	list->Push("Holita");
	printf_s("Pushed \"Holita\"!\n");
	list->Push("Que tal?");
	printf_s("Pushed \"Que tal?\"!\n");

	printf_s("list.Next() = %s\n", list->Next());
	printf_s("list.Next() = %s\n", list->Next());
	printf_s("list.Next() = %s\n", list->Next());
	printf_s("list.Next() = %s\n", list->Next());

	printf_s("list.First() = %s\n", list->First());
	printf_s("list.Pop() = %s\n", list->Pop());
	printf_s("list.First() = %s\n", list->First());
	
	list->Push("Hola");

	list->Reset();
	printf_s("list reset!\n");

	printf_s("list.First() = %s\n", list->First());
	printf_s("list.Next() = %s\n", list->Next());

	delete list;

	getchar();
}