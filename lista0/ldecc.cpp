#include "ldecc.h"

LDECC::LDECC()
{
    cabeca = cauda = new No();
    numeroDeNos = 0;
}

void LDECC::insereCabeca(int novaChave)
{
    No* no = new No(novaChave, cabeca->prox, cabeca);
    
    if (numeroDeNos > 0) {
        cabeca->prox->ant = no;
        cabeca->prox = no;
    } else {
        cabeca->prox = no;
        cauda = cabeca->prox;
    }
    numeroDeNos++;
}

void LDECC::imprime()
{
    if (!cabeca->prox)
        cout << "Lista vazia";
    else
        for (No* ptr = cabeca->prox; ptr != 0; ptr = ptr->prox)
            cout << ptr->chave << " ";
    
    cout << endl;
}

int LDECC::removeChave(int chave)
{
    int val = INT_MAX;
    No* no = buscaNo(chave);

    if (no)
    {
        val = no->chave;
        no->prox->ant = no->ant;
        no->ant->prox = no->prox;

        delete no;
        numeroDeNos--;
    }

    return val;
}

int LDECC::remove_cabeca()
{
    int val = INT_MAX;

    if(cabeca->prox)
    {
        No* ptr = cabeca->prox;
        val = ptr->chave;
        ptr->prox->ant = ptr->ant;
        ptr->ant->prox = ptr->prox;

        if (ptr == cauda)
            cauda = cabeca;
        
        delete ptr;
        numeroDeNos--;
    }

    return val;
}

int LDECC::remove_cauda()
{
    int val = INT_MAX;
    No* lixo;

    if (cabeca->prox)
        lixo = cauda;
    
    cauda->ant->prox = cauda->prox;
    cauda = cauda->ant;
    numeroDeNos--;
    val = lixo->chave;
    delete lixo;
    return val;
}

void LDECC::remove_no(int chave)
{
    No* lixo = buscaNo(chave);
    if (lixo != NULL) {
        lixo->prox->ant = lixo->ant;
        lixo->ant->prox = lixo->prox;
        numeroDeNos--;
        delete lixo;
    }
}

bool LDECC::estaNaLDECC(int chave)
{
    No* ptr = cabeca;

    while (ptr->prox && ptr->chave != chave)
        ptr = ptr->prox;
    return ptr->chave == chave;
}

No* LDECC::buscaNo(int chave)
{
    No* ptr = cabeca;

    while (ptr->prox && ptr->chave != chave)
        ptr = ptr->prox;

    return ptr->chave == chave ? ptr : NULL;
}

No* LDECC::buscaAntecessor(int chave)
{
    /*No* ptr = cabeca;

	while (ptr->prox && ptr->prox->chave != chave)
		ptr = ptr->prox;

	if (!ptr->prox)
		return 0;

	return ptr;*/
    return buscaNo(chave)->ant;
}

LDECC::~LDECC()
{
    cout << "Destruindo a lista\n";
    for (No* ptr = cabeca->prox; ptr != 0;)
    {
        cout << "Liberando o " << ptr->chave << endl;
        No* aux = ptr->prox;

        delete ptr;

        ptr = aux;
    }

    cout << "Liberando a cabeça " << endl;
    delete cabeca; 
}