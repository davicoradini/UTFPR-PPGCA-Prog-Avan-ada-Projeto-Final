#include "Conectivo.h"
#include "Sistema.h"
using namespace std;

//Utilizar este construtor apenas para pré-cadastro dos conectivos na classe Sistema
Conectivo::Conectivo(const int i, const char* n, wchar_t s, const bool p)
{
	id = i;
	strcpy_s(nome, n);
	simbolo = s;
	preCadastrado = p;
}
Conectivo::Conectivo()
{
	id = -1;
	preCadastrado = false;
}

Conectivo::~Conectivo(){}



//setters
void Conectivo::setId(const int i)
{
	id = i;
}
void Conectivo::setNome(const char * n)
{
	strcpy_s(nome, n);
}
void Conectivo::setSimbolo(wchar_t s)
{
	simbolo = s;
}
void Conectivo::setDescricao(string s)
{
	descricao = s;
}
void Conectivo::setPreCadastrado(const bool p)
{
	preCadastrado = p;
}

//getters
const int Conectivo::getId() const
{
	return id;
}
const char * Conectivo::getNome() const
{
	return nome;
}
const wchar_t Conectivo::getSimbolo() const
{
	return simbolo;
}
const string Conectivo::getDescricao() const
{
	return descricao;
}
const bool Conectivo::isPreCadastrado() const
{
	return preCadastrado;
}

//inherited methods
bool Conectivo::gravar()
{
	if (!this->isPreCadastrado())
	{
		if ("" != getNome() && !getSimbolo().Equals(""))
		{
			//inserindo novo cadastro
			if (-1 == getId())
			{
			
				if (Sistema::getGravaTudoMemoriaRam())
				{
					setId(Sistema::Identificadores::getNextIdConectivo());
					Sistema::getListaConectivos()->incluir(dynamic_cast<Persistivel*>(this));
					return true;
				}
			}

			//alterando cadastro
			else
			{
				if (Sistema::getGravaTudoMemoriaRam())
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool Conectivo::remover()
{
	if (!this->isPreCadastrado())
	{
		if (Sistema::getGravaTudoMemoriaRam())
		{
			return Sistema::getListaConectivos()->remover(dynamic_cast<Persistivel*>(this));
		}
	}
	return false;
}

Persistivel* Conectivo::carregar(int id)
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		return Sistema::getListaConectivos()->getElementoPeloId(id);
	}
	return false;
}

vector<Persistivel*> Conectivo::localizarCadastros()
{
	vector<Persistivel*> vLista;
	
	if (Sistema::getGravaTudoMemoriaRam())
	{
		Lista<Persistivel*>* lista = Sistema::getListaConectivos()->getLista();
		if (lista->tamanho() > 0)
		{
			Persistivel* p = new Conectivo();
			Lista<Persistivel*>::Iterator it;
			it = lista->begin();

			while(it != lista->end())
			{
				p = *it;
				vLista.push_back(p);
				it++;
			}
		}
	}
	return vLista;
}