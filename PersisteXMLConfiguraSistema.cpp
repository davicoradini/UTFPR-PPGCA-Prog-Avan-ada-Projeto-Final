#include "PersisteXMLConfiguraSistema.h"
#include "Sistema.h"
#include <direct.h>

typedef ConfiguraSistemaSingleton Persistivel_local;


PersisteXMLConfiguraSistema::PersisteXMLConfiguraSistema(Persistivel* p) : AbsPersisteXML(p)
{
	_mkdir("c:/sisargsavedfiles");
	strcpy_s(arquivo,	  "c:/sisargsavedfiles/ConfiguraSistema.xml");
}

PersisteXMLConfiguraSistema::PersisteXMLConfiguraSistema()
{
}

PersisteXMLConfiguraSistema::~PersisteXMLConfiguraSistema()
{
}


//inherited methods
const bool PersisteXMLConfiguraSistema::inserir()
{
	Persistivel_local *persistivel_local = static_cast<Persistivel_local*>(persistivel);
	
	remove(arquivo);
	ofstream stream(arquivo, ios::out);

	/*
	// ****************************************
	// Apenas para fins didáticos, meio sem tempo na vrdd
	// o correto seriam estes métods de salvar e recuperar a info. do arquivo estarem no classe AbsPersisteXML
	*/
	stream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";

	//grava Conf abertura da tela
	stream << "\n\t<conf_tela_inicial>\n\t\t";
	stream << persistivel_local->getConfAberturaSistemaParaXML();
	stream << "\n\t</conf_tela_inicial>";

	//grava Conf abertura da tela
	stream << "\n\t<conf_persistencia>\n\t\t";
	stream << persistivel_local->getConfPersistenciaParaXML();
	stream << "\n\t</conf_persistencia>";


	stream.close();

	return true;
}
const bool PersisteXMLConfiguraSistema::alterar()
{
	return true;
}
const bool PersisteXMLConfiguraSistema::remover()
{
	return false;
}
vector<Persistivel*> PersisteXMLConfiguraSistema::carregarCadastros(const int id)
{
	vector<Persistivel*> configuracoes;

	Persistivel_local *persistivel_local = static_cast<Persistivel_local*>(persistivel);

	ifstream stream(arquivo, ios::in);

	string line;
	string confTelaInicial = "0";
	string confPersistencia = "0";

	while (getline(stream,line))
	{
		/*
		// ****************************************
		// Apenas para fins didáticos, meio sem tempo na vrdd
		// o correto seriam estes métods de salvar e recuperar a info. do arquivo estarem no classe AbsPersisteXML
		*/
		//pesquisa configuração da abertura da tela
		 size_t found = line.find("<conf_tela_inicial>");
		 if (found!=std::string::npos)
		 {
			 getline(stream, confTelaInicial);
		 }

		 //pesquisa configuração da abertura da tela
		 size_t found2 = line.find("<conf_persistencia>");
		 if (found2!=std::string::npos)
		 {
			 getline(stream, confPersistencia);
		 }
	}
	stream.close();

	persistivel_local->setConfAberturaSistemaVindoDoXML(stoi(confTelaInicial));
	persistivel_local->setConfPersistenciaVindoDoXML(stoi(confPersistencia));

	configuracoes.push_back(persistivel_local);

	return configuracoes;
}
