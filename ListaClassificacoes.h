#ifndef _LISTACLASSIFICACOES_H_
#define _LISTACLASSIFICACOES_H_

#pragma once
#include "AbsListaElementos.h"
#include "Classificacao.h"

class ListaClassificacoes : public AbsListaElementos
{
private:
	Lista<Persistivel*> lista;

public:
	ListaClassificacoes();
	~ListaClassificacoes();
	
	void incluir(Persistivel *p);
	bool remover(Persistivel *p);
	void limpar();
	Lista<Persistivel*>* getLista();
	Persistivel* getElementoPeloId(int id);
};
#endif