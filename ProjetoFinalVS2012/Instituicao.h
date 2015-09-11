#ifndef _INSTITUICAO_H_
#define _INSTITUICAO_H_

#pragma once
#include "stdafx.h"

#include "Persistivel.h"
#include "AbsPersiste.h"
#include "PersisteBinarioInstituicao.h"
#include "PersisteMemoriaInstituicao.h"
#include "Prototype.h"

class Instituicao : public Persistivel, public Prototype
{
private:
	//int id;
	char nome[201];
	char sigla[21];
	char tipo[41];
	AbsPersiste *persistidor;

public:
	Instituicao();
	~Instituicao();

	//setters
	void setNome(const char* n);
	void setSigla(const char* s);
	void setTipo(const char* t);

	//getters
	const char* getNome() const;
	const char* getSigla() const;
	const char* getTipo() const;

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