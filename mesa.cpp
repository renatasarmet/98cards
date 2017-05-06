#include "headers.h"

mesa::mesa() 
{
	LimpaMesa();
	carregou = false;
}

mesa::~mesa() 
{
}

void mesa::LimpaMesa() 
{
	bool DeuCerto;
	set_NroElementos(0);
	for (int i = 0; i<TAMANHO_MESA; i++) 
	{
		set_elemento_i(i, 0, DeuCerto);
	}
	set_NroElementos(0);
}

bool mesa::Vazia() const 
{
	if (get_NroElementos() == 0)
		return true;
	else
		return false;
}

bool mesa::Cheia() const
{
	if (get_NroElementos() == TAMANHO_MESA)
		return true;
	else
		return false;
}

void mesa::diminui_NroElementos()
{
	this->NroElementos -= 1;
}

void mesa::aumenta_NroElementos() 
{
	this->NroElementos += 1;
}

int mesa::get_NroElementos() const 
{
	return this->NroElementos;
}

void mesa::set_NroElementos(int X) 
{
	this->NroElementos = X;
}

int mesa::get_elemento_i(int i, bool &DeuCerto) const
{
	if ((i >= 0) && (i<TAMANHO_MESA)) 
	{
		DeuCerto = true;
		return this->Elementos[i];
	}
	DeuCerto = false;
	return 0;
}

void mesa::set_elemento_i(int i, int X, bool &DeuCerto)
{
	if ((i >= 0) && (i < TAMANHO_MESA))
	{
		DeuCerto = true;
		this->Elementos[i] = X;

		std::string aux = std::to_string(X);
		aux = aux + ".jpg";

		if (X != 0)
		{
			carregar(aux);
			if (i % 2 == 0)
				set_posicao(50, 800);
			else
				set_posicao(50, 900);
		}
		else
			carregar("");

	}
	else
		DeuCerto = false;
}

bool mesa::insereMesa(int X, bool &DeuCerto) 
{
	if (Cheia()) 
	{
		DeuCerto = false;
		cout << "Mesa cheia! Nao foi possivel inserir carta " << X << "!" << endl;
	}
	else 
	{
		for (int i = 0; i < TAMANHO_MESA; i++)
		{
			if (get_elemento_i(i, DeuCerto) == 0)
			{
				//cout << endl << "-----------Carta " << X << " Inserida!" << endl;
				aumenta_NroElementos();
				set_elemento_i(i, X, DeuCerto);
				return true;
			}
		}
	}
	return false;
}

int mesa::removeMesa(int X, bool &DeuCerto) 
{
	for (int i = 0; i<TAMANHO_MESA; i++) 
	{
		if (get_elemento_i(i, DeuCerto) == X) 
		{
			//cout << endl << "-----------Carta " << X << " Removida!" << endl;
			set_elemento_i(i, 0, DeuCerto);
			diminui_NroElementos();
			return X; // retorna o valor
		}
	}
	cout << endl << "Nao foi possivel remover! Carta " << X << " nao encontrada!" << endl;
	return 0; //caso nao tenha o valor
}

void mesa::distribuicao(fila_monte &f, int quantidade)
{
	bool DeuCerto;
	int X;
	for (int i = 0; i < quantidade; i++)
	{
		f.Retira(X, DeuCerto);
		if (DeuCerto)
			insereMesa(X, DeuCerto);
	}
}

void mesa::NovaDistribuicao(fila_monte &f, bool &DeuCerto)
{
	if (get_NroElementos() > 6)
		DeuCerto = false;
	else
	{
		distribuicao(f, 2);
		DeuCerto = true;
	}
}

void mesa::PrimeiraDistribuicao(fila_monte &f, bool &DeuCerto)
{
	if (get_NroElementos() != 0)
		DeuCerto = false;
	else 
	{
		distribuicao(f, 8);
		DeuCerto = true;
	}
}

void mesa::ImprimeMesaAbrindoTV() const
{
	bool DeuCerto;
	//cout << "Nro Elementos: " << get_NroElementos() << endl;
	for (int i = 0; i<(TAMANHO_MESA); i++)
	{
		cout << get_elemento_i(i, DeuCerto) << " ";
	}
	cout << endl;
}

void mesa::carregar(std::string nomearquivo)
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

void mesa::desenhar(sf::RenderWindow& renderWindow)
{
	if (carregou)
		renderWindow.draw(_sprite);
}

void mesa::set_posicao(float x, float y)
{
	if (carregou)
		_sprite.setPosition(x, y);
}
