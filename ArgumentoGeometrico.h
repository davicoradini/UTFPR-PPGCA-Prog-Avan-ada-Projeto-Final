#ifndef _ARGUMENTOGEOMETRICO_H_
#define _ARGUMENTOGEOMETRICO_H_

#pragma once
#include "Persistivel.h"
#include "Argumento.h"

class ArgumentoGeometrico : public Persistivel
{
private:
	int id;
	Argumento *argumento;
	int posX;
	int posY;
	int largura;
	int altura;

public:
	ArgumentoGeometrico(const int i, Argumento *a, const int x, const int y, const int la, const int al);
	ArgumentoGeometrico();
	~ArgumentoGeometrico();

	void setPosX(const int x);
	void setPosY(const int y);
	void setLargura(const int l);
	void setAltura(const int a);

	const int getId();
	Argumento* getArgumento();
	const int getPosX();
	const int getPosY();
	const int getLargura();
	const int getAltura();

	//inherited methods
	bool gravar();
	bool remover();
	Persistivel* carregar(int id);
	vector<Persistivel*> localizarCadastros();
};
#endif