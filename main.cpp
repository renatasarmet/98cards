#include "headers.h"

void ImprimePilha(pilha_burra &p) {
	int x;
	pilha_burra PAux;
	bool ok;
	while (p.Vazia() == false) {
		p.Desempilha(x, ok);
		if (ok) {
			PAux.Empilha(x, ok);
		}
	}

	cout << "Imprimindo a pilha" << endl;
	while (PAux.Vazia() == false) {
		PAux.Desempilha(x, ok);
		if (ok) {
			cout << x << " ";
			p.Empilha(x, ok);
		}
	}
	cout << "<-- topo" << endl;
}

bool VerificaGameOver(mesa m, pilha_crescente &c1, pilha_crescente &c2, pilha_decrescente &d1, pilha_decrescente &d2) {
	int i, carta;
	bool DeuCerto, ok;

	for (i = 0; i<TAMANHO_MESA; i++) {
		carta = m.get_elemento_i(i, DeuCerto);
		if (carta != 0) {
			ok = false;
			c1.Empilha(carta, DeuCerto);
			if (DeuCerto) {
				c1.Desempilha(carta, DeuCerto);
				ok = true;
			}
			else {
				c2.Empilha(carta, DeuCerto);
				if (DeuCerto) {
					c2.Desempilha(carta, DeuCerto);
					ok = true;
				}
				else {
					d1.Empilha(carta, DeuCerto);
					if (DeuCerto) {
						d1.Desempilha(carta, DeuCerto);
						ok = true;
					}
					else {
						d2.Empilha(carta, DeuCerto);
						if (DeuCerto) {
							d2.Desempilha(carta, DeuCerto);
							ok = true;
						}
					}
				}
			}
			if (ok)
				return false;
		}
	}
	return true;
}


bool VerificaGanhou(mesa m, fila_monte f) {
	int i;
	i = f.get_NroElementos() + m.get_NroElementos();
	if (i == 0) {
		return true;
	}
	return false;
}

int main() {
	fila_monte f;
	pilha_crescente c1, c2;
	pilha_decrescente d1, d2;
	mesa m;
	bool DeuCerto, podeDesfazer;
	int op, n, p, carta;

	cout << "Fila Monte: ";
	f.ImprimeFilaAbrindoTV();
	cout << endl;
	m.PrimeiraDistribuicao(f, DeuCerto);
	op = 100; //inicializando com um valor que nao existe
	while (op != 0) {
		if (m.get_NroElementos() == 6) {
			m.NovaDistribuicao(f, DeuCerto);
			podeDesfazer = false;
		}
		else if (m.get_NroElementos() == 8)
			podeDesfazer = false;


		cout << "Pilha Crescente 1: ";
		ImprimePilha(c1);
		cout << "Pilha Crescente 2: ";
		ImprimePilha(c2);
		cout << "Pilha Decrescente 1: ";
		ImprimePilha(d1);
		cout << "Pilha Decrescente 2: ";
		ImprimePilha(d2);
		cout << "Mesa: ";
		m.ImprimeMesaAbrindoTV();


		if (VerificaGanhou(m, f)) {
			cout << "Parabens! Voce venceu!!" << endl;
			op = 0;
			break;
		}
		else if (VerificaGameOver(m, c1, c2, d1, d2)) {
			cout << "GAME OVER! Tente novamente!" << endl;
			op = 0;
			break;
		}

		if (podeDesfazer)
			cout << "Digite 1 para remover da mesa, 2 para desfazer ultima jogada e 0 para sair: " << endl;
		else
			cout << "Digite 1 para remover da mesa e 0 para sair: " << endl;
		cin >> op;
		switch (op) {
		case 1:
			cout << "Digite o numero que deseja remover da mesa: " << endl;
			cin >> n;
			carta = m.removeMesa(n, DeuCerto);
			if (carta != 0) {
				cout << "Digite em qual pilha voce deseja colocar a carta " << carta << ":" << endl;
				cout << "(1) para Crescente 1" << endl;
				cout << "(2) para Crescente 2" << endl;
				cout << "(3) para Decrescente 1" << endl;
				cout << "(4) para Decrescente 2" << endl;
				cin >> p;
				switch (p) {
				case 1:

					c1.Empilha(carta, DeuCerto);
					break;
				case 2:
					c2.Empilha(carta, DeuCerto);
					break;
				case 3:
					d1.Empilha(carta, DeuCerto);

					break;
				case 4:
					d2.Empilha(carta, DeuCerto);
					break;
				default:
					DeuCerto = false;
					cout << "Pilha invalida! Carta de volta para a mesa!" << endl;
				}
				if (!DeuCerto)
					m.insereMesa(carta, DeuCerto);

			}

			break;
		case 2:
			if (podeDesfazer) {
				switch (p) {
				case 1:
					c1.Desempilha(carta, DeuCerto);
					break;
				case 2:
					c2.Desempilha(carta, DeuCerto);
					break;
				case 3:
					d1.Desempilha(carta, DeuCerto);

					break;
				case 4:
					d2.Desempilha(carta, DeuCerto);
					break;
				default:
					DeuCerto = false;
					cout << "Pilha invalida! Carta de volta para a mesa!" << endl;
				}
				if (DeuCerto)
					f.aumenta_NroElementos();
				m.insereMesa(carta, DeuCerto);
			}
			break;
		}
		podeDesfazer = true;

	}
	cout << "Saindo..." << endl;

	system("PAUSE");
	return 0;
}
