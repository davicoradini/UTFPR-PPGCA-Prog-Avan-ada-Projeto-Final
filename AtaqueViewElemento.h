#ifndef _ATAQUEVIEWELEMENTO_H_
#define _ATAQUEVIEWELEMENTO_H_

#include "AtaqueGeometrico.h"

#pragma once
namespace MyViews {

	using namespace System;
	using namespace System::Windows::Forms;

	public ref class AtaqueViewElemento
	{
	private:
		int		  id; //Id do ataque que gerou este componente
		GroupBox ^groupBox;
		Button   ^button;
		Label	 ^label;

	public:
		AtaqueViewElemento(int i, GroupBox ^g, Button ^b, Label ^l)
		{
			id		 = i;
			groupBox = g;
			button	 = b;
			label	 = l;
		}
		AtaqueViewElemento()
		{
			groupBox = gcnew GroupBox();
			button	 = gcnew Button();
			label	 = gcnew Label();
		}
		~AtaqueViewElemento()
		{
			delete groupBox;
			delete button;
			delete label;
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
	};
}
#endif