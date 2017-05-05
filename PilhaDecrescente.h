#ifndef PILHADECRESCENTE_H
#define PILHADECRESCENTE_H
#include <iostream>
#include "PilhaBurra.h"
using namespace std;

class PilhaDecrescente: public PilhaBurra{
	public:
		PilhaDecrescente();
		~PilhaDecrescente();
		void Empilha(int, bool &);
};

#endif //PILHADECRESCENTE_H
