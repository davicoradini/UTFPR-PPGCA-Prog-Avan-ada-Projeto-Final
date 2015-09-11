#ifndef _ATAQUEGEOMETRICO_H_
#define _ATAQUEGEOMETRICO_H_

#pragma once
#include <windows.h>
#include <SFML/Graphics.hpp>
#include "Persistivel.h"
#include "Ataque.h"
#include "Argumento.h"

using namespace System;

class AtaqueGeometrico : public Persistivel
{
private:
	int id;
	//Ataque *ataque;
	Argumento *argOrigem;
	Argumento *argDestino;
	int xInicial;
	int yInicial;
	int xFinal;
	int yFinal;

public:
	AtaqueGeometrico(const int i, Argumento *o, Argumento *d, const int iniX, const int iniY, const int fimX, const int fimY);
	AtaqueGeometrico();
	~AtaqueGeometrico();

	const int getId();
	//Ataque* getAtaque();
	Argumento* getArgOrigem();
	Argumento* getArgDestino();
	const int getXInicial();
	const int getYInicial();
	const int getXFinal();
	const int getYFinal();

	//inherited methods
	bool gravar();
	bool remover();
	Persistivel* carregar(int id);
	vector<Persistivel*> localizarCadastros();
};
#endif