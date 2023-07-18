class no_dado{
	//Declarar atributos
	public:
		int info;
		no_dado* prox;
		
	public:
		no_dado(); //construtor sem passagem de parâmetros
		no_dado(int i, no_dado* l); //construtor com passagem de parâmetros	
};
