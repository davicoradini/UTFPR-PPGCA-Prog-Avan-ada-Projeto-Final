#include "ArgumentoGeometrico.h"
#include "Sistema.h"


ArgumentoGeometrico::ArgumentoGeometrico(const int i, Argumento *a, const int x, const int y, const int la, const int al)
{
	id = i;
	argumento = a;
	posX = x;
	posY = y;
	largura = la;
	altura = al;
}

ArgumentoGeometrico::ArgumentoGeometrico()
{
	id = -1;
	argumento = new Argumento();
	posX = -1;
	posY = -1;
	largura = -1;
	altura = -1;
}

ArgumentoGeometrico::~ArgumentoGeometrico(){}


void ArgumentoGeometrico::setPosX(const int x)
{
	posX = x;
}
void ArgumentoGeometrico::setPosY(const int y)
{
	posY = y;
}
void ArgumentoGeometrico::setLargura(const int l)
{
	largura = l;
}
void ArgumentoGeometrico::setAltura(const int a)
{
	altura = a;
}

const int ArgumentoGeometrico::getId()
{
	return id;
}
Argumento* ArgumentoGeometrico::getArgumento()
{
	return argumento;
}
const int ArgumentoGeometrico::getPosX()
{
	return posX;
}
const int ArgumentoGeometrico::getPosY()
{
	return posY;
}
const int ArgumentoGeometrico::getLargura()
{
	return largura;
}
const int ArgumentoGeometrico::getAltura()
{
	return altura;
}


//inherited methods
bool ArgumentoGeometrico::gravar()
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		return true;
	}
	return false;
}

bool ArgumentoGeometrico::remover()
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		return true;
	}
	return false;
}

Persistivel* ArgumentoGeometrico::carregar(int id)
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		return new ArgumentoGeometrico();
	}
	return false;
}

vector<Persistivel*> ArgumentoGeometrico::localizarCadastros()
{
	vector<Persistivel*> vLista;
	
	if (Sistema::getGravaTudoMemoriaRam())
	{
		
	}
	return vLista;
}