#ifndef JOGO_H
#define JOGO_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "headers.h"

class Jogo
{

public:
	static void Start();

private:
	static bool IsExiting();
	static void loop_jogo();

	static void mostrar_tela_inicial();
	static void mostrar_menu();

	enum GameState{ 
		Inicializado, Mostrando_Tela_Inicial, Pausado, Mostrando_Menu, Jogando, Saindo}; // estado que o jogo pode estar durante a partida

	static GameState estado_jogo;
	static sf::RenderWindow janela;
	static sf::Sprite background;
	static gerenciador_cartas _gerenciador_cartas;
	//static gerenciador_mesa _gerenciador_mesa;
};
#endif