#pragma once
#include "ListaAtaqueGeometrico.h"
#include "ListaArgumentoGeometrico.h"

#include "ViewElementsFactory.h"
#include "AtaqueViewElemento.h"
#include "ArgumentoViewElemento.h"
#include "DesenhistaAtaqueSFML.h"

#include "Sistema.h"
#include "Argumentacao.h"
#include "ListaArgumentacoes.h"

#include "CalculaAceitabilidadeDung.h"
#include "ListaArgsDung.h"

#include "TelaArgumento.h"

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
	/// Summary for TelaArgumentacao
	/// </summary>
	public ref class TelaArgumentacao : public System::Windows::Forms::Form
	{
	

	public:
		TelaArgumentacao(void)
		{
			InitializeComponent();
			inicializaAtributos();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TelaArgumentacao()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 



	private: System::Windows::Forms::TextBox^  txtTitulo;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::TabControl^  tabControlEsquerda;

	private: System::Windows::Forms::TabPage^  tabPageArgumentos;

	private: System::Windows::Forms::TabPage^  tabPageAtaques;
	private: System::Windows::Forms::TabControl^  tabControlCentro;





	private: System::Windows::Forms::TabPage^  tabPageAbs;
	private: System::Windows::Forms::TabPage^  tabPageEstruturada;
	private: System::Windows::Forms::TabControl^  tabControlDireita;

	private: System::Windows::Forms::TabPage^  tabPageAceitabilidade;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  combModeradores;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  combParticipantes;

	private: System::Windows::Forms::LinkLabel^  lblLinkAddModerador;

	private: System::Windows::Forms::LinkLabel^  lblLinkAddParticipante;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  argumentaçãoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  novaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  abrirToolStripMenuItem;

	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  sairToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  descartarToolStripMenuItem;

	//thread
	private: BackgroundWorker^ backgroundWorkerDesenhista;
	private: System::Windows::Forms::TreeView^  treeViewAceitabilidadeDung;



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
			this->backgroundWorkerDesenhista = (gcnew System::ComponentModel::BackgroundWorker());
			this->txtTitulo = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->tabControlEsquerda = (gcnew System::Windows::Forms::TabControl());
			this->tabPageArgumentos = (gcnew System::Windows::Forms::TabPage());
			this->tabPageAtaques = (gcnew System::Windows::Forms::TabPage());
			this->tabControlDireita = (gcnew System::Windows::Forms::TabControl());
			this->tabPageAceitabilidade = (gcnew System::Windows::Forms::TabPage());
			this->treeViewAceitabilidadeDung = (gcnew System::Windows::Forms::TreeView());
			this->tabControlCentro = (gcnew System::Windows::Forms::TabControl());
			this->tabPageAbs = (gcnew System::Windows::Forms::TabPage());
			this->tabPageEstruturada = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->combModeradores = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->combParticipantes = (gcnew System::Windows::Forms::ComboBox());
			this->lblLinkAddModerador = (gcnew System::Windows::Forms::LinkLabel());
			this->lblLinkAddParticipante = (gcnew System::Windows::Forms::LinkLabel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->argumentaçãoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->novaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->abrirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->descartarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->sairToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->tabControlEsquerda->SuspendLayout();
			this->tabControlDireita->SuspendLayout();
			this->tabPageAceitabilidade->SuspendLayout();
			this->tabControlCentro->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// backgroundWorker
			// 
			this->backgroundWorkerDesenhista->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &TelaArgumentacao::backgroundWorkerDesenhista_RunWorkerCompleted);
			// 
			// txtTitulo
			// 
			this->txtTitulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->txtTitulo->Location = System::Drawing::Point(15, 52);
			this->txtTitulo->Name = L"txtTitulo";
			this->txtTitulo->Size = System::Drawing::Size(384, 23);
			this->txtTitulo->TabIndex = 1;
			this->txtTitulo->Leave += gcnew System::EventHandler(this, &TelaArgumentacao::txtTitulo_Leave);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Título da Argumentação";
			// 
			// splitContainer1
			// 
			this->splitContainer1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitContainer1->Location = System::Drawing::Point(15, 81);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->tabControlEsquerda);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->AutoScroll = true;
			this->splitContainer1->Panel2->Controls->Add(this->tabControlDireita);
			this->splitContainer1->Panel2->Controls->Add(this->tabControlCentro);
			this->splitContainer1->Size = System::Drawing::Size(1207, 643);
			this->splitContainer1->SplitterDistance = 226;
			this->splitContainer1->TabIndex = 4;
			// 
			// tabControlEsquerda
			// 
			this->tabControlEsquerda->Controls->Add(this->tabPageArgumentos);
			this->tabControlEsquerda->Controls->Add(this->tabPageAtaques);
			this->tabControlEsquerda->Location = System::Drawing::Point(4, 4);
			this->tabControlEsquerda->Name = L"tabControlEsquerda";
			this->tabControlEsquerda->SelectedIndex = 0;
			this->tabControlEsquerda->Size = System::Drawing::Size(223, 636);
			this->tabControlEsquerda->TabIndex = 0;
			// 
			// tabPageArgumentos
			// 
			this->tabPageArgumentos->AutoScroll = true;
			this->tabPageArgumentos->Location = System::Drawing::Point(4, 22);
			this->tabPageArgumentos->Name = L"tabPageArgumentos";
			this->tabPageArgumentos->Padding = System::Windows::Forms::Padding(3);
			this->tabPageArgumentos->Size = System::Drawing::Size(215, 610);
			this->tabPageArgumentos->TabIndex = 0;
			this->tabPageArgumentos->Text = L"Argumentos";
			this->tabPageArgumentos->UseVisualStyleBackColor = true;
			// 
			// tabPageAtaques
			// 
			this->tabPageAtaques->AutoScroll = true;
			this->tabPageAtaques->Location = System::Drawing::Point(4, 22);
			this->tabPageAtaques->Name = L"tabPageAtaques";
			this->tabPageAtaques->Padding = System::Windows::Forms::Padding(3);
			this->tabPageAtaques->Size = System::Drawing::Size(215, 610);
			this->tabPageAtaques->TabIndex = 1;
			this->tabPageAtaques->Text = L"Ataques";
			this->tabPageAtaques->UseVisualStyleBackColor = true;
			// 
			// tabControlDireita
			// 
			this->tabControlDireita->Controls->Add(this->tabPageAceitabilidade);
			this->tabControlDireita->Location = System::Drawing::Point(748, 3);
			this->tabControlDireita->Name = L"tabControlDireita";
			this->tabControlDireita->SelectedIndex = 0;
			this->tabControlDireita->Size = System::Drawing::Size(224, 636);
			this->tabControlDireita->TabIndex = 3;
			// 
			// tabPageAceitabilidade
			// 
			this->tabPageAceitabilidade->Controls->Add(this->treeViewAceitabilidadeDung);
			this->tabPageAceitabilidade->Location = System::Drawing::Point(4, 22);
			this->tabPageAceitabilidade->Name = L"tabPageAceitabilidade";
			this->tabPageAceitabilidade->Padding = System::Windows::Forms::Padding(3);
			this->tabPageAceitabilidade->Size = System::Drawing::Size(216, 610);
			this->tabPageAceitabilidade->TabIndex = 0;
			this->tabPageAceitabilidade->Text = L"Aceitabilidade";
			this->tabPageAceitabilidade->UseVisualStyleBackColor = true;
			// 
			// treeViewAceitabilidadeDung
			// 
			this->treeViewAceitabilidadeDung->Location = System::Drawing::Point(3, 3);
			this->treeViewAceitabilidadeDung->Name = L"treeViewAceitabilidadeDung";
			this->treeViewAceitabilidadeDung->Size = System::Drawing::Size(210, 604);
			this->treeViewAceitabilidadeDung->TabIndex = 0;
			// 
			// tabControlCentro
			// 
			this->tabControlCentro->Controls->Add(this->tabPageAbs);
			this->tabControlCentro->Controls->Add(this->tabPageEstruturada);
			this->tabControlCentro->Location = System::Drawing::Point(3, 4);
			this->tabControlCentro->Name = L"tabControlCentro";
			this->tabControlCentro->SelectedIndex = 0;
			this->tabControlCentro->Size = System::Drawing::Size(743, 636);
			this->tabControlCentro->TabIndex = 2;
			// 
			// tabPageAbs
			// 
			this->tabPageAbs->Location = System::Drawing::Point(4, 22);
			this->tabPageAbs->Name = L"tabPageAbs";
			this->tabPageAbs->Padding = System::Windows::Forms::Padding(3);
			this->tabPageAbs->Size = System::Drawing::Size(735, 610);
			this->tabPageAbs->TabIndex = 0;
			this->tabPageAbs->Text = L"Abstrata";
			this->tabPageAbs->UseVisualStyleBackColor = true;
			this->tabPageAbs->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TelaArgumentacao::areaArgumentacao_MouseClick);
			// 
			// tabPageEstruturada
			// 
			this->tabPageEstruturada->Location = System::Drawing::Point(4, 22);
			this->tabPageEstruturada->Name = L"tabPageEstruturada";
			this->tabPageEstruturada->Padding = System::Windows::Forms::Padding(3);
			this->tabPageEstruturada->Size = System::Drawing::Size(735, 610);
			this->tabPageEstruturada->TabIndex = 1;
			this->tabPageEstruturada->Text = L"Estruturada";
			this->tabPageEstruturada->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(442, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Moderadores";
			// 
			// combModeradores
			// 
			this->combModeradores->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->combModeradores->FormattingEnabled = true;
			this->combModeradores->Location = System::Drawing::Point(445, 52);
			this->combModeradores->Name = L"combModeradores";
			this->combModeradores->Size = System::Drawing::Size(212, 21);
			this->combModeradores->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(763, 33);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Participantes";
			// 
			// combParticipantes
			// 
			this->combParticipantes->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->combParticipantes->FormattingEnabled = true;
			this->combParticipantes->Location = System::Drawing::Point(766, 52);
			this->combParticipantes->Name = L"combParticipantes";
			this->combParticipantes->Size = System::Drawing::Size(196, 21);
			this->combParticipantes->TabIndex = 8;
			// 
			// lblLinkAddModerador
			// 
			this->lblLinkAddModerador->AutoSize = true;
			this->lblLinkAddModerador->Location = System::Drawing::Point(664, 59);
			this->lblLinkAddModerador->Name = L"lblLinkAddModerador";
			this->lblLinkAddModerador->Size = System::Drawing::Size(51, 13);
			this->lblLinkAddModerador->TabIndex = 9;
			this->lblLinkAddModerador->TabStop = true;
			this->lblLinkAddModerador->Text = L"Adicionar";
			this->lblLinkAddModerador->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &TelaArgumentacao::lblLinkAddModerador_LinkClicked);
			// 
			// lblLinkAddParticipante
			// 
			this->lblLinkAddParticipante->AutoSize = true;
			this->lblLinkAddParticipante->Location = System::Drawing::Point(969, 59);
			this->lblLinkAddParticipante->Name = L"lblLinkAddParticipante";
			this->lblLinkAddParticipante->Size = System::Drawing::Size(51, 13);
			this->lblLinkAddParticipante->TabIndex = 10;
			this->lblLinkAddParticipante->TabStop = true;
			this->lblLinkAddParticipante->Text = L"Adicionar";
			this->lblLinkAddParticipante->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &TelaArgumentacao::lblLinkAddParticipante_LinkClicked);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->argumentaçãoToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1234, 24);
			this->menuStrip1->TabIndex = 11;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// argumentaçãoToolStripMenuItem
			// 
			this->argumentaçãoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->novaToolStripMenuItem, 
				this->abrirToolStripMenuItem, this->descartarToolStripMenuItem, this->toolStripSeparator1, this->sairToolStripMenuItem});
			this->argumentaçãoToolStripMenuItem->Name = L"argumentaçãoToolStripMenuItem";
			this->argumentaçãoToolStripMenuItem->Size = System::Drawing::Size(98, 20);
			this->argumentaçãoToolStripMenuItem->Text = L"Argumentação";
			// 
			// novaToolStripMenuItem
			// 
			this->novaToolStripMenuItem->Name = L"novaToolStripMenuItem";
			this->novaToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->novaToolStripMenuItem->Text = L"Nova";
			this->novaToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaArgumentacao::novaToolStripMenuItem_Click);
			// 
			// abrirToolStripMenuItem
			// 
			this->abrirToolStripMenuItem->Name = L"abrirToolStripMenuItem";
			this->abrirToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->abrirToolStripMenuItem->Text = L"Abrir";
			// 
			// descartarToolStripMenuItem
			// 
			this->descartarToolStripMenuItem->Name = L"descartarToolStripMenuItem";
			this->descartarToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->descartarToolStripMenuItem->Text = L"Remover";
			this->descartarToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaArgumentacao::descartarToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(118, 6);
			// 
			// sairToolStripMenuItem
			// 
			this->sairToolStripMenuItem->Name = L"sairToolStripMenuItem";
			this->sairToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->sairToolStripMenuItem->Text = L"Sair";
			this->sairToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaArgumentacao::sairToolStripMenuItem_Click);
			// 
			// TelaArgumentacao
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1234, 734);
			this->Controls->Add(this->lblLinkAddParticipante);
			this->Controls->Add(this->lblLinkAddModerador);
			this->Controls->Add(this->combParticipantes);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->combModeradores);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtTitulo);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"TelaArgumentacao";
			this->Text = L"Argumentação";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &TelaArgumentacao::TelaArgumentacao_FormClosing);
			this->Shown += gcnew System::EventHandler(this, &TelaArgumentacao::TelaArgumentacao_Shown);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->tabControlEsquerda->ResumeLayout(false);
			this->tabControlDireita->ResumeLayout(false);
			this->tabPageAceitabilidade->ResumeLayout(false);
			this->tabControlCentro->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
