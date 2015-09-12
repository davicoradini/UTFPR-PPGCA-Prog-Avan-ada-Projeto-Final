#include "ListaArgumentacoes.h"

typedef Argumentacao Persistivel_local;

ListaArgumentacoes::ListaArgumentacoes(){}

ListaArgumentacoes::~ListaArgumentacoes(){}


void ListaArgumentacoes::incluir(Persistivel *p)
{
	lista.incluir(p);
}

bool ListaArgumentacoes::remover(Persistivel *p)
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

void ListaArgumentacoes::limpar()
{
	lista.limpar();
}

Persistivel* ListaArgumentacoes::getElementoPeloId(int id)
{
	Persistivel_local* persistivel_local;
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

Lista<Persistivel*>* ListaArgumentacoes::getLista()
{
	return &lista;
}