#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include "no_dado.h"

using namespace std;
class Lista{
	//Declarar atributos
	private:
		no_dado* cabeca; //controle de n� cabeca
		no_dado* cauda;
		int qtd; //guardar qtd de n�s encadeados
		
	//Declarando m�todos	
	public:
		Lista();
		void insere_ordenado(int i);
		void retira_inicio();
		void retira_fim();	
		void retira(int i);					
		void imprime_inicio_fim();
		void imprime_fim_inicio();
		void busca_valor(int i);			

	private:
		bool isEmpty(no_dado* l);//m?todo privado que auxiliar? verifica??o de lista vazia a partir de um ponteiro	
};

