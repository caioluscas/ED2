#include "abb.h"
#include <conio.h>


/* Prof. Irineu - Est. de Dados
Projeto de base para implementa��o de �rvore Bin�ria de Busca (AVL). Sup�e-se:
- main.cpp: front-end com usu�rio;
- abb.h e abb.cpp: prototipa��o OO de m�todos de manipula��o da �rvore bin�ria de busca (abb),
 contendo defini��o "struct" do n�-dado (campos info, filho_esquerda e filho_direita; como 
 tamb�m os m�todos de manipula��o como biblioteca OO.
Dica: refer�ncia de muitos m�todos em: 
 https://www.ic.unicamp.br/~rocha/teaching/2016s1/mc202/aulas/arvore-binaria-busca-01.pdf  
 Livro Robert Lafore, ED e Alg em Java - Ci�ncia Moderna, 2004.
Obs.: Recursos e m�todos adicionais � biblioteca dever�o ser desenvolvidos com base neste modelo.
*/
 
//fun��o de interface com o usu�rio, apenas para facilitar mensagens sobre o estado da �rvore 
void menu(){
	cout << "\n1- Insere\n";
	cout << "2- Imprimir\n";
	cout << "3- Busca\n";
	cout << "4- Quantidade de n�s\n";
	cout << "5.Imprime em Ordem\n";
	cout << "6.Imprime em Pre-Ordem\n";
	cout << "7.Imprime em Pos-Ordem\n";	
	cout << "8.Imprime em Nivel\n";			
	cout << "9.Nivel da Arvore\n";	
	cout << "10.Retira Valor\n";
	cout << "11.Balancear Arvore\n";	
	cout << "12.Reinicia\n";
	cout << "13.Sair\n";
}

void mensagem_arvore_vazia(bool t){
	cout << "�rvore est� ";
	if(t)
		cout << "vazia\n";
	else
		cout << "n�o-vazia\n";
}


int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	cout<<"\tPROGRAMA �RVORE BIN�RIA DE BUSCA OO";
	ArvBB tree; //instancia objeto conforme a classe, construtor faz root = NULL
	int op,x,i;
	int* arr = NULL;
	do{
		menu();
		cin >> op;
		switch(op){
			case 1:
				cout << "N�mero para colocar na �rvore: ";
				cin >> x;
				tree.insere(x);
				break;
				
			case 2:
				tree.displayTree(); 	 	
				break;
				
			case 3:
				cout << "N�mero para ser buscado: ";
				cin >> x;
				tree.busca(x);
				break;
				
			case 4:
				cout <<"\n"<< tree.qtdNos() << " nos na Arvore Bin�ria\n";
				break;
				
			case 5:
				tree.emOrdem(tree.getRoot());
				cout <<"\n";
				break;
				
			case 6:
				tree.preOrdem(tree.getRoot());
				cout<< "\n";
				break;
				
			case 7:
				tree.posOrdem(tree.getRoot());
				cout<<"\n";
				break;
				
			case 8:
				tree.emNivel(tree.getRoot());
				cout<<"\n";
				break;
				
			case 9:
				cout<<"N�vel da �rvore:"<<tree.nivel()<<"\n";
				break;
				
			case 10:
				cout<<"Diga o valor para ser retirado da arvore: ";
				cin>>x;
				tree.retira(x);
				break;
				
			case 11:
				tree.AddToArray(tree.getRoot(),arr,&i);
				tree.reiniciaTree();
				tree.balance(arr,0,tree.qtdNos()-1);
				
				break;
				
			case 12:
				tree.reiniciaTree();
				break;
				
			case 13:
				break;
				
			default:
				printf("Opcao errada amigo, adeus\n");
				printf("    _______    \n");
				printf("   /       \\   \n");
				printf("  /  o   o  \\  \n");
				printf(" |    (_)    | \n");
				printf("  \\    O    /  \n");
				printf("   \\_______/   \n");
			
		}
	}while(op>=1 && op<13);


	return 0;
}
