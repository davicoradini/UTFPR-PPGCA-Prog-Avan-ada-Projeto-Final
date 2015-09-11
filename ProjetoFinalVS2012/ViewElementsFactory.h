#ifndef _ViewElementsFactory_H_
#define _ViewElementsFactory_H_

#pragma once

#include <string>
using namespace std;

namespace MyViews {
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class ViewElementsFactory
	{
	private:
		ViewElementsFactory(){}
		static ViewElementsFactory ^_INSTANCIA;

	public:
		static ViewElementsFactory ^getInstancia()
		{
			if (nullptr == _INSTANCIA) _INSTANCIA = gcnew ViewElementsFactory();
			return _INSTANCIA;
		}

		GroupBox^ criarGroupBox(const char* name, const char* text, System::Drawing::Size size, System::Drawing::Point point)
		{
			//Cria elemento GroupBox com configurações padrão + recebidas
			GroupBox^  groupBox;
			groupBox = (gcnew System::Windows::Forms::GroupBox());

			groupBox->Name = gcnew System::String( name );
			groupBox->Text = gcnew System::String( text );
			groupBox->Size = size;
			groupBox->Location = point;

			groupBox->ResumeLayout(false);
			groupBox->PerformLayout();

			return groupBox;
		}
	
		Button^ criarBotao(const char* name, const char* text, System::Drawing::Size size, System::Drawing::Point point)
		{
			//Cria botão com configurações padrão + recebidas
			Button^  button;
			button = (gcnew System::Windows::Forms::Button());

			button->Name = gcnew System::String( name );
			button->Text = gcnew System::String( text );
			button->Size = size;
			button->Location = point;

			button->FlatAppearance->BorderSize = 0;
			button->UseVisualStyleBackColor = true;

			return button;
		}

		Label ^criarLabel(const char* name, const char* text, System::Drawing::Size size, System::Drawing::Point point)
		{
			//Cria label com configurações padrão + recebidas
			Label ^label;
			label = (gcnew System::Windows::Forms::Label());
			
			label->AutoSize = true;
			label->Size = size;
			label->Location = point;
			label->Name = gcnew System::String( name );
			label->Text =  gcnew System::String( text );
			label->ForeColor = System::Drawing::SystemColors::WindowFrame;
			
			return label;
		}
		
		LinkLabel ^criarLinkLabel(const char* name, const char* text, System::Drawing::Size size, System::Drawing::Point point)
		{
			//Cria label com configurações padrão + recebidas
			LinkLabel ^label;
			label = (gcnew System::Windows::Forms::LinkLabel());
			
			label->AutoSize = true;
			label->Size = size;
			label->Location = point;
			label->Name = gcnew System::String( name );
			label->Text =  gcnew System::String( text );
			
			return label;
		}
		
		TextBox ^criarTextBox(const char* name, const char* text, System::Drawing::Size size, System::Drawing::Point point)
		{
			//Cria label com configurações padrão + recebidas
			TextBox ^textBox;
			textBox = (gcnew System::Windows::Forms::TextBox());
			
			textBox->AutoSize = true;
			textBox->Size = size;
			textBox->Location = point;
			textBox->Name = gcnew System::String( name );
			textBox->Text =  gcnew System::String( text );
			textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			textBox->BackColor = Color::Cyan;
			textBox->Focus();

			return textBox;
		}
	};
}
#endif