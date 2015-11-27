/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <cstdio>
#include <cstdlib>
#include "TApple.h"

TApple::TApple(int * content) {
	this->m_content = (int *)malloc(sizeof(int));
	this->m_content = content;
}

int TApple::getContent() {
	printf_s("This is TApple::getContent()");
	return *(this->m_content);
}

void TApple::setContent(int * newContent) {
	this->m_content = newContent;
	printf_s("TApple::m_content new value: %d\n", *newContent);
}

void TApple::printElement() {
	printf_s("TApple: %d\n", *(this->m_content));
}

TApple::~TApple() {
	free(this->m_content);
}
