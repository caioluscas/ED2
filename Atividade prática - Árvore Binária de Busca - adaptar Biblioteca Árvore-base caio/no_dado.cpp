#include "no_dado.h"

NoArv::NoArv(){ //construtor
	this->dir=0;
	this->esq=0;
}

NoArv::NoArv(int i, NoArv*abb){
	this->info=i;
	this->esq=abb;
	this->dir=abb;
}