private: Argumentacao*	pArgumentacao;
private: vector<int>*	idsModeradores;
private: vector<int>*	idsParticipantes;

//Ponteiros para as listas que estão armazenadas na argumentação atual
private: ListaAtaqueGeometrico		*listaAtaqueGeometrico;
private: ListaArgumentoGeometrico	*listaArgumentoGeometrico;
private: ListaArgumentos			*listaArgumentos;
private: ListaAtaques				*listaAtaques;
private: ListaModeradores			*listaModeradores;
private:ListaParticipantes			*listaParticipantes;

//Realizar calculo da aceitabilidade dos argumentos
CalculaAceitabilidadeDung* calcDung;

//Lista de elementos visuais que representam os ataques
private: System::Collections::Generic::List<ArgumentoViewElemento^>		listaArgumentoViewElemento;
private: System::Collections::Generic::List<AtaqueViewElemento^>		listaAtaqueViewElemento;

private: System::Windows::Forms::TextBox ^tbSelected;
private: DesenhistaAtaqueSFML *desenhista;
private: TabPage			  ^desenhistaDestino;
private: TabPage			  ^desenhistaDestinoNova;
private: Button				  ^btnClicado;

private: void inicializaAtributos()
{
	idsModeradores		= new vector<int>;
	idsParticipantes	= new vector<int>;

	tbSelected = nullptr;
	desenhista = nullptr;
	desenhistaDestino = nullptr;
	desenhistaDestinoNova = nullptr;
	btnClicado = nullptr;
	calcDung = nullptr;

}
public: System::Void setPArgumentacao(Argumentacao* p)
{
	pArgumentacao = p;

	if (pArgumentacao->getId() < 0) pArgumentacao->gravar();
	
	carregarCadastrosDePArgumentacao();
}
public: System::Void carregarCadastrosDePArgumentacao()
{
	txtTitulo->Text = gcnew String( pArgumentacao->getNome() );

	listaAtaqueGeometrico		= pArgumentacao->getListaAtaqueGeometrico();
	listaArgumentoGeometrico	= pArgumentacao->getListaArgumentoGeometrico();
	listaArgumentos				= pArgumentacao->getListaArgumentos();
	listaAtaques				= pArgumentacao->getListaAtaques();
	listaModeradores			= pArgumentacao->getListaModeradores();
	listaParticipantes			= pArgumentacao->getListaParticipantes();

	carregarCadastros();

	if (nullptr == calcDung) calcDung = new CalculaAceitabilidadeDung(listaArgumentos, listaAtaques);
}
public: Argumentacao* getPArgumentacao()			   { return pArgumentacao; }

