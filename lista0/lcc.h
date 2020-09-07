#include "no.h"
#include <iostream>
#include <limits.h>

using namespace std;

class LCC
{
	public:
		No* cabeca;
		No* cauda;//Defini que quando a lista estiver vazia, ela vai apontar para o nó cabeça
		int numeroDeNos;
		//Construtor: constrói uma lista vazia
		LCC();

		//Método para inserir um novo elemento na lista logo após
		void insereCabeca(int);

		//Método para imprimir a lista
		void imprime();

		//Remoção
		int removeChave(int);

		//Exercício 1
		int remove_cabeca();

		//Exercício 3
		int remove_cauda();

		//Exercício 5
		void remove_no(int);

		//Exercício 4
		bool estaNaLCC(int);

		//Exercício 5
		No* buscaNo(int);

		//Exercício 5: busca chave e retor antecessor
		No* buscaAntecessor(int);
		
		//Destrutor
		~LCC();
};