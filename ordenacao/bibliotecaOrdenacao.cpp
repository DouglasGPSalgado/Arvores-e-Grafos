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

int getNumComparacoes() {
    return numComparacoes;
}

int getNumTrocas() {
    return numTrocas;
}