private: void novaArgumentacao()
{
	//delete pArgumentacao;
	pArgumentacao = new Argumentacao();
	this->Visible = false;
	pArgumentacao = Sistema::AbreTelas::abreTelaArgumentacao(pArgumentacao);
	this->Close();
}

private: System::Void areaArgumentacao_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	int x = e->X; x = x > 50 ? x - 50 : x;
	int y = e->Y; y = y > 12 ? y - 12 : y;

	Argumento *argumento = new Argumento();
	argumento->setId(pArgumentacao->getNextIdArgumento());
	argumento->setNome(pArgumentacao->getNextLetraArgumento().c_str());
	argumento->setIdArgumentacao(pArgumentacao->getId());

	ArgumentoGeometrico *argGeometrico = new ArgumentoGeometrico(argumento->getId(), argumento, x, y, 100, 24);

	listaArgumentoGeometrico->incluir(argGeometrico);
	listaArgumentos->incluir(argumento); //o primeiro aqui está estranho

	TabPage ^tabDesenho = dynamic_cast<TabPage ^>(sender);
	criarCaixaArgumento(argGeometrico, tabDesenho, tabPageArgumentos);
}
private: System::Void txtArgDesenho_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	System::Windows::Forms::TextBox ^tbClicado = dynamic_cast<System::Windows::Forms::TextBox ^>(sender);
	if (tbClicado->Cursor == System::Windows::Forms::Cursors::PanNE)
	{
		if (nullptr == tbSelected)
		{
			tbSelected = tbClicado;
			tbClicado->BackColor = System::Drawing::Color::Orange;
			tbClicado->Parent->Focus();
			tbClicado->Parent->Cursor = System::Windows::Forms::Cursors::UpArrow;
		}
		else
		{
			if (!tbSelected->Equals(tbClicado))
			{
				int xIni = (int) tbSelected->Location.X + (tbSelected->Size.Width /2);
				int yIni = (int) tbSelected->Location.Y + (tbSelected->Size.Height /2);
				int xFim = (int) tbClicado->Location.X +  (tbClicado->Size.Width /2);
				int yFim = (int) tbClicado->Location.Y +  (tbClicado->Size.Height /2);
	
				//carrega argumento origem do ataque
				string	cName = (char*)(void*)Marshal::StringToHGlobalAnsi(tbSelected->Name);
				int		idArgumento = std::stoi(cName);
				Argumento *argOrigem = dynamic_cast<Argumento*>( listaArgumentos->getElementoPeloId(idArgumento) );
				
				//carrega argumento destino do ataque
						cName = (char*)(void*)Marshal::StringToHGlobalAnsi(tbClicado->Name);
						idArgumento = std::stoi(cName);
				Argumento *argDestino = dynamic_cast<Argumento*>( listaArgumentos->getElementoPeloId(idArgumento) );

				Ataque* ataque = new Ataque();
				ataque->setId(pArgumentacao->getNextIdAtaque());
				//ataque->setIdArgumentacao(pArgumentacao->getId()); -- REMOVER IDARGUMENTACAO DO ATAQUE PRIVATE Persistivel - TESTAR
				ataque->setPOrigem(argOrigem);
				ataque->setPDestino(argDestino);
				listaAtaques->incluir(ataque);

				AtaqueGeometrico *ataqueGeo = new AtaqueGeometrico(ataque->getId(), argOrigem, argDestino, xIni, yIni, xFim, yFim);
				listaAtaqueGeometrico->incluir(ataqueGeo);

				criarCaixaAtaque(ataqueGeo, tbClicado->Parent);
				
				desenhistaDestinoNova = tabPageAbs;
				this->backgroundWorkerDesenhista->RunWorkerAsync();

			}
			tbSelected->ResetBackColor();
			tbSelected = nullptr;
			tbClicado->Parent->Focus();
			tbClicado->Parent->Cursor = System::Windows::Forms::Cursors::Default;
		}
	}
}
private: System::Void txtArgDesenho_MouseEnter(System::Object^  sender, System::EventArgs^  e)
{
	System::Windows::Forms::TextBox ^tb = dynamic_cast<System::Windows::Forms::TextBox ^>(sender);
	if (tb->BackColor != System::Drawing::Color::Orange)
	{
		tb->BackColor = Color::Cyan;
	}
}
private: System::Void txtArgDesenho_MouseLeave(System::Object^  sender, System::EventArgs^  e)
{
	System::Windows::Forms::TextBox ^tb = dynamic_cast<System::Windows::Forms::TextBox ^>(sender);
	if (tb->BackColor != System::Drawing::Color::Orange && !tb->ContainsFocus)
	{
		tb->ResetBackColor();
	}
}
private: System::Void txtArgDesenho_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	 if(e->KeyCode == Keys::Enter || e->KeyCode == Keys::Tab)
	 {
		System::Windows::Forms::TextBox ^tb = dynamic_cast<System::Windows::Forms::TextBox ^>(sender);
		if (tb->BackColor != System::Drawing::Color::Orange)
		{
			tb->Parent->Focus();
			tb->ResetBackColor();
			tb->Cursor = System::Windows::Forms::Cursors::PanNE;

			atualizarCaixaArgumento(tb);
		}
	 }
}
private: System::Void txtArgDesenho_Leave(System::Object^  sender, System::EventArgs^  e)
{
	System::Windows::Forms::TextBox ^tb = dynamic_cast<System::Windows::Forms::TextBox ^>(sender);
	if (tb->BackColor != System::Drawing::Color::Orange)
	{
		tb->ResetBackColor();
		tb->Cursor = System::Windows::Forms::Cursors::PanNE;
	}
}
private: System::Void txtArgDesenho_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
	System::Windows::Forms::TextBox ^tb = dynamic_cast<System::Windows::Forms::TextBox ^>(sender);
	
	tb->Cursor = System::Windows::Forms::Cursors::Default;
	tb->BackColor = Color::Cyan;
	tb->Focus();
	tb->SelectAll();
	tbSelected = nullptr;
}
private: System::Void atualizarCaixaArgumento(System::Windows::Forms::TextBox ^tb)
{
	string	cName = (char*)(void*)Marshal::StringToHGlobalAnsi(tb->Name);
	int		idArgumento = std::stoi(cName);

	Argumento *argumento = dynamic_cast<Argumento*>( listaArgumentos->getElementoPeloId(idArgumento) );
	
	string digitadoTextBox = (char*)(void*)Marshal::StringToHGlobalAnsi(tb->Text);
	string nomeArgumento = argumento->getNome();

	if (digitadoTextBox.compare(nomeArgumento) != 0)
	{
		ArgumentoViewElemento^ ave = getArgumentoViewElementoPeloId(idArgumento);
		ave->setLabelText(digitadoTextBox.c_str());
		ave->setTextBoxText(nomeArgumento.c_str());
	}

	this->tabControlEsquerda->SelectedTab = tabPageArgumentos;
}
private: ArgumentoViewElemento^ getArgumentoViewElementoPeloId(int id)
{
	ArgumentoViewElemento^ aveRetorno = gcnew ArgumentoViewElemento();
	
	for each (ArgumentoViewElemento^ ave in listaArgumentoViewElemento)
	{
		if (ave->getId() == id)
		{
			aveRetorno = ave;
		}
	}

	return aveRetorno;
}
private: System::Void criarCaixaArgumento(ArgumentoGeometrico *argumentoGeo, TabPage^ tabDesenho, TabPage^ tabCaixa)
{
	//Cria caixa de exibição
	ViewElementsFactory ^viewElements = ViewElementsFactory::getInstancia();

	string sId = to_string(argumentoGeo->getId());
	string argNome  (argumentoGeo->getArgumento()->getNome());
	string argDesc  (argumentoGeo->getArgumento()->getDescricao());
	int x = argumentoGeo->getPosX();
	int y = argumentoGeo->getPosY();
	int l = argumentoGeo->getLargura();
	int a = argumentoGeo->getAltura();

	int posY = 3 + (listaArgumentoViewElemento.Count * 46);
	GroupBox	^groupBox	= viewElements->criarGroupBox("gbArgumento", argNome.c_str(),	System::Drawing::Size(194, 45), System::Drawing::Point(3, posY));
	Button		^button		= viewElements->criarBotao(sId.c_str(), "X",					System::Drawing::Size(20,  22), System::Drawing::Point(168,  2));
	LinkLabel	^linkLabel	= viewElements->criarLinkLabel(sId.c_str(), "Editar",			System::Drawing::Size(40,  22), System::Drawing::Point(160,  26));
	Label		^label		= viewElements->criarLabel("lbArgumento", "sem descrição",		System::Drawing::Size(190, 22), System::Drawing::Point(6,   15));
	TextBox		^textBox	= viewElements->criarTextBox(sId.c_str(), argNome.c_str(),	System::Drawing::Size(l,    a),	System::Drawing::Point(x,    y));

	//Adiciona listeners
	button->MouseClick		+= gcnew System::Windows::Forms::MouseEventHandler(this, &TelaArgumentacao::btnDeleteArg_MouseClick);
	linkLabel->MouseClick	+= gcnew System::Windows::Forms::MouseEventHandler(this, &TelaArgumentacao::btnEditaArg_MouseClick);

	textBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TelaArgumentacao::txtArgDesenho_MouseClick);
	textBox->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &TelaArgumentacao::txtArgDesenho_KeyUp);
	textBox->MouseEnter += gcnew System::EventHandler(this, &TelaArgumentacao::txtArgDesenho_MouseEnter);
	textBox->MouseLeave += gcnew System::EventHandler(this, &TelaArgumentacao::txtArgDesenho_MouseLeave);
	textBox->DoubleClick += gcnew System::EventHandler(this, &TelaArgumentacao::txtArgDesenho_DoubleClick);
	textBox->Leave += gcnew System::EventHandler(this, &TelaArgumentacao::txtArgDesenho_Leave);

	groupBox->Controls->Add(button);
	groupBox->Controls->Add(label);
	groupBox->Controls->Add(linkLabel);

	//Adiciona componentes criados em seus lugares
	tabCaixa->Controls->Add(groupBox);
	tabDesenho->Controls->Add(textBox);
	
	ArgumentoViewElemento ^ave = gcnew ArgumentoViewElemento(argumentoGeo->getId(), groupBox, button, label, linkLabel, textBox);
	listaArgumentoViewElemento.Add(ave);

	textBox->BackColor = Color::Cyan;
	if (nullptr != tbSelected)
	{
		tbSelected->ResetBackColor();
		tbSelected = nullptr;
	}

	this->tabControlEsquerda->SelectedTab = tabPageArgumentos;
	textBox->Focus();
	textBox->SelectAll();

	
	calcularAceitabilidadeDung();
}

