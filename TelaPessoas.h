#pragma once
#include <vector>
#include "Sistema.h"
#include "Pessoa.h"

namespace MyViews {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MyViews;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for TelaPessoas
	/// </summary>
	public ref class TelaPessoas : public System::Windows::Forms::Form
	{
	public:
		TelaPessoas(void)
		{
			InitializeComponent();
			inicializaAtributos();
			carregarCadastros();
			carregarCadastrosInstituicoes();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TelaPessoas()
		{
			if (components)
			{
				delete components;
				idsInstituicoes->clear();
				delete idsInstituicoes;
				//delete pPessoa;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtLocalizar;
	protected:

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txtCodigo;
	private: System::Windows::Forms::TextBox^  txtNome;
	private: System::Windows::Forms::TextBox^  txtCargo;
	private: System::Windows::Forms::ComboBox^  combInstituicao;




	private: System::Windows::Forms::Button^  btnNovaInstituicao;
	private: System::Windows::Forms::DataGridView^  dataGridPessoas;






	private: System::Windows::Forms::Button^  btnNovo;
	private: System::Windows::Forms::Button^  btnGravar;
	private: System::Windows::Forms::Button^  btnRemover;




	private: System::Windows::Forms::Label^  lblInfo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgwCodigo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgwNome;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dgwCargo;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtLocalizar = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtCodigo = (gcnew System::Windows::Forms::TextBox());
			this->txtNome = (gcnew System::Windows::Forms::TextBox());
			this->txtCargo = (gcnew System::Windows::Forms::TextBox());
			this->combInstituicao = (gcnew System::Windows::Forms::ComboBox());
			this->btnNovaInstituicao = (gcnew System::Windows::Forms::Button());
			this->dataGridPessoas = (gcnew System::Windows::Forms::DataGridView());
			this->dgwCodigo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgwNome = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgwCargo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgwInstituicao = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnNovo = (gcnew System::Windows::Forms::Button());
			this->btnGravar = (gcnew System::Windows::Forms::Button());
			this->btnRemover = (gcnew System::Windows::Forms::Button());
			this->lblInfo = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridPessoas))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Localizar";
			// 
			// txtLocalizar
			// 
			this->txtLocalizar->Location = System::Drawing::Point(16, 30);
			this->txtLocalizar->Name = L"txtLocalizar";
			this->txtLocalizar->Size = System::Drawing::Size(696, 20);
			this->txtLocalizar->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Código";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 111);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Nome";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(486, 111);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Cargo";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 162);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Instituição";
			// 
			// txtCodigo
			// 
			this->txtCodigo->Enabled = false;
			this->txtCodigo->Location = System::Drawing::Point(16, 77);
			this->txtCodigo->Name = L"txtCodigo";
			this->txtCodigo->Size = System::Drawing::Size(100, 20);
			this->txtCodigo->TabIndex = 6;
			this->txtCodigo->TabStop = false;
			// 
			// txtNome
			// 
			this->txtNome->Location = System::Drawing::Point(16, 128);
			this->txtNome->MaxLength = 200;
			this->txtNome->Name = L"txtNome";
			this->txtNome->Size = System::Drawing::Size(454, 20);
			this->txtNome->TabIndex = 7;
			// 
			// txtCargo
			// 
			this->txtCargo->Location = System::Drawing::Point(489, 128);
			this->txtCargo->MaxLength = 100;
			this->txtCargo->Name = L"txtCargo";
			this->txtCargo->Size = System::Drawing::Size(223, 20);
			this->txtCargo->TabIndex = 8;
			// 
			// combInstituicao
			// 
			this->combInstituicao->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->combInstituicao->FormattingEnabled = true;
			this->combInstituicao->Location = System::Drawing::Point(16, 178);
			this->combInstituicao->Name = L"combInstituicao";
			this->combInstituicao->Size = System::Drawing::Size(454, 21);
			this->combInstituicao->TabIndex = 9;
			// 
			// btnNovaInstituicao
			// 
			this->btnNovaInstituicao->Location = System::Drawing::Point(489, 176);
			this->btnNovaInstituicao->Name = L"btnNovaInstituicao";
			this->btnNovaInstituicao->Size = System::Drawing::Size(93, 23);
			this->btnNovaInstituicao->TabIndex = 10;
			this->btnNovaInstituicao->Text = L"Nova";
			this->btnNovaInstituicao->UseVisualStyleBackColor = true;
			this->btnNovaInstituicao->Click += gcnew System::EventHandler(this, &TelaPessoas::btnNovaInstituicao_Click);
			// 
			// dataGridPessoas
			// 
			this->dataGridPessoas->AllowUserToOrderColumns = true;
			this->dataGridPessoas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridPessoas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->dgwCodigo, 
				this->dgwNome, this->dgwCargo, this->dgwInstituicao});
			this->dataGridPessoas->Location = System::Drawing::Point(16, 245);
			this->dataGridPessoas->Name = L"dataGridPessoas";
			this->dataGridPessoas->Size = System::Drawing::Size(696, 204);
			this->dataGridPessoas->TabIndex = 14;
			this->dataGridPessoas->DoubleClick += gcnew System::EventHandler(this, &TelaPessoas::dataGridPessoas_DoubleClick);
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
			// dgwCargo
			// 
			this->dgwCargo->HeaderText = L"Cargo";
			this->dgwCargo->Name = L"dgwCargo";
			this->dgwCargo->Width = 180;
			// 
			// dgwInstituicao
			// 
			this->dgwInstituicao->HeaderText = L"Instituição";
			this->dgwInstituicao->Name = L"dgwInstituicao";
			this->dgwInstituicao->ReadOnly = true;
			this->dgwInstituicao->Width = 172;
			// 
			// btnNovo
			// 
			this->btnNovo->Location = System::Drawing::Point(16, 210);
			this->btnNovo->Name = L"btnNovo";
			this->btnNovo->Size = System::Drawing::Size(75, 23);
			this->btnNovo->TabIndex = 12;
			this->btnNovo->Text = L"Novo";
			this->btnNovo->UseVisualStyleBackColor = true;
			this->btnNovo->Click += gcnew System::EventHandler(this, &TelaPessoas::btnNovo_Click);
			// 
			// btnGravar
			// 
			this->btnGravar->Location = System::Drawing::Point(138, 210);
			this->btnGravar->Name = L"btnGravar";
			this->btnGravar->Size = System::Drawing::Size(75, 23);
			this->btnGravar->TabIndex = 11;
			this->btnGravar->Text = L"Gravar";
			this->btnGravar->UseVisualStyleBackColor = true;
			this->btnGravar->Click += gcnew System::EventHandler(this, &TelaPessoas::btnGravar_Click);
			// 
			// btnRemover
			// 
			this->btnRemover->Enabled = false;
			this->btnRemover->Location = System::Drawing::Point(219, 210);
			this->btnRemover->Name = L"btnRemover";
			this->btnRemover->Size = System::Drawing::Size(75, 23);
			this->btnRemover->TabIndex = 13;
			this->btnRemover->Text = L"Remover";
			this->btnRemover->UseVisualStyleBackColor = true;
			this->btnRemover->Click += gcnew System::EventHandler(this, &TelaPessoas::btnRemover_Click);
			// 
			// lblInfo
			// 
			this->lblInfo->AutoSize = true;
			this->lblInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblInfo->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->lblInfo->Location = System::Drawing::Point(309, 215);
			this->lblInfo->Name = L"lblInfo";
			this->lblInfo->Size = System::Drawing::Size(113, 15);
			this->lblInfo->TabIndex = 15;
			this->lblInfo->Text = L"Cadastro removido!";
			this->lblInfo->Visible = false;
			// 
			// TelaPessoas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(724, 462);
			this->Controls->Add(this->lblInfo);
			this->Controls->Add(this->btnRemover);
			this->Controls->Add(this->btnGravar);
			this->Controls->Add(this->btnNovo);
			this->Controls->Add(this->dataGridPessoas);
			this->Controls->Add(this->btnNovaInstituicao);
			this->Controls->Add(this->combInstituicao);
			this->Controls->Add(this->txtCargo);
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
			this->Name = L"TelaPessoas";
			this->Text = L"Cadastro de Pessoas";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &TelaPessoas::TelaPessoas_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridPessoas))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: Pessoa *pPessoa;
