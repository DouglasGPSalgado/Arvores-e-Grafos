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
    while (opcao != 7) {
        cout << "------------------" << endl;
        cout << "MENU DE OPÇÕES" << endl;
        cout << "------------------" << endl;
        cout << "1 - Bubble Sort" << endl;
        cout << "2 - Selection Sort" << endl;
        cout << "3 - Insertion Sort" << endl;
        cout << "4 - Quick Sort" << endl;
        cout << "5 - Merge Sort" << endl;
        cout << "6 - Heap Sort" << endl;
        cout << "7 - Comparação" << endl;
        cout << "8 - Sair" << endl;;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        switch (opcao) {
            case 1:
                numTrocas = 0;
                numComparacoes = 0;
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
                numTrocas = 0;
                numComparacoes = 0;
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
                numTrocas = 0;
                numComparacoes = 0;
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
                numTrocas = 0;
                numComparacoes = 0;
                quickSort(vetor, 0, tamanho - 1);
                cout << "Quick Sort executado com sucesso!" << endl;
                cout << "Número de comparações: " << getNumComparacoes() << endl;
                cout << "Número de trocas: " << getNumTrocas() << endl;
                cout << "Vetor ordenado: ";
                for (int i = 0; i < tamanho; i++) {
                    cout << vetor[i] << " ";
                }
                cout << endl;
                break;

                case 5:
                numTrocas = 0;
                numComparacoes = 0;
                mergeSort(vetor, 0, tamanho - 1);
                cout << "Merge Sort executado com sucesso!" << endl;
                cout << "Número de comparações: " << getNumComparacoes() << endl;
                cout << "Número de trocas: " << getNumTrocas() << endl;
                cout << "Vetor ordenado: ";
                for (int i = 0; i < tamanho; i++) {
                    cout << vetor[i] << " ";
                }
                cout << endl;
                break;

                case 6:
                numTrocas = 0;
                numComparacoes = 0;
                heapSort(vetor);
                cout << "Heap Sort executado com sucesso!" << endl;
                cout << "Número de comparações: " << getNumComparacoes() << endl;
                cout << "Número de trocas: " << getNumTrocas() << endl;
                cout << "Vetor ordenado: ";
                for (int i = 0; i < tamanho; i++) {
                    cout << vetor[i] << " ";
                }
                cout << endl;
                break;

            case 7:
                numTrocas = 0;
                numComparacoes = 0;
                int numComparacoesBubble, numTrocasBubble;
                int numComparacoesSelection, numTrocasSelection;
                int numComparacoesInsertion, numTrocasInsertion;
                int numComparacoesQuick, numTrocasQuick;
                int numComparacoesMerge, numTrocasMerge;
                int numComparacoesHeap, numTrocasHeap;

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

                //Quick Sort
                quickSort(vetor, 0, tamanho - 1);
                numComparacoesQuick = getNumComparacoes();
                numTrocasQuick = getNumTrocas();

                //Merge Sort
                mergeSort(vetor, 0, tamanho - 1);
                numComparacoesMerge = getNumComparacoes();
                numTrocasMerge = getNumTrocas();

                //Heap Sort
                numComparacoesHeap = getNumComparacoes();
                numTrocasHeap = getNumTrocas();

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
                cout << "Quick Sort: " << endl;
                cout << "Número de comparações: " << numComparacoesQuick << endl;
                cout << "Número de trocas: " << numTrocasQuick << endl;
                cout << "Merge Sort: " << endl;
                cout << "Número de comparações: " << numComparacoesMerge << endl;
                cout << "Número de trocas: " << numTrocasMerge << endl;
                cout << "Heap Sort: " << endl;
                cout << "Número de comparações: " << numComparacoesHeap << endl;
                cout << "Número de trocas: " << numTrocasHeap << endl;

                if (numTrocasBubble <= numTrocasSelection && numTrocasBubble <= numTrocasInsertion && numTrocasBubble <= numTrocasQuick && numTrocasBubble <= numTrocasMerge && numTrocasBubble <= numTrocasHeap) {
                    cout << "Bubble Sort foi o método que realizou menos trocas." << endl;
                } else if (numTrocasSelection <= numTrocasBubble && numTrocasSelection <= numTrocasInsertion && numTrocasSelection <= numTrocasQuick && numTrocasSelection <= numTrocasMerge && numTrocasSelection <= numTrocasHeap) {
                    cout << "Selevtion sort foi o método que realizou menos trocas." << endl;
                } else if (numTrocasInsertion <= numTrocasSelection && numTrocasInsertion <= numTrocasBubble && numTrocasInsertion <= numTrocasQuick && numTrocasInsertion <= numTrocasMerge && numTrocasInsertion <= numTrocasHeap) {
                    cout << "Insert Sort foi o método que realizou menos trocas." << endl;
                } else if (numTrocasQuick <= numTrocasSelection && numTrocasQuick <= numTrocasBubble && numTrocasQuick <= numTrocasInsertion && numTrocasQuick <= numTrocasMerge && numTrocasQuick <= numTrocasHeap) {
                    cout << "Quick Sort foi o método que realizou menos trocas." << endl;
                } else if (numTrocasMerge <= numTrocasSelection && numTrocasMerge <= numTrocasBubble && numTrocasMerge <= numTrocasQuick && numTrocasMerge <= numTrocasInsertion && numTrocasMerge <= numTrocasHeap) {
                    cout << "Merge Sort foi o método que realizou menos trocas." << endl;
                } else if (numTrocasHeap <= numTrocasSelection && numTrocasHeap <= numTrocasBubble && numTrocasHeap <= numTrocasQuick && numTrocasHeap <= numTrocasMerge && numTrocasHeap <= numTrocasInsertion) {
                    cout << "Heap Sort foi o método que realizou menos trocas." << endl;
                }
                break;
                case 8:
                cout << "Saindo do programa..." << endl;
                break;

            default:
                cout << "Opção inválida! Tente novamente." << endl;
        };
    };
};
            