//Cria setas para conectar ataques de argumentos
private: System::Void criarCaixaAtaque(AtaqueGeometrico *ataqueGeo, System::Object^ sender)
{
	//Cria caixa de exibição
	ViewElementsFactory ^viewElements = ViewElementsFactory::getInstancia();

	string sId = to_string(ataqueGeo->getId());
	string argOrigem  (ataqueGeo->getArgOrigem()->getNome());
	string argDestino (ataqueGeo->getArgDestino()->getNome());
	string labelText = argOrigem + " --> " + argDestino;

	int posY = 3 + (listaAtaqueViewElemento.Count * 31);
	GroupBox ^groupBox	= viewElements->criarGroupBox("gbAtaque", "",			  System::Drawing::Size(194, 30), System::Drawing::Point(3,	posY));
	Button   ^button	= viewElements->criarBotao(sId.c_str(), "X",			  System::Drawing::Size(22,  25), System::Drawing::Point(173,  5));
	Label	 ^label		= viewElements->criarLabel("lbAtaque", labelText.c_str(), System::Drawing::Size(190, 22), System::Drawing::Point(6,   11));

	button->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TelaArgumentacao::btnDelAtaque_MouseClick);

	groupBox->Controls->Add(button);
	groupBox->Controls->Add(label);
	tabPageAtaques->Controls->Add(groupBox);
	
	AtaqueViewElemento ^ave = gcnew AtaqueViewElemento(ataqueGeo->getId(), groupBox, button, label);
	listaAtaqueViewElemento.Add(ave);

	this->tabControlEsquerda->SelectedTab = tabPageAtaques;
	calcularAceitabilidadeDung();
}
/*private: System::Void repintarTela(System::Windows::Forms::TabPage ^destino)
{
	if (nullptr == desenhista || desenhistaDestino != destino)
	{
		desenhista = new DesenhistaAtaqueSFML(tabPageAbs);
		desenhistaDestino = destino;
	}

	desenhista->limparTela();

	vector<AtaqueGeometrico*> *lista = listaAtaqueGeometrico->getLista();
	if ((int)lista->size() > 0)
	{
		for (int i = 0; i < (int) lista->size(); i++)
		{
			desenhista->desenhar(lista->at(i));
		}
		x1->Text = gcnew String( desenhista->P_x1.ToString() );
		x2->Text = gcnew String( desenhista->P_x2.ToString() );
		y1->Text = gcnew String( desenhista->P_y1.ToString() );
		y2->Text = gcnew String( desenhista->P_y2.ToString() );

		a->Text = gcnew String( desenhista->P_a.ToString() );
		angle->Text = gcnew String( desenhista->P_angle.ToString() );
		aAngle->Text = gcnew String( desenhista->P_aAngle.ToString() );

		x3->Text = gcnew String( desenhista->P_x3.ToString() );
		y3->Text = gcnew String( desenhista->P_y3.ToString() );

		desenhista->repintarTela();
	}
}*/
private: System::Void btnDeleteArg_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	System::Windows::Forms::Button^ button = dynamic_cast<System::Windows::Forms::Button ^>(sender);

	string	cName = (char*)(void*)Marshal::StringToHGlobalAnsi(button->Name);
	int		idArgumento = std::stoi(cName);

	int idAtaque = listaAtaqueGeometrico->getIdPeloArgumento(idArgumento);
	while (idAtaque > 0)
	{
		removerAtaquePeloId(idAtaque);
		idAtaque = listaAtaqueGeometrico->getIdPeloArgumento(idArgumento);
	}

	//Re-desenha tela para apagar a seta
	desenhistaDestinoNova = tabPageAbs;
	this->backgroundWorkerDesenhista->RunWorkerAsync();

	//Sai removendo de todos os lugares
	Argumento *argumento = dynamic_cast<Argumento*>( listaArgumentos->getElementoPeloId(idArgumento) );
	if (argumento->getId() > 0)
	{
		listaArgumentos->remover(argumento);

		ArgumentoGeometrico *argumentoGeo = listaArgumentoGeometrico->getElementoPeloId(idArgumento);
		listaArgumentoGeometrico->remover(argumentoGeo);

		delete argumento;
		delete argumentoGeo;

		int count = 0;
		bool ajustarPosicao = false;
		for each (ArgumentoViewElemento^ ave in listaArgumentoViewElemento)
		{
			if (ajustarPosicao) //Ajusta a posição dos ataques que estão localizados após o removido
			{
				ave->ajustarPosicao(0, 46);
			}
			else if (ave->getId() == idArgumento)
			{
				delete ave;
				ajustarPosicao = true;
			}
			else count++;
		}
		listaArgumentoViewElemento.RemoveAt(count);

		if (listaArgumentos->getLista()->tamanho() <= 0) {
			listaArgumentos->limpar();
			listaAtaques->limpar();
			listaArgumentoGeometrico->limpar();
			listaAtaqueGeometrico->limpar();
			listaAtaqueViewElemento.RemoveRange(0, listaAtaqueViewElemento.Count);
			listaArgumentoViewElemento.RemoveRange(0, listaArgumentoViewElemento.Count);
		}
	}
}
private: System::Void btnEditaArg_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	System::Windows::Forms::LinkLabel^ linkLabel = dynamic_cast<System::Windows::Forms::LinkLabel ^>(sender);

	string	cName = (char*)(void*)Marshal::StringToHGlobalAnsi(linkLabel->Name);
	int		idArgumento = std::stoi(cName);

	//Sai removendo de todos os lugares
	Argumento *argumento = dynamic_cast<Argumento*>( listaArgumentos->getElementoPeloId(idArgumento) );

	argumento = abreTelaArgumento(argumento);
	
	for each(ArgumentoViewElemento ^ave in listaArgumentoViewElemento)
	{
		if (ave->getId() == argumento->getId())
		{
			ave->setGroupBoxText(argumento->getNome());

			if (argumento->getDescricao().length() > 0)
				ave->setLabelText(argumento->getDescricao().c_str());

			else
				ave->resetLabelText();

			ave->setTextBoxText(argumento->getNome());

			break;
		}
	}
}
private: Argumento* abreTelaArgumento(Argumento* p)
{
	TelaArgumento ^form = gcnew TelaArgumento();
	form->setListaModeradores(listaModeradores);
	form->setListaParticipantes(listaParticipantes);
	form->setPArgumento(p);
	form->Visible = false;
	form->ShowDialog();

	p = form->getPArgumento();
	delete form;

	return p;
}
private: System::Void lblLinkAddModerador_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
{
	Pessoa *pessoa = new Pessoa();
	pessoa->setIdArgumentacao(pArgumentacao->getId());
	pessoa = Sistema::AbreTelas::abreTelaPessoa(pessoa);

	Moderador *moderador = static_cast<Moderador*>(pessoa);
	moderador->setIdArgumentacao(pArgumentacao->getId());

	if (moderador->getId() > 0)
	{
		listaModeradores->incluir( dynamic_cast<Persistivel*>( moderador ));
		carregarCadastrosModeradores();
	}

	combModeradores->SelectedIndex = combModeradores->Items->Count -1;
}
private: System::Void lblLinkAddParticipante_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
{
	Pessoa *pessoa = new Pessoa();
	pessoa->setIdArgumentacao(pArgumentacao->getId());
	pessoa = Sistema::AbreTelas::abreTelaPessoa(pessoa);

	Participante *participante = static_cast<Participante*>(pessoa);
	participante->setIdArgumentacao(pArgumentacao->getId());

	if (participante->getId() > 0)
	{
		listaParticipantes->incluir(dynamic_cast<Persistivel*>( participante ));
		carregarCadastrosParticipantes();
	}

	combParticipantes->SelectedIndex = combParticipantes->Items->Count -1;
}

