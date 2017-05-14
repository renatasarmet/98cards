#include "headers.h"
#include "jogo.h"

#define LARGURA 1125;
#define ALTURA 1500;

Jogo::GameState Jogo::estado_jogo = Inicializado;
sf::RenderWindow Jogo::janela;
gerenciador_cartas Jogo::_gerenciador_cartas;
sf::Sprite Jogo::background;

void Jogo::Start(void)
{
	bool deucerto;
	mesa* m = new mesa();

	fila_monte f;

	m->PrimeiraDistribuicao(f, deucerto);

	if (estado_jogo != Inicializado)
		return;

	janela.create(sf::VideoMode(1125, 1500), "99 Cartas", sf::Style::Close); //DEFINE TAMANHO DA JANELA, O QUE APARECE NO CABEÇALHO E FUNCOES DISPONIVEIS (FECHAR, RESIZE, MINIMIZAR)
	
	sf::Texture imagem;
	imagem.loadFromFile("principal.jpg");
	background.setTexture(imagem); //DEFINE O BACKGROUND

	pilha_crescente *pilha1 = new pilha_crescente(); //CRIA A PILHA CRESCENTE DA DIREITA
	pilha1->carregar("carta_teste.jpg");
	pilha1->set_posicao(750, 260);

	pilha_crescente *pilha2 = new pilha_crescente(); //CRIA A PILHA CRESCENTE DA ESQUERDA
	pilha2->carregar("carta_teste.jpg");
	pilha2->set_posicao(230, 260);

	pilha_decrescente *pilha3 = new pilha_decrescente(); //CRIA A PILHA DECRESCENTE DA DIREITA
	pilha3->carregar("carta_teste.jpg");
	pilha3->set_posicao(750, 710);

	pilha_decrescente *pilha4 = new pilha_decrescente(); //CRIA A PILHA DECRESCENTE DA ESQUERDA
	pilha4->carregar("carta_teste.jpg");
	pilha4->set_posicao(230, 710);

	_gerenciador_cartas.adicionar("pilha1", pilha1); //adiciona as novas pilhas ao gerenciador de cartas
	_gerenciador_cartas.adicionar("pilha2", pilha2);
	_gerenciador_cartas.adicionar("pilha3", pilha3);
	_gerenciador_cartas.adicionar("pilha4", pilha4);

	for (int j = 0; j < TAMANHO_MESA; j++)
	{
		std::string aux = std::to_string(j);
		aux = "teste" + aux;
		_gerenciador_cartas.adicionar(aux, m->teste[j]);
	}

	estado_jogo = Jogo::Mostrando_Tela_Inicial;

	while (!IsExiting())
	{
		loop_jogo(*m);
	}

	janela.close();
}

bool Jogo::IsExiting()
{
	if (estado_jogo == Jogo::Saindo)
		return true;
	else
		return false;
}

void Jogo::loop_jogo(mesa& m)
{
	switch (estado_jogo)
	{
		case Jogo::Mostrando_Menu:
		{
			mostrar_menu();
			break;
		}
		case Jogo::Mostrando_Tela_Inicial:
		{
			mostrar_tela_inicial();
			break;
		}
		case Jogo::Jogando:
		{
			sf::Event evento_atual;

			//sf::RectangleShape teste(sf::Vector2f(150, 200)); //Cria um "objeto", nesse caso a carta
			//teste.setOrigin(75.f, 100.f); //coloca o ponteiro do mouse no centro da carta
			//sf::Texture imagem_carta; //cria uma nova textura
			//imagem_carta.loadFromFile("carta_teste.jpg"); //importa uma imagem para a nova textura
			//teste.setTexture(&imagem_carta); //aplica a nova textura à carta
			//teste.setPosition(50, 900);

			//if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) //checa os cliques do mouse
			//{
			//	sf::Vector2i mousepos = sf::Mouse::getPosition(janela);
			//	teste.setPosition((float)mousepos.x, (float)mousepos.y);
			//	cout << "teste2" << endl;
			//}

			while (janela.pollEvent(evento_atual))
			{
				janela.clear();
				janela.draw(background);
	
				_gerenciador_cartas.desenhar_todos(janela);
				//m.desenhar(janela);
				//janela.draw(teste);
				janela.display();
			
				if (evento_atual.type == sf::Event::Closed)
					estado_jogo = Jogo::Saindo;
				
				if (evento_atual.mouseButton.button == sf::Mouse::Left)
					for (int i = 0; i < TAMANHO_MESA; i++)
					{
						if(m.teste[i]->pressionado(janela))
						{
							m.removeMesa(janela, i);
						}
					}

				if (evento_atual.type == sf::Event::KeyPressed)
				{
					if (evento_atual.key.code == sf::Keyboard::Escape)
						mostrar_menu();
				}
			}
			break;
		}
	}
}

void Jogo::mostrar_tela_inicial()
{
	Tela_Inicial tela_incial;
	tela_incial.Mostrar(janela);
	estado_jogo = Jogo::Mostrando_Menu;
}

void Jogo::mostrar_menu()
{
	Menu menu;
	Menu::menu_inicial resultado = menu.Mostrar(janela);
	switch (resultado)
	{
	case Menu::Sair:
		estado_jogo = Jogo::Saindo;
		break;
	case Menu::Jogar:
		estado_jogo = Jogo::Jogando;
		break;
	}
}

int main(int argc, char** argv)
{
	Jogo::Start();



	
	//sf::RectangleShape carta(sf::Vector2f(150, 200)); //Cria um "objeto", nesse caso a carta
	//carta.setOrigin(75.f, 100.f); //coloca o ponteiro do mouse no centro da carta
	//sf::Texture imagem_carta; //cria uma nova textura
	//imagem_carta.loadFromFile("carta_teste.jpg"); //importa uma imagem para a nova textura
	//carta.setTexture(&imagem_carta); //aplica a nova textura à carta
	//
	//while (window.isopen())
	//{
	//	sf::event evnt;
	//	while (window.pollevent(evnt))
	//	{
	//		switch (evnt.type)
	//		{
	//		case sf::event::closed:
	//			window.close();
	//			break;
	//		}	
	//	}

	//	if (sf::mouse::isbuttonpressed(sf::mouse::button::left)) //checa os cliques do mouse
	//	{
	//		sf::vector2i mousepos = sf::mouse::getposition(window);
	//		carta.setposition((float)mousepos.x, (float)mousepos.y);
	//	}

	//	window.clear();
	//	window.draw(carta);
	//	window.display();
	//}

	return 0;
}