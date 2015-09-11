#include "AbsPersiste.h"

AbsPersiste::AbsPersiste(Persistivel* p)
{
	persistivel = p;
}

AbsPersiste::AbsPersiste()
{
	persistivel = nullptr;
}

AbsPersiste::~AbsPersiste()
{
}


void AbsPersiste::setPersistivel(Persistivel* p)
{
	persistivel = p;
}
Persistivel* AbsPersiste::getPersistivel()
{
	return persistivel;
}
