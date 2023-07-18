//Lista.cpp

#include "Lista.h"

Lista::Lista(){ //Construtor - inicializar a lista em NULL
	this->cabeca = 0; //inicializa a lista vazia, mesmo que NULL
	this->qtd = 0;
}

Lista::~Lista(){ //Destrutor - invocar m�todo libera
	libera();
}

void Lista::insere_inicio(int i){ //Inserir dado i no in�cio da Lista
	no_dado* novo = (no_dado*) malloc(sizeof(no_dado));
 	novo->info = i;
 	novo->prox = this->cabeca;
 	this->cabeca = novo; //atualiza o cabe�a para apontar ao novo 1o n�-dado
 	this->qtd++; //incrementa contador de dados na Lista
}

void Lista::insere_fim(int i){
    if(this->isEmpty(this->cabeca)){
       insere_inicio(i);
    }
    else{
        no_dado* novo = new no_dado(i,NULL);
        no_dado* p;
        for(p = this->cabeca; p->prox != NULL; p = p->prox);
        p->prox = novo;
        this->qtd++;
    }
}

void Lista::imprime(){ //Imprime a lista do in�cio para o fim
	if(!isEmpty(this->cabeca)){
		no_dado* p; /* vari�vel auxiliar para percorrer a lista */
 		cout << "Info: ";
		for (p = this->cabeca; p != NULL; p = p->prox)
 			cout << p->info << " - ";
		cout << endl;
	} else {
		cout << "Lista eh vazia!" << endl;
	}
}

void Lista::imprime_inicio(){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p = this->cabeca;
		cout << "Inicio: " << p->info;
	} 
	else{
		cout << "Lista esta vazia brother";
	}
}

void Lista::imprime_fim(){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p = this->cabeca;
		for(p = this->cabeca; p->prox!=NULL; p = p->prox);
		cout << "Fim: " << p->info;
	}
	else{
		cout << "Lista vazia brother";
	}
}



bool Lista::vazia(){ //True se lista � vazia, false caso contr�rio
	return isEmpty(this->cabeca);
}

void Lista::busca(int i){ //Busca i na Lista, retornando bool
	no_dado* p = this->cabeca;
	int achou_mano = 0;
 	for (; p!=NULL; p=p->prox){
 		if (p->info == i){
		 	achou_mano = 1;
		 }
	 }
	 if(achou_mano==1){
	 	cout << "N�mero encontrado!";
	 }
	 else{
	 	cout << "N�mero n�o encontrado :(";
	 }
}

bool Lista::retira(int i){ //Remove 1a ocorr�ncia de i, retornando true caso encontre
	no_dado* ant = NULL; /* ponteiro para elemento anterior */
 	no_dado* p = this->cabeca; /* ponteiro para percorrer a lista*/
 	/* procura elemento na lista, guardando anterior */
 	while (p != NULL && p->info != i) {
 		ant = p;
 		p = p->prox;
 	}
 	/* verifica se achou elemento */
 	/* caso n�o achou, retorne false */
	if (p == NULL)
 		return 0; //false
 	
	/* sen�o, chou elemento para retirar e retorne true*/
 	if (ant == NULL) { /* retira elemento do inicio */
 		this->cabeca = p->prox;
 	}
 	else { /* retira elemento do meio da lista */
 		ant->prox = p->prox;
 	}
 	free(p); //desaloca o n�-dado
 	this->qtd--; //decrementa o contador de no-dados da lista
 	return 1; //true
}

void Lista::retira_inicio(){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p = this->cabeca;
		this->cabeca = p->prox;
		this->qtd--;
		cout << "Retirado do inicio: " <<p->info;
		free(p);
	}
	else{
		cout << "Lista vazia o mano";
	}
}

void Lista::retira_fim(){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p = this->cabeca;
		no_dado* ant = NULL;
		while(p->prox!=NULL){
			ant=p;
			p = p->prox;
		}
		if(ant==NULL){
			this->cabeca = p->prox;
		}
		else{
			ant->prox = p->prox;
		}
		
		this->qtd--;
		cout << "Elemento retirado do fim: " << p->info;
		free(p);
	}
	else{
		cout << "A lista ta vazia brother! ";
	}
}

int Lista::size(){ //Retorna a qtd de n�s na lista
	return this->qtd;
}

void Lista::libera(){ //Libera a lista
	no_dado* p = this->cabeca;
 	while (p != NULL) {
 		no_dado* t = p->prox; /* guarda refer�ncia para o pr�ximo elemento*/
 		free(p); /* libera a mem�ria apontada por p */
 		p = t; /* faz p apontar para o pr�ximo */
	}
	this->qtd = 0;
	this->cabeca = 0;
}

bool Lista::isEmpty(no_dado* l){ //M�todo privado que auxiliar� verifica��o de lista vazia a partir de dada refer�ncia	
	return l==NULL;
}