//Referente aos ataques
private: System::Void btnDelAtaque_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	System::Windows::Forms::Button^ button = dynamic_cast<System::Windows::Forms::Button ^>(sender);

	string	cName = (char*)(void*)Marshal::StringToHGlobalAnsi(button->Name);
	int		idAtaque = std::stoi(cName);

	removerAtaquePeloId(idAtaque);

	//Re-desenha tela para apagar a seta
	desenhistaDestinoNova = tabPageAbs;
	this->backgroundWorkerDesenhista->RunWorkerAsync();
}
private: System::Void removerAtaquePeloId(const int idAtaque)
{
	//Sai removendo de todos os lugares
	Ataque *ataque = dynamic_cast<Ataque*>( listaAtaques->getElementoPeloId(idAtaque) );
	listaAtaques->remover(ataque);

	AtaqueGeometrico *ataqueGeo = listaAtaqueGeometrico->getElementoPeloId(idAtaque);
	listaAtaqueGeometrico->remover(ataqueGeo); //lista tem 3 elementos mas 2 foram removidos

	delete ataque;
	delete ataqueGeo;

	int count = 0;
	bool ajustarPosicao = false;
	for each (AtaqueViewElemento^ ave in listaAtaqueViewElemento)
	{
		if (ajustarPosicao) //Ajusta a posição dos ataques que estão localizados após o removido
		{
			ave->ajustarPosicao(0, 34);
		}
		else if (ave->getId() == idAtaque)
		{
			delete ave;
			ajustarPosicao = true;
		}
		else count++;
	}
	listaAtaqueViewElemento.RemoveAt(count);

}

