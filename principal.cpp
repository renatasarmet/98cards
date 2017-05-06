//#include "principal.h"
//#include "headers.h"
//
//Principal::tela_principal Principal::Mostrar(sf::RenderWindow& window)
//{
//	//Carrega a imagem do menu de um arquivo
//	sf::Texture imagem;
//	imagem.loadFromFile("principal.jpg");
//	
//	sf::Sprite sprite;
//	sprite.setTexture(imagem);
//
//	//Areas clicaveis no menu
//
//	//Coordenadas do botao SAIR
//	Item_principal botao_sair;
//	botao_sair.rect.top = 0;
//	botao_sair.rect.height = 300;
//	botao_sair.rect.left = 0;
//	botao_sair.rect.width = 610;
//	botao_sair.action = Sair;
//
//	//Coordenadas do botao MENU
//	Item_principal botao_menu;
//	botao_menu.rect.top = 0;
//	botao_menu.rect.height = 300;
//	botao_menu.rect.left = 750;
//	botao_menu.rect.width = 1225;
//	botao_menu.action = Menu;
//
//	itens_menu.push_back(botao_sair);
//	itens_menu.push_back(botao_menu);
//
//	window.draw(sprite);
//	window.display();
//
//	return obter_resposta_principal(window);
//}
//
//Principal::tela_principal Principal::clique(int x, int y)
//{
//	std::list<Item_principal>::iterator it;
//
//	for (it = itens_menu.begin(); it != itens_menu.end(); it++)
//	{
//		sf::Rect<int> item_do_menu = (*it).rect;
//		if (item_do_menu.top < y && item_do_menu.height > y && item_do_menu.left < x && item_do_menu.width > x)
//			return (*it).action;
//	}
//
//	return Nada;
//}
//
//Principal::tela_principal Principal::obter_resposta_principal(sf::RenderWindow& window)
//{
//	sf::Event evento_principal;
//
//	while (1 != 0)
//	{
//		while (window.pollEvent(evento_principal))
//		{
//			if (evento_principal.type == sf::Event::MouseButtonPressed)
//				return clique(int(evento_principal.mouseButton.x), int(evento_principal.mouseButton.y));
//			if (evento_principal.type == sf::Event::Closed)
//				return Sair;
//		}
//	}
//}