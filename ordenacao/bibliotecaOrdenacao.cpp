#include "bibliotecaOrdenacao.h"

int numTrocas, numComparacoes;

void bubbleSort(std::vector<int> &v) {
    int tamanho = v.size();
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            numComparacoes++;
            if (v[j] > v[j + 1]) {
                numTrocas++;
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void selectionSort(std::vector<int> &v) {
    int tamanho = v.size();
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMinimo = i;
        for (int j = i + 1; j < tamanho; j++) {
            numComparacoes++;
            if (v[j] < v[indiceMinimo]) {
                indiceMinimo = j;
            }
        }
        numTrocas++;
        int temp = v[i];
        v[i] = v[indiceMinimo];
        v[indiceMinimo] = temp;
    }
}

void insertionSort(std::vector<int> &v) {
    int tamanho = v.size();
    for (int i = 1; i < tamanho; i++) {
        int j = i - 1;
        int chave = v[i];
        while (j >= 0 && v[j] > chave) {
            numComparacoes++;
            numTrocas++;
            v[j + 1] = v[j];
            j--;
        }
        numTrocas++;
        v[j + 1] = chave;
    }
}

void quickSort(std::vector<int> &v, int esquerda, int direita) {
    if (esquerda < direita) {
        int pivo = v[direita];
        int i = esquerda - 1;
        for (int j = esquerda; j < direita; j++) {
            if (v[j] < pivo) {
                i++;
                std::swap(v[i], v[j]);
                numTrocas++;
            }
            numComparacoes++;
        }
        std::swap(v[i + 1], v[direita]);
        numTrocas++;
        int posicao_pivo = i + 1;
        quickSort(v, esquerda, posicao_pivo - 1);
        quickSort(v, posicao_pivo + 1, direita);
    }
}

void merge(std::vector<int> &v, int inicio, int meio, int fim) {
    std::vector<int> temp(fim - inicio + 1);
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= fim) {
        numComparacoes++;
        if (v[i] < v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
        }
    }

    while (i <= meio) {
        temp[k++] = v[i++];
        numComparacoes++;
    }

    while (j <= fim) {
        temp[k++] = v[j++];
        numComparacoes++;

    }

    for (i = inicio; i <= fim; i++) {
        v[i] = temp[i - inicio];
        numComparacoes++;
        numTrocas++;
    }
}

void mergeSort(std::vector<int> &v, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

void heapify(std::vector<int> &v, int n, int i) {
    int maior = i; // Inicializar o maior como a raiz
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    // Se o filho da esquerda é maior que a raiz
    if (esq < n && v[esq] > v[maior]) {
        maior = esq;
        numComparacoes++;
    }

    // Se o filho da direita é maior que o maior até agora
    if (dir < n && v[dir] > v[maior]) {
        maior = dir;
        numComparacoes++;
    }

    // Se o maior não é a raiz
    if (maior != i) {
        std::swap(v[i], v[maior]);
        heapify(v, n, maior);
        numComparacoes++;
    }
}

void heapSort(std::vector<int> &v) {
    int n = v.size();

    // Construir a heap a partir do vetor
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }

    // Extrair os elementos da heap em ordem decrescente
    for (int i = n - 1; i > 0; i--) {
        std::swap(v[0], v[i]);
        heapify(v, i, 0);
        numTrocas++;
    }
}

int getNumComparacoes() {
    return numComparacoes;
}

int getNumTrocas() {
    return numTrocas;
}
