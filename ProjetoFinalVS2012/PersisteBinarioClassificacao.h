#ifndef _PERSISTEBINARIOCLASSIFICACAO_H_
#define _PERSISTEBINARIOCLASSIFICACAO_H_

#pragma once
#include "stdafx.h"
#include "AbsPersisteBinario.h"

class PersisteBinarioClassificacao : public AbsPersisteBinario
{
private:
	char nome[41];
	char descricao[1000];

	//inherited methods
	vector<Persistivel*> operacoesEmBinario(int id, Persistivel* persistivel, OPERACAO operacao);

public:
	PersisteBinarioClassificacao(Persistivel* p);
	PersisteBinarioClassificacao();
	~PersisteBinarioClassificacao();

	//inherited methods
	const bool inserir();
	const bool alterar();
	const bool remover();
	vector<Persistivel*> carregarCadastros(const int id);
};
#endif