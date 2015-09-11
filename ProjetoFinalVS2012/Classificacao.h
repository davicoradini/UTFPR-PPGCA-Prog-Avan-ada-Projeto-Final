#ifndef _CLASSIFICACAO_H_
#define _CLASSIFICACAO_H_

#pragma once
#include "stdafx.h"

#include "Persistivel.h"
#include "AbsPersiste.h"
#include "PersisteBinarioClassificacao.h"
#include "PersisteMemoriaClassificacao.h"

class Classificacao : public Persistivel
{
private:
	char nome[41];
	string descricao;
	AbsPersiste *persistidor;

public:
	Classificacao();
	~Classificacao();
	
	//setters
	void setNome(const char* n);
	void setDescricao(string s);

	//getters
	const char* getNome() const;
	const string getDescricao() const;

	//inherited methods
	bool gravar();
	bool remover();
	Persistivel* carregar(int id);
	vector<Persistivel*> localizarCadastros();
	
private:
	vector<Persistivel*> localizarCadastroPeloId(const int id);
	void definePersistidorNaConstrutora();
};
#endif