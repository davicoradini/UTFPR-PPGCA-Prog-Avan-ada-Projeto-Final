#include "ListaInstituicoes.h"

typedef Instituicao Persistivel_local;

ListaInstituicoes::ListaInstituicoes() : AbsListaElementos(){}


ListaInstituicoes::~ListaInstituicoes(){}


void ListaInstituicoes::incluir(Persistivel *p)
{
	lista.incluir(p);
}

bool ListaInstituicoes::remover(Persistivel *p)
{
	Persistivel_local* persistivel_local;
	Lista<Persistivel*>::Iterator it;
	it = lista.begin();
	int contIndex = 0;

	while(it != lista.end())
	{
		persistivel_local = dynamic_cast<Persistivel_local*>(*it);
		if (persistivel_local->getId() == dynamic_cast<Persistivel_local*>(p)->getId())
		{
			lista.remover(contIndex);
			return true;
		}
		contIndex++;
		it ++;
	}
	return false;
}

void ListaInstituicoes::limpar()
{
	lista.limpar();
}

Persistivel* ListaInstituicoes::getElementoPeloId(int id)
{
	Persistivel_local* persistivel_local = new Persistivel_local();
	Lista<Persistivel*>::Iterator it;
	it = lista.begin();

	while(it != lista.end())
	{
		persistivel_local = dynamic_cast<Persistivel_local*>(*it);
		if (persistivel_local->getId() == id) return *it;
		it ++;
	}
	return persistivel_local;
}

Lista<Persistivel*>* ListaInstituicoes::getLista()
{
	return &lista;
}