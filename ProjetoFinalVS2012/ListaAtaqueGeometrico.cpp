#include "ListaAtaqueGeometrico.h"


ListaAtaqueGeometrico::ListaAtaqueGeometrico(){}

ListaAtaqueGeometrico::~ListaAtaqueGeometrico(){}


void ListaAtaqueGeometrico::incluir(AtaqueGeometrico *p)
{
	lista.push_back(p);
}

vector<AtaqueGeometrico*>* ListaAtaqueGeometrico::getLista()
{
	return &lista;
}

bool ListaAtaqueGeometrico::remover(AtaqueGeometrico *p)
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

void ListaAtaqueGeometrico::limpar()
{
	lista.clear();
}

AtaqueGeometrico* ListaAtaqueGeometrico::getElementoPeloId(int id)
{
	AtaqueGeometrico* p = new AtaqueGeometrico();
	for (int i = 0; i < (int) lista.size(); i++)
	{
		if (lista.at(i)->getId() == id) return lista.at(i);
	}
	return p;
}
const int ListaAtaqueGeometrico::getIdPeloArgumento(int idArgumento)
{
	int idAtaque = -1;
	AtaqueGeometrico* p = new AtaqueGeometrico();
	for (int i = 0; i < (int) lista.size(); i++)
	{
		if (lista.at(i)->getArgOrigem()->getId() == idArgumento ||lista.at(i)->getArgDestino()->getId() == idArgumento)
			return lista.at(i)->getId();
	}
	return idAtaque;
}