//carregar cadastros
private: System::Void carregarCadastros()
{
	carregarCadastrosModeradores();
	carregarCadastrosParticipantes();
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
private: System::Void sairToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Close();
}
private: System::Void salvarArgumentacao()
{
	string	cName = (char*)(void*)Marshal::StringToHGlobalAnsi(txtTitulo->Text);
	if (txtTitulo->Text->Length > 0)
		pArgumentacao->setNome(cName.c_str());
	else
	{
		cName = "Argumentação " + to_string( pArgumentacao->getId() );
		txtTitulo->Text = gcnew String( cName.c_str() );
		pArgumentacao->setNome(cName.c_str());
	}

	pArgumentacao->gravar();
}
private: System::Void descartarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Sistema::getListaArgumentacoes()->remover(pArgumentacao);
			 this->Close();
		 }
private: System::Void txtTitulo_Leave(System::Object^  sender, System::EventArgs^  e) {
			 salvarArgumentacao();
		 }
private: System::Void novaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 pArgumentacao->gravar();
			 novaArgumentacao();
		 }


/****************************************************************************************************
								CARREGAR UMA ARGUMENTAÇÃO

*****************************************************************************************************/
private: System::Void carregarArgumentacaoCompleta()
{
	carregarArgumentacaoCaixasArgumentos();
	carregarArgumentacaoAtaques();

	desenhistaDestinoNova = tabPageAbs;
	this->backgroundWorkerDesenhista->RunWorkerAsync();
}
private: System::Void carregarArgumentacaoCaixasArgumentos()
{
	vector<ArgumentoGeometrico*> *lista = listaArgumentoGeometrico->getLista();

	for (int i = 0; i < (int) lista->size(); i++)
	{
		criarCaixaArgumento(lista->at(i), tabPageAbs, tabPageArgumentos);
	}
}
private: System::Void carregarArgumentacaoAtaques()
{
	vector<AtaqueGeometrico*> *lista = listaAtaqueGeometrico->getLista();

	for (int i = 0; i < (int) lista->size(); i++)
	{
		criarCaixaAtaque(lista->at(i), tabPageAtaques);
	}
}
private: System::Void TelaArgumentacao_Shown(System::Object^  sender, System::EventArgs^  e)
{
	carregarArgumentacaoCompleta();
}

