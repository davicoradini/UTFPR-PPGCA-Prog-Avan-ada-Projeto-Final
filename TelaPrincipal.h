#pragma once
#include "Sistema.h"
#include "ViewElementsFactory.h"

namespace MyViews {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for TelaPrincipal
	/// </summary>
	public ref class TelaPrincipal : public System::Windows::Forms::Form
	{
	public:
		TelaPrincipal(void)
		{
			InitializeComponent();
			carregaConfiguracoesDoSistema();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TelaPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnTelaPessoa;
	protected:
	private: System::Windows::Forms::Button^  btnTelaInstituicao;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  cadastroToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  argumentaçãoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pessoasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  instituiçõesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  conectivosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  classificaçãoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  sairToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  configuraçõesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sobreToolStripMenuItem;
	private: System::Windows::Forms::Button^  btnArgumentacao;
	private: System::Windows::Forms::GroupBox^  groupBoxArgRecent;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutArgRecent;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;







	protected:

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
			this->btnTelaPessoa = (gcnew System::Windows::Forms::Button());
			this->btnTelaInstituicao = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->cadastroToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->argumentaçãoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pessoasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->instituiçõesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->conectivosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->classificaçãoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->sairToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->configuraçõesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sobreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnArgumentacao = (gcnew System::Windows::Forms::Button());
			this->groupBoxArgRecent = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutArgRecent = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->groupBoxArgRecent->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnTelaPessoa
			// 
			this->btnTelaPessoa->Location = System::Drawing::Point(136, 50);
			this->btnTelaPessoa->Name = L"btnTelaPessoa";
			this->btnTelaPessoa->Size = System::Drawing::Size(119, 51);
			this->btnTelaPessoa->TabIndex = 0;
			this->btnTelaPessoa->Text = L"Pessoas";
			this->btnTelaPessoa->UseVisualStyleBackColor = true;
			this->btnTelaPessoa->Click += gcnew System::EventHandler(this, &TelaPrincipal::btnTelaPessoas_Click);
			// 
			// btnTelaInstituicao
			// 
			this->btnTelaInstituicao->Location = System::Drawing::Point(136, 107);
			this->btnTelaInstituicao->Name = L"btnTelaInstituicao";
			this->btnTelaInstituicao->Size = System::Drawing::Size(119, 47);
			this->btnTelaInstituicao->TabIndex = 1;
			this->btnTelaInstituicao->Text = L"Instituições";
			this->btnTelaInstituicao->UseVisualStyleBackColor = true;
			this->btnTelaInstituicao->Click += gcnew System::EventHandler(this, &TelaPrincipal::btnTelaInstituicao_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->cadastroToolStripMenuItem, 
				this->configuraçõesToolStripMenuItem, this->sobreToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1008, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// cadastroToolStripMenuItem
			// 
			this->cadastroToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->argumentaçãoToolStripMenuItem, 
				this->pessoasToolStripMenuItem, this->instituiçõesToolStripMenuItem, this->conectivosToolStripMenuItem, this->classificaçãoToolStripMenuItem, 
				this->toolStripSeparator1, this->sairToolStripMenuItem});
			this->cadastroToolStripMenuItem->Name = L"cadastroToolStripMenuItem";
			this->cadastroToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->cadastroToolStripMenuItem->Text = L"Cadastros";
			// 
			// argumentaçãoToolStripMenuItem
			// 
			this->argumentaçãoToolStripMenuItem->Name = L"argumentaçãoToolStripMenuItem";
			this->argumentaçãoToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->argumentaçãoToolStripMenuItem->Text = L"Argumentação";
			this->argumentaçãoToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaPrincipal::argumentaçãoToolStripMenuItem_Click);
			// 
			// pessoasToolStripMenuItem
			// 
			this->pessoasToolStripMenuItem->Name = L"pessoasToolStripMenuItem";
			this->pessoasToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->pessoasToolStripMenuItem->Text = L"Pessoas";
			this->pessoasToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaPrincipal::pessoasToolStripMenuItem_Click);
			// 
			// instituiçõesToolStripMenuItem
			// 
			this->instituiçõesToolStripMenuItem->Name = L"instituiçõesToolStripMenuItem";
			this->instituiçõesToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->instituiçõesToolStripMenuItem->Text = L"Instituições";
			this->instituiçõesToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaPrincipal::instituiçõesToolStripMenuItem_Click);
			// 
			// conectivosToolStripMenuItem
			// 
			this->conectivosToolStripMenuItem->Name = L"conectivosToolStripMenuItem";
			this->conectivosToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->conectivosToolStripMenuItem->Text = L"Conectivos";
			this->conectivosToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaPrincipal::conectivosToolStripMenuItem_Click);
			// 
			// classificaçãoToolStripMenuItem
			// 
			this->classificaçãoToolStripMenuItem->Name = L"classificaçãoToolStripMenuItem";
			this->classificaçãoToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->classificaçãoToolStripMenuItem->Text = L"Classificação";
			this->classificaçãoToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaPrincipal::classificaçãoToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(150, 6);
			// 
			// sairToolStripMenuItem
			// 
			this->sairToolStripMenuItem->Name = L"sairToolStripMenuItem";
			this->sairToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->sairToolStripMenuItem->Text = L"Sair";
			this->sairToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaPrincipal::sairToolStripMenuItem_Click);
			// 
			// configuraçõesToolStripMenuItem
			// 
			this->configuraçõesToolStripMenuItem->Name = L"configuraçõesToolStripMenuItem";
			this->configuraçõesToolStripMenuItem->Size = System::Drawing::Size(96, 20);
			this->configuraçõesToolStripMenuItem->Text = L"Configurações";
			this->configuraçõesToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaPrincipal::configuraçõesToolStripMenuItem_Click);
			// 
			// sobreToolStripMenuItem
			// 
			this->sobreToolStripMenuItem->Name = L"sobreToolStripMenuItem";
			this->sobreToolStripMenuItem->Size = System::Drawing::Size(49, 20);
			this->sobreToolStripMenuItem->Text = L"Sobre";
			this->sobreToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaPrincipal::sobreToolStripMenuItem_Click);
			// 
			// btnArgumentacao
			// 
			this->btnArgumentacao->Location = System::Drawing::Point(13, 50);
			this->btnArgumentacao->Name = L"btnArgumentacao";
			this->btnArgumentacao->Size = System::Drawing::Size(117, 104);
			this->btnArgumentacao->TabIndex = 3;
			this->btnArgumentacao->Text = L"Argumentação";
			this->btnArgumentacao->UseVisualStyleBackColor = true;
			this->btnArgumentacao->Click += gcnew System::EventHandler(this, &TelaPrincipal::btnArgumentacao_Click);
			// 
			// groupBoxArgRecent
			// 
			this->groupBoxArgRecent->Controls->Add(this->tableLayoutArgRecent);
			this->groupBoxArgRecent->Location = System::Drawing::Point(13, 205);
			this->groupBoxArgRecent->Name = L"groupBoxArgRecent";
			this->groupBoxArgRecent->Size = System::Drawing::Size(403, 317);
			this->groupBoxArgRecent->TabIndex = 4;
			this->groupBoxArgRecent->TabStop = false;
			this->groupBoxArgRecent->Text = L"Argumentações Recentes";
			// 
			// tableLayoutArgRecent
			// 
			this->tableLayoutArgRecent->ColumnCount = 1;
			this->tableLayoutArgRecent->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutArgRecent->Location = System::Drawing::Point(6, 19);
			this->tableLayoutArgRecent->Name = L"tableLayoutArgRecent";
			this->tableLayoutArgRecent->RowCount = 10;
			this->tableLayoutArgRecent->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 
				10)));
			this->tableLayoutArgRecent->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 
				10)));
			this->tableLayoutArgRecent->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 
				10)));
			this->tableLayoutArgRecent->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 
				10)));
			this->tableLayoutArgRecent->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 
				10)));
			this->tableLayoutArgRecent->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 
				10)));
			this->tableLayoutArgRecent->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 
				10)));
			this->tableLayoutArgRecent->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 
				10)));
			this->tableLayoutArgRecent->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 
				10)));
			this->tableLayoutArgRecent->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 
				10)));
			this->tableLayoutArgRecent->Size = System::Drawing::Size(391, 292);
			this->tableLayoutArgRecent->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(704, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(292, 39);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Sistema desenvolvido como requisito da disciplina\r\nde Programação Avançada do Pro" 
				L"grama de Pós-Graduação\r\nem Computação Aplicada da UTFPR";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(704, 107);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(204, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Acesse no menu \"Sobre\" para saber mais";
			// 
			// TelaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 681);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBoxArgRecent);
			this->Controls->Add(this->btnArgumentacao);
			this->Controls->Add(this->btnTelaInstituicao);
			this->Controls->Add(this->btnTelaPessoa);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"TelaPrincipal";
			this->Text = L"Sistema para Argumentação";
			this->Activated += gcnew System::EventHandler(this, &TelaPrincipal::TelaPrincipal_Activated);
			this->Shown += gcnew System::EventHandler(this, &TelaPrincipal::TelaPrincipal_Shown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBoxArgRecent->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnTelaPessoas_Click(System::Object^  sender, System::EventArgs^  e) {
		Sistema::AbreTelas::abreTelaPessoa(new Pessoa());
	}
	private: System::Void btnTelaInstituicao_Click(System::Object^  sender, System::EventArgs^  e) {
		Sistema::AbreTelas::abreTelaInstituicao(new Instituicao());
	}
	private: System::Void pessoasToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Sistema::AbreTelas::abreTelaPessoa(new Pessoa());
	}
	private: System::Void instituiçõesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Sistema::AbreTelas::abreTelaInstituicao(new Instituicao());
	}
	private: System::Void classificaçãoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Sistema::AbreTelas::abreTelaClassificacao(new Classificacao());
	}
	private: System::Void conectivosToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Sistema::AbreTelas::abreTelaConectivo(new Conectivo());
	}
	private: System::Void argumentaçãoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Sistema::AbreTelas::abreTelaArgumentacao(new Argumentacao());
	}
	private: System::Void sairToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
