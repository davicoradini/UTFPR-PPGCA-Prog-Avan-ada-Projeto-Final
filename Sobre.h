#pragma once

namespace MyViews {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Sobre
	/// </summary>
	public ref class Sobre : public System::Windows::Forms::Form
	{
	public:
		Sobre(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Sobre()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	protected: 

	protected: 


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(244, 39);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Protótipo de sistema que será desenvolvido\r\ndurante projeto de pesquisa do curso " 
				L"de Mestrado\r\ndo Programa de Pós-Graduação em Computação";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 86);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(145, 26);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Aluno: Davi Daniel Siepmann\r\ndavicoradini@gmail.com";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 48);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(238, 26);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Aplicada (PPGCA) da Universidade Tecnológica \r\nFederal do Paraná (UTFPR) - Campus" 
				L" Curitiba";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 127);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(308, 39);
			this->label4->TabIndex = 7;
			this->label4->Text = L"O presente trabalho foi desenvolvido como projeto final \r\nda disciplina de Progra" 
				L"mação Avançada e tem por objetivo \r\nempregar todas as estruturas, técnicas e pad" 
				L"rões da linguagem ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 179);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(301, 39);
			this->label5->TabIndex = 8;
			this->label5->Text = L"contribuir com o projeto final do curso de Mestrado, no que se \r\nrefere a elabora" 
				L"ção de estruturas de argumentação abstrata. \r\nA argumentação é um componente da " 
				L"inteligência humana, ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 218);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(330, 39);
			this->label6->TabIndex = 9;
			this->label6->Text = L"que possibilita as pessoas se comunicarem, expressarem suas \r\nideias, defenderem " 
				L"seus interesses e se relacionar como sociedade. \r\nEm Ciência da Computação, a te" 
				L"oria da argumentação possibilita ";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 257);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(317, 39);
			this->label7->TabIndex = 10;
			this->label7->Text = L"estudar meios de entender o componente humano durante uma \r\nargumentação, estudan" 
				L"do meios para transmitir a habilidade de \r\nraciocinar para os computadores. O pr" 
				L"esente projeto tem objetivo ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(12, 296);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(325, 39);
			this->label8->TabIndex = 11;
			this->label8->Text = L"de descrever o processo de desenvolvimento de um software para \r\nargumentação abs" 
				L"trata, que possui interface para o usuário inserir \r\nargumentos e analisar a ace" 
				L"itabilidade dos mesmos de acordo com ";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 335);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(287, 13);
			this->label9->TabIndex = 12;
			this->label9->Text = L"definições presente na literatura de argumentação abstrata.";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(12, 166);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(282, 13);
			this->label10->TabIndex = 13;
			this->label10->Text = L"de programação C++. O sistema aqui desenvolvido vem a ";
			// 
			// Sobre
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(353, 364);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Sobre";
			this->Text = L"Sobre";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
