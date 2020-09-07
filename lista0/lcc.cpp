#include "lcc.h"

//Construtor: constrói uma lista vazia
LCC::LCC()
{
	cabeca = cauda = new No();
	numeroDeNos = 0;
}

//Método para inserir um novo elemento na lista logo após
void LCC::insereCabeca(int novaChave)
{
	cabeca->prox = new No(novaChave, cabeca->prox);

	if (!cabeca->prox->prox)//if (cabeca == cauda)
		cauda = cabeca->prox;

	numeroDeNos++;
}

//Método para imprimir a lista
void LCC::imprime()
{
	//Verifica se a lista vazia
	if (!cabeca->prox)// cabeca->prox == 0
		cout << "Lista vazia";
	else
		for (No* ptr = cabeca->prox; ptr != 0; ptr = ptr->prox)
			cout << ptr->chave << " ";

	cout << endl;
}

//Remoção
int LCC::removeChave(int chave)
{
	/*No* atual;
	No* ant;

	atual = cabeca->prox;
	ant = cabeca;

	while (atual && atual->chave != chave)
	{
		ant = atual;
		atual = atual->prox;
	}

	//Se eu encontrei
	if (atual)
	{
		int val = atual->chave;
		ant->prox = atual->prox;

		if (atual == cauda)
			cauda = ant;

		delete atual;

		return val;
	}
	else
		return INT_MAX;*/

	int val = INT_MAX;

	No* ant = buscaAntecessor(chave);

	if (ant)
	{//Encontrei, vou remover
		No* lixo = ant->prox;
		val = lixo->chave;
		ant->prox = lixo->prox;

		if (lixo == cauda)
			cauda = ant;

		delete lixo;
		numeroDeNos--;
	}

	return val;
}

int LCC::remove_cabeca()
{
	int val = INT_MAX;

	if (cabeca->prox)
	{
		No* ptr = cabeca->prox;
		val = ptr->chave;
		cabeca->prox = ptr->prox;

		if (ptr == cauda)
			cauda = cabeca;

		delete ptr;
		numeroDeNos--;
	}

	return val;
}

int LCC::remove_cauda()
{
	int val = INT_MAX;
	No* ptr = cabeca;
	No* no = cauda;

	if (cabeca->prox) {
		while (ptr->prox != no)
			ptr = ptr->prox;
		ptr->prox = NULL;
		cauda = ptr;
		val = no->chave;
		delete no;
		numeroDeNos--;
	}
	return val;
}

void LCC::remove_no(int chave)
{
	No* no = buscaNo(chave);
	if (no != NULL) {
		No* ptr = cabeca;

		while (ptr->prox != no)
			ptr = ptr->prox;

		ptr->prox = no->prox;
		delete no;
		numeroDeNos--;
	}
}

bool LCC::estaNaLCC(int chave)
{
	No* ptr = cabeca;

	while (ptr->prox && ptr->chave != chave)
		ptr = ptr->prox;

	return ptr->chave == chave;

}

No* LCC::buscaNo(int chave)
{
	No* ptr = cabeca;

	while (ptr->prox && ptr->chave != chave)
		ptr = ptr->prox;

	return ptr->chave == chave ? ptr : NULL;
}

No* LCC::buscaAntecessor(int chave)
{
	No* ptr = cabeca;

	while (ptr->prox && ptr->prox->chave != chave)
		ptr = ptr->prox;

	if (!ptr->prox)
		return 0;

	return ptr;
}

//Destrutor
LCC::~LCC()
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