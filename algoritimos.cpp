#include <iostream>

using namespace std;

// função para ordenação Bubble Sort
void bubble_sort(int vetor[], int tam, int &num_comp, int &num_trocas) {
    int i, j, aux;

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam - 1 - i; j++) {
            num_comp++;

            if (vetor[j] > vetor[j+1]) {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                num_trocas++;
            }
        }
    }
}

// função para ordenação Selection Sort
void selection_sort(int vetor[], int tam, int &num_trocas) {
    int i, j, min, aux;

    for (i = 0; i < tam - 1; i++) {
        min = i;
        for (j = i+1; j < tam; j++) {
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }

        if (i != min) {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
            num_trocas++;
        }
    }
}

int main() {
    int opcao, tam = 10, vetor[tam], i, num_comp = 0, num_trocas = 0;

    // preencher o vetor com 10 números
    cout << "Digite " << tam << " numeros quaisquer: " << endl;
    for (i = 0; i < tam; i++) {
        cin >> vetor[i];
    }

    cout << "\nVetor original: ";
    for (i = 0; i < tam; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    // apresentar o menu de opções
    cout << "\nEscolha uma opcao de ordenacao: " << endl;
    cout << "1 - Bubble Sort" << endl;
    cout << "2 - Selection Sort" << endl;
    cin >> opcao;

    // chamar a função correspondente à opção escolhida pelo usuário
    switch (opcao) {
        case 1:
            bubble_sort(vetor, tam, num_comp, num_trocas);
            cout << "\nOrdenado pelo Bubble Sort:" << endl;
            cout << "Numero de comparacoes: " << num_comp << endl;
            cout << "Numero de trocas: " << num_trocas << endl;
                // imprimir o vetor ordenado
            cout << "\nVetor ordenado: ";
            for (i = 0; i < tam; i++) {
                cout << vetor[i] << " ";
            }
            cout << endl;
            break;
        case 2:
            selection_sort(vetor, tam, num_trocas);
            cout << "\nOrdenado pelo Selection Sort:" << endl;
            cout << "Numero de trocas: " << num_trocas << endl;
            // imprimir o vetor ordenado
            cout << "\nVetor ordenado: ";
            for (i = 0; i < tam; i++) {
                cout << vetor[i] << " ";
            }
            cout << endl;
            break;
        default:
            cout << "\nOpcao invalida." << endl;
            break;
    }



    return 0;
}
