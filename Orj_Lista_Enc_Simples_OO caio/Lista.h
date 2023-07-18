//Lista.h
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include "no_dado.h"
using namespace std;

class Lista{
	//Declarar atributos
	private:
		no_dado* cabeca; //controla a lista (nó-cabeça)
		int qtd; //guarda a qtd de nós na lista
	
	//Declara métodos
	public:
		Lista(); //Construtor - inicializar a lista em NULL
		~Lista(); //Destrutor - invocar método libera
		void insere_inicio(int i); //Inserir dado i no início da Lista
		void imprime(); //Imprime a lista do início para o fim
		void imprime_inicio();
		void imprime_fim();
		bool vazia(); //retornar bool se lista é vazia
		void busca(int i); //Busca i na Lista, retornando bool
		bool retira(int i); //Remove 1a ocorrência de i, retornando true caso encontre
		void retira_inicio();
		void retira_fim();
		void insere_fim(int i);
		int size(); //Retorna a qtd de nós na lista
		void libera(); //Libera a lista

	private:
		bool isEmpty(no_dado* l); //Método privado que auxiliará verificação de lista vazia a partir de dada referência	
};
