#include <iostream>
#include "PilhaDecrescente.h"
using namespace std;

PilhaDecrescente::PilhaDecrescente():PilhaBurra(){
}

PilhaDecrescente::~PilhaDecrescente(){
}

void PilhaDecrescente::Empilha(int X, bool &DeuCerto, int &totalRestante){
	bool DeuCertoTbm;
	if((Vazia()) || (X < get_elemento_topo())||( X == get_elemento_topo()+10)){
		PilhaBurra::Empilha(X,DeuCertoTbm,totalRestante);
	}
	if(DeuCertoTbm)
		DeuCerto = true;
	else
		DeuCerto = false;
}