//thread
private: void backgroundWorkerDesenhista_RunWorkerCompleted(Object^ sender, RunWorkerCompletedEventArgs^ e)
{
	if (nullptr == desenhista)
	{
		desenhista = new DesenhistaAtaqueSFML(desenhistaDestinoNova);
		desenhistaDestino = desenhistaDestinoNova;
	}
	else if (desenhistaDestino != desenhistaDestinoNova)
	{
		delete desenhista;
		desenhista = new DesenhistaAtaqueSFML(desenhistaDestinoNova);
		desenhistaDestino = desenhistaDestinoNova;
	}

	desenhista->limparTela();

	vector<AtaqueGeometrico*> *lista = listaAtaqueGeometrico->getLista();
	if ((int)lista->size() > 0)
	{
		for (int i = 0; i < (int) lista->size(); i++)
		{
			desenhista->desenhar(lista->at(i));
		}
		desenhista->repintarTela();

		/*x1->Text = gcnew String( desenhista->P_x1.ToString() );
		x2->Text = gcnew String( desenhista->P_x2.ToString() );
		y1->Text = gcnew String( desenhista->P_y1.ToString() );
		y2->Text = gcnew String( desenhista->P_y2.ToString() );

		a->Text = gcnew String( desenhista->P_a.ToString() );
		angle->Text = gcnew String( desenhista->P_angle.ToString() );
		aAngle->Text = gcnew String( desenhista->P_aAngle.ToString() );

		x3->Text = gcnew String( desenhista->P_x3.ToString() );
		y3->Text = gcnew String( desenhista->P_y3.ToString() );*/
	}
}
//thread
private: void calcularAceitabilidadeDung()
{
	//limpa arvore
	treeViewAceitabilidadeDung->Nodes->Clear();

	calcDung->atualizaTodos();

	//mostraConjuntosDungs(calcDung->getSetsConflictFree(), "ConflictFree Sets");
	mostraConjuntosDungs(calcDung->getSetsConflictFreeAdmissible(), "Admissible ConflictFree Sets");
	mostraConjuntosDungs(calcDung->getPreferedExtensions(), "Prefered Extension");
}
private: void mostraConjuntosDungs(list<ListaArgsDung*>	*conjunto, String^ treeTitle)
{
	//nós de argumentos para compor árvore
	TreeNode ^ parentNode = gcnew TreeNode(treeTitle);

	for (list<ListaArgsDung*>::iterator it = conjunto->begin(); it != conjunto->end(); it++)
	{
		ListaArgsDung* listaArgsDung = static_cast<ListaArgsDung*>(*it);
		vector<Argumento*>* argumentos = listaArgsDung->getLista();

		String^ childNodeDescription = gcnew String("{");
		bool comma = false;
		for (vector<Argumento*>::iterator it = argumentos->begin(); it != argumentos->end(); it++)
		{
			Argumento* argumento = *it;

			if (comma) childNodeDescription += ",";

			childNodeDescription += gcnew String( argumento->getNome() );

			comma = true;
		}
		childNodeDescription += "}";

		parentNode->Nodes->Add (gcnew TreeNode( childNodeDescription ) );
	}
	treeViewAceitabilidadeDung->Nodes->Add( parentNode );
	treeViewAceitabilidadeDung->ExpandAll();
}
private: System::Void TelaArgumentacao_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 pArgumentacao->gravar();
		 }
};
}
