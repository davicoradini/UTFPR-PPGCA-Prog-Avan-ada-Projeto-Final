#ifndef _DesenhistaAtaqueSFMLL_H_
#define _DesenhistaAtaqueSFML_H_

#pragma once
#include "stdafx.h"

#include <windows.h>
#include <SFML/Graphics.hpp>
#include "AtaqueGeometrico.h"

class DesenhistaAtaqueSFML
{
private:
	sf::RenderWindow window;

public:
	DesenhistaAtaqueSFML(System::Windows::Forms::Control ^control);
	~DesenhistaAtaqueSFML();
	
	void limparTela();
	void desenhar(AtaqueGeometrico* ataqueGeometrico);
	void repintarTela();

private:
	void desenharLinha(const float x1, const float y1, const float x2, const float y2);
	void desenharTriangulo(const float x, const float y, const float rotation);
};
#endif