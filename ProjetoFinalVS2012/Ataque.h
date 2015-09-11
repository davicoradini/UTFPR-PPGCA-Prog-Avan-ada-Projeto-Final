#ifndef _ATAQUE_H_
#define _ATAQUE_H_

#pragma once
#include "Persistivel.h"
#include "Argumento.h"

#include <string>
#include <vector>
using namespace std;

class Ataque : public Persistivel
{
private:
	int id;
	Argumento* pOrigem;
	Argumento* pDestino;

public:
	Ataque();
	~Ataque();

	//setters
	void setId(const int i);
	void setPOrigem(Argumento* o);
	void setPDestino(Argumento* d);

	//getters
	const int getId() const;
	Argumento* getPOrigem() const;
	Argumento* getPDestino() const;

	//inherited methods
	bool gravar();
	bool remover();
	Persistivel* carregar(int id);
	vector<Persistivel*> localizarCadastros();
};
#endif