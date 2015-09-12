#ifndef _LISTAARGUMENTOGEOMETRICO_H_
#define _LISTAARGUMENTOGEOMETRICO_H_

#pragma once
#include <vector>
#include "ArgumentoGeometrico.h"

using namespace std;
using namespace System::Collections;

class ListaArgumentoGeometrico
{
private:
	private: vector<ArgumentoGeometrico*> lista;

public:
	ListaArgumentoGeometrico();
	~ListaArgumentoGeometrico();
	
	void incluir(ArgumentoGeometrico *p);
	bool remover(ArgumentoGeometrico *p);
	void limpar();
	vector<ArgumentoGeometrico*>* getLista();
	ArgumentoGeometrico* getElementoPeloId(int id);
};
#endif