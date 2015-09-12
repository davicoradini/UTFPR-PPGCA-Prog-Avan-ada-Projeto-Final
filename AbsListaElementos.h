#ifndef _ABSLISTAELEMENTOS_H_
#define _ABSLISTAELEMENTOS_H_

#pragma once
#include "Persistivel.h"
#include "Lista.h"

class AbsListaElementos
{

public:
	//atributo publico acessível nas classes derivadas
	//Lista<Persistivel*> lista;

	//construtor e destrutor
	AbsListaElementos(void);
	virtual ~AbsListaElementos(void);


	//Métodos virtuais puros -devem ser implementados nas derivadas
	virtual void incluir(Persistivel *p) = 0;
	virtual bool remover(Persistivel *p) = 0;
	virtual void limpar() = 0;
	virtual Lista<Persistivel*>* getLista() = 0;
	virtual Persistivel* getElementoPeloId(int id) = 0;
};
#endif