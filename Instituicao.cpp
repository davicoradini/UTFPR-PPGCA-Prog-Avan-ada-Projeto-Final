#include "Instituicao.h"
#include "Sistema.h"

Instituicao::Instituicao() : Persistivel()
{
	id = -1;
	strcpy_s(nome, "");
	strcpy_s(sigla, "");
	strcpy_s(tipo, "");

	definePersistidorNaConstrutora();
}

Instituicao::~Instituicao()
{
	delete persistidor;
}

void Instituicao::definePersistidorNaConstrutora()
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		persistidor = new PersisteMemoriaInstituicao(this);
	}
	else
	{
		persistidor = new PersisteBinarioInstituicao(this);
	}
}

//setters
void Instituicao::setNome(const char * n)
{
	strcpy_s(nome, n);
}
void Instituicao::setSigla(const char * s)
{
	strcpy_s(sigla, s);
}
void Instituicao::setTipo(const char * t)
{
	strcpy_s(tipo, t);
}

//getters
const char * Instituicao::getNome() const
{
	return nome;
}
const char * Instituicao::getSigla() const
{
	return sigla;
}
const char * Instituicao::getTipo() const
{
	return tipo;
}

///inherited methods
bool Instituicao::gravar()
{
	//inserindo novo cadastro
	if (-1 == getId())
	{
		bool resposta = persistidor->inserir();
		return resposta;
	}

	//alterando cadastro
	else
	{
		bool resposta = persistidor->alterar();
		return resposta;
	}
	return false;
}

bool Instituicao::remover()
{
	bool resposta = persistidor->remover();
	return resposta;
}

Persistivel* Instituicao::carregar(int id)
{
	vector<Persistivel*> vLista = localizarCadastroPeloId(id);

	if (vLista.size() == 1)
	{
		return vLista.at(0);
	}

	return false;
}
vector<Persistivel*> Instituicao::localizarCadastros()
{
	return localizarCadastroPeloId(-1);
}
vector<Persistivel*> Instituicao::localizarCadastroPeloId(const int id)
{
	vector<Persistivel*> vLista = persistidor->carregarCadastros(id);
	
	return vLista;
}

Prototype*  Instituicao::clone()
{
	Instituicao *p = new Instituicao();
	p->setId(getId());
	p->setNome(getNome());
	p->setSigla(getSigla());
	p->setTipo(getTipo());

	return p;
}