#include <iostream>
#include "PilhaBurra.h"
#include "PilhaCrescente.h"
#include "PilhaDecrescente.h"
#include "FilaMonte.h"
#include "Mesa.h"


using namespace std;

void ImprimePilha(PilhaBurra &p, int &totalRestante){
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
	//cout << "Restam: " << totalRestante << endl;
}

//void ImprimeFila(FilaMonte &f){ // VERIFICAR O QUE HA DE ERRADO COM O IMPRIME FILA - OBS : ELE ALTERA VALORES NA FILA
//	int x, p;
//	FilaMonte FAux;
//	bool ok;
//	//p = f.get_primeiro();
//	while(f.Vazia()==false){
//		f.Retira(x,ok);
//		if(ok){
//			FAux.Insere(x, ok);
//			//cout << FAux.get_elemento_ultimo()<<endl;
//		}
//	}
//	cout << "Imprimindo a fila"<<endl;
//	while(FAux.Vazia()==false){
//		FAux.Retira(x, ok);
//		if(ok){
//			cout<< x << " ";
//			f.Insere(x, ok);
//			//cout << f.get_elemento_ultimo()<<endl;
//		}
//	}
//	cout << " <--ultimo" << endl;
//	//f.set_primeiro(p); //TALVEZ TENHA QUE FAZER ISSO
//	cout << "Restam: " << f.get_NroElementos() << endl;
//	cout << "Primeiro : " << f.get_primeiro() <<endl;
//	cout << "Ultimo: " << f.get_ultimo() << endl;
//}

//void ImprimeFilaAbrindoTV(FilaMonte &f){
//	cout << "Primeiro--> ";
//	for(int i=f.get_primeiro();i<(f.get_ultimo()+1);i++){
//		cout << f.get_elemento_X(i) << " ";
//	}
//	cout << " <--Ultimo"<<endl;
//}



int main(){

// TESTE DA PILHA
//
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
//		ImprimePilha(p, totalRestante);
//	}


	// TESTE DA FILA
//
//	FilaMonte f;
//	int x, a;
//	bool ok;
////	cout << "Restam :"<< f.get_NroElementos()<<endl;
////	cout << "Primeiro : " << f.get_primeiro() <<endl;
////	cout << "Ultimo: " << f.get_ultimo() << endl;
//	//ImprimeFila(f);
//
//	ImprimeFilaAbrindoTV(f);
//	f.Retira(x, ok);
//	if (ok)
//		cout << "Retirou o elemento: " << x << endl;
//	else
//		cout << "Nao foi possivel retirar elemento" << endl;
//	//ImprimeFila(f);
////	cout << "Restam :"<< f.get_NroElementos()<<endl;
////	cout << "Primeiro : " << f.get_primeiro() <<endl;
////	cout << "Ultimo: " << f.get_ultimo() << endl;
//
//
//	ImprimeFilaAbrindoTV(f);
//
//	f.Retira(x, ok);
//	if (ok)
//		cout << "Retirou o elemento: " << x << endl;
//	else
//		cout << "Nao foi possivel retirar elemento" << endl;
//	//ImprimeFila(f);
////	cout << "Restam :"<< f.get_NroElementos()<<endl;
////	cout << "Primeiro : " << f.get_primeiro() <<endl;
////	cout << "Ultimo: " << f.get_ultimo() << endl;
//
//	//IMPRIMINDO A FILA ABRINDO A TV
//	ImprimeFilaAbrindoTV(f);
//
//	a = 10;
//	f.Insere(a, ok);
//	if (ok)
//		cout << "Inseriu o elemento: " << a << endl;
//	else
//		cout << "Nao foi possivel inserir elemento" << endl;
////
////	cout << "Restam :"<< f.get_NroElementos()<<endl;
////	cout << "Primeiro : " << f.get_primeiro() <<endl;
////	cout << "Ultimo: " << f.get_ultimo() << endl;
//
//	ImprimeFilaAbrindoTV(f);

	//TESTE DA MESA
	FilaMonte f;
	PilhaCrescente c1, c2;
	PilhaDecrescente d1,d2;
	Mesa m;
	bool DeuCerto, ok;
	int op, n, p, carta, totalRestante = QUANT_CARTAS;  //Resolver sobre totalRestante : ele nao sera necessario ( diminui_NroElementos)

	cout<<"Fila Monte: ";
	f.ImprimeFilaAbrindoTV();
	cout << endl;
//	m.ImprimeMesaAbrindoTV();
	m.PrimeiraDistribuicao(f,DeuCerto);
	//m.ImprimeMesaAbrindoTV();
	op = 2;
	while(op!=0){
		if(m.get_NroElementos() == 6)
			m.NovaDistribuicao(f, DeuCerto);
		cout << "Mesa: ";
		m.ImprimeMesaAbrindoTV();
		cout << "Pilha Crescente 1: ";
		ImprimePilha(c1, totalRestante);
		cout << "Pilha Crescente 2: ";
		ImprimePilha(c2, totalRestante);
		cout << "Pilha Decrescente 1: ";
		ImprimePilha(d1, totalRestante);
		cout << "Pilha Decrescente 2: ";
		ImprimePilha(d2, totalRestante);

		cout << "Digite 1 para remover da mesa e 0 para sair: "<<endl;
		cin >> op;
		switch(op){
		case 1:
			cout << "Digite o numero que deseja remover da mesa: " << endl;
			cin >> n;
			carta = m.removeMesa(n, DeuCerto);
			if(carta!=0){
				cout << "Digite em qual pilha voce deseja colocar a carta "<< carta << ":" <<endl;
				cout << "(1) para Crescente 1" << endl;
				cout << "(2) para Crescente 2" << endl;
				cout << "(3) para Decrescente 1" << endl;
				cout << "(4) para Decrescente 2" << endl;
				cin >> p;
				totalRestante = f.get_NroElementos(); // LINHA DEVERA SER APAGADA
				switch(p){
				case 1:

					c1.Empilha(carta, DeuCerto, totalRestante);
					break;
				case 2:
					c2.Empilha(carta, DeuCerto, totalRestante);
					break;
				case 3:
					d1.Empilha(carta, DeuCerto, totalRestante);

					break;
				case 4:
					d2.Empilha(carta, DeuCerto, totalRestante);
					break;
				default:
					DeuCerto = false;
					cout << "Pilha invalida! Carta de volta para a mesa!" << endl;
				}
				if(DeuCerto)
					f.diminui_NroElementos();
				else
					m.insereMesa(carta, DeuCerto);

			}

			break;
		}

	}
	cout << "Saindo...";
//	m.insereMesa(9, DeuCerto);
//	m.ImprimeMesaAbrindoTV();
//	m.insereMesa(8, DeuCerto);
//	m.ImprimeMesaAbrindoTV();
//	m.insereMesa(7, DeuCerto);
//	m.ImprimeMesaAbrindoTV();
//	m.removeMesa(8, DeuCerto);
//	m.ImprimeMesaAbrindoTV();
//	m.removeMesa(10, DeuCerto);
//	m.ImprimeMesaAbrindoTV();




	return 0;
}
