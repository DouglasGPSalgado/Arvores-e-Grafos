#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "bibliotecaOrdenacao.h"

using namespace std;

int main() {
    srand(time(NULL));
    int tamanho;
    cout << "Informe o tamanho do vetor: ";
    cin >> tamanho;

    vector<int> vetor(tamanho);
    cout << "Vetor original: ";
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000;
         cout << vetor[i] << " ";
    }
    cout << endl;
    int opcao = -1;
    while (opcao != 5) {
        cout << "------------------" << endl;
        cout << "MENU DE OPÇÕES" << endl;
        cout << "------------------" << endl;
        cout << "1 - Bubble Sort" << endl;
        cout << "2 - Selection Sort" << endl;
        cout << "3 - Insertion Sort" << endl;
        cout << "4 - Comparação" << endl;
        cout << "5 - Sair" << endl;;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        switch (opcao) {
            case 1:
                bubbleSort(vetor);
                cout << "Bubble Sort executado com sucesso!" << endl;
                cout << "Número de comparações: " << getNumComparacoes() << endl;
                cout << "Número de trocas: " << getNumTrocas() << endl;
                // imprimir o vetor ordenado
                cout << "Vetor ordenado: ";
                for (int i = 0; i < tamanho; i++) {
                    cout << vetor[i] << " ";
                }
                cout << endl;
                break;

            case 2:
                selectionSort(vetor);
                cout << "Selection Sort executado com sucesso!" << endl;
                cout << "Número de comparações: " << getNumComparacoes() << endl;
                cout << "Número de trocas: " << getNumTrocas() << endl;
                cout << "Vetor ordenado: ";
                for (int i = 0; i < tamanho; i++) {
                    cout << vetor[i] << " ";
                }
                cout << endl;
                break;

            case 3:
                insertionSort(vetor);
                cout << "Insertion Sort executado com sucesso!" << endl;
                cout << "Número de comparações: " << getNumComparacoes() << endl;
                cout << "Número de trocas: " << getNumTrocas() << endl;
                cout << "Vetor ordenado: ";
                for (int i = 0; i < tamanho; i++) {
                    cout << vetor[i] << " ";
                }
                cout << endl;
                break;

            case 4:
                int numComparacoesBubble, numTrocasBubble;
                int numComparacoesSelection, numTrocasSelection;
                int numComparacoesInsertion, numTrocasInsertion;

                // Bubble Sort
                bubbleSort(vetor);
                numComparacoesBubble = getNumComparacoes();
                numTrocasBubble = getNumTrocas();

                // Selection Sort
                selectionSort(vetor);
                numComparacoesSelection = getNumComparacoes();
                numTrocasSelection = getNumTrocas();

                // Insertion Sort
                insertionSort(vetor);
                numComparacoesInsertion = getNumComparacoes();
                numTrocasInsertion = getNumTrocas();

                cout << "Comparação entre os métodos de ordenação:" << endl;
                cout << "---------------------------------------" << endl;
                cout << "Bubble Sort: " << endl;
                cout << "Número de comparações: " << numComparacoesBubble << endl;
                cout << "Número de trocas: " << numTrocasBubble << endl;
                cout << "Selection Sort: " << endl;
                cout << "Número de comparações: " << numComparacoesSelection << endl;
                cout << "Número de trocas: " << numTrocasSelection << endl;
                cout << "Insertion Sort: " << endl;
                cout << "Número de comparações: " << numComparacoesInsertion << endl;
                cout << "Número de trocas: " << numTrocasInsertion << endl;

                if (numTrocasBubble <= numTrocasSelection && numTrocasBubble <= numTrocasInsertion) {
                    cout << "Bubble Sort foi o método que realizou menos trocas." << endl;
                } else if (numTrocasSelection <= numTrocasBubble && numTrocasBubble <= numTrocasInsertion) {
                    cout << "Selevtion sort foi o método que realizou menos trocas." << endl;
                } else if (numTrocasInsertion <= numTrocasSelection && numTrocasInsertion <= numTrocasBubble) {
                    cout << "Insert Sort foi o método que realizou menos trocas." << endl;
                }
                break;
                case 5:
                cout << "Saindo do programa..." << endl;
                break;

            default:
                cout << "Opção inválida! Tente novamente." << endl;
        };
    };
};
            