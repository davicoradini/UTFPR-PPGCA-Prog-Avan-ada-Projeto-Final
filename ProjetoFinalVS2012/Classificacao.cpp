#include "Classificacao.h"
#include "Sistema.h"
using namespace std;

Classificacao::Classificacao()
{
	id = -1;
	strcpy_s(nome, "");
	descricao = "";

	definePersistidorNaConstrutora();
}


Classificacao::~Classificacao()
{
	delete persistidor;
}

void Classificacao::definePersistidorNaConstrutora()
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		persistidor = new PersisteMemoriaClassificacao(this);
	}
	else
	{
		persistidor = new PersisteBinarioClassificacao(this);
	}
}

//setters
void Classificacao::setNome(const char * n)
{
	strcpy_s(nome, n);
}
void Classificacao::setDescricao(string s)
{
	descricao = s;
}

//getters
const char * Classificacao::getNome() const
{
	return nome;
}
const string Classificacao::getDescricao() const
{
	return descricao;
}

//inherited methods
bool Classificacao::gravar()
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

bool Classificacao::remover()
{
	bool resposta = persistidor->remover();
	return resposta;
}

Persistivel* Classificacao::carregar(int id)
{
	vector<Persistivel*> vLista = localizarCadastroPeloId(id);

	if (vLista.size() == 1)
	{
		return vLista.at(0);
	}

	return false;
}
vector<Persistivel*> Classificacao::localizarCadastros()
{
	return localizarCadastroPeloId(-1);
}
vector<Persistivel*> Classificacao::localizarCadastroPeloId(const int id)
{
	vector<Persistivel*> vLista = persistidor->carregarCadastros(id);
	
	return vLista;
}