#ifndef _LISTAPESSOAS_H_
#define _LISTAPESSOAS_H_

#pragma once
#include "AbsListaElementos.h"
#include "Pessoa.h"

class ListaPessoas : public AbsListaElementos
{
private:
	Lista<Persistivel*> lista;

public:
	ListaPessoas();
	~ListaPessoas();
	
	void incluir(Persistivel *p);
	bool remover(Persistivel *p);
	void limpar();
	Lista<Persistivel*>* getLista();
	Persistivel* getElementoPeloId(int id);
};
#endif