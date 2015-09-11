#ifndef _LISTAMODERADORES_H_
#define _LISTAMODERADORES_H_

#pragma once
#include "AbsListaElementos.h"
#include "Moderador.h"

class ListaModeradores : public AbsListaElementos
{
private:
	Lista<Persistivel*> lista;

public:
	ListaModeradores();
	~ListaModeradores();
	
	void incluir(Persistivel *p);
	bool remover(Persistivel *p);
	void limpar();
	Lista<Persistivel*>* getLista();
	Persistivel* getElementoPeloId(int id);
};
#endif