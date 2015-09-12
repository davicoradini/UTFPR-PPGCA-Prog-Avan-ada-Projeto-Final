#pragma once

#include "Argumento.h"
#include "Classificacao.h"
#include "Moderador.h"
#include "Participante.h"

#include "Sistema.h"

#include "ListaClassificacoes.h"
#include "ListaModeradores.h"
#include "ListaParticipantes.h"

#include <vector>

namespace MyViews {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;

	/// <summary>
	/// Summary for TelaArgumento
	/// </summary>
	public ref class TelaArgumento : public System::Windows::Forms::Form
	{
	public:
		TelaArgumento(void)
		{
			InitializeComponent();
			inicializaAtributos();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TelaArgumento()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ComboBox^  combClassificacao;

	private: System::Windows::Forms::RichTextBox^  rtDescricao;

	private: System::Windows::Forms::TextBox^  txtCodigo;
	private: System::Windows::Forms::TextBox^  txtNome;
	private: System::Windows::Forms::ComboBox^  combModeradores;
	private: System::Windows::Forms::ComboBox^  combParticipantes;
	private: System::Windows::Forms::Button^  btnSalvar;
	private: System::Windows::Forms::Button^  btnDesfazer;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->combClassificacao = (gcnew System::Windows::Forms::ComboBox());
			this->rtDescricao = (gcnew System::Windows::Forms::RichTextBox());
			this->txtCodigo = (gcnew System::Windows::Forms::TextBox());
			this->txtNome = (gcnew System::Windows::Forms::TextBox());
			this->combModeradores = (gcnew System::Windows::Forms::ComboBox());
			this->combParticipantes = (gcnew System::Windows::Forms::ComboBox());
			this->btnSalvar = (gcnew System::Windows::Forms::Button());
			this->btnDesfazer = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Código";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(139, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nome";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(14, 57);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Descrição";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(14, 128);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Classificação";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(181, 128);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(58, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Moderador";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(14, 179);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(63, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Participante";
			// 
			// combClassificacao
			// 
			this->combClassificacao->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->combClassificacao->FormattingEnabled = true;
			this->combClassificacao->Location = System::Drawing::Point(17, 144);
			this->combClassificacao->Name = L"combClassificacao";
			this->combClassificacao->Size = System::Drawing::Size(147, 21);
			this->combClassificacao->TabIndex = 23;
			// 
			// rtDescricao
			// 
			this->rtDescricao->Location = System::Drawing::Point(17, 73);
			this->rtDescricao->Name = L"rtDescricao";
			this->rtDescricao->Size = System::Drawing::Size(305, 39);
			this->rtDescricao->TabIndex = 22;
			this->rtDescricao->Text = L"";
			// 
			// txtCodigo
			// 
			this->txtCodigo->Enabled = false;
			this->txtCodigo->Location = System::Drawing::Point(17, 29);
			this->txtCodigo->Name = L"txtCodigo";
			this->txtCodigo->Size = System::Drawing::Size(93, 20);
			this->txtCodigo->TabIndex = 20;
			// 
			// txtNome
			// 
			this->txtNome->Location = System::Drawing::Point(142, 29);
			this->txtNome->Name = L"txtNome";
			this->txtNome->Size = System::Drawing::Size(180, 20);
			this->txtNome->TabIndex = 21;
			// 
			// combModeradores
			// 
			this->combModeradores->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->combModeradores->FormattingEnabled = true;
			this->combModeradores->Location = System::Drawing::Point(184, 144);
			this->combModeradores->Name = L"combModeradores";
			this->combModeradores->Size = System::Drawing::Size(138, 21);
			this->combModeradores->TabIndex = 24;
			// 
			// combParticipantes
			// 
			this->combParticipantes->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->combParticipantes->FormattingEnabled = true;
			this->combParticipantes->Location = System::Drawing::Point(17, 195);
			this->combParticipantes->Name = L"combParticipantes";
			this->combParticipantes->Size = System::Drawing::Size(138, 21);
			this->combParticipantes->TabIndex = 25;
			// 
			// btnSalvar
			// 
			this->btnSalvar->Location = System::Drawing::Point(184, 196);
			this->btnSalvar->Name = L"btnSalvar";
			this->btnSalvar->Size = System::Drawing::Size(55, 23);
			this->btnSalvar->TabIndex = 26;
			this->btnSalvar->Text = L"Salvar";
			this->btnSalvar->UseVisualStyleBackColor = true;
			this->btnSalvar->Click += gcnew System::EventHandler(this, &TelaArgumento::btnSalvar_Click);
			// 
			// btnDesfazer
			// 
			this->btnDesfazer->Location = System::Drawing::Point(245, 196);
			this->btnDesfazer->Name = L"btnDesfazer";
			this->btnDesfazer->Size = System::Drawing::Size(75, 23);
			this->btnDesfazer->TabIndex = 27;
			this->btnDesfazer->Text = L"Desfazer";
			this->btnDesfazer->UseVisualStyleBackColor = true;
			this->btnDesfazer->Click += gcnew System::EventHandler(this, &TelaArgumento::btnDesfazer_Click);
			// 
			// TelaArgumento
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(334, 231);
			this->Controls->Add(this->btnDesfazer);
			this->Controls->Add(this->btnSalvar);
			this->Controls->Add(this->combParticipantes);
			this->Controls->Add(this->combModeradores);
			this->Controls->Add(this->txtNome);
			this->Controls->Add(this->txtCodigo);
			this->Controls->Add(this->combClassificacao);
			this->Controls->Add(this->rtDescricao);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(350, 270);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(350, 270);
			this->Name = L"TelaArgumento";
			this->Text = L"Argumento";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: Argumento*	pArgumento;
private: ListaModeradores *listaModeradores;
private: ListaParticipantes *listaParticipantes;
private: vector<int>* idsClassificacoes;
private: vector<int>* idsModeradores;
private: vector<int>* idsParticipantes;

public: System::Void setListaModeradores(ListaModeradores *l)	  { listaModeradores = l;   }
public: System::Void setListaParticipantes(ListaParticipantes *l) { listaParticipantes = l; }
		
private: void inicializaAtributos()
{
	if (nullptr == pArgumento) pArgumento = new Argumento();

	idsClassificacoes	= new vector<int>;
	idsModeradores		= new vector<int>;
	idsParticipantes	= new vector<int>;
	
	listaModeradores = new ListaModeradores();
	listaParticipantes = new ListaParticipantes();
}
public: System::Void setPArgumento(Argumento* p)
{
	pArgumento = p;

	carregarCadastros();

	txtCodigo->Text = pArgumento->getId().ToString();
	txtNome->Text	= gcnew System::String( pArgumento->getNome() );
	rtDescricao->Text	= gcnew System::String( pArgumento->getDescricao().c_str() );

	for (int i = 0; i < (int) idsClassificacoes->size(); i++)
	{
		if (idsClassificacoes->at(i) == pArgumento->getClassificacao()->getId())
		{
			combClassificacao->SelectedIndex = i;
			break;
		}
		else combClassificacao->SelectedIndex = 0;
	}
	
	for (int i = 0; i < (int) idsModeradores->size(); i++)
	{
		if (idsModeradores->at(i) == pArgumento->getModerador()->getId())
		{
			combModeradores->SelectedIndex = i;
			break;
		}
		else combModeradores->SelectedIndex = 0;
	}
	
	for (int i = 0; i < (int) idsParticipantes->size(); i++)
	{
		if (idsParticipantes->at(i) == pArgumento->getParticipante()->getId())
		{
			combParticipantes->SelectedIndex = i;
			break;
		}
		else combParticipantes->SelectedIndex = 0;
	}
}

public: Argumento* getPArgumento()
{
	return pArgumento;
}

private: System::Void carregarCadastros()
{
	carregarCadastrosClassificacoes();
	carregarCadastrosModeradores();
	carregarCadastrosParticipantes();
}

private: System::Void carregarCadastrosClassificacoes()
{
	combClassificacao->Items->Clear();
	idsClassificacoes->clear();

	combClassificacao->Items->Add("");
	idsClassificacoes->push_back(-1);

	Classificacao* p = new Classificacao();
		
	vector<Persistivel*> lista = p->localizarCadastros();

	if (lista.size() > 0)
	{
		for (int i = 0; i < (int) lista.size(); i++)
		{
			p = dynamic_cast<Classificacao*>(lista.at(i));

			combClassificacao->Items->Add(gcnew System::String( p->getNome()));
			
			idsClassificacoes->push_back(p->getId());
		}
	}
}
private: System::Void carregarCadastrosModeradores()
{
	combModeradores->Items->Clear();
	idsModeradores->clear();

	combModeradores->Items->Add("");
	idsModeradores->push_back(-1);

	Pessoa* p;

	if (Sistema::getGravaTudoMemoriaRam())
	{
		Lista<Persistivel*>* lista = listaModeradores->getLista();
		if (lista->tamanho() > 0)
		{
			Lista<Persistivel*>::Iterator it;
			it = lista->begin();

			while(it != lista->end())
			{
				p = dynamic_cast<Pessoa*>(*it);

				combModeradores->Items->Add(gcnew System::String( p->getNome()));
			
				idsModeradores->push_back(p->getId());
				it++;
			}
		}
	}
}
private: System::Void carregarCadastrosParticipantes()
{
	combParticipantes->Items->Clear();
	idsParticipantes->clear();

	combParticipantes->Items->Add("");
	idsParticipantes->push_back(-1);

	Pessoa* p;

	if (Sistema::getGravaTudoMemoriaRam())
	{
		Lista<Persistivel*>* lista = listaParticipantes->getLista();
		if (lista->tamanho() > 0)
		{
			Lista<Persistivel*>::Iterator it;
			it = lista->begin();

			while(it != lista->end())
			{
				p = dynamic_cast<Pessoa*>(*it);

				combParticipantes->Items->Add(gcnew System::String( p->getNome()));
			
				idsParticipantes->push_back(p->getId());
				it++;
			}
		}
	}
}
private: System::Void btnSalvar_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (txtCodigo->Text->Length >> 0 && txtNome->Text->Length > 0)
	{
		char* cNome = (char*)(void*)Marshal::StringToHGlobalAnsi(txtNome->Text);
		char* cDescricao = (char*)(void*)Marshal::StringToHGlobalAnsi(rtDescricao->Text);
		pArgumento->setNome(cNome);
		pArgumento->setDescricao(cDescricao);
		
		//seta classificação
		Classificacao *classificacao = pArgumento->getClassificacao();
		int combClassIndex = combClassificacao->SelectedIndex;
		if (combClassIndex > 0)
		{
			int idClass = idsClassificacoes->at(combClassIndex);
			classificacao = static_cast<Classificacao*>(classificacao->carregar(idClass));
		}
		pArgumento->setClassificacao(classificacao);
		
		//seta moderador
		Moderador *moderador = new Moderador();
		int combModIndex = combModeradores->SelectedIndex;
		if (combModIndex > 0)
		{
			int idMod = idsModeradores->at(combModIndex);
			moderador = static_cast<Moderador*>( listaModeradores->getElementoPeloId(idMod) );
		}
		pArgumento->setModerador(moderador);
		
		//seta participante
		Participante *participante = new Participante();
		int combParIndex = combParticipantes->SelectedIndex;
		if (combParIndex > 0)
		{
			int idPar = idsParticipantes->at(combParIndex);
			participante = static_cast<Participante*>( listaParticipantes->getElementoPeloId(idPar) );
		}
		pArgumento->setParticipante(participante);


		pArgumento->gravar();

		this->Close();
	}
}
private: System::Void btnDesfazer_Click(System::Object^  sender, System::EventArgs^  e) 
{
	this->Close();
}
};
}
