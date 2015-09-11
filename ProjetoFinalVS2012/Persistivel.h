#ifndef _Persistivel_H_
#define _Persistivel_H_

#pragma once
#include "stdafx.h"

class Persistivel
{
protected:
	int idArgumentacao;
	int id;

public:
	Persistivel();
	virtual ~Persistivel();

	//não precisam ser re-implementados
	void setIdArgumentacao(const int i);
	const int getIdArgumentacao();
	void setId(const int i);
	const int getId() const;

	//devem ser implementados em classes filhas
	virtual bool gravar() = 0;
	virtual bool remover() = 0;
	virtual Persistivel* carregar(int i) = 0;
	virtual vector<Persistivel*> localizarCadastros() = 0;

private:
	//contrato garantindo a implementação desta lógica
	//virtual void definePersistidorNaConstrutora() = 0;
	//vector<Persistivel*> localizarCadastroPeloId(const int id);

};
#endif