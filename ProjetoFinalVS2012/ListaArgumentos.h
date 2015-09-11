#ifndef _LISTAARGUMENTOS_H_
#define _LISTAARGUMENTOS_H_

#pragma once
#include "AbsListaElementos.h"
#include "Argumento.h"

class ListaArgumentos : public AbsListaElementos
{
private:
	Lista<Persistivel*> lista;

public:
	ListaArgumentos();
	~ListaArgumentos();
	
	void incluir(Persistivel *p);
	bool remover(Persistivel *p);
	void limpar();
	Lista<Persistivel*>* getLista();
	Persistivel* getElementoPeloId(int id);

};
#endif