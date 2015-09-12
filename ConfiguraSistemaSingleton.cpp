#include "ConfiguraSistemaSingleton.h"

ConfiguraSistemaSingleton* ConfiguraSistemaSingleton::_INSTANCIA = nullptr;

ConfiguraSistemaSingleton::ConfiguraSistemaSingleton()
{
	persistidor = new PersisteXMLConfiguraSistema(this);

	confAberturaSistema = CONF_ABERTURA_SISTEMA::Normal;
}

ConfiguraSistemaSingleton::~ConfiguraSistemaSingleton()
{
}

ConfiguraSistemaSingleton* ConfiguraSistemaSingleton::getInstancia()
{
	if (nullptr == _INSTANCIA) _INSTANCIA = new ConfiguraSistemaSingleton();
	return _INSTANCIA;
}

//getters and setters
void ConfiguraSistemaSingleton::setConfAberturaSistema(CONF_ABERTURA_SISTEMA conf)
{
	confAberturaSistema = conf;
}
void ConfiguraSistemaSingleton::setConfAberturaSistemaVindoDoXML(int conf)
{
	switch (conf)
	{
	case 0:	 confAberturaSistema = ConfiguraSistemaSingleton::Normal;
		break;
	case 1:	 confAberturaSistema = ConfiguraSistemaSingleton::Maximizado;
		break;
	case 2:	 confAberturaSistema = ConfiguraSistemaSingleton::NovaArg;
		break;
	case 3:	 confAberturaSistema = ConfiguraSistemaSingleton::AbreUltimaArg;
		break;
	default: confAberturaSistema = ConfiguraSistemaSingleton::Normal;
		break;
	}
}
const int ConfiguraSistemaSingleton::getConfAberturaSistemaParaXML()
{
	int conf;

	switch (confAberturaSistema)
	{
	case ConfiguraSistemaSingleton::Normal:			conf = 0;
		break;
	case ConfiguraSistemaSingleton::Maximizado:		conf = 1;
		break;
	case ConfiguraSistemaSingleton::NovaArg:		conf = 2;
		break;
	case ConfiguraSistemaSingleton::AbreUltimaArg:	conf = 3;
		break;
	default:								conf = 0;
		break;
	}

	return conf;
}
ConfiguraSistemaSingleton::CONF_ABERTURA_SISTEMA ConfiguraSistemaSingleton::getConfAberturaSistema()
{
	return confAberturaSistema;
}

void ConfiguraSistemaSingleton::setConfPersistencia(CONF_PERSISTENCIA conf)
{
	confPersistencia = conf;
}
void ConfiguraSistemaSingleton::setConfPersistenciaVindoDoXML(int conf)
{
	switch (conf)
	{
	case 0:	 confPersistencia = ConfiguraSistemaSingleton::MemoriaRam;
		break;
	case 1:	 confPersistencia = ConfiguraSistemaSingleton::Binario;
		break;
	default: confPersistencia = ConfiguraSistemaSingleton::MemoriaRam;
		break;
	}
}
const int ConfiguraSistemaSingleton::getConfPersistenciaParaXML()
{
	int conf;

	switch (confPersistencia)
	{
	case ConfiguraSistemaSingleton::MemoriaRam:			conf = 0;
		break;
	case ConfiguraSistemaSingleton::Binario:			conf = 1;
		break;
	default:											conf = 0;
		break;
	}

	return conf;
}
ConfiguraSistemaSingleton::CONF_PERSISTENCIA ConfiguraSistemaSingleton::getConfPersistencia()
{
	return confPersistencia;
}

//inherited methods
bool ConfiguraSistemaSingleton::gravar()
{
	return persistidor->inserir();
}
bool ConfiguraSistemaSingleton::remover()
{
	return false;
}
Persistivel* ConfiguraSistemaSingleton::carregar(int id)
{
	vector<Persistivel*> vLista = localizarCadastros();

	if (vLista.size() == 1)
	{
		return vLista.at(0);
	}

	return false;
}
vector<Persistivel*> ConfiguraSistemaSingleton::localizarCadastros()
{
	vector<Persistivel*> vLista = persistidor->carregarCadastros(id);
	
	return vLista;
}