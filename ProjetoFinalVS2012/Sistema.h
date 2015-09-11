#ifndef _SISTEMA_H_
#define _SISTEMA_H_

#pragma once
#include "stdafx.h"

#include "ListaPessoas.h"
#include "ListaInstituicoes.h"
#include "ListaClassificacoes.h"
#include "ListaConectivos.h"
#include "ListaArgumentacoes.h"

#include "ConfiguraSistemaSingleton.h"

class Sistema
{
private:
	static ListaPessoas			listaPessoas;
	static ListaInstituicoes	listaInstituicoes;
	static ListaClassificacoes	listaClassificacoes;
	static ListaConectivos		listaConectivos;
	static ListaArgumentacoes	listaArgumentacoes;
	
	Sistema();
	~Sistema();
	static bool _INSTANCIADO;

public:
	static void iniciaSistema();

	static const bool			getGravaTudoMemoriaRam();
	static ListaPessoas*		getListaPessoas();
	static ListaInstituicoes*	getListaInstituicoes();
	static ListaClassificacoes*	getListaClassificacoes();
	static ListaConectivos*		getListaConectivos();
	static ListaArgumentacoes*	getListaArgumentacoes();

	//configurações do sistema
	static ConfiguraSistemaSingleton* configuracaoSistema;


private:
	void carregarCadastrosAbrirTelaPrincipal();
	void registraConectivosPreCadastrados();





//Classe aninhada responsável por retornar os códigos /identificadores
public:
	class Identificadores
	{
	private:
		static int idArgumentacao;
		static int idPessoa;
		static int idInstituicao;
		static int idClassificacao;
		static int idConectivo;
		static int idLetraArgumento;
		
	public:
		//incrementa e retorna códigos /identificadores
		static const int getNextIdArgumentacao();
		static const int getNextIdPessoa();
		static const int getNextIdInstituicao();
		static const int getNextIdClassificacao();
		static const int getNextIdConectivo();

		//retorna códigos /identificadores
		static const int getAtualIdArgumentacao();
		static const int getAtualIdPessoa();
		static const int getAtualIdInstituicao();
		static const int getAtualIdClassificacao();
		static const int getAtualIdConectivo();
	};


//Classe aninhada responsável pela abertura das telas do sistema
public:
	class AbreTelas
	{
	public:
		static Instituicao*				abreTelaInstituicao		(Instituicao* p);
		static Pessoa*					abreTelaPessoa			(Pessoa* p);
		static Classificacao*			abreTelaClassificacao	(Classificacao* p);
		static Conectivo*				abreTelaConectivo		(Conectivo* p);
		static Argumentacao*			abreTelaArgumentacao	(Argumentacao* p);
		static void						abreTelaConfiguracao	();
		static void						abreTelaSobre			();
	};
};
#endif