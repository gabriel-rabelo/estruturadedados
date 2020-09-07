#include "lsc.cpp"

int main()
{
	//Cria a lista
	LSC* lista = new LSC();//lista = (LCC*) malloc(sizeof(LCC));

	lista->imprime();

	lista->insereCabeca(10);
	lista->insereCabeca(11);
	lista->insereCabeca(12);
	lista->insereCabeca(13);
	lista->insereCabeca(14);
	lista->insereCabeca(15);

	lista->imprime();

	lista->remove_no(10);
	lista->remove_no(11);

	lista->imprime();

	//Libero a lista
	delete lista;//free(lista);

	return 0;
}