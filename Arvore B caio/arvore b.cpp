#include "header.h"

using namespace std;

ArvoreMultiplaB::ArvoreMultiplaB(int grau) {
    this->grau = grau;
    raiz = new No(grau, true);
}

void ArvoreMultiplaB::inserir(int chave) {
    No *raiz = this->raiz;

    if (raiz->numChaves == 2 * grau - 1) {
        No *novoNo = new No(grau, false);
        novoNo->filhos[0] = raiz;
        this->raiz = novoNo;
        inserirNoNaoCheio(novoNo, chave);
    } else {
        inserirNoNaoCheio(raiz, chave);
    }
}

void ArvoreMultiplaB::inserirNoNaoCheio(No *no, int chave) {
    int i = no->numChaves - 1;

    if (no->folha) {
        while (i >= 0 && chave < no->chaves[i]) {
            no->chaves[i + 1] = no->chaves[i];
            i--;
        }

        no->chaves[i + 1] = chave;
        no->numChaves++;
    } else {
        while (i >= 0 && chave < no->chaves[i]) {
            i--;
        }

        i++;
        if (no->filhos[i]->numChaves == 2 * grau - 1) {
            dividirFilho(no, i, no->filhos[i]);

            if (chave > no->chaves[i]) {
                i++;
            }
        }

        inserirNoNaoCheio(no->filhos[i], chave);
    }
}




void ArvoreMultiplaB::remover(int chave) {
    if (!raiz) {
        cout << "Arvore vazia." << endl;
        return;
    }

    removerChave(raiz, chave);

    if (raiz->numChaves == 0) {
        No *antigaRaiz = raiz;

        if (raiz->folha) {
            raiz = NULL;
        } else {
            raiz = raiz->filhos[0];
        }

        delete antigaRaiz;
    }
}


void ArvoreMultiplaB::removerChave(No *no, int chave) {
    int indice = encontrarChave(no, chave);

    if (indice < no->numChaves && no->chaves[indice] == chave) {
        if (no->folha) {
            removerFolha(no, indice);
        } else {
            removerNoInterno(no, indice);
        }
    } else {
        if (no->folha) {
            cout << "Chave " << chave << " nao encontrada na arvore." << endl;
            return;
        }

        bool flag = (indice == no->numChaves);

        if (no->filhos[indice]->numChaves < grau) {
            preencher(no, indice);
        }

        if (flag && indice > no->numChaves) {
            removerChave(no->filhos[indice - 1], chave);
        } else {
            removerChave(no->filhos[indice], chave);
        }
    }
}

void ArvoreMultiplaB::removerFolha(No *no, int indice) {
    for (int i = indice + 1; i < no->numChaves; i++) {
        no->chaves[i - 1] = no->chaves[i];
    }

    no->numChaves--;
}

void ArvoreMultiplaB::removerNoInterno(No *no, int indice) {
    int chave = no->chaves[indice];

    if (no->filhos[indice]->numChaves >= grau) {
        int antecessor = getAntecessor(no, indice);
        no->chaves[indice] = antecessor;
        removerChave(no->filhos[indice], antecessor);
    } else if (no->filhos[indice + 1]->numChaves >= grau) {
        int sucessor = getSucessor(no, indice);
        no->chaves[indice] = sucessor;
        removerChave(no->filhos[indice + 1], sucessor);
    } else {
        merge(no, indice);
        removerChave(no->filhos[indice], chave);
    }
}

int ArvoreMultiplaB::getAntecessor(No *no, int indice) {
    No *atual = no->filhos[indice];

    while (!atual->folha) {
        atual = atual->filhos[atual->numChaves];
    }

    return atual->chaves[atual->numChaves - 1];
}

int ArvoreMultiplaB::getSucessor(No *no, int indice) {
    No *atual = no->filhos[indice + 1];

    while (!atual->folha) {
        atual = atual->filhos[0];
    }

    return atual->chaves[0];
}

void ArvoreMultiplaB::preencher(No *no, int indice) {
    if (indice != 0 && no->filhos[indice - 1]->numChaves >= grau) {
        emprestarAntecessor(no, indice);
    } else if (indice != no->numChaves && no->filhos[indice + 1]->numChaves >= grau) {
        emprestarSucessor(no, indice);
    } else {
        if (indice != no->numChaves) {
            merge(no, indice);
        } else {
            merge(no, indice - 1);
        }
    }
}

