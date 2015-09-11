#pragma once
//#include "Sistema.h"
#include "ConfiguraSistemaSingleton.h"

namespace MyViews {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TelaConfiguracao
	/// </summary>
	public ref class TelaConfiguracao : public System::Windows::Forms::Form
	{
	public:
		TelaConfiguracao(void)
		{
			InitializeComponent();
			inicializaAtributos();
			carregarCadastro();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TelaConfiguracao()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::RadioButton^  rbJanelaNormal;
	private: System::Windows::Forms::RadioButton^  rbJanelaMaximizada;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  rbJanelaNovaArgAbertura;
	private: System::Windows::Forms::RadioButton^  rbJanelaAbrirUltArg;
	private: System::Windows::Forms::Button^  btnGravar;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::RadioButton^  rbPersisteBinario;
	private: System::Windows::Forms::RadioButton^  rbPersisteMem;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;

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
			this->rbJanelaNormal = (gcnew System::Windows::Forms::RadioButton());
			this->rbJanelaMaximizada = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->rbJanelaAbrirUltArg = (gcnew System::Windows::Forms::RadioButton());
			this->rbJanelaNovaArgAbertura = (gcnew System::Windows::Forms::RadioButton());
			this->btnGravar = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->rbPersisteBinario = (gcnew System::Windows::Forms::RadioButton());
			this->rbPersisteMem = (gcnew System::Windows::Forms::RadioButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Iniciar Sistema";
			// 
			// rbJanelaNormal
			// 
			this->rbJanelaNormal->AutoSize = true;
			this->rbJanelaNormal->Checked = true;
			this->rbJanelaNormal->Location = System::Drawing::Point(3, 3);
			this->rbJanelaNormal->Name = L"rbJanelaNormal";
			this->rbJanelaNormal->Size = System::Drawing::Size(58, 17);
			this->rbJanelaNormal->TabIndex = 1;
			this->rbJanelaNormal->TabStop = true;
			this->rbJanelaNormal->Text = L"Normal";
			this->rbJanelaNormal->UseVisualStyleBackColor = true;
			// 
			// rbJanelaMaximizada
			// 
			this->rbJanelaMaximizada->AutoSize = true;
			this->rbJanelaMaximizada->Location = System::Drawing::Point(83, 3);
			this->rbJanelaMaximizada->Name = L"rbJanelaMaximizada";
			this->rbJanelaMaximizada->Size = System::Drawing::Size(80, 17);
			this->rbJanelaMaximizada->TabIndex = 2;
			this->rbJanelaMaximizada->Text = L"Maximizado";
			this->rbJanelaMaximizada->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->rbJanelaAbrirUltArg);
			this->panel1->Controls->Add(this->rbJanelaNovaArgAbertura);
			this->panel1->Controls->Add(this->rbJanelaNormal);
			this->panel1->Controls->Add(this->rbJanelaMaximizada);
			this->panel1->Location = System::Drawing::Point(15, 25);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(493, 26);
			this->panel1->TabIndex = 3;
			// 
			// rbJanelaAbrirUltArg
			// 
			this->rbJanelaAbrirUltArg->AutoSize = true;
			this->rbJanelaAbrirUltArg->Location = System::Drawing::Point(333, 3);
			this->rbJanelaAbrirUltArg->Name = L"rbJanelaAbrirUltArg";
			this->rbJanelaAbrirUltArg->Size = System::Drawing::Size(148, 17);
			this->rbJanelaAbrirUltArg->TabIndex = 4;
			this->rbJanelaAbrirUltArg->TabStop = true;
			this->rbJanelaAbrirUltArg->Text = L"Abrir última Argumentação";
			this->rbJanelaAbrirUltArg->UseVisualStyleBackColor = true;
			this->rbJanelaAbrirUltArg->Visible = false;
			// 
			// rbJanelaNovaArgAbertura
			// 
			this->rbJanelaNovaArgAbertura->AutoSize = true;
			this->rbJanelaNovaArgAbertura->Location = System::Drawing::Point(187, 3);
			this->rbJanelaNovaArgAbertura->Name = L"rbJanelaNovaArgAbertura";
			this->rbJanelaNovaArgAbertura->Size = System::Drawing::Size(123, 17);
			this->rbJanelaNovaArgAbertura->TabIndex = 3;
			this->rbJanelaNovaArgAbertura->TabStop = true;
			this->rbJanelaNovaArgAbertura->Text = L"Nova Argumentação";
			this->rbJanelaNovaArgAbertura->UseVisualStyleBackColor = true;
			// 
			// btnGravar
			// 
			this->btnGravar->Location = System::Drawing::Point(427, 307);
			this->btnGravar->Name = L"btnGravar";
			this->btnGravar->Size = System::Drawing::Size(75, 23);
			this->btnGravar->TabIndex = 4;
			this->btnGravar->Text = L"Gravar";
			this->btnGravar->UseVisualStyleBackColor = true;
			this->btnGravar->Click += gcnew System::EventHandler(this, &TelaConfiguracao::btnGravar_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Forma de Persistência";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->rbPersisteBinario);
			this->panel2->Controls->Add(this->rbPersisteMem);
			this->panel2->Location = System::Drawing::Point(15, 103);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(493, 28);
			this->panel2->TabIndex = 6;
			// 
			// rbPersisteBinario
			// 
			this->rbPersisteBinario->AutoSize = true;
			this->rbPersisteBinario->Location = System::Drawing::Point(119, 4);
			this->rbPersisteBinario->Name = L"rbPersisteBinario";
			this->rbPersisteBinario->Size = System::Drawing::Size(96, 17);
			this->rbPersisteBinario->TabIndex = 1;
			this->rbPersisteBinario->TabStop = true;
			this->rbPersisteBinario->Text = L"Arquivo Binário";
			this->rbPersisteBinario->UseVisualStyleBackColor = true;
			// 
			// rbPersisteMem
			// 
			this->rbPersisteMem->AutoSize = true;
			this->rbPersisteMem->Checked = true;
			this->rbPersisteMem->Location = System::Drawing::Point(4, 4);
			this->rbPersisteMem->Name = L"rbPersisteMem";
			this->rbPersisteMem->Size = System::Drawing::Size(92, 17);
			this->rbPersisteMem->TabIndex = 0;
			this->rbPersisteMem->TabStop = true;
			this->rbPersisteMem->Text = L"Memória RAM";
			this->rbPersisteMem->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 143);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(304, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Obs. nem todas as classes estão persistindo em arquivo binário";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label4->Location = System::Drawing::Point(121, 307);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(281, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Armazena arquivos em: c:\\sisargsavedfiles\\";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 165);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(99, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Persiste em Binário:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(111, 165);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(164, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Pessoa, Instituição, Classificação";
			// 
			// TelaConfiguracao
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(514, 342);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnGravar);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(530, 380);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(530, 380);
			this->Name = L"TelaConfiguracao";
			this->Text = L"Configuracões do Sistema";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: ConfiguraSistemaSingleton* pConfiguraSistema;

		private: void inicializaAtributos()
		{
			pConfiguraSistema = ConfiguraSistemaSingleton::getInstancia();
			pConfiguraSistema = static_cast<ConfiguraSistemaSingleton*>( pConfiguraSistema->carregar() );
		}
		
		private: System::Void carregarCadastro()
		{
			pConfiguraSistema = static_cast<ConfiguraSistemaSingleton*>(pConfiguraSistema->carregar());

			switch (pConfiguraSistema->getConfAberturaSistema())
			{
			case ConfiguraSistemaSingleton::Normal:			rbJanelaNormal->Checked = true;
				break;
			case ConfiguraSistemaSingleton::Maximizado:		rbJanelaMaximizada->Checked = true;
				break;
			case ConfiguraSistemaSingleton::NovaArg:		rbJanelaNovaArgAbertura->Checked = true;
				break;
			case ConfiguraSistemaSingleton::AbreUltimaArg:	rbJanelaAbrirUltArg->Checked = true;
				break;
			default:								rbJanelaNormal->Checked = true;
				break;
			}
			
			switch (pConfiguraSistema->getConfPersistencia())
			{
			case ConfiguraSistemaSingleton::MemoriaRam:			rbPersisteMem->Checked = true;
				break;
			case ConfiguraSistemaSingleton::Binario:			rbPersisteBinario->Checked = true;
				break;
			default:											rbPersisteMem->Checked = true;
				break;
			}
		}
		private: System::Void btnGravar_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (rbJanelaNormal->Checked == true)				pConfiguraSistema->setConfAberturaSistema(ConfiguraSistemaSingleton::Normal);
			else if (rbJanelaMaximizada->Checked == true)		pConfiguraSistema->setConfAberturaSistema(ConfiguraSistemaSingleton::Maximizado);
			else if (rbJanelaNovaArgAbertura->Checked == true)	pConfiguraSistema->setConfAberturaSistema(ConfiguraSistemaSingleton::NovaArg);
			else if (rbJanelaAbrirUltArg->Checked == true)		pConfiguraSistema->setConfAberturaSistema(ConfiguraSistemaSingleton::AbreUltimaArg);
			
			if (rbPersisteMem->Checked == true)					pConfiguraSistema->setConfPersistencia(ConfiguraSistemaSingleton::MemoriaRam);
			else if (rbPersisteBinario->Checked == true)		pConfiguraSistema->setConfPersistencia(ConfiguraSistemaSingleton::Binario);

			pConfiguraSistema->gravar();
			this->Close();
		}
};
}
