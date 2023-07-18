#include "Lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void menu(){
	cout << "\n################################################\n";
	cout << "# 			MENU                   #\n";
	cout << "# 1 - Insere inicio                            #\n";
	cout << "# 2 - Insere fim                               #\n";
	cout << "# 3 - imprimir                                 #\n";
	cout << "# 4 - Size  				       #\n";
	cout << "# 5 - Buscar número		               #\n";
	cout << "# 6 - Retirar número			       #\n";
	cout << "# 7 - Retira inicio			       #\n";
	cout << "# 8 - Retira fim			       #\n";
	cout << "# 9 - Imprime inicio			       #\n";
	cout << "# 10 - Imprime fim		               #";
	cout << "\n################################################\n";
	cout << "-> ";
}
/*void teste(Lista l){
	int o = 0;
	do{
		o++;
		l.insere_inicio(3);
		l.imprime();	
	}while(o<5);
	
}*/

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	cout << "\tPROGRAMA LISTA ENCADEADA SIMPLES " << endl;
	Lista l; //instanciando o objeto l conforme a classe Lista
	int op=0, x;
	do{
		//teste(l);
		menu();
		cin >> op;
		switch(op){
			case 1:
				cout << "Insira um numero no inicio: ";
				cin >> x;
				l.insere_inicio(x);
				break;
				
			case 2:
				cout << "Insira um número no fim: ";
				cin >> x;
				l.insere_fim(x);
				break;
				
			case 3:
				cout << "\nImprimindo brother :)\n";
				l.imprime();
				break;
				
			case 4:
				l.size();
				break;
				
			case 5:
				cout << "Diga um número para buscar: ";
				cin >> x;
				l.busca(x);
				break;
				
			case 6:
				cout << "Diga um número para retirar: ";
				cin >> x;
				l.retira(x);
				break;
				
			case 7:
				l.retira_inicio();
				break;
				
			case 8:
				l.retira_fim();
				break;
				
			case 9:
				l.imprime_inicio();
				break;
				
			case 10:
				l.imprime_fim();
				break;
				
			default: 
				cout << "Opção inváliza mano :(\n";
				break;
		}
	}while(op>=1 && op<=10);
}
