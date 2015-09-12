#include "Sistema.h"
#include "AbridoraDeTelasSingleton.h"

bool Sistema::_INSTANCIADO = false;

ConfiguraSistemaSingleton*	Sistema::configuracaoSistema= ConfiguraSistemaSingleton::getInstancia();

void Sistema::iniciaSistema()
{
	if (!_INSTANCIADO)
	{
		_INSTANCIADO = true;
		Sistema();
	}
}

Sistema::Sistema()
{
	carregarCadastrosAbrirTelaPrincipal();
}


Sistema::~Sistema()
{
	listaPessoas.limpar();
	listaInstituicoes.limpar();
	listaClassificacoes.limpar();
	listaConectivos.limpar();
	listaArgumentacoes.limpar();
}

void Sistema::carregarCadastrosAbrirTelaPrincipal()
{
	registraConectivosPreCadastrados();

	configuracaoSistema= ConfiguraSistemaSingleton::getInstancia();
	configuracaoSistema = static_cast<ConfiguraSistemaSingleton*>( configuracaoSistema->carregar() );

	//Carrega tela principal do sistema
	AbridoraDeTelasSingleton *t = AbridoraDeTelasSingleton::getInstancia();
	t->abreTelaInicial();
}

//Inicializa as listas estáticas
ListaPessoas		Sistema::listaPessoas		 = ListaPessoas();
ListaInstituicoes	Sistema::listaInstituicoes	 = ListaInstituicoes();
ListaClassificacoes Sistema::listaClassificacoes = ListaClassificacoes();
ListaConectivos		Sistema::listaConectivos	 = ListaConectivos();
ListaArgumentacoes	Sistema::listaArgumentacoes	 = ListaArgumentacoes();


//Retornos
const bool			 Sistema::getGravaTudoMemoriaRam()
{ 
	if (configuracaoSistema->getConfPersistencia() == ConfiguraSistemaSingleton::MemoriaRam) return true;
	else return false;
}

ListaPessoas*		 Sistema::getListaPessoas()				{ return &listaPessoas; }
ListaInstituicoes*	 Sistema::getListaInstituicoes()		{ return &listaInstituicoes; }
ListaClassificacoes* Sistema::getListaClassificacoes()		{ return &listaClassificacoes; }
ListaConectivos*	 Sistema::getListaConectivos()			{ return &listaConectivos; }
ListaArgumentacoes*	 Sistema::getListaArgumentacoes()		{ return &listaArgumentacoes; }





/*
* Classe aninhada Identificadores
*/
//Inicialização dos códigos /identificadores
int Sistema::Identificadores::idArgumentacao	= 0;
int Sistema::Identificadores::idPessoa			= 0;
int Sistema::Identificadores::idInstituicao		= 0;
int Sistema::Identificadores::idClassificacao	= 0;
int Sistema::Identificadores::idConectivo		= 0;
int Sistema::Identificadores::idLetraArgumento	= 0;

//Retorna os códigos /identificadores incrementando o valor
const int Sistema::Identificadores::getNextIdArgumentacao() { return ++idArgumentacao; }
const int Sistema::Identificadores::getNextIdPessoa()		{ return ++idPessoa; }
const int Sistema::Identificadores::getNextIdInstituicao()  { return ++idInstituicao; }
const int Sistema::Identificadores::getNextIdClassificacao(){ return ++idClassificacao; }
const int Sistema::Identificadores::getNextIdConectivo()	{ return ++idConectivo; }

//Retorna os códigos /identificadores incrementando o valor
const int Sistema::Identificadores::getAtualIdArgumentacao()	{ return idArgumentacao; }
const int Sistema::Identificadores::getAtualIdPessoa()			{ return idPessoa; }
const int Sistema::Identificadores::getAtualIdInstituicao()		{ return idInstituicao; }
const int Sistema::Identificadores::getAtualIdClassificacao()	{ return idClassificacao; }
const int Sistema::Identificadores::getAtualIdConectivo()		{ return idConectivo; }



/*
* Classe aninhada AbreAbridoraDeTelasSingleton
*/
Instituicao*	Sistema::AbreTelas::abreTelaInstituicao(Instituicao* p)
{
	AbridoraDeTelasSingleton *t = AbridoraDeTelasSingleton::getInstancia();
	p = t->abreTelaInstituicao(p);
	return p;
}
Pessoa*	Sistema::AbreTelas::abreTelaPessoa(Pessoa* p)
{
	AbridoraDeTelasSingleton *t = AbridoraDeTelasSingleton::getInstancia();
	p = t->abreTelaPessoa(p);
	return p;
}
Classificacao*	Sistema::AbreTelas::abreTelaClassificacao(Classificacao* p)
{
	AbridoraDeTelasSingleton *t = AbridoraDeTelasSingleton::getInstancia();
	p = t->abreTelaClassificacao(p);
	return p;
}
Conectivo*	Sistema::AbreTelas::abreTelaConectivo(Conectivo* p)
{
	AbridoraDeTelasSingleton *t = AbridoraDeTelasSingleton::getInstancia();
	p = t->abreTelaConectivo(p);
	return p;
}
Argumentacao*	Sistema::AbreTelas::abreTelaArgumentacao(Argumentacao* p)
{
	AbridoraDeTelasSingleton *t = AbridoraDeTelasSingleton::getInstancia();
	p = t->abreTelaArgumentacao(p);
	return p;
}
void Sistema::AbreTelas::abreTelaConfiguracao()
{
	AbridoraDeTelasSingleton *t = AbridoraDeTelasSingleton::getInstancia();
	t->abreTelaConfiguracao();
}
void Sistema::AbreTelas::abreTelaSobre()
{
	AbridoraDeTelasSingleton *t = AbridoraDeTelasSingleton::getInstancia();
	t->abreTelaSobre();
}


//Verifica e/ou cadastra conectivos lógicos pré-cadastrados, necessário ao uso básico
void Sistema::registraConectivosPreCadastrados()
{
	Conectivo* c1 = new Conectivo(Sistema::Identificadores::getNextIdConectivo(), "Negação", L'¬', true);
	Conectivo* c2 = new Conectivo(Sistema::Identificadores::getNextIdConectivo(), "Conjunção", L'^', true);
	Conectivo* c3 = new Conectivo(Sistema::Identificadores::getNextIdConectivo(), "Disjunção Inclusiva", L'v', true);
	Conectivo* c4 = new Conectivo(Sistema::Identificadores::getNextIdConectivo(), "Disjunção Exclusiva", L'⊕', true);
	Conectivo* c5 = new Conectivo(Sistema::Identificadores::getNextIdConectivo(), "Condicional", L'→', true);
	Conectivo* c6 = new Conectivo(Sistema::Identificadores::getNextIdConectivo(), "Bicondicional", L'↔', true);

	Sistema::getListaConectivos()->incluir(c1);
	Sistema::getListaConectivos()->incluir(c2);
	Sistema::getListaConectivos()->incluir(c3);
	Sistema::getListaConectivos()->incluir(c4);
	Sistema::getListaConectivos()->incluir(c5);
	Sistema::getListaConectivos()->incluir(c6);
}