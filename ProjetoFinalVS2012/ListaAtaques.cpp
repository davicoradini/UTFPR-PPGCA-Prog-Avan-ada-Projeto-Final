#include "ListaAtaques.h"

typedef Ataque Persistivel_local;

ListaAtaques::ListaAtaques(){}

ListaAtaques::~ListaAtaques(){}


void ListaAtaques::incluir(Persistivel *p)
{
	lista.incluir(p);
}

bool ListaAtaques::remover(Persistivel *p)
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

void ListaAtaques::limpar()
{
	lista.limpar();
}

Persistivel* ListaAtaques::getElementoPeloId(int id)
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

Lista<Persistivel*>* ListaAtaques::getLista()
{
	return &lista;
}

bool ListaAtaques::ataqueExiste(Argumento* origem, Argumento* destino)
{
	Persistivel_local* persistivel_local;
	Lista<Persistivel*>::Iterator it;
	it = lista.begin();

	while(it != lista.end())
	{
		persistivel_local = dynamic_cast<Persistivel_local*>(*it);
		if (persistivel_local->getPOrigem() == origem && destino == persistivel_local->getPDestino()) return true;
		it ++;
	}
	return false;
}