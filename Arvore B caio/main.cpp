#include <iostream>
#include "header.h"

using namespace std;

int main() {
    int grau;
    cout << "Informe o grau da arvore: ";
    cin >> grau;

    ArvoreMultiplaB arvore(grau);

    int opcao, chave;

    do {
        cout << "\nMenu de Opcoes:" << endl;
        cout << "1. Inserir chave" << endl;
        cout << "2. Remover chave" << endl;
        cout << "3. Buscar chave" << endl;
        cout << "4. Imprimir arvore" << endl;
        cout << "5. Sair" << endl;
        cout << "Digite a opcao desejada: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite a chave a ser inserida: ";
                cin >> chave;
                arvore.inserir(chave);
                break;
            case 2:
                cout << "Digite a chave a ser removida: ";
                cin >> chave;
                arvore.remover(chave);
                break;
            case 3:
                cout << "Digite a chave a ser buscada: ";
                cin >> chave;
                if (arvore.buscar(chave)) {
                    cout << "A chave " << chave << " foi encontrada na arvore." << endl;
                } else {
                    cout << "A chave " << chave << " nao foi encontrada na arvore." << endl;
                }
                break;
            case 4:
                cout << "Arvore:" << endl;
                arvore.imprimir();
                break;
            case 5:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida. Digite novamente." << endl;
                break;
        }
    } while (opcao != 5);

    return 0;
}

