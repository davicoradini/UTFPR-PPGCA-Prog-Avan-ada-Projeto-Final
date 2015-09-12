#include "ListaArgumentos.h"

typedef Argumento Persistivel_local;

ListaArgumentos::ListaArgumentos(){}

ListaArgumentos::~ListaArgumentos(){}


void ListaArgumentos::incluir(Persistivel *p)
{
	lista.incluir(p);
}

bool ListaArgumentos::remover(Persistivel *p)
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

void ListaArgumentos::limpar()
{
	lista.limpar();
}

Persistivel* ListaArgumentos::getElementoPeloId(int id)
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

Lista<Persistivel*>* ListaArgumentos::getLista()
{
	return &lista;
}