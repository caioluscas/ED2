#include "abb.h"
#include <conio.h>


/* Prof. Irineu - Est. de Dados
Projeto de base para implementação de Árvore Binária de Busca (AVL). Supõe-se:
- main.cpp: front-end com usuário;
- abb.h e abb.cpp: prototipação OO de métodos de manipulação da árvore binária de busca (abb),
 contendo definição "struct" do nó-dado (campos info, filho_esquerda e filho_direita; como 
 também os métodos de manipulação como biblioteca OO.
Dica: referência de muitos métodos em: 
 https://www.ic.unicamp.br/~rocha/teaching/2016s1/mc202/aulas/arvore-binaria-busca-01.pdf  
 Livro Robert Lafore, ED e Alg em Java - Ciência Moderna, 2004.
Obs.: Recursos e métodos adicionais à biblioteca deverão ser desenvolvidos com base neste modelo.
*/
 
//função de interface com o usuário, apenas para facilitar mensagens sobre o estado da árvore 
void menu(){
	cout << "\n1- Insere\n";
	cout << "2- Imprimir\n";
	cout << "3- Busca\n";
	cout << "4- Quantidade de nós\n";
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
	cout << "Árvore está ";
	if(t)
		cout << "vazia\n";
	else
		cout << "não-vazia\n";
}


int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	cout<<"\tPROGRAMA ÁRVORE BINÁRIA DE BUSCA OO";
	ArvBB tree; //instancia objeto conforme a classe, construtor faz root = NULL
	int op,x,i;
	int* arr = NULL;
	do{
		menu();
		cin >> op;
		switch(op){
			case 1:
				cout << "Número para colocar na árvore: ";
				cin >> x;
				tree.insere(x);
				break;
				
			case 2:
				tree.displayTree(); 	 	
				break;
				
			case 3:
				cout << "Número para ser buscado: ";
				cin >> x;
				tree.busca(x);
				break;
				
			case 4:
				cout <<"\n"<< tree.qtdNos() << " nos na Arvore Binária\n";
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
				cout<<"Nível da árvore:"<<tree.nivel()<<"\n";
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
