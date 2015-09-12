#include "ListaAfirmacoes.h"

typedef Afirmacao Persistivel_local;

ListaAfirmacoes::ListaAfirmacoes(){}

ListaAfirmacoes::~ListaAfirmacoes(){}


void ListaAfirmacoes::incluir(Persistivel *p)
{
	lista.incluir(p);
}

bool ListaAfirmacoes::remover(Persistivel *p)
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

void ListaAfirmacoes::limpar()
{
	lista.limpar();
}

Persistivel* ListaAfirmacoes::getElementoPeloId(int id)
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

Lista<Persistivel*>* ListaAfirmacoes::getLista()
{
	return &lista;
}