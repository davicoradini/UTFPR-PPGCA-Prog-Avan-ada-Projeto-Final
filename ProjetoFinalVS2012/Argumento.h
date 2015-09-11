#ifndef _ARGUMENTO_H_
#define _ARGUMENTO_H_

#pragma once
#include "Persistivel.h"
#include "Classificacao.h"
#include "Moderador.h"
#include "Participante.h"

#include <string>
#include <vector>
using namespace std;

class Argumento : public Persistivel
{
private:
	int id;
	char nome[21];
	string descricao;
	string apoio;
	string conclusao;
	Moderador* moderador;
	Participante* autor;
	Classificacao* classificacao;

public:
	Argumento();
	~Argumento();

	//setters
	void setIdArgumentacao(const int i);
	void setId(const int i);
	void setNome(const char *n);
	void setDescricao(string d);
	void setApoio(string a);
	void setConclusao(string c);
	void setModerador(Moderador* m);
	void setParticipante(Participante* p);
	void setClassificacao(Classificacao* c);

	//getters
	const int getId() const;
	const char* getNome() const;
	const string getDescricao() const;
	const string getApoio() const;
	const string getConclusao() const;
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