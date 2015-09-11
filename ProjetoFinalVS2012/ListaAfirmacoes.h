#ifndef _LISTAAFIRMACOES_H_
#define _LISTAAFIRMACOES_H_

#pragma once
#include "AbsListaElementos.h"
#include "Afirmacao.h"

class ListaAfirmacoes : public AbsListaElementos
{
private:
	Lista<Persistivel*> lista;

public:
	ListaAfirmacoes();
	~ListaAfirmacoes();
	
	void incluir(Persistivel *p);
	bool remover(Persistivel *p);
	void limpar();
	Lista<Persistivel*>* getLista();
	Persistivel* getElementoPeloId(int id);
};
#endif