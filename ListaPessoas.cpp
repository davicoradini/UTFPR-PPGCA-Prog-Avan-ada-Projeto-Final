#include "ListaPessoas.h"

typedef Pessoa Persistivel_local;

ListaPessoas::ListaPessoas() : AbsListaElementos(){}


ListaPessoas::~ListaPessoas(){}


void ListaPessoas::incluir(Persistivel *p)
{
	lista.incluir(p);
}

bool ListaPessoas::remover(Persistivel *p)
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

void ListaPessoas::limpar()
{
	lista.limpar();
}

Persistivel* ListaPessoas::getElementoPeloId(int id)
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

Lista<Persistivel*>* ListaPessoas::getLista()
{
	return &lista;
}