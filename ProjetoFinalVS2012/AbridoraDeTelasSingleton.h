#ifndef _AbridoraDeTelasSingleton_H_
#define _AbridoraDeTelasSingleton_H_

#pragma once
#include "Instituicao.h"

#include "TelaPrincipal.h"
#include "TelaPessoas.h"
#include "TelaInstituicao.h"
#include "TelaClassificacao.h"
#include "TelaConectivo.h"
#include "TelaArgumentacao.h"
#include "TelaArgumento.h"
#include "TelaConfiguracao.h"
#include "Sobre.h"

using namespace MyViews;

class AbridoraDeTelasSingleton
{
private:
	AbridoraDeTelasSingleton();
	~AbridoraDeTelasSingleton();
	static AbridoraDeTelasSingleton* _INSTANCIA;

public:
	static AbridoraDeTelasSingleton* getInstancia();
	void abreTelaInicial();
	Instituicao*	abreTelaInstituicao		(Instituicao* p);
	Pessoa*			abreTelaPessoa			(Pessoa* p);
	Classificacao*	abreTelaClassificacao	(Classificacao* p);
	Conectivo*		abreTelaConectivo		(Conectivo* p);
	Argumentacao*	abreTelaArgumentacao	(Argumentacao* p);
	void			abreTelaConfiguracao	();
	void			abreTelaSobre			();
};
#endif