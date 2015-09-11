#ifndef _PERSISTEXMLCONFIGURASISTEMA_H_
#define _PERSISTEXMLCONFIGURASISTEMA_H_

#pragma once
#include "stdafx.h"
#include "AbsPersisteXML.h"

#pragma once
class PersisteXMLConfiguraSistema : public AbsPersisteXML
{
public:
	PersisteXMLConfiguraSistema(Persistivel* p);
	PersisteXMLConfiguraSistema();
	~PersisteXMLConfiguraSistema();

	//inherited methods
	const bool inserir();
	const bool alterar();
	const bool remover();
	vector<Persistivel*> carregarCadastros(const int id);
};
#endif