#ifndef _ABSPERSISTEBINARIO_H_
#define _ABSPERSISTEBINARIO_H_

#pragma once
#include "AbsPersiste.h"

#include <iostream>
#include <fstream>

using namespace std;

class AbsPersisteBinario : public AbsPersiste
{
protected:
	char arquivo[100];
	char arquivoTemp[100];

	enum OPERACAO
	{
		Alterar, Remover, Localizar
	};
	virtual vector<Persistivel*> operacoesEmBinario(int id, Persistivel* persistivel, OPERACAO operacao) = 0;

	template<typename T>
	ostream& binary_write(ostream& stream, const T& value){
		return stream.write(reinterpret_cast<const char*>(&value), sizeof(T));
	}
	template<typename T>
	istream & binary_read(istream& stream, T& value){
		return stream.read(reinterpret_cast<char*>(&value), sizeof(T));
	}

public:
	AbsPersisteBinario(Persistivel* p);
	AbsPersisteBinario();
	~AbsPersisteBinario();

};
#endif