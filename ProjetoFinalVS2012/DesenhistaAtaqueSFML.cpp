#include "DesenhistaAtaqueSFML.h"


DesenhistaAtaqueSFML::DesenhistaAtaqueSFML(System::Windows::Forms::Control ^control)
{
	HWND hWnd = static_cast<HWND>(control->Handle.ToPointer());
	sf::WindowHandle handle = hWnd;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window.create(handle,settings);
}

DesenhistaAtaqueSFML::~DesenhistaAtaqueSFML()
{
}


void DesenhistaAtaqueSFML::repintarTela()
{
	window.display();
}
void DesenhistaAtaqueSFML::limparTela()
{
	window.clear(sf::Color::White);
}

void DesenhistaAtaqueSFML::desenharLinha(const float x1, const float y1, const float x2, const float y2)
{
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(x1, y1)),
		sf::Vertex(sf::Vector2f(x2, y2))
	};
	line->color = sf::Color::Black;
	

	window.draw(line, 2, sf::Lines);
}
void DesenhistaAtaqueSFML::desenharTriangulo(const float x, const float y, const float rotation)
{
	sf::CircleShape triangle(10, 3);
	triangle.setPosition(x, y);
	triangle.rotate(rotation);
	triangle.setFillColor(sf::Color::Red);
	triangle.setOutlineColor(sf::Color::Red);

	window.draw(triangle);
}

void DesenhistaAtaqueSFML::desenhar(AtaqueGeometrico* ataqueGeometrico)
{
	float x1 = (float)ataqueGeometrico->getXInicial();
	float y1 = (float)ataqueGeometrico->getYInicial();
	float x2 = (float)ataqueGeometrico->getXFinal();
	float y2 = (float)ataqueGeometrico->getYFinal();

	float y2n = (y1 > y2) ? y2 + 15 : y2 - 15;
	

	//Linha que liga dois argumentos
	desenharLinha(x2, y2n, x1, y1);
	

	float angle = (y1 > y2) ? (float)0.0 : (float)180.0;
	x2 = (y1 > y2) ? x2 - 10 : x2 + 10;
	
	//Seta que aponta o ataque
	desenharTriangulo(x2, y2, angle);
}
