#include "PilhaBurra.h"
#include <iostream>
using namespace std;

PilhaBurra::PilhaBurra(){
	set_topo(-1);
}


PilhaBurra::~PilhaBurra(){
}

bool PilhaBurra::Vazia() const{
	if(get_topo()==-1)
		return true;
	else
		return false;
}

bool PilhaBurra::Cheia() const{
	if(get_topo() == (QUANT_CARTAS -1))
		return true;
	else
		return false;
}

void PilhaBurra::Empilha(int X, bool &DeuCerto, int &totalRestante){
	if(Cheia())
		DeuCerto = false;
	else{
		DeuCerto = true;
		aumenta_topo();
		set_elemento_topo(X);
		totalRestante -= 1;
	}
}

void PilhaBurra::Desempilha(int &X, bool &DeuCerto, int &totalRestante){
	if(Vazia()) // || tag == 1;
		DeuCerto = false;
	else{
		DeuCerto = true;
		X = get_elemento_topo();
		diminui_topo();
		totalRestante += 1;
	}
}

void PilhaBurra::aumenta_topo(){
	this->topo += 1;
}

void PilhaBurra::diminui_topo(){
	this->topo -= 1;
}

int PilhaBurra::get_topo() const{
	return this->topo;
}

void PilhaBurra::set_topo(int t){
	this->topo = t;
}

void PilhaBurra::set_elemento_topo(int X){
	this->Elementos[this->topo] = X;
}

int PilhaBurra::get_elemento_topo() const{
	return this->Elementos[this->topo];
}


void PilhaBurra::Teste(int &t){
	t = get_topo();
}
