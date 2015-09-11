#include "Argumentacao.h"
#include "Sistema.h"
using namespace std;

Argumentacao::Argumentacao()
{
	id = -1;
	strcpy_s(nome, "");
	//strcpy_s(modeloArgumentacao, "ABS");
	//baseConhecimento		= L'';
	//exibeTelaCompleta		= false;
	idLetraArgumento		= 0;
	idArgumento				= 0;
	idAtaque				= 0;
	listaParticipantes		= ListaParticipantes();
	listaModeradores		= ListaModeradores();
	listaArgumentos			= ListaArgumentos();
	listaAtaques			= ListaAtaques();
	listaAfirmacoes			= ListaAfirmacoes();
	listaAtaqueGeometrico	= ListaAtaqueGeometrico();
	listaArgumentoGeometrico = ListaArgumentoGeometrico();

	definePersistidorNaConstrutora();
}

Argumentacao::~Argumentacao(){}

void Argumentacao::definePersistidorNaConstrutora()
{
	persistidor = new PersisteMemoriaArgumentacao(this);

	//nao implementado persistencia em binário
	/*if (Sistema::getGravaTudoMemoriaRam())
	{
		persistidor = new PersisteMemoriaArgumentac'ao(this);
	}
	else
	{
		persistidor = new PersisteBinarioArgumentacao(this);
	}*/
}

//setters
void Argumentacao::setId(const int i)
{
	id = i;
	idArgumentacao = i;
}
void Argumentacao::setNome(const char * n)
{
	strcpy_s(nome, n);
}
/*void Argumentacao::setBaseConhecimento(wchar_t s)
{
	baseConhecimento = s;
}
void Argumentacao::setModeloArgumentacao(const char* m)
{
	strcpy_s(modeloArgumentacao, m);
}
void Argumentacao::setExibeTelaCompleta(const bool e)
{
	exibeTelaCompleta = e;
}*/


//getters
const int Argumentacao::getId() const
{
	return id;
}
const char * Argumentacao::getNome() const
{
	return nome;
}
/*const wchar_t Argumentacao::getBaseConhecimento() const
{
	return baseConhecimento;
}
const char* Argumentacao::getModeloArgumentacao() const
{
	return modeloArgumentacao;
}
const bool Argumentacao::isExibeTelaCompleta() const
{
	return exibeTelaCompleta;
}*/
const string Argumentacao::getNextLetraArgumento()
{
	string letras[27] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","x","w","y","z"};
	int idLetra = idLetraArgumento++;
	
	return letras[idLetra];
}
const int Argumentacao::getNextIdArgumento()
{
	return ++idArgumento;
}
const int Argumentacao::getNextIdAtaque()
{
	return ++idAtaque;
}

ListaParticipantes*	Argumentacao::getListaParticipantes()
{
	return &listaParticipantes;
}
ListaModeradores*	Argumentacao::getListaModeradores()
{
	return &listaModeradores;
}
ListaArgumentos*	Argumentacao::getListaArgumentos()
{
	return &listaArgumentos;
}
ListaAtaques*		Argumentacao::getListaAtaques()
{
	return &listaAtaques;
}
ListaAfirmacoes*	Argumentacao::getListaAfirmacoes()
{
	return &listaAfirmacoes;
}
ListaAtaqueGeometrico* Argumentacao::getListaAtaqueGeometrico()
{
	return &listaAtaqueGeometrico;
}
ListaArgumentoGeometrico* Argumentacao::getListaArgumentoGeometrico()
{
	return & listaArgumentoGeometrico;
}


//inherited methods
bool Argumentacao::gravar()
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

bool Argumentacao::remover()
{
	bool resposta = persistidor->remover();
	return resposta;
}

Persistivel* Argumentacao::carregar(int id)
{
	vector<Persistivel*> vLista = localizarCadastroPeloId(id);

	if (vLista.size() == 1)
	{
		return vLista.at(0);
	}

	return false;
}
vector<Persistivel*> Argumentacao::localizarCadastros()
{
	return localizarCadastroPeloId(-1);
}
vector<Persistivel*> Argumentacao::localizarCadastroPeloId(const int id)
{
	vector<Persistivel*> vLista = persistidor->carregarCadastros(id);
	
	return vLista;
}

/*Prototype*  Argumentacao::clone()
{
	Argumentacao *p = new Argumentacao();
	p->setId(getId());
	p->setNome(getNome());
	p->setIdArgumentacao(getIdArgumentacao());
	
	p->idLetraArgumento = idLetraArgumento;
	p->idArgumento		= idArgumento;
	p->idAtaque			= idAtaque;
	p->persistidor		= persistidor;

	p->listaParticipantes = listaParticipantes;
	p->listaModeradores = listaModeradores;
	p->listaArgumentos = listaArgumentos;
	p->listaAtaques = listaAtaques;
	p->listaAfirmacoes = listaAfirmacoes;
	p->listaAtaqueGeometrico = listaAtaqueGeometrico;
	p->listaArgumentoGeometrico = listaArgumentoGeometrico;

	return p;
}*/