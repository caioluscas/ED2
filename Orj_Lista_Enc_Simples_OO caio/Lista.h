//Lista.h
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include "no_dado.h"
using namespace std;

class Lista{
	//Declarar atributos
	private:
		no_dado* cabeca; //controla a lista (n�-cabe�a)
		int qtd; //guarda a qtd de n�s na lista
	
	//Declara m�todos
	public:
		Lista(); //Construtor - inicializar a lista em NULL
		~Lista(); //Destrutor - invocar m�todo libera
		void insere_inicio(int i); //Inserir dado i no in�cio da Lista
		void imprime(); //Imprime a lista do in�cio para o fim
		void imprime_inicio();
		void imprime_fim();
		bool vazia(); //retornar bool se lista � vazia
		void busca(int i); //Busca i na Lista, retornando bool
		bool retira(int i); //Remove 1a ocorr�ncia de i, retornando true caso encontre
		void retira_inicio();
		void retira_fim();
		void insere_fim(int i);
		int size(); //Retorna a qtd de n�s na lista
		void libera(); //Libera a lista

	private:
		bool isEmpty(no_dado* l); //M�todo privado que auxiliar� verifica��o de lista vazia a partir de dada refer�ncia	
};
