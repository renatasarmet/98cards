#include <iostream>
#include "PilhaBurra.h"
#include "PilhaCrescente.h"
#include "PilhaDecrescente.h"

using namespace std;

void Imprime(PilhaBurra &p, int &totalRestante){
	int x;
	PilhaBurra PAux;
	bool ok;
	while(p.Vazia()==false){
		p.Desempilha(x, ok, totalRestante);
		if(ok){
			PAux.Empilha(x, ok, totalRestante);
		}
	}

	cout << "Imprimindo a pilha"<<endl;
	while (PAux.Vazia()==false){
		PAux.Desempilha(x, ok, totalRestante);
		if(ok){
			cout << x << " ";
			p.Empilha(x, ok, totalRestante);
		}
	}
	cout << "<-- topo" << endl;
	cout << "Restam: " << totalRestante << endl;

}

int main(){
	PilhaCrescente p; //Tambem funciona para Decrescente
	bool ok;
	char op = 't';
	int valor;
	int totalRestante = QUANT_CARTAS;
	cout << "Restam :" << totalRestante << endl;
	while(op != 's'){
		cout << "Digite (e) empilhar, (d) desempilhar, (s) sair [enter]" <<endl;
		cin >> op;
		switch(op){
		case 'e':
			cout << "Digite valor INTEIRO para empilhar" << endl;
			cin >>valor;
			p.Empilha(valor, ok, totalRestante);
			if(ok==true)
				cout << "> valor empilhado"<<endl;
			else
				cout << ">nao conseguiu empilhar" << endl;
			break;
		case 'd':
			p.Desempilha(valor,ok, totalRestante);
			if(ok==true)
				cout << "valor desempilhado = " << valor << endl;
			else
				cout << "nao conseguiu desempilhar" << endl;
			break;
		default:
			cout << "saindo... " << endl;
			op = 's';
			break;
		}
		Imprime(p, totalRestante);
	}
	return 0;
}
