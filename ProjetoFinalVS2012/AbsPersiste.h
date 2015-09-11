#ifndef _ABSPERSISTE_H_
#define _ABSPERSISTE_H_

#pragma once
#include "stdafx.h"
#include "Persistivel.h"

class AbsPersiste
{
protected:
	Persistivel* persistivel;
	vector<Persistivel*> cadastrosLocalizados;

public:
	AbsPersiste(Persistivel *p);
	AbsPersiste();
	virtual ~AbsPersiste();
	
	void setPersistivel(Persistivel* p);
	Persistivel* getPersistivel();

	virtual const bool inserir() = 0;
	virtual const bool alterar() = 0;
	virtual const bool remover() = 0;
	virtual vector<Persistivel*> carregarCadastros(const int id) = 0;
};
#endif