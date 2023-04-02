#include<math.h>
#include<locale.h>
#include<stdio.h>
#include<vector>
#include<stdlib.h>


extern void bubbleSort(int vet[], int tam, int *resultBubble){
	int i, j, aux;
	resultBubble[1]=0;
	resultBubble[2]=0;
	
	for(i=1; i<tam; i++){
		for(j=0; j<tam-1; j++){
			resultBubble[1]++;
			if(vet[j] > vet[j+1]){
				aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = aux;
				resultBubble[2]++;
			}
		}
	}
	printf("\nLista Ordenada:\n");
	for (i = 0; i < tam; i++) {
    	printf ("%d ",vet[i]);
  	}
  	printf("\n");
}

extern void selectionSort(int vet[], int tam, int *resultSelection){
	int i, j, min, aux;
	resultSelection[1]=0;
	resultSelection[2]=0;
	
	for(i=0; i< (tam-1); i++){
		resultSelection[1]++;
		min = i;
		for (j=i+1; j<tam; j++){
			if(vet[j] < vet[min]){
				min=j;
			}
		}
		if(i != min){
			aux = vet[i];
			vet[i] = vet[min];
			vet[min] = aux;
			resultSelection[2]++;
		}
	}
	printf("\nLista Ordenada:\n");
	for (i = 0; i < tam; i++) {
    	printf ("%d ",vet[i]);
  	}
  	printf("\n");
}

extern void insertionSort(int vet[], int tam, int *resultInsertion){
    int i, key, j;
	resultInsertion[1]=0;
	resultInsertion[2]=0;
	
    for (i = 1; i < tam; i++) {
    	resultInsertion[1]++;
        key = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > key) {
            vet[j + 1] = vet[j];
            j = j - 1;
            resultInsertion[2]++;
        }
        vet[j + 1] = key;
    }
    printf("\nLista Ordenada:\n");
	for (i = 0; i < tam; i++) {
    	printf ("%d ",vet[i]);
  	}
	printf("\n");
}

extern void quickSort(int vet[], int left, int right, int *resultQuick){
	resultQuick[3]++;
	int i, j, x, y;
     
    i = left;
    j = right;
    x = vet[(left + right) / 2];
     
    while(i <= j) {
        while(vet[i] < x && i < right) {
            i++;
        }
        while(vet[j] > x && j > left) {
            j--;
        }
        resultQuick[1]++;
        if(i <= j) {
        	resultQuick[2]++;
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quickSort(vet, left, j, resultQuick);
    }
    if(i < right) {
		quickSort(vet, i, right, resultQuick);
    }
}

extern void merge(std::vector<int> &v, int inicio, int meio, int fim) {
    std::vector<int> temp(fim - inicio + 1);
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    int numComparacoes = 0;
    int numTrocas = 0;

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

extern void mergeSort(std::vector<int> &v, int inicio, int fim) {
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
    int numComparacoes = 0;

    // Se o filho da esquerda � maior que a raiz
    if (esq < n && v[esq] > v[maior]) {
        maior = esq;
        numComparacoes++;
    }

    // Se o filho da direita � maior que o maior at� agora
    if (dir < n && v[dir] > v[maior]) {
        maior = dir;
        numComparacoes++;
    }

    // Se o maior n�o � a raiz
    if (maior != i) {
        std::swap(v[i], v[maior]);
        heapify(v, n, maior);
        numComparacoes++;
    }
}

void heapSort(std::vector<int> &v) {
    int n = v.size();
    int numTrocas=0;

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

extern void sortComparison(int *resultBubble,int *resultSelection,int *resultInsertion, int *resultQuick){
	setlocale(LC_ALL, "Portuguese");
	printf("\n\n========Comparando=======\n");
	printf("|------Bubble Sort------|\n");
	printf("|  Compara��es: %i      |\n", resultBubble[1]);
	printf("|  Trocas: %i            |\n", resultBubble[2]);
	printf("|----Selecition Sort----|\n");
	printf("|  Compara��es: %i       |\n", resultSelection[1]);
	printf("|  Trocas: %i            |\n", resultSelection[2]);
	printf("|-----Insertion Sort----|\n");
	printf("|  Compara��es: %i       |\n", resultInsertion[1]);
	printf("|  Trocas: %i            |\n", resultInsertion[2]);
	printf("|-------Quick Sort------|\n");
	printf("|  Compara��es: %i       |\n", resultQuick[1]);
	printf("|  Trocas: %i            |\n", resultQuick[2]);
	printf("|  Chamada de Fun��o: %i |\n", resultQuick[3]);
	printf("=========================\n\n");
}
