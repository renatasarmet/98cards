#ifndef MESA_H
#define MESA_H
#include <iostream>
#include "FilaMonte.h"
#define TAMANHO_MESA 8


class Mesa {
public:
    Mesa();
    ~Mesa();
   //METODOS
    bool Vazia() const;
    bool Cheia() const;
    bool insereMesa (int X, bool &DeuCerto);
    int removeMesa(int X, bool &DeuCerto);
    void LimpaMesa();
    void distribuicao (FilaMonte &f, int quantidade);
    void NovaDistribuicao(FilaMonte &f, bool &DeuCerto);
    void PrimeiraDistribuicao (FilaMonte &f, bool &DeuCerto);
    void ImprimeMesaAbrindoTV() const;

    //METODOS GET E SET
    int get_NroElementos() const;
    void set_NroElementos(int );
    void diminui_NroElementos();
    void aumenta_NroElementos();



    int get_elemento_i(int i, bool &DeuCerto) const;
    void set_elemento_i(int i, int X, bool &DeuCerto);


private:
    int Elementos[TAMANHO_MESA];
    int NroElementos;
};

#endif // MESA_H
