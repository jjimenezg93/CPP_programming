/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#include <cstdio>
#include <cstdlib>
#include "TPear.h"

TPear::TPear(char * content) {
	this->m_content = (char *)malloc(sizeof(int));
	this->m_content = content;
}

char * TPear::getContent() {
	printf_s("This is TApple::getContent()");
	return this->m_content;
}

void TPear::setContent(char * newContent) {
	this->m_content = newContent;
	printf_s("TPear::m_content new value: %s\n", newContent);
}

void TPear::printElement() {
	printf_s("TPear:  %s\n", this->m_content);
}

TPear::~TPear() {
	free(this->m_content);
}
