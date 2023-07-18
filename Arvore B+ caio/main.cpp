#include <iostream>
#include "arvore_b.h"

using namespace std;

void exibirMenu() {
    cout << "\nMenu de Op��es:" << endl;
    cout << "1. Inserir chave" << endl;
    cout << "2. Remover chave" << endl;
    cout << "3. Buscar chave" << endl;
    cout << "4. Imprimir �rvore" << endl;
    cout << "5. Sair" << endl;
}

int main() {
    int grau;
    cout << "Digite o grau da �rvore B+: ";
    cin >> grau;

    ArvoreBMais arvore(grau);

    int opcao;
    int chave;

    do {
        exibirMenu();
        cout << "Digite a op��o desejada: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite a chave a ser inserida: ";
                cin >> chave;
                arvore.inserir(chave);
                cout << "Chave inserida com sucesso." << endl;
                break;
            case 2:
                cout << "Digite a chave a ser removida: ";
                cin >> chave;
                arvore.remover(chave);
                cout << "Chave removida com sucesso." << endl;
                break;
            case 3:
                cout << "Digite a chave a ser buscada: ";
                cin >> chave;
                No* resultado = arvore.buscar(chave);
                if (resultado != nullptr) {
                    cout << "Chave encontrada." << endl;
                } else {
                    cout << "Chave n�o encontrada." << endl;
                }
                break;
            case 4:
                cout << "�rvore B+:" << endl;
                arvore.imprimirArvore();
                break;
            case 5:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Op��o inv�lida." << endl;
                break;
        }

        cout << endl;
    } while (opcao != 5);

    return 0;
}

