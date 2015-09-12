#ifndef _PERSISTEMEMORIAPESSOA_H_
#define _PERSISTEMEMORIAPESSOA_H_

#pragma once
#include "stdafx.h"
#include "AbsPersiste.h"

using namespace std;

class PersisteMemoriaPessoa : public AbsPersiste
{
public:
	PersisteMemoriaPessoa(Persistivel* p);
	PersisteMemoriaPessoa();
	~PersisteMemoriaPessoa();

	const bool inserir();
	const bool alterar();
	const bool remover();
	vector<Persistivel*> carregarCadastros(const int id);
};
#endif