#ifndef _PERSISTEBINARIOINSTITUICAO_H_
#define _PERSISTEBINARIOINSTITUICAO_H_

#pragma once
#include "stdafx.h"
#include "AbsPersisteBinario.h"

class PersisteBinarioInstituicao : public AbsPersisteBinario
{
private:
	char nome[201];
	char sigla[21];
	char tipo[41];
	
	//inherited methods
	vector<Persistivel*> operacoesEmBinario(int id, Persistivel* persistivel, OPERACAO operacao);

public:
	PersisteBinarioInstituicao(Persistivel* p);
	PersisteBinarioInstituicao();
	~PersisteBinarioInstituicao();
	
	//inherited methods
	const bool inserir();
	const bool alterar();
	const bool remover();
	vector<Persistivel*> carregarCadastros(const int id);
};
#endif