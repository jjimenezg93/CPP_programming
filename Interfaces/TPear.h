/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#ifndef _TPEAR_H
#define _TPEAR_H

#include "TElement.h"

struct TPear : public TElement {
public:
	TPear(char * content);

	char * getContent();

	void setContent(char * newContent);

	virtual void printElement();

	~TPear();
private:
	char *m_content;
};

#endif