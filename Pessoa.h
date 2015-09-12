#ifndef _PESSOA_H_
#define _PESSOA_H_

#pragma once
#include "stdafx.h"

#include "Persistivel.h"
#include "AbsPersiste.h"
#include "PersisteBinarioPessoa.h"
#include "PersisteMemoriaPessoa.h"
#include "Instituicao.h"
#include "Prototype.h"

class Pessoa : public Persistivel, public Prototype
{
private:
	char nome[201];
	char cargo[101];
	Instituicao* instituicao;
	AbsPersiste *persistidor;

public:
	Pessoa();
	~Pessoa();

	//setters
	void setNome(const char* n);
	void setCargo(const char* c);
	void setInstituicao(Instituicao* i);

	//getters
	const char* getNome() const;
	const char* getCargo() const;
	Instituicao* getInstituicao() const;

	//inherited methods
	bool gravar();
	bool remover();
	Persistivel* carregar(int id);
	vector<Persistivel*> localizarCadastros();

	Prototype* clone();

private:
	vector<Persistivel*> localizarCadastroPeloId(const int id);
	void definePersistidorNaConstrutora();
};
#endif