/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#ifndef _TELEMENT_H
#define _TELEMENT_H

class TElement {
public:
	virtual void printElement() = 0;
	/*virtual void * getContent() = 0;

	virtual void setContent(void * newContent) = 0;*/

	virtual ~TElement() { }		//haria falta si los TElement se crearan dentro de la lista
};

#endif