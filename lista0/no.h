class No
{
	public:
		int chave;
		No* prox;

		//Construtores
		No()
		{
			prox = 0;
		}

		No(int c, No* p = 0)
		{
			chave = c;
			prox = p;
		}
};