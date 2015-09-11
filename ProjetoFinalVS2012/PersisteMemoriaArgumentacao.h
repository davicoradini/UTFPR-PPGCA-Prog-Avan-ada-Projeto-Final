#ifndef _PERSISTEMEMORIAARGUMENTACAO_H_
#define _PERSISTEMEMORIAARGUMENTACAO_H_

#pragma once
#include "stdafx.h"
#include "AbsPersiste.h"

using namespace std;

class PersisteMemoriaArgumentacao : public AbsPersiste
{
public:
	PersisteMemoriaArgumentacao(Persistivel* p);
	PersisteMemoriaArgumentacao();
	~PersisteMemoriaArgumentacao();

	const bool inserir();
	const bool alterar();
	const bool remover();
	vector<Persistivel*> carregarCadastros(const int id);
};
#endif