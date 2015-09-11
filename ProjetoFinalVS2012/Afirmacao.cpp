#include "Afirmacao.h"
#include "Sistema.h"

Afirmacao::Afirmacao()
{
	id = -1;
}

Afirmacao::~Afirmacao(){}


//setters
void Afirmacao::setId(const int i)
{
	id = i;
}
void Afirmacao::setNome(string n)
{
	nome = n;
}
void Afirmacao::setDescricao(string a)
{
	descricao = a;
}
void Afirmacao::setModerador(Moderador* m)
{
	moderador = m;
}
void Afirmacao::setParticipante(Participante* p)
{
	autor = p;
}
void Afirmacao::setClassificacao(Classificacao* c)
{
	classificacao = c;
}

//getters
const int Afirmacao::getId() const
{
	return id;
}
const string Afirmacao::getNome() const
{
	return nome;
}
const string Afirmacao::getDescricao() const
{
	return descricao;
}
Moderador* Afirmacao::getModerador() const
{
	return moderador;
}
Participante* Afirmacao::getParticipante() const
{
	return autor;
}
Classificacao* Afirmacao::getClassificacao() const
{
	return classificacao;
}

//inherited methods
bool Afirmacao::gravar()
{
	if ("" != getNome())
	{
		if (Sistema::getGravaTudoMemoriaRam())
		{
			return true;
		}
	}
	return false;
}

bool Afirmacao::remover()
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		return true;
	}
	return false;
}

Persistivel* Afirmacao::carregar(int id)
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		return new Afirmacao();
	}
	return false;
}

vector<Persistivel*> Afirmacao::localizarCadastros()
{
	vector<Persistivel*> vLista;
	
	if (Sistema::getGravaTudoMemoriaRam())
	{
		
	}
	return vLista;
}