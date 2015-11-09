/*
	Julián Jiménez González
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

//copy constructor
TList::TList(const TList &listCopy) {
	if (listCopy.m_size > 0) {
		TNode * ptr = listCopy.m_firstNode;
		this->m_size = 0;
		for (unsigned int i = 0; i < listCopy.m_size; i++) {
			TNode * newNode = new TNode(ptr->getString());
			if (this->m_size == 0) {
				this->m_firstNode = newNode;
				this->m_currentNode = newNode;
				this->m_lastNode = newNode;
				this->m_size++;
			} else {
				this->m_lastNode->setNextNode(newNode);
				this->m_lastNode = newNode;
				this->m_size++;
			}
			ptr = ptr->getNextNode();
		}
	} else {
		this->m_firstNode = nullptr;
		this->m_currentNode = nullptr;
		this->m_lastNode = nullptr;
		this->m_size = 0;
	}
}

TList GetReverseList(TList &lstSrc) {
	TList copy = TList();
	const char * ptr;
	if (lstSrc.Size() > 0) {
		for (unsigned int l = 0; l < lstSrc.Size(); l++) {
			for (unsigned int i = 0; i < lstSrc.Size() - 2; i++) {		//se mueve current al penúltimo elemento
				lstSrc.Next();
			}
			ptr = lstSrc.Next();				//se coge el último, en cada ejecución 1 menos
			copy.Push(ptr);
		}
	}
	return copy;
}

unsigned int TList::Size() {
	return m_size;
}

int TList::Push(const char * newNodeValue) {		//añade al final
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

void TList::Reset() {		//comparte el código con ~TList(), pero el destructor hace más cosas que limpiar los nodos
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

	//copy constructor
	list->Push("Hola");
	list->Push("que");

	TList *list2 = new TList(*list);

	printf_s("list2.First() = %s\n", list2->First());
	printf_s("list2.Next() = %s\n", list2->Next());

	list2->Push("tal?");
	printf_s("list2.Next() = %s\n", list2->Next());

	delete list2;

	//GetReverseList
	list->Push("tal");
	list->Push("estas?");

	TList listInv = GetReverseList(*list);
	printf_s("listInv.First() = %s\n", listInv.First());
	printf_s("listInv.Next() = %s\n", listInv.Next());
	printf_s("listInv.Next() = %s\n", listInv.Next());
	printf_s("listInv.Next() = %s\n", listInv.Next());

	delete list;

	getchar();
}