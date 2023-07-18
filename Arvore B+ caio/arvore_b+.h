#include <iostream>
#include <vector>

using namespace std;

const int MAX_CHAVES = 3;

class No {
public:
    vector<int> chaves;
    vector<No*> filhos;
    No* proximo;
    bool folha;

    No(bool folha = false);
};

class ArvoreBMais {
private:
    No* raiz;
    int grau;

public:
    ArvoreBMais(int grau);
    void inserir(int chave);
    void remover(int chave);
    No* buscar(int chave);
    void exibirMenu();

private:
    void dividirFilho(No* pai, int indice, No* filho);
    void inserirNaoCheio(No* no, int chave);
    void removerChave(No* no, int chave);
    void removerNoFolha(No* no, int indice);
    void removerNoNaoFolha(No* no, int indice);
    int encontrarPredecessor(No* no, int indice);
    int encontrarSucessor(No* no, int indice);
    void preencher(No* no, int indice);
    void pegarEmprestadoDoAnterior(No* no, int indice);
    void pegarEmprestadoDoProximo(No* no, int indice);
    void mesclarNos(No* no, int indice);
    No* buscarNo(No* no, int chave);
    void percorrer(No* no);
};

