#ifndef FILAMONTE_H
#define FILAMONTE_H
#include <iostream>
#include "PilhaBurra.h"


class FilaMonte {
public:
    FilaMonte();
    ~FilaMonte();
   //METODOS
    bool Vazia() const;
    bool Cheia() const;
    void Insere(int X, bool &DeuCerto);
    void Retira(int &X, bool &DeuCerto);
    void InicializaElementos();
    void EmbaralhaElementos();
    void ImprimeFilaAbrindoTV() const;


    //METODOS GET E SET
    void proximo_primeiro();
    int get_primeiro() const;
    void proximo_ultimo();
    int get_ultimo() const;
    void set_primeiro(int);

    int get_NroElementos() const;
    void diminui_NroElementos();
    void aumenta_NroElementos();

    void set_elemento_ultimo(int);
    int get_elemento_ultimo() const;
    int get_elemento_primeiro() const;
    //so para teste
    int get_elemento_X(int X) const;


private:
    int Elementos[QUANT_CARTAS];
    int NroElementos; // Fazer integracao com o totalRestante do MAIN.cpp
    int Primeiro;
    int Ultimo;
};

#endif // PILHABURRA_H
