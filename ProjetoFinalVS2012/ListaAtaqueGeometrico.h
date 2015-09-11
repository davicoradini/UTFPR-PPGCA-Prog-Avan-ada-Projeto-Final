#ifndef _LISTAATAQUEGEOMETRICO_H_
#define _LISTAATAQUEGEOMETRICO_H_

#pragma once
#include <vector>
#include "AtaqueGeometrico.h"

using namespace std;
using namespace System::Collections;

class ListaAtaqueGeometrico
{
private:
	private: vector<AtaqueGeometrico*> lista;

public:
	ListaAtaqueGeometrico();
	~ListaAtaqueGeometrico();
	
	void incluir(AtaqueGeometrico *p);
	bool remover(AtaqueGeometrico *p);
	void limpar();
	vector<AtaqueGeometrico*>* getLista();
	AtaqueGeometrico* getElementoPeloId(int id);
	const int getIdPeloArgumento(int idArgumento);
};
#endif