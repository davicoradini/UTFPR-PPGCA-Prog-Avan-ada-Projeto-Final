#include "PersisteMemoriaPessoa.h"
#include "Sistema.h"

typedef Pessoa Persistivel_local;

PersisteMemoriaPessoa::PersisteMemoriaPessoa(Persistivel* p) : AbsPersiste(p){}

PersisteMemoriaPessoa::PersisteMemoriaPessoa() : AbsPersiste(){}

PersisteMemoriaPessoa::~PersisteMemoriaPessoa(){}


//inherited methods
const bool PersisteMemoriaPessoa::inserir()
{
	//o primeiro passo é obter um ID para o objeto
	Persistivel_local* persistivel_local = static_cast<Persistivel_local*>(persistivel);
	Persistivel_local* clone = static_cast<Persistivel_local*>( persistivel_local->clone() );

	clone->setId(Sistema::Identificadores::getNextIdPessoa());
	persistivel_local->setId(clone->getId());

	Sistema::getListaPessoas()->incluir(dynamic_cast<Persistivel*>(clone));

	return true;
}

const bool PersisteMemoriaPessoa::alterar()
{
	return true;
}

const bool PersisteMemoriaPessoa::remover()
{
	return Sistema::getListaPessoas()->remover(dynamic_cast<Persistivel*>(persistivel));
}

vector<Persistivel*> PersisteMemoriaPessoa::carregarCadastros(const int id)
{
	vector<Persistivel*> vLista;

	Lista<Persistivel*>* lista = Sistema::getListaPessoas()->getLista();

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
