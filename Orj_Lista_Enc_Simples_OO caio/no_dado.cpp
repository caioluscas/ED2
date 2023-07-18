//no_dado.cpp
#include "no_dado.h"

no_dado::no_dado(){ //Construtor - inicializar atributos em NULL
	this->info = 0;
	this->prox = 0; //NULL
}

no_dado::no_dado(int i, no_dado* l){ //construtor com passagem de parâmetros	
	this->info = i;
	this->prox = l;
}
