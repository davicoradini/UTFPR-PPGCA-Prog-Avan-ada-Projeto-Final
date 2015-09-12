#include "PersisteMemoriaArgumentacao.h"
#include "Sistema.h"

typedef Argumentacao Persistivel_local;

PersisteMemoriaArgumentacao::PersisteMemoriaArgumentacao(Persistivel* p) : AbsPersiste(p){}

PersisteMemoriaArgumentacao::PersisteMemoriaArgumentacao() : AbsPersiste(){}

PersisteMemoriaArgumentacao::~PersisteMemoriaArgumentacao(){}


//inherited methods
const bool PersisteMemoriaArgumentacao::inserir()
{
	//o primeiro passo é obter um ID para o objeto
	Persistivel_local* persistivel_local = static_cast<Persistivel_local*>(persistivel);
	
	persistivel_local->setId(Sistema::Identificadores::getNextIdArgumentacao());
	
	string cName = "Argumentação " + to_string( persistivel_local->getId() );
	persistivel_local->setNome(cName.c_str());

	//Persistivel_local* clone = static_cast<Persistivel_local*>( persistivel_local->clone() );

	Sistema::getListaArgumentacoes()->incluir(dynamic_cast<Persistivel*>(persistivel_local));

	return true;
}

const bool PersisteMemoriaArgumentacao::alterar()
{
	return true;
}

const bool PersisteMemoriaArgumentacao::remover()
{
	return Sistema::getListaArgumentacoes()->remover(dynamic_cast<Persistivel*>(persistivel));
}

vector<Persistivel*> PersisteMemoriaArgumentacao::carregarCadastros(const int id)
{
	vector<Persistivel*> vLista;

	Lista<Persistivel*>* lista = Sistema::getListaArgumentacoes()->getLista();

	if (lista->tamanho() > 0)
	{
		Persistivel_local* persistivel_local = new Persistivel_local();
		Lista<Persistivel*>::Iterator it;
		it = lista->begin();

		while(it != lista->end())
		{
			persistivel_local = static_cast<Persistivel_local*>( *it );

			if (id > 0 && persistivel_local->getId() == id)
			{
				vLista.push_back( static_cast<Persistivel*>(persistivel_local) );
				return vLista;
			}
			else if (id < 0)
			{
				vLista.push_back(persistivel_local);
			}
			it++;
		}
	}
	return vLista;
}
