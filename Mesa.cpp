#include "Mesa.h"
#include <iostream>
using namespace std;

Mesa::Mesa(){
	LimpaMesa();
}


Mesa::~Mesa(){
}


void Mesa::LimpaMesa(){
	bool DeuCerto;

	set_NroElementos(0);

	for(int i=0;i<TAMANHO_MESA;i++){
		set_elemento_i(i, 0, DeuCerto);
	}

	set_NroElementos(0);
}


bool Mesa::Vazia() const{
	if(get_NroElementos()==0)
		return true;
	else
		return false;
}

bool Mesa::Cheia() const{
	if(get_NroElementos() == TAMANHO_MESA)
		return true;
	else
		return false;
}

void Mesa::diminui_NroElementos(){
	this->NroElementos -= 1;
}

void Mesa::aumenta_NroElementos(){
	this->NroElementos += 1;
}


int Mesa::get_NroElementos() const{
	return this->NroElementos;
}

void Mesa::set_NroElementos(int X){
	this->NroElementos = X;
}

int Mesa::get_elemento_i(int i, bool &DeuCerto) const{
	if((i>=0)&&(i<TAMANHO_MESA)){
		DeuCerto = true;
		return this->Elementos[i];
	}
	DeuCerto = false;
	return 0;
}

void Mesa::set_elemento_i(int i, int X, bool &DeuCerto){
	if((i>=0)&&(i<TAMANHO_MESA)){
		DeuCerto = true;
		this->Elementos[i] = X;
	}
	else
		DeuCerto = false;
}

bool Mesa::insereMesa (int X, bool &DeuCerto){
	if(Cheia()){
		DeuCerto = false;
		cout << "Mesa cheia! Nao foi possivel inserir carta " << X << "!" << endl;
	}
	else{
		for(int i=0;i<TAMANHO_MESA;i++){
			if(get_elemento_i(i, DeuCerto)==0){
				//cout << endl << "-----------Carta " << X << " Inserida!" << endl;
				aumenta_NroElementos();
				set_elemento_i(i, X, DeuCerto);
				return true;
			}
		}
	}
	return false;
}


int Mesa::removeMesa(int X, bool &DeuCerto){
	for(int i=0;i<TAMANHO_MESA;i++){
		if(get_elemento_i(i,DeuCerto) == X){
			//cout << endl << "-----------Carta " << X << " Removida!" << endl;
			set_elemento_i(i, 0, DeuCerto);
			diminui_NroElementos();
			return X; // retorna o valor
		}
	}
	cout << endl << "Nao foi possivel remover! Carta "<< X << " nao encontrada!" << endl;
	return 0; //caso nao tenha o valor
}



void Mesa::distribuicao (FilaMonte &f, int quantidade){
	bool DeuCerto;
	int X;
	for(int i = 0; i < quantidade; i++){
		f.Retira(X, DeuCerto);
		if (DeuCerto)
			insereMesa(X, DeuCerto);
	}
}

void Mesa::NovaDistribuicao(FilaMonte &f, bool &DeuCerto){
	if (get_NroElementos() > 6)
		DeuCerto = false;
	else {
		distribuicao (f, 2);
		DeuCerto = true;
	}
}


void Mesa::PrimeiraDistribuicao (FilaMonte &f, bool &DeuCerto){
	if (get_NroElementos() != 0)
		DeuCerto = false;
	else {
		distribuicao (f, 8);
		DeuCerto = true;
	}
}

void Mesa::ImprimeMesaAbrindoTV() const{
	bool DeuCerto;
	//cout << "Nro Elementos: " << get_NroElementos() << endl;
	for(int i=0;i<(TAMANHO_MESA);i++){
		cout << get_elemento_i(i, DeuCerto) << " ";
	}
	cout << endl;
}
