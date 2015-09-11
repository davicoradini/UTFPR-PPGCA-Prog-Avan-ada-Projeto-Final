#include "PersisteMemoriaInstituicao.h"
#include "Sistema.h"

typedef Instituicao Persistivel_local;

PersisteMemoriaInstituicao::PersisteMemoriaInstituicao(Persistivel* p) : AbsPersiste(p){}

PersisteMemoriaInstituicao::PersisteMemoriaInstituicao() : AbsPersiste(){}

PersisteMemoriaInstituicao::~PersisteMemoriaInstituicao(){}


//inherited methods
const bool PersisteMemoriaInstituicao::inserir()
{
	//o primeiro passo é obter um ID para o objeto
	Persistivel_local *persistivel_local = static_cast<Persistivel_local*>(persistivel);
	Persistivel_local* clone = static_cast<Persistivel_local*>( persistivel_local->clone() );

	clone->setId(Sistema::Identificadores::getNextIdInstituicao());
	persistivel_local->setId(clone->getId());

	Sistema::getListaInstituicoes()->incluir(dynamic_cast<Persistivel*>(clone));

	return true;
}

const bool PersisteMemoriaInstituicao::alterar()
{
	return true;
}

const bool PersisteMemoriaInstituicao::remover()
{
	bool resultado = Sistema::getListaInstituicoes()->remover(dynamic_cast<Persistivel*>(persistivel));
	delete persistivel;
	return resultado;
}

vector<Persistivel*> PersisteMemoriaInstituicao::carregarCadastros(const int id)
{
	vector<Persistivel*> vLista;

	Lista<Persistivel*>* lista = Sistema::getListaInstituicoes()->getLista();

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
