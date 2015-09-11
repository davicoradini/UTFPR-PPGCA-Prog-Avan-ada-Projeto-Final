#ifndef _CONFIGURASISTEMASINGLETON_H_
#define _CONFIGURASISTEMASINGLETON_H_

#pragma once
#include "Persistivel.h"
#include "PersisteXMLConfiguraSistema.h"

#include <string>
#include <vector>
using namespace std;

#pragma once
class ConfiguraSistemaSingleton : public Persistivel
{
public:
	enum CONF_ABERTURA_SISTEMA
	{
		Normal, Maximizado, NovaArg, AbreUltimaArg
	};
	enum CONF_PERSISTENCIA
	{
		MemoriaRam, Binario
	};

private:
	CONF_ABERTURA_SISTEMA	confAberturaSistema;
	CONF_PERSISTENCIA		confPersistencia;


	AbsPersiste *persistidor;

	static ConfiguraSistemaSingleton* _INSTANCIA;

	ConfiguraSistemaSingleton();
	~ConfiguraSistemaSingleton();

public:
	static ConfiguraSistemaSingleton* getInstancia();

	void setConfAberturaSistema(CONF_ABERTURA_SISTEMA conf);
	void setConfAberturaSistemaVindoDoXML(int conf);
	const int getConfAberturaSistemaParaXML();
	CONF_ABERTURA_SISTEMA getConfAberturaSistema();
	
	void setConfPersistencia(CONF_PERSISTENCIA conf);
	void setConfPersistenciaVindoDoXML(int conf);
	const int getConfPersistenciaParaXML();
	CONF_PERSISTENCIA getConfPersistencia();
	
	//inherited methods
	bool gravar();
	bool remover();
	Persistivel* carregar(int id = 0);
	vector<Persistivel*> localizarCadastros();

};
#endif