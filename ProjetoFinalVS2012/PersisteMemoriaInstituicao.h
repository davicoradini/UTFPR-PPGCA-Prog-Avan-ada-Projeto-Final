#ifndef _PERSISTEMEMORIAINSTITUICAO_H_
#define _PERSISTEMEMORIAINSTITUICAO_H_

#pragma once
#include "stdafx.h"
#include "AbsPersiste.h"

using namespace std;

class PersisteMemoriaInstituicao : public AbsPersiste
{
public:
	PersisteMemoriaInstituicao(Persistivel* p);
	PersisteMemoriaInstituicao();
	~PersisteMemoriaInstituicao();

	const bool inserir();
	const bool alterar();
	const bool remover();
	vector<Persistivel*> carregarCadastros(const int id);
};
#endif