#include "AbsPersisteBinario.h"

AbsPersisteBinario::AbsPersisteBinario(Persistivel* p) : AbsPersiste(p)
{
}

AbsPersisteBinario::AbsPersisteBinario() : AbsPersiste()
{
}

AbsPersisteBinario::~AbsPersisteBinario()
{
	for (vector<Persistivel*>::iterator it = cadastrosLocalizados.begin(); it != cadastrosLocalizados.end(); ++it)
	{
		delete *it;
	}
}
