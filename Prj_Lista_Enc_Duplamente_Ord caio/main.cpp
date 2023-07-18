#include "lista.h"

void menu(){ 
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "\t  MENU" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;		
		cout << "1 - Insere Ordenado" << endl;
		cout << "2 - Retira Inicio" << endl;			
		cout << "3 - Retira Fim" << endl;
		cout << "4 - Retira elemento na lista" << endl;
		cout << "5 - Imprime Inicio->Fim" << endl;
		cout << "6 - Imprime Fim->Inicio" << endl;	
		cout << "7 - Busca elemento na lista" << endl;									
		cout << "->";

	}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	int op(0),x;
	Lista l;
	do{
		menu();
		cin >> op;
		switch(op){
			case 1:
				cout << "Insira um número: ";
				cin >> x;
				l.insere_ordenado(x);
				break;
				
			case 2:
				l.retira_inicio();
				break;
				
			case 3:
				l.retira_fim();
				break;
				
			case 4:
				cout << "Diga um número para retirar: ";
				cin >> x;
				l.retira(x);
				break;
				
			case 5:
				l.imprime_fim_inicio();
				break;
				
			case 6:
				l.imprime_inicio_fim();
				break;
				
			case 7:
				cout << "Diga o número para ser buscado: ";
				cin >> x;
				l.busca_valor(x);
				break;
				
			default:
				cout << "\nOpção inválidaaaa!";
				return 0;
		}
		
	}while(op>=1 && op<=7);
	menu();
	return 0;
}
