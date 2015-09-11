#include "Ataque.h"
#include "Sistema.h"

Ataque::Ataque()
{
	id = -1;
	pOrigem = new Argumento();
	pDestino = new Argumento();
}

Ataque::~Ataque(){}


//setters
void Ataque::setId(const int i)
{
	id = i;
}
void Ataque::setPOrigem(Argumento* o)
{
	pOrigem = o;
}
void Ataque::setPDestino(Argumento* d)
{
	pDestino = d;
}

//getters
const int Ataque::getId() const
{
	return id;
}
Argumento* Ataque::getPOrigem() const
{
	return pOrigem;
}
Argumento* Ataque::getPDestino() const
{
	return pDestino;
}

//inherited methods
bool Ataque::gravar()
{
	if (nullptr != pOrigem && nullptr != pDestino)
	{
		if (Sistema::getGravaTudoMemoriaRam())
		{
			return true;
		}
	}
	return false;
}

bool Ataque::remover()
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		return true;
	}
	return false;
}

Persistivel* Ataque::carregar(int id)
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		return new Ataque();
	}
	return false;
}

vector<Persistivel*> Ataque::localizarCadastros()
{
	vector<Persistivel*> vLista;
	
	if (Sistema::getGravaTudoMemoriaRam())
	{
		
	}
	return vLista;
}