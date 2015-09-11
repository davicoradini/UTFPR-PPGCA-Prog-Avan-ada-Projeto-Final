#ifndef _ABSPERSISTEXML_H_
#define _ABSPERSISTEXML_H_

#pragma once
#include "AbsPersiste.h"

#include <iostream>
#include <fstream>

using namespace std;

#pragma once
class AbsPersisteXML : public AbsPersiste
{
protected:
	char arquivo[100];

public:
	AbsPersisteXML(Persistivel* p);
	AbsPersisteXML();
	~AbsPersisteXML();
};
#endif