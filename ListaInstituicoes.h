#ifndef _LISTAINSTITUICOES_H_
#define _LISTAINSTITUICOES_H_

#pragma once
#include "AbsListaElementos.h"
#include "Instituicao.h"

class ListaInstituicoes : public AbsListaElementos
{
private:
	Lista<Persistivel*> lista;

public:
	ListaInstituicoes();
	~ListaInstituicoes();
	
	void incluir(Persistivel *p);
	bool remover(Persistivel *p);
	void limpar();
	Lista<Persistivel*>* getLista();
	Persistivel* getElementoPeloId(int id);
};
#endif