#include "AbridoraDeTelasSingleton.h"

using namespace System;
using namespace System::Windows::Forms;

AbridoraDeTelasSingleton* AbridoraDeTelasSingleton::_INSTANCIA = nullptr;

AbridoraDeTelasSingleton::AbridoraDeTelasSingleton(){}

AbridoraDeTelasSingleton::~AbridoraDeTelasSingleton(){}

 AbridoraDeTelasSingleton* AbridoraDeTelasSingleton::getInstancia()
{
	if (nullptr == _INSTANCIA) _INSTANCIA = new AbridoraDeTelasSingleton();
	return _INSTANCIA;
}

void AbridoraDeTelasSingleton::abreTelaInicial()
{	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TelaPrincipal tela;
	Application::Run(%tela);
}

//Abertura das AbridoraDeTelasSingleton do sistema
Instituicao* AbridoraDeTelasSingleton::abreTelaInstituicao(Instituicao* p)
{
	TelaInstituicao ^form = gcnew TelaInstituicao();
	form->setPInstituicao(p);
	form->ShowDialog();

	p = form->getPInstituicao();
	delete form;

	return p;
}
Pessoa* AbridoraDeTelasSingleton::abreTelaPessoa(Pessoa* p)
{
	TelaPessoas ^form = gcnew TelaPessoas();
	form->setPPessoa(p);
	form->ShowDialog();

	p = form->getPPessoa();
	delete form;

	return p;
}
Classificacao* AbridoraDeTelasSingleton::abreTelaClassificacao(Classificacao* p)
{
	TelaClassificacao ^form = gcnew TelaClassificacao();
	form->setPClassificacao(p);
	form->ShowDialog();

	p = form->getPClassificacao();
	delete form;

	return p;
}
Conectivo* AbridoraDeTelasSingleton::abreTelaConectivo(Conectivo* p)
{
	TelaConectivo ^form = gcnew TelaConectivo();
	form->setPConectivo(p);
	form->ShowDialog();

	p = form->getPConectivo();
	delete form;

	return p;
}
Argumentacao* AbridoraDeTelasSingleton::abreTelaArgumentacao(Argumentacao* p)
{
	TelaArgumentacao ^form = gcnew TelaArgumentacao();
	form->setPArgumentacao(p);
	form->Visible = false;
	form->ShowDialog();

	p = form->getPArgumentacao();
	delete form;

	return p;
}
void AbridoraDeTelasSingleton::abreTelaConfiguracao()
{
	TelaConfiguracao ^form = gcnew TelaConfiguracao();

	form->Visible = false;
	form->ShowDialog();

	delete form;
}
void AbridoraDeTelasSingleton::abreTelaSobre()
{
	Sobre ^form = gcnew Sobre();

	form->Visible = false;
	form->ShowDialog();

	delete form;
}