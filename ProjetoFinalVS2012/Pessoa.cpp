#include "Pessoa.h"
#include "Sistema.h"

Pessoa::Pessoa() : Persistivel()
{
	id = -1;
	strcpy_s(nome, "");
	strcpy_s(cargo, "");
	instituicao = new Instituicao();

	definePersistidorNaConstrutora();
}

Pessoa::~Pessoa()
{
	delete persistidor;
}

void Pessoa::definePersistidorNaConstrutora()
{
	if (Sistema::getGravaTudoMemoriaRam())
	{
		persistidor = new PersisteMemoriaPessoa(this);
	}
	else
	{
		persistidor = new PersisteBinarioPessoa(this);
	}
}

//setters
void Pessoa::setNome(const char *n) {
	strcpy_s(nome, n);
}
void Pessoa::setCargo(const char *c) {
	strcpy_s(cargo, c);
}
void Pessoa::setInstituicao(Instituicao* i) {
	if (nullptr != instituicao && -1 == instituicao->getId()) delete instituicao;
	instituicao = i;
}

//getters
const char* Pessoa::getNome() const {
	return nome;
}
const char* Pessoa::getCargo() const {
	return cargo;
}
Instituicao* Pessoa::getInstituicao() const {
	return instituicao;
}


//inherited methods
bool Pessoa::gravar()
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

bool Pessoa::remover()
{
	bool resposta = persistidor->remover();
	return resposta;
}

Persistivel* Pessoa::carregar(int id)
{
	vector<Persistivel*> vLista = localizarCadastroPeloId(id);

	if (vLista.size() == 1)
	{
		return vLista.at(0);
	}

	return false;
}
vector<Persistivel*> Pessoa::localizarCadastros()
{
	return localizarCadastroPeloId(-1);
}
vector<Persistivel*> Pessoa::localizarCadastroPeloId(const int id)
{
	vector<Persistivel*> vLista = persistidor->carregarCadastros(id);
	
	return vLista;
}

Prototype*  Pessoa::clone()
{
	Pessoa *p = new Pessoa();
	p->setId(getId());
	p->setNome(getNome());
	p->setCargo(getCargo());
	p->setInstituicao(getInstituicao());

	return p;
}