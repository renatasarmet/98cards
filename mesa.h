#ifndef MESA_H
#define MESA_H

#include "headers.h"
#define TAMANHO_MESA 8

class mesa
{
public:

	//CONSTRUTOR
	mesa();

	//DESTRUTOR
	~mesa();

	//METODOS
	bool Vazia() const;
	bool Cheia() const;
	bool insereMesa(int X, bool &DeuCerto);
	int removeMesa(int X, bool &DeuCerto);
	void LimpaMesa();
	void distribuicao(fila_monte &f, int quantidade);
	void NovaDistribuicao(fila_monte &f, bool &DeuCerto);
	void PrimeiraDistribuicao(fila_monte &f, bool &DeuCerto);
	void ImprimeMesaAbrindoTV() const;

	//METODOS GET E SET
	int get_NroElementos() const;
	void set_NroElementos(int);
	void diminui_NroElementos();
	void aumenta_NroElementos();
	int get_elemento_i(int i, bool &DeuCerto) const;
	void set_elemento_i(int i, int X, bool &DeuCerto);

	//TESTE
	virtual void carregar(std::string nome_arquivo);
	virtual void desenhar(sf::RenderWindow& window);

	virtual void set_posicao(float x, float y);

private:
	int Elementos[TAMANHO_MESA];
	int NroElementos;
	//TESTE
	sf::Sprite _sprite;
	sf::Texture _imagem;
	std::string nome_arquivo;
	bool carregou;
};
#endif // MESA_H