#include "AtaqueGeometrico.h"
#include "Sistema.h"

AtaqueGeometrico::AtaqueGeometrico(const int i, Argumento *o, Argumento *d, const int iniX, const int iniY, const int fimX, const int fimY)
{
	id = i;
	argOrigem = o;
	argDestino = d;
	xInicial = iniX;
	yInicial = iniY;
	xFinal = fimX;
	yFinal = fimY;
}

AtaqueGeometrico::AtaqueGeometrico()
{
	id = -1;
	argOrigem = nullptr;
	argDestino = nullptr;
	xInicial = -1;
	yInicial = -1;
	xFinal = -1;
	yFinal = -1;
}

AtaqueGeometrico::~AtaqueGeometrico(){}


const int AtaqueGeometrico::getId()
{
	return id;
}
Argumento* AtaqueGeometrico::getArgOrigem()
{
	return argOrigem;
}
Argumento* AtaqueGeometrico::getArgDestino()
{
	return argDestino;
}
const int AtaqueGeometrico::getXInicial()
{
	return xInicial;
	//return (xInicial < xFinal) ? xInicial + 50 : xInicial - 50;
}
const int AtaqueGeometrico::getYInicial()
{
	return yInicial;
	//return (yInicial < yFinal) ? yInicial + 14 : yInicial - 14;
}
const int AtaqueGeometrico::getXFinal()
{
	return xFinal;
	//return (xInicial < xFinal) ? xFinal - 50 : xInicial + 50;
}
const int AtaqueGeometrico::getYFinal()
{
	//return yFinal;
	return (yInicial < yFinal) ? yFinal - 11 : yFinal + 11;
}

//inherited methods
bool AtaqueGeometrico::gravar()
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		return true;
	}
	return false;
}

bool AtaqueGeometrico::remover()
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		return true;
	}
	return false;
}

Persistivel* AtaqueGeometrico::carregar(int id)
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		return new AtaqueGeometrico();
	}
	return false;
}

vector<Persistivel*> AtaqueGeometrico::localizarCadastros()
{
	vector<Persistivel*> vLista;
	
	if (Sistema::getGravaTudoMemoriaRam())
	{
		
	}
	return vLista;
}
