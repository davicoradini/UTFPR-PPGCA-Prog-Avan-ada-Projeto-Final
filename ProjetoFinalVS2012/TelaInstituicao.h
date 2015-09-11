#pragma once
#include "Sistema.h"
#include "Instituicao.h"
#include "ListaInstituicoes.h"

namespace MyViews {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for TelaInstituicao
	/// </summary>
	public ref class TelaInstituicao : public System::Windows::Forms::Form
	{
	public:
		TelaInstituicao(void)
		{
			InitializeComponent();
			inicializaAtributos();
			carregarCadastros();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TelaInstituicao()
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
	private: System::Windows::Forms::DataGridView^  dataGridInstituicoes;


	private: System::Windows::Forms::ComboBox^  combTipo;

	private: System::Windows::Forms::TextBox^  txtSigla;

	private: System::Windows::Forms::TextBox^  txtNome;
	private: System::Windows::Forms::TextBox^  txtCodigo;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txtLocalizar;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgwCodigo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgwNome;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgwSigla;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgwInstituicao;





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
			this->dataGridInstituicoes = (gcnew System::Windows::Forms::DataGridView());
			this->combTipo = (gcnew System::Windows::Forms::ComboBox());
			this->txtSigla = (gcnew System::Windows::Forms::TextBox());
			this->txtNome = (gcnew System::Windows::Forms::TextBox());
			this->txtCodigo = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtLocalizar = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dgwCodigo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgwNome = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgwSigla = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgwInstituicao = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridInstituicoes))->BeginInit();
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
			this->lblInfo->TabIndex = 31;
			this->lblInfo->Text = L"Cadastro removido!";
			this->lblInfo->Visible = false;
			// 
			// btnGravar
			// 
			this->btnGravar->Location = System::Drawing::Point(138, 209);
			this->btnGravar->Name = L"btnGravar";
			this->btnGravar->Size = System::Drawing::Size(75, 23);
			this->btnGravar->TabIndex = 27;
			this->btnGravar->Text = L"Gravar";
			this->btnGravar->UseVisualStyleBackColor = true;
			this->btnGravar->Click += gcnew System::EventHandler(this, &TelaInstituicao::btnGravar_Click);
			// 
			// btnNovo
			// 
			this->btnNovo->Location = System::Drawing::Point(16, 209);
			this->btnNovo->Name = L"btnNovo";
			this->btnNovo->Size = System::Drawing::Size(75, 23);
			this->btnNovo->TabIndex = 28;
			this->btnNovo->Text = L"Novo";
			this->btnNovo->UseVisualStyleBackColor = true;
			this->btnNovo->Click += gcnew System::EventHandler(this, &TelaInstituicao::btnNovo_Click);
			// 
			// btnRemover
			// 
			this->btnRemover->Enabled = false;
			this->btnRemover->Location = System::Drawing::Point(219, 209);
			this->btnRemover->Name = L"btnRemover";
			this->btnRemover->Size = System::Drawing::Size(75, 23);
			this->btnRemover->TabIndex = 29;
			this->btnRemover->Text = L"Remover";
			this->btnRemover->UseVisualStyleBackColor = true;
			this->btnRemover->Click += gcnew System::EventHandler(this, &TelaInstituicao::btnRemover_Click);
			// 
			// dataGridInstituicoes
			// 
			this->dataGridInstituicoes->AllowUserToOrderColumns = true;
			this->dataGridInstituicoes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridInstituicoes->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->dgwCodigo, 
				this->dgwNome, this->dgwSigla, this->dgwInstituicao});
			this->dataGridInstituicoes->Location = System::Drawing::Point(16, 244);
			this->dataGridInstituicoes->Name = L"dataGridInstituicoes";
			this->dataGridInstituicoes->Size = System::Drawing::Size(696, 204);
			this->dataGridInstituicoes->TabIndex = 30;
			this->dataGridInstituicoes->DoubleClick += gcnew System::EventHandler(this, &TelaInstituicao::dataGridInstituicoes_DoubleClick);
			// 
			// combTipo
			// 
			this->combTipo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->combTipo->FormattingEnabled = true;
			this->combTipo->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"Instituição de Ensino", L"Empresa Publica", L"Empresa Privada", 
				L"Organização", L"Entidade", L"Outros"});
			this->combTipo->Location = System::Drawing::Point(16, 177);
			this->combTipo->Name = L"combTipo";
			this->combTipo->Size = System::Drawing::Size(454, 21);
			this->combTipo->TabIndex = 25;
			// 
			// txtSigla
			// 
			this->txtSigla->Location = System::Drawing::Point(489, 127);
			this->txtSigla->MaxLength = 100;
			this->txtSigla->Name = L"txtSigla";
			this->txtSigla->Size = System::Drawing::Size(223, 20);
			this->txtSigla->TabIndex = 24;
			// 
			// txtNome
			// 
			this->txtNome->Location = System::Drawing::Point(16, 127);
			this->txtNome->MaxLength = 200;
			this->txtNome->Name = L"txtNome";
			this->txtNome->Size = System::Drawing::Size(454, 20);
			this->txtNome->TabIndex = 23;
			// 
			// txtCodigo
			// 
			this->txtCodigo->Enabled = false;
			this->txtCodigo->Location = System::Drawing::Point(16, 76);
			this->txtCodigo->Name = L"txtCodigo";
			this->txtCodigo->Size = System::Drawing::Size(100, 20);
			this->txtCodigo->TabIndex = 22;
			this->txtCodigo->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 161);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(28, 13);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Tipo";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(486, 110);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Sigla";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Nome";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Código";
			// 
			// txtLocalizar
			// 
			this->txtLocalizar->Location = System::Drawing::Point(16, 29);
			this->txtLocalizar->Name = L"txtLocalizar";
			this->txtLocalizar->Size = System::Drawing::Size(696, 20);
			this->txtLocalizar->TabIndex = 17;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 13);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Localizar";
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
			this->dgwNome->Width = 250;
			// 
			// dgwSigla
			// 
			this->dgwSigla->HeaderText = L"Sigla";
			this->dgwSigla->Name = L"dgwSigla";
			this->dgwSigla->Width = 180;
			// 
			// dgwInstituicao
			// 
			this->dgwInstituicao->HeaderText = L"Instituição";
			this->dgwInstituicao->Name = L"dgwInstituicao";
			this->dgwInstituicao->ReadOnly = true;
			this->dgwInstituicao->Width = 172;
			// 
			// TelaInstituicao
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(724, 461);
			this->Controls->Add(this->lblInfo);
			this->Controls->Add(this->btnGravar);
			this->Controls->Add(this->btnNovo);
			this->Controls->Add(this->btnRemover);
			this->Controls->Add(this->dataGridInstituicoes);
			this->Controls->Add(this->combTipo);
			this->Controls->Add(this->txtSigla);
			this->Controls->Add(this->txtNome);
			this->Controls->Add(this->txtCodigo);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtLocalizar);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(740, 500);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(740, 500);
			this->Name = L"TelaInstituicao";
			this->Text = L"Cadastro de Instituição";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridInstituicoes))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: Instituicao* pInstituicao;
