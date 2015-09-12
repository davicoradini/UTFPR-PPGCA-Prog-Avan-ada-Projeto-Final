#include "Argumento.h"
#include "Sistema.h"


Argumento::Argumento()
{
	id = -1;
	strcpy_s(nome, "");
	descricao = "";
	apoio = "";
	conclusao = "";
	moderador = new Moderador();
	autor = new Participante();
	classificacao = new Classificacao();
}

Argumento::~Argumento(){}


//setters
void Argumento::setIdArgumentacao(const int i){
	idArgumentacao = i;
}
void Argumento::setId(const int i)
{
	id = i;
}
void Argumento::setNome(const char *n)
{
	strcpy_s(nome, n);
}
void Argumento::setDescricao(string d)
{
	descricao = d;
}
void Argumento::setApoio(string a)
{
	apoio = a;
}
void Argumento::setConclusao(string c)
{
	conclusao = c;
}
void Argumento::setModerador(Moderador* m)
{
	moderador = m;
}
void Argumento::setParticipante(Participante* p)
{
	autor = p;
}
void Argumento::setClassificacao(Classificacao* c)
{
	classificacao = c;
}

//getters
const int Argumento::getId() const
{
	return id;
}
const char* Argumento::getNome() const
{
	return nome;
}
const string Argumento::getDescricao() const
{
	return descricao;
}
const string Argumento::getApoio() const
{
	return apoio;
}
const string Argumento::getConclusao() const
{
	return conclusao;
}
Moderador* Argumento::getModerador() const
{
	return moderador;
}
Participante* Argumento::getParticipante() const
{
	return autor;
}
Classificacao* Argumento::getClassificacao() const
{
	return classificacao;
}

//inherited methods
bool Argumento::gravar()
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

bool Argumento::remover()
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		return true;
	}
	return false;
}

Persistivel* Argumento::carregar(int id)
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		return new Argumento();
	}
	return false;
}

vector<Persistivel*> Argumento::localizarCadastros()
{
	vector<Persistivel*> vLista;
	
	if (Sistema::getGravaTudoMemoriaRam())
	{
		
	}
	return vLista;
}