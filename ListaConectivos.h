#ifndef _LISTACONECTIVOSS_H_
#define _LISTACONECTIVOSS_H_

#pragma once
#include "AbsListaElementos.h"
#include "Conectivo.h"

class ListaConectivos : public AbsListaElementos
{
private:
	Lista<Persistivel*> lista;

public:
	ListaConectivos();
	~ListaConectivos();
	
	void incluir(Persistivel *p);
	bool remover(Persistivel *p);
	void limpar();
	Lista<Persistivel*>* getLista();
	Persistivel* getElementoPeloId(int id);
};
#endif