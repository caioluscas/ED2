#ifndef HEADER_H
#define HEADER_H

#include <iostream>

class ArvoreMultiplaB {
public:
    ArvoreMultiplaB(int grau);

    void inserir(int chave);
    void remover(int chave);
    bool buscar(int chave);
    void imprimir();

private:
    struct No {
        int *chaves;
        No **filhos;
        int numChaves;
        bool folha;

        No(int grau, bool folha);
        ~No();
    };

    No *raiz;
    int grau; // Membro 'grau' adicionado aqui

    void dividirFilho(No* pai, int indice, No* filho);
    int encontrarChave(No *no, int chave);
    int getSucessor(No *no, int indice);
    int getAntecessor(No *no, int indice);
    void inserirNoNaoCheio(No *no, int chave);
    void removerChave(No *no, int chave);
    void removerFolha(No *no, int indice);
    void removerNoInterno(No *no, int indice);
    void preencher(No *no, int indice);
    void emprestarAntecessor(No *no, int indice);
    void emprestarSucessor(No *no, int indice);
    void merge(No *no, int indice);
    bool buscarNo(No *no, int chave);
    void imprimirNo(No *no);
};

#endif

