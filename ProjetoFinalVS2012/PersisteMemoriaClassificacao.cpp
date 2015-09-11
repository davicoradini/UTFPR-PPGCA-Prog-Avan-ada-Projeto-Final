#include "PersisteMemoriaClassificacao.h"
#include "Sistema.h"

typedef Classificacao Persistivel_local;

PersisteMemoriaClassificacao::PersisteMemoriaClassificacao(Persistivel* p) : AbsPersiste(p){}

PersisteMemoriaClassificacao::PersisteMemoriaClassificacao() : AbsPersiste(){}

PersisteMemoriaClassificacao::~PersisteMemoriaClassificacao(){}


//inherited methods
const bool PersisteMemoriaClassificacao::inserir()
{
	//o primeiro passo é obter um ID para o objeto
	Persistivel_local *persistivel_local = static_cast<Persistivel_local*>(persistivel);
	persistivel_local->setId(Sistema::Identificadores::getNextIdClassificacao());

	Sistema::getListaClassificacoes()->incluir(dynamic_cast<Persistivel*>(persistivel_local));

	return true;
}

const bool PersisteMemoriaClassificacao::alterar()
{
	return true;
}

const bool PersisteMemoriaClassificacao::remover()
{
	return Sistema::getListaClassificacoes()->remover(dynamic_cast<Persistivel*>(this));
}

vector<Persistivel*> PersisteMemoriaClassificacao::carregarCadastros(const int id)
{
	vector<Persistivel*> vLista;

	Lista<Persistivel*>* lista = Sistema::getListaClassificacoes()->getLista();

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
			else
			{
				vLista.push_back(persistivel_local);
				it++;
			}
		}
	}
	return vLista;
}
