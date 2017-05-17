#include "headers.h"

cartas::cartas()
{
	carregou = false;
}

cartas::~cartas()
{
}

void cartas::carregar(std::string nomearquivo)
{
	if (_imagem.loadFromFile(nomearquivo) == false)
	{
		nome_arquivo = "";
		carregou = false;
	}
	else
	{
		nome_arquivo = nomearquivo;
		_sprite.setTexture(_imagem);
		carregou = true;
	}
}

void cartas::desenhar(sf::RenderWindow& renderWindow)
{
	if (carregou)	
		renderWindow.draw(_sprite);
}

void cartas::set_posicao(float x, float y)
{
	if (carregou)
		_sprite.setPosition(x, y);
}
