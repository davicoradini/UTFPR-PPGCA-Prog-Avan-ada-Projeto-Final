#ifndef _LISTAATAQUES_H_
#define _LISTAATAQUES_H_

#pragma once
#include "AbsListaElementos.h"
#include "Ataque.h"

class ListaAtaques : public AbsListaElementos
{
private:
	Lista<Persistivel*> lista;

public:
	ListaAtaques();
	~ListaAtaques();
	
	void incluir(Persistivel *p);
	bool remover(Persistivel *p);
	void limpar();
	Lista<Persistivel*>* getLista();
	Persistivel* getElementoPeloId(int id);

	bool ataqueExiste(Argumento* origem, Argumento* destino);
	//Persistivel* getElementoPeloIdArgumento(int id);
};
#endif