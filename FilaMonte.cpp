#include "FilaMonte.h"
#include <iostream>
using namespace std;

FilaMonte::FilaMonte(){
	NroElementos = 0;
	Primeiro = -1;
	Ultimo = -1;
	InicializaElementos();
}


FilaMonte::~FilaMonte(){
}


void FilaMonte::InicializaElementos(){
	bool DeuCerto;
	//Inicializando vetor na ordem
	for(int i=0;i<QUANT_CARTAS;i++)
		Insere(i, DeuCerto);
	//Chamando funcao para embaralhar vetor
	//EmbaralhaElementos();
}

void FilaMonte::EmbaralhaElementos(){
	for(int i=0; i<NroElementos;i++){
		int r = rand() % NroElementos; // ARRUMAR ESSE ALEATORIO QUE ESTA SE REPETINDO
		//cout << "R: " << r << endl;
		int temp = Elementos[i];
		Elementos[i] = Elementos[r];
		Elementos[r] = temp;
	}
}

bool FilaMonte::Vazia() const{
	if(get_NroElementos()==0)
		return true;
	else
		return false;
}

bool FilaMonte::Cheia() const{
	if(get_NroElementos() == QUANT_CARTAS)
		return true;
	else
		return false;
}

void FilaMonte::Insere(int X, bool &DeuCerto){
	if(Cheia())
		DeuCerto = false;
	else{
		if(Vazia())
			proximo_primeiro();

		DeuCerto = true;
		aumenta_NroElementos();
		proximo_ultimo();
		set_elemento_ultimo(X);
	}
}

void FilaMonte::Retira(int &X, bool &DeuCerto){
	if(Vazia())
		DeuCerto = false;
	else{
		DeuCerto = true;
		diminui_NroElementos();
		X = get_elemento_primeiro();
		proximo_primeiro();
	}
}

void FilaMonte::proximo_primeiro(){
	this->Primeiro += 1;
}

void FilaMonte::proximo_ultimo(){
	this->Ultimo += 1;
}

int FilaMonte::get_primeiro() const{
	return this->Primeiro;
}

int FilaMonte::get_ultimo() const{
	return this->Ultimo;
}

void FilaMonte::set_elemento_ultimo(int novo){
	this->Elementos[this->Ultimo] = novo;
}

void FilaMonte::diminui_NroElementos(){
	this->NroElementos -= 1;
}

void FilaMonte::aumenta_NroElementos(){
	this->NroElementos += 1;
}

int FilaMonte::get_elemento_primeiro() const{
	return this->Elementos[this->Primeiro];
}

int FilaMonte::get_elemento_ultimo() const{
	return this->Elementos[this->Ultimo];
}

int FilaMonte::get_NroElementos() const{
	return this->NroElementos;
}
