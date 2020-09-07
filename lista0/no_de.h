class No
{
	public:
		int chave;
		No* prox;
        No* ant;

		//Construtores
		No()
		{
			prox = ant = 0;
		}

		No(int c, No* p = 0, No* a = 0)
		{
			chave = c;
			prox = p;
            ant = a;
		}
};