private: std::vector<int>* idsInstituicoes;
			 
private: void inicializaAtributos() {
	idsInstituicoes = new vector<int>;
}
public: System::Void setPPessoa(Pessoa* p)	{ pPessoa = p; }
public: Pessoa* getPPessoa()				{ return pPessoa; }

private: System::Void btnGravar_Click(System::Object^  sender, System::EventArgs^  e)
{
	Pessoa pessoa = Pessoa();
	bool newPessoa = false;

	if (txtCodigo->Text->Length > 0) pPessoa = dynamic_cast<Pessoa*>(pessoa.carregar(int::Parse(txtCodigo->Text)));
	else
	{
		pPessoa = new Pessoa();
		newPessoa = true;
	}

	char* cNome = (char*)(void*)Marshal::StringToHGlobalAnsi(txtNome->Text);
	char* cCargo = (char*)(void*)Marshal::StringToHGlobalAnsi(txtCargo->Text);
	pPessoa->setNome(cNome);
	pPessoa->setCargo(cCargo);

	if (combInstituicao->Text->Length > 0)
	{
		int combSelectedItem = combInstituicao->SelectedIndex;
		int idInst = idsInstituicoes->at(combSelectedItem);
		Instituicao instituicao = Instituicao();
		Instituicao* pInstituicao = dynamic_cast<Instituicao*>(instituicao.carregar(idInst));
		pPessoa->setInstituicao(pInstituicao);
	}

	bool gravouOk = pPessoa->gravar();

	if (gravouOk && txtCodigo->Text->Length == 0)
	{
		txtCodigo->Text = pPessoa->getId().ToString();

		dataGridPessoas->Rows->Add(
			txtCodigo->Text,
			txtNome->Text, 
			txtCargo->Text,
			combInstituicao->Text
		);
		lblInfo->Text = "Inserido com Sucesso!";
		lblInfo->Visible = true;
		lblInfo->ForeColor = System::Drawing::Color::CornflowerBlue;
	}
	else if (gravouOk)
	{
		for( int i = 0; i < dataGridPessoas->RowCount -1; i++)
		{
			String ^s1 = dataGridPessoas->Rows[i]->Cells[0]->Value->ToString();
			String ^s2 = pPessoa->getId().ToString();
			if (s1->Equals(s2))
			{
				dataGridPessoas->Rows[i]->SetValues(
					txtCodigo->Text,
					txtNome->Text,
					txtCargo->Text,
					combInstituicao->Text
				);
			}
		}
		lblInfo->Text = "Alteração realizada!";
		lblInfo->Visible = true;
		lblInfo->ForeColor = System::Drawing::Color::CornflowerBlue;
	}

	if (newPessoa) delete pPessoa;
	carregarCadastroEmTela( int::Parse(txtCodigo->Text) );
}
private: System::Void reiniciaForm()
{
	txtCodigo->Clear();
	txtNome->Clear();
	txtCargo->Clear();
	btnGravar->Enabled = true;
	btnRemover->Enabled = false;
	btnNovo->Enabled = true;

	pPessoa = nullptr;
}
private: System::Void dataGridPessoas_DoubleClick(System::Object^  sender, System::EventArgs^  e) 
{
	int idPessoa = -1;
	try
	{
		idPessoa = int::Parse(dataGridPessoas->CurrentRow->Cells[0]->Value->ToString());
	}	catch(...) {}

	if (idPessoa >= 0)
	{
		carregarCadastroEmTela(idPessoa);
	}
 }