private: System::Void btnArgumentacao_Click(System::Object^  sender, System::EventArgs^  e) {
		Sistema::AbreTelas::abreTelaArgumentacao(new Argumentacao());
		atualizaArgumentacoesRecentes();
	}
private: System::Void atualizaArgumentacoesRecentes()
{
	limparTabelaArgRecentes();

	ViewElementsFactory ^views = ViewElementsFactory::getInstancia();

	Argumentacao *arg = new Argumentacao();

	vector<Persistivel*> lista = arg->localizarCadastros();

	int linha = 0;
	for (int i = lista.size() -1; i >= 0 && linha < tableLayoutArgRecent->RowCount; i--)
	{
		arg = static_cast<Argumentacao*>(lista.at(i));
		string idS = to_string(arg->getId());

		LinkLabel ^label = views->criarLinkLabel(idS.c_str(), arg->getNome(), System::Drawing::Size(300, 13), System::Drawing::Point(3, 0));
		label->Click += gcnew System::EventHandler(this, &TelaPrincipal::labelLinkArg_Click);

		tableLayoutArgRecent->Controls->Add(label, 0, linha);
		linha++;
	}
}
private: System::Void limparTabelaArgRecentes()
{
	while (tableLayoutArgRecent->Controls->Count > 0)
	{
		tableLayoutArgRecent->Controls->RemoveAt(0);
	}
}
private: System::Void labelLinkArg_Click(System::Object^  sender, System::EventArgs^  e)
{
	System::Windows::Forms::LinkLabel ^linkLabelArg = dynamic_cast<System::Windows::Forms::LinkLabel ^>(sender);
	string	cName = (char*)(void*)Marshal::StringToHGlobalAnsi(linkLabelArg->Name);
	int		idArgumentacao = std::stoi(cName);

	Argumentacao argumentacao = Argumentacao();
	Sistema::AbreTelas::abreTelaArgumentacao(static_cast<Argumentacao*>( argumentacao.carregar(idArgumentacao) ));
	
}
private: System::Void configuraçõesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	Sistema::AbreTelas::abreTelaConfiguracao();
}
private: void carregaConfiguracoesDoSistema()
{
	Argumentacao* argumentacao;
	
	switch (Sistema::configuracaoSistema->getConfAberturaSistema())
	{
	case ConfiguraSistemaSingleton::Normal:			this->WindowState = System::Windows::Forms::FormWindowState::Normal;
		break;
	case ConfiguraSistemaSingleton::Maximizado:		this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
		break;
	case ConfiguraSistemaSingleton::NovaArg:		argumentacao = new Argumentacao();
													Sistema::AbreTelas::abreTelaArgumentacao(argumentacao);
		break;
	/*case ConfiguraSistemaSingleton::AbreUltimaArg:	argumentacao = new Argumentacao();
													argumentacao = static_cast<Argumentacao*>( argumentacao->carregar(Sistema::Identificadores::getAtualIdArgumentacao()) );
													Sistema::AbreTelas::abreTelaArgumentacao(argumentacao);
		break;*/

	default: this->WindowState = System::Windows::Forms::FormWindowState::Normal;
		break;
	}
}
private: System::Void TelaPrincipal_Activated(System::Object^  sender, System::EventArgs^  e) {
			 atualizaArgumentacoesRecentes();
		 }
private: System::Void TelaPrincipal_Shown(System::Object^  sender, System::EventArgs^  e) {
			 atualizaArgumentacoesRecentes();
		 }
private: System::Void sobreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Sistema::AbreTelas::abreTelaSobre();
		 }
};
}
