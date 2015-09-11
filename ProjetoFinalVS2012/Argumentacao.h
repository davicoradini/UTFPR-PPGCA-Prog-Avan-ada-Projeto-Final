#ifndef _ARGUMENTACAO_H_
#define _ARGUMENTACAO_H_

#pragma once
#include "Persistivel.h"
#include "Argumento.h"
#include "PersisteMemoriaArgumentacao.h"
#include "ListaParticipantes.h"
#include "ListaModeradores.h"
#include "ListaArgumentos.h"
#include "ListaAtaques.h"
#include "ListaAfirmacoes.h"
#include "ListaAtaqueGeometrico.h"
#include "ListaArgumentoGeometrico.h"

#include <string>
#include <vector>
using namespace std;

class Argumentacao : public Persistivel//, public Prototype
{
private:
	int						id;
	char					nome[201];
	//Argumento*				objetivo;
	//char					modeloArgumentacao[4];
	//wchar_t					baseConhecimento;
	//bool					exibeTelaCompleta;
	int						idLetraArgumento;
	int						idArgumento;
	int						idAtaque;
	AbsPersiste*			persistidor;

	ListaParticipantes		listaParticipantes;
	ListaModeradores		listaModeradores;
	ListaArgumentos			listaArgumentos;
	ListaAtaques			listaAtaques;
	ListaAfirmacoes			listaAfirmacoes;
	ListaAtaqueGeometrico	listaAtaqueGeometrico;
	ListaArgumentoGeometrico listaArgumentoGeometrico;
		
public:
	Argumentacao();
	~Argumentacao();

	//setters
	void setId(const int i);
	void setNome(const char* n);
	void setObjetivo(Argumento* o);
	void setModeloArgumentacao(const char* m);
	void setBaseConhecimento(wchar_t s);
	void setExibeTelaCompleta(const bool e);

	//getters
	const int		getId() const;
	const char*		getNome() const;
	//Argumento*		getObjetivo() const;
	//const char*		getModeloArgumentacao() const;
	//const wchar_t	getBaseConhecimento() const;
	//const bool		isExibeTelaCompleta() const;
	const string	getNextLetraArgumento();
	const int		getNextIdArgumento();
	const int		getNextIdAtaque();
	
	ListaParticipantes*		getListaParticipantes();
	ListaModeradores*		getListaModeradores();
	ListaArgumentos*		getListaArgumentos();
	ListaAtaques*			getListaAtaques();
	ListaAfirmacoes*		getListaAfirmacoes();
	ListaAtaqueGeometrico*	getListaAtaqueGeometrico();
	ListaArgumentoGeometrico* getListaArgumentoGeometrico();

	//inherited methods
	bool gravar();
	bool remover();
	Persistivel* carregar(int id);
	vector<Persistivel*> localizarCadastros();
	
	//Prototype* clone();

private:
	vector<Persistivel*> localizarCadastroPeloId(const int id);
	void definePersistidorNaConstrutora();
};
#endif