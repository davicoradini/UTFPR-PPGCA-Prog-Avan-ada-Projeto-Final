#ifndef _PERSISTEBINARIOPESSOA_H_
#define _PERSISTEBINARIOPESSOA_H_

#pragma once
#include "stdafx.h"
#include "AbsPersisteBinario.h"

class PersisteBinarioPessoa : public AbsPersisteBinario
{
private:
	char nome[201];
	char cargo[101];
	int  idInstituicao;

	//inherited methods
	vector<Persistivel*> operacoesEmBinario(int id, Persistivel* persistivel, OPERACAO operacao);

public:
	PersisteBinarioPessoa(Persistivel* p);
	PersisteBinarioPessoa();
	~PersisteBinarioPessoa();

	//inherited methods
	const bool inserir();
	const bool alterar();
	const bool remover();
	vector<Persistivel*> carregarCadastros(const int id);
};
#endif