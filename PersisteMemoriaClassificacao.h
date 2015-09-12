#ifndef _PERSISTEMEMORIACLASSIFICACAO_H_
#define _PERSISTEMEMORIACLASSIFICACAO_H_

#pragma once
#include "stdafx.h"
#include "AbsPersiste.h"

using namespace std;

class PersisteMemoriaClassificacao : public AbsPersiste
{
public:
	PersisteMemoriaClassificacao(Persistivel* p);
	PersisteMemoriaClassificacao();
	~PersisteMemoriaClassificacao();

	const bool inserir();
	const bool alterar();
	const bool remover();
	vector<Persistivel*> carregarCadastros(const int id);
};
#endif