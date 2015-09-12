#include "ListaConectivos.h"

typedef Conectivo Persistivel_local;

ListaConectivos::ListaConectivos(){}

ListaConectivos::~ListaConectivos(){}



void ListaConectivos::incluir(Persistivel *p)
{
	lista.incluir(p);
}

bool ListaConectivos::remover(Persistivel *p)
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

void ListaConectivos::limpar()
{
	lista.limpar();
}

Persistivel* ListaConectivos::getElementoPeloId(int id)
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

Lista<Persistivel*>* ListaConectivos::getLista()
{
	return &lista;
}