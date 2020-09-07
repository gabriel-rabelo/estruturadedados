#include <iostream>
#include <limits.h>
#include "no.h"

using namespace std;

class LSC
{
    public:
        No* inicio;
        int numeroDeNos;

        LSC();

        void insereCabeca(int);

        void imprime();

        int removeChave(int);

        int remove_inicio();

        void remove_no(int);

        bool estaNaLSC(int);

        No* buscaNo(int);

        No* buscaAntecessor(int);

        ~LSC();
};