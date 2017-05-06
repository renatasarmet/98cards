#include <iostream>
#include "PilhaCrescente.h"
using namespace std;

PilhaCrescente::PilhaCrescente():PilhaBurra(){
}

PilhaCrescente::~PilhaCrescente(){
}

void PilhaCrescente::Empilha(int X, bool &DeuCerto){
	bool DeuCertoTbm = false;
	if((Vazia()) || (X > get_elemento_topo())||( X == get_elemento_topo()-10)){
		PilhaBurra::Empilha(X,DeuCertoTbm);
	}

	if(DeuCertoTbm){
		DeuCerto = true;
	}
	else
		DeuCerto = false;

}

