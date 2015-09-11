#include "ListaArgumentoGeometrico.h"


ListaArgumentoGeometrico::ListaArgumentoGeometrico(){}

ListaArgumentoGeometrico::~ListaArgumentoGeometrico(){}


void ListaArgumentoGeometrico::incluir(ArgumentoGeometrico *p)
{
	lista.push_back(p);
}

vector<ArgumentoGeometrico*>* ListaArgumentoGeometrico::getLista()
{
	return &lista;
}

bool ListaArgumentoGeometrico::remover(ArgumentoGeometrico *p)
{
	for (int i = 0; i < (int) lista.size(); i++)
	{
		if (lista.at(i) == p)
		{
			lista.erase(lista.begin() +i);
			return true;
		}
	}

	return false;
}

void ListaArgumentoGeometrico::limpar()
{
	lista.clear();
}

ArgumentoGeometrico* ListaArgumentoGeometrico::getElementoPeloId(int id)
{
	ArgumentoGeometrico* p = new ArgumentoGeometrico();
	for (int i = 0; i < (int) lista.size(); i++)
	{
		if (lista.at(i)->getId() == id) return lista.at(i);
	}
	return p;
}