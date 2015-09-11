#pragma once
#include "Sistema.h"
#include "Classificacao.h"
#include "ListaClassificacoes.h"

namespace MyViews {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for TelaClassificacao
	/// </summary>
	public ref class TelaClassificacao : public System::Windows::Forms::Form
	{
	public:
		TelaClassificacao(void)
		{
			InitializeComponent();
			inicializaAtributos();
			carregarCadastros();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TelaClassificacao()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblInfo;
	protected: 
	private: System::Windows::Forms::Button^  btnGravar;
	private: System::Windows::Forms::Button^  btnNovo;
	private: System::Windows::Forms::Button^  btnRemover;
	private: System::Windows::Forms::DataGridView^  dataGridClassificacoes;







	private: System::Windows::Forms::TextBox^  txtNome;
	private: System::Windows::Forms::TextBox^  txtCodigo;
	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txtLocalizar;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgwCodigo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgwNome;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgwDescricao;
	private: System::Windows::Forms::RichTextBox^  richDescricao;


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
			this->lblInfo = (gcnew System::Windows::Forms::Label());
			this->btnGravar = (gcnew System::Windows::Forms::Button());
			this->btnNovo = (gcnew System::Windows::Forms::Button());
			this->btnRemover = (gcnew System::Windows::Forms::Button());
			this->dataGridClassificacoes = (gcnew System::Windows::Forms::DataGridView());
			this->dgwCodigo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgwNome = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgwDescricao = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->txtNome = (gcnew System::Windows::Forms::TextBox());
			this->txtCodigo = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtLocalizar = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richDescricao = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridClassificacoes))->BeginInit();
			this->SuspendLayout();
			// 
			// lblInfo
			// 
			this->lblInfo->AutoSize = true;
			this->lblInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblInfo->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->lblInfo->Location = System::Drawing::Point(309, 214);
			this->lblInfo->Name = L"lblInfo";
			this->lblInfo->Size = System::Drawing::Size(113, 15);
			this->lblInfo->TabIndex = 46;
			this->lblInfo->Text = L"Cadastro removido!";
			this->lblInfo->Visible = false;
			// 
			// btnGravar
			// 
			this->btnGravar->Location = System::Drawing::Point(138, 209);
			this->btnGravar->Name = L"btnGravar";
			this->btnGravar->Size = System::Drawing::Size(75, 23);
			this->btnGravar->TabIndex = 42;
			this->btnGravar->Text = L"Gravar";
			this->btnGravar->UseVisualStyleBackColor = true;
			this->btnGravar->Click += gcnew System::EventHandler(this, &TelaClassificacao::btnGravar_Click);
			// 
			// btnNovo
			// 
			this->btnNovo->Location = System::Drawing::Point(16, 209);
			this->btnNovo->Name = L"btnNovo";
			this->btnNovo->Size = System::Drawing::Size(75, 23);
			this->btnNovo->TabIndex = 45;
			this->btnNovo->Text = L"Novo";
			this->btnNovo->UseVisualStyleBackColor = true;
			this->btnNovo->Click += gcnew System::EventHandler(this, &TelaClassificacao::btnNovo_Click);
			// 
			// btnRemover
			// 
			this->btnRemover->Enabled = false;
			this->btnRemover->Location = System::Drawing::Point(219, 209);
			this->btnRemover->Name = L"btnRemover";
			this->btnRemover->Size = System::Drawing::Size(75, 23);
			this->btnRemover->TabIndex = 44;
			this->btnRemover->Text = L"Remover";
			this->btnRemover->UseVisualStyleBackColor = true;
			this->btnRemover->Click += gcnew System::EventHandler(this, &TelaClassificacao::btnRemover_Click);
			// 
			// dataGridClassificacoes
			// 
			this->dataGridClassificacoes->AllowUserToOrderColumns = true;
			this->dataGridClassificacoes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridClassificacoes->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->dgwCodigo, 
				this->dgwNome, this->dgwDescricao});
			this->dataGridClassificacoes->Location = System::Drawing::Point(16, 244);
			this->dataGridClassificacoes->Name = L"dataGridClassificacoes";
			this->dataGridClassificacoes->Size = System::Drawing::Size(696, 204);
			this->dataGridClassificacoes->TabIndex = 45;
			this->dataGridClassificacoes->DoubleClick += gcnew System::EventHandler(this, &TelaClassificacao::dataGridClassificacoes_DoubleClick);
			// 
			// dgwCodigo
			// 
			this->dgwCodigo->HeaderText = L"Código";
			this->dgwCodigo->Name = L"dgwCodigo";
			this->dgwCodigo->ReadOnly = true;
			this->dgwCodigo->Width = 50;
			// 
			// dgwNome
			// 
			this->dgwNome->HeaderText = L"Nome";
			this->dgwNome->Name = L"dgwNome";
			this->dgwNome->Width = 200;
			// 
			// dgwDescricao
			// 
			this->dgwDescricao->HeaderText = L"Descrição";
			this->dgwDescricao->Name = L"dgwDescricao";
			this->dgwDescricao->Width = 400;
			// 
			// txtNome
			// 
			this->txtNome->Location = System::Drawing::Point(16, 127);
			this->txtNome->MaxLength = 200;
			this->txtNome->Name = L"txtNome";
			this->txtNome->Size = System::Drawing::Size(696, 20);
			this->txtNome->TabIndex = 39;
			// 
			// txtCodigo
			// 
			this->txtCodigo->Enabled = false;
			this->txtCodigo->Location = System::Drawing::Point(16, 76);
			this->txtCodigo->Name = L"txtCodigo";
			this->txtCodigo->Size = System::Drawing::Size(100, 20);
			this->txtCodigo->TabIndex = 38;
			this->txtCodigo->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 150);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 13);
			this->label5->TabIndex = 37;
			this->label5->Text = L"Descrição";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 35;
			this->label3->Text = L"Nome";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 34;
			this->label2->Text = L"Código";
			// 
			// txtLocalizar
			// 
			this->txtLocalizar->Location = System::Drawing::Point(16, 29);
			this->txtLocalizar->Name = L"txtLocalizar";
			this->txtLocalizar->Size = System::Drawing::Size(696, 20);
			this->txtLocalizar->TabIndex = 33;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 13);
			this->label1->TabIndex = 32;
			this->label1->Text = L"Localizar";
			// 
			// richDescricao
			// 
			this->richDescricao->Location = System::Drawing::Point(16, 166);
			this->richDescricao->Name = L"richDescricao";
			this->richDescricao->Size = System::Drawing::Size(696, 37);
			this->richDescricao->TabIndex = 40;
			this->richDescricao->Text = L"";
			// 
			// TelaClassificacao
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(724, 461);
			this->Controls->Add(this->richDescricao);
			this->Controls->Add(this->lblInfo);
			this->Controls->Add(this->btnGravar);
			this->Controls->Add(this->btnNovo);
			this->Controls->Add(this->btnRemover);
			this->Controls->Add(this->dataGridClassificacoes);
			this->Controls->Add(this->txtNome);
			this->Controls->Add(this->txtCodigo);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtLocalizar);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(740, 500);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(740, 500);
			this->Name = L"TelaClassificacao";
			this->Text = L"Cadastro de Classificacões";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridClassificacoes))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: Classificacao* pClassificacao;