void ArvoreMultiplaB::emprestarAntecessor(No *no, int indice) {
    No *filho = no->filhos[indice];
    No *irmao = no->filhos[indice - 1];

    for (int i = filho->numChaves - 1; i >= 0; i--) {
        filho->chaves[i + 1] = filho->chaves[i];
    }

    if (!filho->folha) {
        for (int i = filho->numChaves; i >= 0; i--) {
            filho->filhos[i + 1] = filho->filhos[i];
        }
    }

    filho->chaves[0] = no->chaves[indice - 1];

    if (!filho->folha) {
        filho->filhos[0] = irmao->filhos[irmao->numChaves];
    }

    no->chaves[indice - 1] = irmao->chaves[irmao->numChaves - 1];

    filho->numChaves++;
    irmao->numChaves--;
}

void ArvoreMultiplaB::emprestarSucessor(No *no, int indice) {
    No *filho = no->filhos[indice];
    No *irmao = no->filhos[indice + 1];

    filho->chaves[filho->numChaves] = no->chaves[indice];

    if (!filho->folha) {
        filho->filhos[filho->numChaves + 1] = irmao->filhos[0];
    }

    no->chaves[indice] = irmao->chaves[0];

    for (int i = 1; i < irmao->numChaves; i++) {
        irmao->chaves[i - 1] = irmao->chaves[i];
    }

    if (!irmao->folha) {
        for (int i = 1; i <= irmao->numChaves; i++) {
            irmao->filhos[i - 1] = irmao->filhos[i];
        }
    }

    filho->numChaves++;
    irmao->numChaves--;
}

void ArvoreMultiplaB::merge(No *no, int indice) {
    No *filho = no->filhos[indice];
    No *irmao = no->filhos[indice + 1];

    filho->chaves[grau - 1] = no->chaves[indice];

    for (int i = 0; i < irmao->numChaves; i++) {
        filho->chaves[i + grau] = irmao->chaves[i];
    }

    if (!filho->folha) {
        for (int i = 0; i <= irmao->numChaves; i++) {
            filho->filhos[i + grau] = irmao->filhos[i];
        }
    }

    for (int i = indice + 1; i < no->numChaves; i++) {
        no->chaves[i - 1] = no->chaves[i];
    }

    for (int i = indice + 2; i <= no->numChaves; i++) {
        no->filhos[i - 1] = no->filhos[i];
    }

    filho->numChaves += irmao->numChaves + 1;
    no->numChaves--;

    delete irmao;
}

bool ArvoreMultiplaB::buscar(int chave) {
    return buscarNo(raiz, chave);
}

bool ArvoreMultiplaB::buscarNo(No *no, int chave) {
    int i = 0;

    while (i < no->numChaves && chave > no->chaves[i]) {
        i++;
    }

    if (no->chaves[i] == chave) {
        return true;
    }

    if (no->folha) {
        return false;
    }

    return buscarNo(no->filhos[i], chave);
}

void ArvoreMultiplaB::imprimir() {
    if (raiz) {
        imprimirNo(raiz);
    } else {
        cout << "Arvore vazia." << endl;
    }
}

void ArvoreMultiplaB::imprimirNo(No *no) {
    int i;
    for (i = 0; i < no->numChaves; i++) {
        if (!no->folha) {
            imprimirNo(no->filhos[i]);
        }
        cout << " " << no->chaves[i];
    }

    if (!no->folha) {
        imprimirNo(no->filhos[i]);
    }
}

ArvoreMultiplaB::No::No(int grau, bool folha) {
    this->chaves = new int[2 * grau - 1];
    this->filhos = new No *[2 * grau];
    this->numChaves = 0;
    this->folha = folha;
}

ArvoreMultiplaB::No::~No() {
    delete[] chaves;
    delete[] filhos;
}

void ArvoreMultiplaB::dividirFilho(No* pai, int indice, No* filho) {
    int meio = grau / 2;

    No* novoFilho = new No(grau, filho->folha);
    novoFilho->numChaves = meio - 1;

    for (int i = 0; i < meio - 1; i++) {
        novoFilho->chaves[i] = filho->chaves[i + meio];
    }

    if (!filho->folha) {
        for (int i = 0; i < meio; i++) {
            novoFilho->filhos[i] = filho->filhos[i + meio];
        }
    }

    filho->numChaves = meio - 1;

    for (int i = pai->numChaves; i >= indice + 1; i--) {
        pai->filhos[i + 1] = pai->filhos[i];
    }

    pai->filhos[indice + 1] = novoFilho;

    for (int i = pai->numChaves - 1; i >= indice; i--) {
        pai->chaves[i + 1] = pai->chaves[i];
    }

    pai->chaves[indice] = filho->chaves[meio - 1];
    pai->numChaves++;
}


int ArvoreMultiplaB::encontrarChave(No* no, int chave) {
    int i = 0;
    while (i < no->numChaves && chave > no->chaves[i]) {
        i++;
    }
    return i;
}



