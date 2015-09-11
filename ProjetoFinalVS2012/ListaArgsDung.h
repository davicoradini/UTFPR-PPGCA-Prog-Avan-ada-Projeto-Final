#ifndef _LISTAARGSDUNG_H_
#define _LISTAARGSDUNG_H_

#pragma once
#include "stdafx.h"
#include "Argumento.h"

class ListaArgsDung
{
private:
	vector<Argumento*> lista;

public:
	ListaArgsDung();
	~ListaArgsDung();

	void incluir(Argumento* a);
	void copiarArgsLista(ListaArgsDung* listaCopiar);
	//void remover(Argumento* a);
	void limpar();
	bool isThere(Argumento* a);
	Argumento* getUltimoArgumento();

	vector<Argumento*> *getLista(){ return &lista; }

};
#endif