#include "lsc.h"

LSC::LSC ()
{
    inicio = 0;
    numeroDeNos = 0;
}

void LSC::insereCabeca(int novaChave) {
    if (inicio) {
        No* no = new No(novaChave, inicio);
        inicio = no;
        numeroDeNos++;
    } else {
        inicio = new No(novaChave, NULL);
        numeroDeNos++;
    }
}

void LSC::imprime()
{
    if (!inicio) 
        cout << "Lista vazia";
    else
        for (No* ptr = inicio; ptr != 0; ptr = ptr->prox)
            cout << ptr->chave << " ";
    cout << endl;
}

int LSC::removeChave(int chave)
{
    int val = INT_MAX;

    if (inicio->chave == chave) {
        No* lixo = inicio;
        val = inicio->chave;
        inicio = inicio->prox;
        delete lixo;
        numeroDeNos--;
        return val;
    }

    No* ant = buscaAntecessor(chave);

    if (ant)
    {
        No* lixo = ant->prox;
        val = lixo->chave;
        ant->prox = lixo->prox;

        delete lixo;
        numeroDeNos--;
    }
    
    return val;
}

int LSC::remove_inicio()
{
    int val = INT_MAX;

    if(numeroDeNos == 0)
        return val;
    
    No* lixo = inicio;
    val = inicio->chave;
    inicio = inicio->prox;
    delete lixo;
    numeroDeNos--;

    return val;
}

void LSC::remove_no(int chave)
{
    No* no = buscaNo(chave);
    if (no != NULL) {
        if (no == inicio)
            remove_inicio();
        else {
            No* ptr = inicio;

            while (ptr->prox != no)
                ptr = ptr->prox;
            
            ptr->prox = no->prox;
            delete no;
            numeroDeNos--;
        }
    }
}

bool LSC::estaNaLSC(int chave)
{
    No* ptr = inicio;

    while (ptr->prox && ptr->chave != chave)
        ptr = ptr->prox;

    return ptr->chave == chave;
}

No* LSC::buscaNo(int chave)
{
    No* ptr = inicio;
    while (ptr->prox && ptr->chave != chave)
        ptr = ptr->prox;

    return ptr->chave == chave ? ptr : NULL;
}

No* LSC::buscaAntecessor(int chave)
{
    No* ptr = inicio;

    while (ptr->prox && ptr->prox->chave != chave)
        ptr = ptr->prox;

    return !ptr->prox ? 0 : ptr;
}

LSC::~LSC()
{
    cout << "Destruindo a lista\n";
    for (No* ptr = inicio; ptr != 0;)
    {
        cout << "Liberando o " << ptr->chave << endl;
        No* aux = ptr->prox;

        delete ptr;

        ptr = aux;
    }
}