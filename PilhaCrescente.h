#ifndef PILHACRESCENTE_H
#define PILHACRESCENTE_H
#include <iostream>
#include "PilhaBurra.h"
using namespace std;

class PilhaCrescente: public PilhaBurra{
	public:
		PilhaCrescente();
		~PilhaCrescente();
		void Empilha(int, bool &, int &);
};

#endif //PILHACRESCENTE_H
