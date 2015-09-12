#ifndef _CONECTIVO_H_
#define _CONECTIVO_H_

#pragma once
#include "Persistivel.h"

#include <string>
#include <vector>
using namespace std;

class Conectivo : public Persistivel
{
private:
	int id;
	char nome[201];
	wchar_t simbolo;
	string descricao;
	bool preCadastrado;

public:
	Conectivo(const int i, const char *n, wchar_t s, const bool p);
	Conectivo();
	~Conectivo();
	
	//setters
	void setId(const int i);
	void setNome(const char* n);
	void setSimbolo(wchar_t s);
	void setDescricao(string s);
	void setPreCadastrado(const bool p);

	//getters
	const int getId() const;
	const char* getNome() const;
	const wchar_t getSimbolo() const;
	const string getDescricao() const;
	const bool isPreCadastrado() const;

	//inherited methods
	bool gravar();
	bool remover();
	Persistivel* carregar(int id);
	vector<Persistivel*> localizarCadastros();
};
#endif