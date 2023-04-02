//Jo�o Pedro Camargo Silva Barbaresco - 2110290

#include<math.h>
#include<locale.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include <iostream>
#include "ordenacoes_arp.h"

using namespace std;

int tam;

main(){
	setlocale(LC_ALL, "Portuguese");
	int tam, opcao, i, resultBubble[2], resultSelection[2], resultInsertion[2], resultQuick[3], resultMerge[3], resultHeap[3];
	int vet[tam];
	int vetIdade[tam];
	int vetCpf[tam];
	int cpf[tam];
	char sexo[1];
	char nome[75];
	int vetBubble[tam];
	int vetSelection[tam];
	int vetInsertion[tam];
	int vetQuick[tam];
	int vetMerge[tam];
	int vetHeap[tam];
	int escolha;
	
	vector<int> vetor(tam);
	
	printf("Quantos pacientes deseja registrar? ");
	scanf("%i", &tam);
	
	for (i=0; i < tam; i++){
		printf("\n\nPaciente %i:\n", i+1);
	    printf("Nome: ");
		scanf("%s", &nome[i]);
		printf("Idade: ");
		scanf("%i", &vetIdade[i]);
		printf("Sexo: ");
		scanf("%s", &sexo);
		printf("CPF: ");
		scanf("%i", &vetCpf[i]);
	}
  
	
	while(true){
		
		printf("\n\n|--O que deseja filtrar:--|\n");
		printf("|  1- Idade               |\n");
		printf("|  2- CPF                 |\n");
		printf("|-------------------------|\n");
		scanf("%i", &escolha);
		
		printf("\n\n|--Selecione uma op��o:--|\n");
		printf("|  1- Bubble Sort        |\n");
		printf("|  2- Select Sort        |\n");
		printf("|  3- Insertion Sort     |\n");
		printf("|  4- Quick Sort         |\n");
		printf("|  5- Merge Sort         |\n");
		printf("|  6- Heap Sort          |\n");
		printf("|  7- Finalizar          |\n");
		printf("|------------------------|\n");
		scanf("%i", &opcao);
		printf("\n\n");
		
		switch(escolha){
			case 1:
				for (i=0; i < tam; i++){
		    			vet[i] = vetIdade[i];
					}
				break;	
			case 2:
				for (i=0; i < tam; i++){
		    			vet[i] = vetCpf[i];
					}
				break;
		}
		
		switch(opcao){
			case 1: {
				for (i=0; i < tam; i++){
	    			vetBubble[i] = vet[i];
				}

				bubbleSort(vetBubble, tam, resultBubble);
				break;
			}
			case 2:{
				
				for (i=0; i < tam; i++){
	    			vetSelection[i] = vet[i];
				}

				selectionSort(vetSelection, tam, resultSelection);
				break;
			}
			case 3:{
				
				for (i=0; i < tam; i++){
	    			vetInsertion[i] = vet[i];
				}
				printf ("%d ",vetInsertion[5]);

				insertionSort(vetInsertion, tam, resultInsertion);
				break;
			}
			case 4:{
				
				for(i=0; i<tam; i++){
					vetQuick[i] = vet[i];
				}		
				quickSort(vetQuick, 0, tam, resultQuick);
				printf("\nLista Ordenada:\n");
				for (i = 0; i < tam+1; i++) {
					if(i!=2){
						printf ("%d ",vetQuick[i]);
					}
  				}			
				break;
			}
							
			case 5:	
				for(i=0; i<tam; i++){
					vetMerge[i] = vet[i];
				}
				mergeSort(vetor, 0, tam - 1);
				for (int i = 0; i < tam; i++) {
					printf ("%d ",vetor[i]);
               }	
				break;
			
			case 6:
				for(i=0; i<tam; i++){
					vetHeap[i] = vet[i];
				}
				heapSort(vetor);
				for (int i = 0; i < tam; i++) {
                    cout << vetor[i] << " ";
                }
				break;
			
			case 7:
				printf("\n\nFinalizando...\n\n");
				return 0;
				break;
		}		
	}	
}
