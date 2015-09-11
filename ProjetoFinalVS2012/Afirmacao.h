#ifndef _AFIRMACAO_H_
#define _AFIRMACAO_H_

#pragma once
#include "stdafx.h"

#include "Persistivel.h"
#include "Classificacao.h"
#include "Moderador.h"
#include "Participante.h"


class Afirmacao : public Persistivel
{
private:
	int id;
	string nome;
	string descricao;
	Moderador* moderador;
	Participante* autor;
	Classificacao* classificacao;

public:
	Afirmacao();
	~Afirmacao();

	//setters
	void setId(const int i);
	void setNome(string n);
	void setDescricao(string a);
	void setModerador(Moderador* m);
	void setParticipante(Participante* p);
	void setClassificacao(Classificacao* c);

	//getters
	const int getId() const;
	const string getNome() const;
	const string getDescricao() const;
	Moderador* getModerador() const;
	Participante* getParticipante() const;
	Classificacao* getClassificacao() const;

	//inherited methods
	bool gravar();
	bool remover();
	Persistivel* carregar(int id);
	vector<Persistivel*> localizarCadastros();
};
#endif