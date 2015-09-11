#ifndef _LISTARGUMENTACOES_H_
#define _LISTARGUMENTACOES_H_

#pragma once
#include "AbsListaElementos.h"
#include "Argumentacao.h"

class ListaArgumentacoes : public AbsListaElementos
{
private:
	Lista<Persistivel*> lista;

public:
	ListaArgumentacoes();
	~ListaArgumentacoes();
	
	void incluir(Persistivel *p);
	bool remover(Persistivel *p);
	void limpar();
	Lista<Persistivel*>* getLista();
	Persistivel* getElementoPeloId(int id);
};
#endif