private: void inicializaAtributos() {
	//pInstituicao = new Instituicao();
}
public: System::Void setPInstituicao(Instituicao* p) { pInstituicao = p; }
public: Instituicao* getPInstituicao()				 { return pInstituicao; }

private: System::Void reiniciaForm()
{
	txtCodigo->Clear();
	txtNome->Clear();
	txtSigla->Clear();
	combTipo->Text = "";
	btnGravar->Enabled = true;
	btnRemover->Enabled = false;
	btnNovo->Enabled = true;
}
private: System::Void btnNovo_Click(System::Object^  sender, System::EventArgs^  e)
{
	reiniciaForm();
	lblInfo->Visible = false;
	lblInfo->ForeColor = System::Drawing::Color::CornflowerBlue;
}

private: System::Void btnGravar_Click(System::Object^  sender, System::EventArgs^  e)
{
	Instituicao instituicao = Instituicao();
	bool newInstituicao = false;

	if (txtNome->Text->Length > 0 || txtSigla->Text->Length > 0)
	{
		if (txtCodigo->Text->Length > 0)
		{
			pInstituicao = dynamic_cast<Instituicao*>(instituicao.carregar(int::Parse(txtCodigo->Text)));
		}
		else
		{
			pInstituicao = new Instituicao();
			newInstituicao = true;
		}

		char* cNome  = (char*)(void*)Marshal::StringToHGlobalAnsi(txtNome->Text);
		char* cSigla = (char*)(void*)Marshal::StringToHGlobalAnsi(txtSigla->Text);
		char* cTipo  = (char*)(void*)Marshal::StringToHGlobalAnsi(combTipo->Text);
		pInstituicao->setNome(cNome);
		pInstituicao->setSigla(cSigla);
		pInstituicao->setTipo(cTipo);

		bool gravouOk = pInstituicao->gravar();
		//pInstituicao = instituicao;

		if (gravouOk && txtCodigo->Text->Length == 0)
		{
			txtCodigo->Text = pInstituicao->getId().ToString();

			dataGridInstituicoes->Rows->Add(
				txtCodigo->Text,
				txtNome->Text, 
				txtSigla->Text,
				combTipo->Text
			);
			lblInfo->Text = "Inserido com Sucesso!";
			lblInfo->Visible = true;
			lblInfo->ForeColor = System::Drawing::Color::CornflowerBlue;
		}
		else if (gravouOk)
		{
			for( int i = 0; i < dataGridInstituicoes->RowCount -1; i++)
			{
				String ^s1 = dataGridInstituicoes->Rows[i]->Cells[0]->Value->ToString();
				String ^s2 = pInstituicao->getId().ToString();
				if (s1->Equals(s2))
				{
					dataGridInstituicoes->Rows[i]->SetValues(
						txtCodigo->Text,
						txtNome->Text,
						txtSigla->Text,
						combTipo->Text
					);
				}
			}
			lblInfo->Text = "Alteração realizada!";
			lblInfo->Visible = true;
			lblInfo->ForeColor = System::Drawing::Color::CornflowerBlue;
		}

		if (newInstituicao) delete pInstituicao;
		carregarCadastroEmTela( int::Parse(txtCodigo->Text) );
	}
}
private: System::Void carregarCadastros()
{
	Instituicao instituicao = Instituicao();
		
	vector<Persistivel*> lista = instituicao.localizarCadastros();

	if (lista.size() > 0)
	{
		Instituicao* p;
		
		for (int i = 0; i < (int) lista.size(); i++)
		{
			p = dynamic_cast<Instituicao*>(lista.at(i));

			dataGridInstituicoes->Rows->Add(
				p->getId().ToString(),
				gcnew System::String( p->getNome() ),
				gcnew System::String( p->getSigla() ),
				gcnew System::String( p->getTipo() )
			);
		}
	}
	pInstituicao = nullptr;
	lista.clear();
}

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

		if (id >= 0)
		{
			Instituicao instituicao = Instituicao();
			pInstituicao = dynamic_cast<Instituicao*>( instituicao.carregar(id) );
			if (pInstituicao->remover()) {
				for( int i = 0; i < dataGridInstituicoes->RowCount -1; i++)
				{
					if (dataGridInstituicoes->Rows[i]->Cells[0]->Value->ToString()->Equals(txtCodigo->Text))
						dataGridInstituicoes->Rows[i]->Visible = false;
				}

				btnRemover->Enabled = false;
				reiniciaForm();
				lblInfo->Text = "Cadastro removido!";
				lblInfo->Visible = true;
				lblInfo->ForeColor = System::Drawing::Color::CornflowerBlue;

				//delete pInstituicao;
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
private: System::Void dataGridInstituicoes_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
	int id = -1;
	try
	{
		id = int::Parse(dataGridInstituicoes->CurrentRow->Cells[0]->Value->ToString());
	}	catch(...) {}

	Instituicao* p = new Instituicao();
	if (id >= 0)
	{
		carregarCadastroEmTela(id);
	}
}
private: System::Void carregarCadastroEmTela(const int idInstituicao)
{
	Instituicao instituicao = Instituicao();
	pInstituicao = dynamic_cast<Instituicao*>( instituicao.carregar(idInstituicao) );

	txtCodigo->Text = pInstituicao->getId().ToString();
	txtNome->Text	= gcnew System::String( pInstituicao->getNome() );
	txtSigla->Text	= gcnew System::String( pInstituicao->getSigla() );
	combTipo->Text  = gcnew System::String( pInstituicao->getTipo() );
	btnRemover->Enabled = true;
}
};
}
