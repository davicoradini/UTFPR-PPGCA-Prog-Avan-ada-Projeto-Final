#ifndef _ARGUMENTOVIEWELEMENTO_H_
#define _ARGUMENTOVIEWELEMENTO_H_

#include "ArgumentoGeometrico.h"

#pragma once
namespace MyViews {

	using namespace System;
	using namespace System::Windows::Forms;

	public ref class ArgumentoViewElemento
	{
	private:
		int		   id; //Id do ataque que gerou este componente
		GroupBox  ^groupBox;
		Button    ^button;
		Label	  ^label;
		LinkLabel ^linkLabel;
		TextBox	  ^textBox;

	public:
		ArgumentoViewElemento(int i, GroupBox ^g, Button ^b, Label ^l, LinkLabel ^ll, TextBox ^r)
		{
			id		 = i;
			groupBox = g;
			button	 = b;
			label	 = l;
			linkLabel= ll;
			textBox = r;
		}
		ArgumentoViewElemento()
		{
			groupBox = gcnew GroupBox();
			button	 = gcnew Button();
			label	 = gcnew Label();
			linkLabel= gcnew LinkLabel();
			textBox = gcnew TextBox();
		}
		~ArgumentoViewElemento()
		{
			delete groupBox;
			delete button;
			delete label;
			delete linkLabel;
			delete textBox;
		}

		const int getId()
		{
			return id;
		}

		void ajustarPosicao(int diminuiX, int diminuiY)
		{
			int x = groupBox->Location.X - diminuiX;
			int y = groupBox->Location.Y - diminuiY;
			groupBox->Location = System::Drawing::Point(x, y);
		}

		void setGroupBoxText(const char *t)
		{
			groupBox->Text = gcnew System::String( t );
		}
		
		void setLabelText(const char *t)
		{
			label->Text = gcnew System::String( t );
			label->ForeColor = System::Drawing::SystemColors::ControlText;
		}
		
		void resetLabelText()
		{
			label->Text = gcnew System::String( "sem descrição" );
			label->ForeColor = System::Drawing::SystemColors::WindowFrame;
		}
		void setTextBoxText(const char *t)
		{
			textBox->Text = gcnew System::String( t );
		}
	};
}
#endif