private: System::Void carregarCadastroEmTela(const int idPessoa)
{
	Pessoa pessoa = Pessoa();
	pPessoa = dynamic_cast<Pessoa*>(pessoa.carregar(idPessoa));

	txtCodigo->Text = pPessoa->getId().ToString();
	txtNome->Text	= gcnew System::String( pPessoa->getNome() );
	txtCargo->Text	= gcnew System::String( pPessoa->getCargo() );

	selecionaInstituicaoNoCombo(pPessoa->getInstituicao()->getId());

	btnRemover->Enabled = true;
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
			pPessoa = dynamic_cast<Pessoa*>( pPessoa->carregar(pPessoa->getId()) );
			if (pPessoa->remover()) {
				for( int i = 0; i < dataGridPessoas->RowCount -1; i++)
				{
					if (dataGridPessoas->Rows[i]->Cells[0]->Value->ToString()->Equals(txtCodigo->Text))
						dataGridPessoas->Rows[i]->Visible = false;
				}

				btnRemover->Enabled = false;
				reiniciaForm();
				lblInfo->Text = "Cadastro removido!";
				lblInfo->Visible = true;
				lblInfo->ForeColor = System::Drawing::Color::CornflowerBlue;

				pPessoa = nullptr;
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
private: System::Void btnNovo_Click(System::Object^  sender, System::EventArgs^  e)
{
	reiniciaForm();
	lblInfo->Visible = false;
	lblInfo->ForeColor = System::Drawing::Color::CornflowerBlue;
}
private: System::Void carregarCadastros()
{
	Pessoa pessoa = Pessoa();

	vector<Persistivel*> lista = pessoa.localizarCadastros();

	if (lista.size() > 0)
	{
		
		for (int i = 0; i < (int) lista.size(); i++)
		{
			pPessoa = dynamic_cast<Pessoa*>(lista.at(i));

			//pegar nomme ou sigla da instituição
			System::String			  ^instName = gcnew System::String( pPessoa->getInstituicao()->getSigla() );
			if (instName->Length == 0) instName = gcnew System::String( pPessoa->getInstituicao()->getNome());

			dataGridPessoas->Rows->Add(
				pPessoa->getId().ToString(),
				gcnew System::String( pPessoa->getNome() ),
				gcnew System::String( pPessoa->getCargo() ),
				gcnew System::String( instName )
			);
		}
	}
	pPessoa = nullptr;
	lista.clear();
}

#pragma warning( disable : 4700 )
private: System::Void btnNovaInstituicao_Click(System::Object^  sender, System::EventArgs^  e)
{
	Instituicao* pInstituicao = Sistema::AbreTelas::abreTelaInstituicao(pInstituicao);

	if (nullptr != pInstituicao && pInstituicao->getId() != -1)
	{
		carregarCadastrosInstituicoes();
		selecionaInstituicaoNoCombo(pInstituicao->getId());
	}
}
private: System::Void selecionaInstituicaoNoCombo(int id)
{
	for (int i = 0; i < (int) idsInstituicoes->size(); i++)
	{
		if (idsInstituicoes->at(i) == id)
		{
			combInstituicao->SelectedIndex = i;
		}
	}
}
private: System::Void carregarCadastrosInstituicoes()
{
	combInstituicao->Items->Clear();
	idsInstituicoes->clear();

	Instituicao instituicao = Instituicao();
	vector<Persistivel*> lista = instituicao.localizarCadastros();
	if (lista.size() > 0)
	{
		Instituicao* p;
		
		for (int i = 0; i < (int) lista.size(); i++)
		{
			p = dynamic_cast<Instituicao*>(lista.at(i));

			System::String ^str = gcnew System::String( p->getSigla() );

			if ( str->Length == 0 )
				combInstituicao->Items->Add(gcnew System::String( p->getNome()));
			else
				combInstituicao->Items->Add(gcnew System::String( p->getSigla()));

			idsInstituicoes->push_back(p->getId());
		}
	}
	lista.clear();
}
private: System::Void TelaPessoas_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 //const char *eta = pPessoa->getNome();
		 }
};
}