private: void inicializaAtributos() {
	pClassificacao = new Classificacao();
}
public: System::Void setPClassificacao(Classificacao* p) { pClassificacao = p; }
public: Classificacao* getPClassificacao()				 { return pClassificacao; }

private: System::Void btnRemover_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (MessageBox::Show("Confirma remoção do cadastro?",
         "Confirmação", MessageBoxButtons::OKCancel,
         MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::OK)
    {
		int id = -1;
		try
		{
			id = int::Parse(txtCodigo->Text);
		}	catch(...) {}

		Classificacao *p = new Classificacao();
		if (id >= 0)
		{
			p = dynamic_cast<Classificacao*>(p->carregar(id));

			if (p->remover()) {
				for( int i = 0; i < dataGridClassificacoes->RowCount -1; i++)
				{
					if (dataGridClassificacoes->Rows[i]->Cells[0]->Value->ToString()->Equals(txtCodigo->Text))
						dataGridClassificacoes->Rows[i]->Visible = false;
				}

				btnRemover->Enabled = false;
				reiniciaForm();
				lblInfo->Text = "Cadastro removido!";
				lblInfo->Visible = true;
				lblInfo->ForeColor = System::Drawing::Color::CornflowerBlue;
			}
			else
			{
				lblInfo->Text = "Não foi possível remover!";
				lblInfo->Visible = true;
				lblInfo->ForeColor = System::Drawing::Color::Crimson;
			}
		}
	}
}
private: System::Void carregarCadastros()
{
	Classificacao* p = new Classificacao();
		
	vector<Persistivel*> lista = p->localizarCadastros();

	if (lista.size() > 0)
	{
		for (int i = 0; i < (int) lista.size(); i++)
		{
			p = dynamic_cast<Classificacao*>(lista.at(i));

			dataGridClassificacoes->Rows->Add(
				p->getId().ToString(),
				gcnew System::String( p->getNome() ),
				gcnew System::String( p->getDescricao().c_str() )
			);
		}
	}
}
private: System::Void btnGravar_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (txtNome->Text->Length > 0)
	{
		Classificacao *p = new Classificacao();
		if (txtCodigo->Text->Length > 0)
			p = dynamic_cast<Classificacao*>(p->carregar(int::Parse(txtCodigo->Text)));

		char* cNome  = (char*)(void*)Marshal::StringToHGlobalAnsi(txtNome->Text);
		string sDesc = (char*)(void*)Marshal::StringToHGlobalAnsi(richDescricao->Text);
		p->setNome(cNome);
		p->setDescricao(sDesc);

		bool gravouOk = p->gravar();
		pClassificacao = p;

		if (gravouOk && txtCodigo->Text->Length == 0)
		{
			txtCodigo->Text = p->getId().ToString();

			dataGridClassificacoes->Rows->Add(
				txtCodigo->Text,
				txtNome->Text, 
				richDescricao->Text
			);
			lblInfo->Text = "Inserido com Sucesso!";
			lblInfo->Visible = true;
			lblInfo->ForeColor = System::Drawing::Color::CornflowerBlue;
		}
		else if (gravouOk)
		{
			for( int i = 0; i < dataGridClassificacoes->RowCount -1; i++)
			{
				String ^s1 = dataGridClassificacoes->Rows[i]->Cells[0]->Value->ToString();
				String ^s2 = p->getId().ToString();
				if (s1->Equals(s2))
				{
					dataGridClassificacoes->Rows[i]->SetValues(
						txtCodigo->Text,
						txtNome->Text,
						richDescricao->Text
					);
				}
			}
			lblInfo->Text = "Alteração realizada!";
			lblInfo->Visible = true;
			lblInfo->ForeColor = System::Drawing::Color::CornflowerBlue;
		}
		if (gravouOk) reiniciaForm();
	}
}
private: System::Void btnNovo_Click(System::Object^  sender, System::EventArgs^  e)
{
	reiniciaForm();
	lblInfo->Visible = false;
	lblInfo->ForeColor = System::Drawing::Color::CornflowerBlue;
}
private: System::Void reiniciaForm()
{
	txtCodigo->Clear();
	txtNome->Clear();
	richDescricao->Clear();
	btnGravar->Enabled = true;
	btnRemover->Enabled = false;
	btnNovo->Enabled = true;
}
private: System::Void dataGridClassificacoes_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
	int id = -1;
	try
	{
		id = int::Parse(dataGridClassificacoes->CurrentRow->Cells[0]->Value->ToString());
	}	catch(...) {}

	Classificacao* p = new Classificacao();
	if (id >= 0)
	{
		pClassificacao = p;

		p = dynamic_cast<Classificacao*>(p->carregar(id));

		txtCodigo->Text = p->getId().ToString();
		txtNome->Text	= gcnew System::String( p->getNome() );
		richDescricao->AppendText( gcnew String(p->getDescricao().c_str()) );

		btnRemover->Enabled = true;
	}
}
};
}
