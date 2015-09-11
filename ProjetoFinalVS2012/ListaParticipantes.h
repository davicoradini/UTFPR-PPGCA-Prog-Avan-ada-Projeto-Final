#ifndef _LISTAPARTICIPANTES_H_
#define _LISTAPARTICIPANTES_H_

#pragma once
#include "AbsListaElementos.h"
#include "Participante.h"

class ListaParticipantes : public AbsListaElementos
{
private:
	Lista<Persistivel*> lista;

public:
	ListaParticipantes();
	~ListaParticipantes();
	
	void incluir(Persistivel *p);
	bool remover(Persistivel *p);
	void limpar();
	Lista<Persistivel*>* getLista();
	Persistivel* getElementoPeloId(int id);
};
#endif