#ifndef PILHABURRA_H
#define PILHABURRA_H
#include <iostream>
#define QUANT_CARTAS 99


class PilhaBurra {
public:
    PilhaBurra();
    ~PilhaBurra();
   //METODOS
    bool Vazia() const;
    bool Cheia() const;
    void Empilha(int, bool &, int &);
    void Desempilha(int &, bool &, int &);

    //METODOS GET E SET
    void aumenta_topo();
    void diminui_topo();
    int get_topo() const;
    void set_topo(int);

    void set_elemento_topo(int);
    int get_elemento_topo() const;

private:
    int Elementos[QUANT_CARTAS];
    int topo;
};

#endif // PILHABURRA_H
