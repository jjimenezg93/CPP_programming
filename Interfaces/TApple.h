/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#ifndef _TAPPLE_H
#define _TAPPLE_H

#include "TElement.h"

struct TApple : public TElement {
public:
	TApple(int * content);

	int getContent();

	void setContent(int * newContent);

	virtual void printElement();

	~TApple();
private:
	int *m_content;
};

#endif