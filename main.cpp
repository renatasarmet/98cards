#include <iostream>
#include "PilhaBurra.h"
#include "PilhaCrescente.h"
#include "PilhaDecrescente.h"
#include "FilaMonte.h"

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

void ImprimeFila(FilaMonte &f){ // VERIFICAR O QUE HA DE ERRADO COM O IMPRIME FILA - OBS : ELE ALTERA VALORES NA FILA
	int x, p;
	FilaMonte FAux;
	bool ok;
	//p = f.get_primeiro();
	while(f.Vazia()==false){
		f.Retira(x,ok);
		if(ok){
			FAux.Insere(x, ok);
			//cout << FAux.get_elemento_ultimo()<<endl;
		}
	}
	cout << "Imprimindo a fila"<<endl;
	while(FAux.Vazia()==false){
		FAux.Retira(x, ok);
		if(ok){
			cout<< x << " ";
			f.Insere(x, ok);
			//cout << f.get_elemento_ultimo()<<endl;
		}
	}
	cout << " <--ultimo" << endl;
	//f.set_primeiro(p); //TALVEZ TENHA QUE FAZER ISSO
	cout << "Restam: " << f.get_NroElementos() << endl;
	cout << "Primeiro : " << f.get_primeiro() <<endl;
	cout << "Ultimo: " << f.get_ultimo() << endl;
}

void ImprimeFilaAbrindoTV(FilaMonte &f){
	cout << "Primeiro--> ";
	for(int i=f.get_primeiro();i<(f.get_ultimo()+1);i++){
		cout << f.get_elemento_X(i) << " ";
	}
	cout << " <--Ultimo"<<endl;
}

int main(){
//	PilhaCrescente p; //Tambem funciona para Decrescente
//	bool ok;
//	char op = 't';
//	int valor;
//	int totalRestante = QUANT_CARTAS;
//	cout << "Restam :" << totalRestante << endl;
//	while(op != 's'){
//		cout << "Digite (e) empilhar, (d) desempilhar, (s) sair [enter]" <<endl;
//		cin >> op;
//		switch(op){
//		case 'e':
//			cout << "Digite valor INTEIRO para empilhar" << endl;
//			cin >>valor;
//			p.Empilha(valor, ok, totalRestante);
//			if(ok==true)
//				cout << "> valor empilhado"<<endl;
//			else
//				cout << ">nao conseguiu empilhar" << endl;
//			break;
//		case 'd':
//			p.Desempilha(valor,ok, totalRestante);
//			if(ok==true)
//				cout << "valor desempilhado = " << valor << endl;
//			else
//				cout << "nao conseguiu desempilhar" << endl;
//			break;
//		default:
//			cout << "saindo... " << endl;
//			op = 's';
//			break;
//		}
//		Imprime(p, totalRestante);
//	}


	FilaMonte f;
	int x, a;
	bool ok;
//	cout << "Restam :"<< f.get_NroElementos()<<endl;
//	cout << "Primeiro : " << f.get_primeiro() <<endl;
//	cout << "Ultimo: " << f.get_ultimo() << endl;
	//ImprimeFila(f);

	ImprimeFilaAbrindoTV(f);
	f.Retira(x, ok);
	if (ok)
		cout << "Retirou o elemento: " << x << endl;
	else
		cout << "Nao foi possivel retirar elemento" << endl;
	//ImprimeFila(f);
//	cout << "Restam :"<< f.get_NroElementos()<<endl;
//	cout << "Primeiro : " << f.get_primeiro() <<endl;
//	cout << "Ultimo: " << f.get_ultimo() << endl;


	ImprimeFilaAbrindoTV(f);

	f.Retira(x, ok);
	if (ok)
		cout << "Retirou o elemento: " << x << endl;
	else
		cout << "Nao foi possivel retirar elemento" << endl;
	//ImprimeFila(f);
//	cout << "Restam :"<< f.get_NroElementos()<<endl;
//	cout << "Primeiro : " << f.get_primeiro() <<endl;
//	cout << "Ultimo: " << f.get_ultimo() << endl;

	//IMPRIMINDO A FILA ABRINDO A TV
	ImprimeFilaAbrindoTV(f);

	a = 10;
	f.Insere(a, ok);
	if (ok)
		cout << "Inseriu o elemento: " << a << endl;
	else
		cout << "Nao foi possivel inserir elemento" << endl;
//
//	cout << "Restam :"<< f.get_NroElementos()<<endl;
//	cout << "Primeiro : " << f.get_primeiro() <<endl;
//	cout << "Ultimo: " << f.get_ultimo() << endl;

	ImprimeFilaAbrindoTV(f);

	return 0;
}
