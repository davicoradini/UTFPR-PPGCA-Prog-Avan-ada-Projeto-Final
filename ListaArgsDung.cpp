#include "ListaArgsDung.h"


ListaArgsDung::ListaArgsDung()
{
}


ListaArgsDung::~ListaArgsDung()
{
}


void ListaArgsDung::incluir(Argumento* a)
{
	lista.push_back(a);
}
void ListaArgsDung::copiarArgsLista(ListaArgsDung* listaCopiar)
{
	for (vector<Argumento*>::iterator it = listaCopiar->getLista()->begin(); it != listaCopiar->getLista()->end(); it++)
	{
		lista.push_back( static_cast<Argumento*>(*it) );
	}
}
/*void ListaArgsDung::remover(Argumento* a)
{

}*/
void ListaArgsDung::limpar()
{
	lista.clear();
}
bool ListaArgsDung::isThere(Argumento* a)
{
	vector<Argumento*>::iterator it;
	it = lista.begin();

	while (it != lista.end())
	{
		if (a == *it) return true;

		it++;
	}

	return false;
}
Argumento* ListaArgsDung::getUltimoArgumento()
{
	vector<Argumento*> *listaArgs = &lista;
	vector<Argumento*>::iterator it = listaArgs->end();
	it--;
	return *it;
}