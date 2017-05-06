#ifndef cartas_h
#define cartas_h

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class cartas
{
public:
	//CONSTRUTOR
	cartas();

	//DESTRUTOR
	virtual ~cartas();

	//FUNCOES
	virtual void carregar(std::string nome_arquivo);
	virtual void desenhar(sf::RenderWindow& window);

	virtual void set_posicao(float x, float y);

private:
	sf::Sprite _sprite;
	sf::Texture _imagem;
	std::string nome_arquivo;
	int valor;
	bool carregou;
};

#endif // !cartas_h