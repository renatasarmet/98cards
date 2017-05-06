#include "pilha_crescente.h"
#include <iostream>
#include "headers.h"
using namespace std;

pilha_crescente::pilha_crescente() :pilha_burra() 
{
}

pilha_crescente::~pilha_crescente() 
{
}

void pilha_crescente::Empilha(int x, bool &deucerto)
{
	bool deucertotbm = false;
	if ((Vazia()) || (x > get_elemento_topo()) || (x == get_elemento_topo() - 10))
		pilha_burra::Empilha(x, deucertotbm);
	if (deucertotbm)
		deucerto = true;
	else
		deucerto = false;
}