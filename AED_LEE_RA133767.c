/* Programa: LEE
   Autor: Michelly Oliveira
   Versao: 1.0 - 02/06/2021
*/


// ##################### Bibliotecas Externas ##############################

#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define MAX 100

// ########################## TAD X.h ######################################


   // coloque o codigo da sua implementação e definicao da TAD aqui
// Tipo info
struct info
{
int valor;
int prox;
};
typedef struct info tipoInfo;
// Lista Estática Encadeada
struct listaEE {
int tamanhoLista;
int primeiro;
int ultimo;
// 0 ocupado, 1 livre
int posLivre[10];
tipoInfo elemento[10];
};
typedef struct listaEE tipoListaEE;

// Inicializando Lista
void inicializaLista (tipoListaEE *listaAux)
{ // Inicializa elementos da lista
int i;
listaAux->tamanhoLista =0;
listaAux->primeiro=-1;
listaAux->ultimo=-1;
for (i=0; i<10; i++){
listaAux->elemento[i].valor=0;
listaAux->elemento[i].prox=-1;
listaAux-> posLivre[i]=1; }}

// Encontra a prox Posição Livre

int proxPosLivre(tipoListaEE *listaAux)
{
int i;
for (i=0;i<10;i++){
if (listaAux->posLivre[i]==1)
return i;
}
return -1;
}

// ///////Inserção no final

void insereElementoFinal (tipoListaEE *listaAux, int posicao, int R)
{
if (posicao!=-1){
// lê valores para lista
listaAux->elemento[posicao].valor = R;
// atualiza elementos da lista
if (listaAux->tamanhoLista==0) listaAux->primeiro=posicao;
else listaAux->elemento[listaAux->ultimo].prox = posicao;
listaAux->elemento[posicao].prox=-1;
listaAux->tamanhoLista++;
listaAux->ultimo=posicao;
listaAux->posLivre[posicao]=0; }
}

// remover um elemento NO MEIO da lista

void removeElemento (tipoListaEE *listaAux, int R)
{
    int i, j, p;
    //busca o elemento
    p = listaAux->elemento[i].prox;
    listaAux->elemento[i].valor = 0;
    listaAux->elemento[i].prox = -1;
    listaAux->tamanhoLista = listaAux->tamanhoLista-1;
    listaAux->posLivre[i] = 1;
    for (j=0; j<10; j++) {
        //achar o anterior e pegar a posicao dele
        if (listaAux->elemento[j].prox == i){
            listaAux->elemento[j].prox = p; // o anterior recebe o sucessor do item removido
        }
    }
}
// remove um elemento NO FINAL da lista/
void removePrimeiroE (tipoListaEE *listaAux, int R)
{
    int i, p, frst;

    //encontra se for o primeiro
    frst = listaAux->primeiro;
    p = listaAux->elemento[frst].prox;
    listaAux->elemento[frst].valor = 0;
    listaAux->elemento[frst].prox = -1;
    listaAux->tamanhoLista = listaAux->tamanhoLista-1;
    listaAux->posLivre[frst] = 1;
    //Indique o sucessor do primeiro elemento como o novo primeiro elemento da lista
    listaAux->primeiro = p;




}

// remover um elemento NA PRIMEIRA POSIÇÃO da lista
void removeUltimo(tipoListaEE *listaAux)
{
    int i, u;
    for (i=0; i<listaAux->ultimo; i++)
    {
        if(listaAux->elemento[i].prox == listaAux->ultimo)
        {
            listaAux->elemento[i].prox == -1;
            u = i;
            listaAux->elemento[listaAux->ultimo].valor = 0;
            listaAux->ultimo =  u;
            listaAux->posLivre[u] = 1;
            listaAux->tamanhoLista--;
        }
    }

}

// ###################### Funcoes e Procedimentos do programa ##############


// Ordena Elementos com algoritimo inserction sort

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        if (arr[i]>-1){
            printf("%d ", arr[i]);
        }
    printf("\n");
}

// verifica existência de um RA na Lista
int reservou(int vetorAux[], int Ra)
{
    int qtd, i;
    qtd = -1;
    for(i=0; i<10; i++){
        if (vetorAux[i]==Ra){
            return 1;
        }
    }
    printf("nao existe\n");
    return 0;
}
//o elemento é o ultimo?
int eUltimo (tipoListaEE *listaAux, int R)
{
    int i;
    for (i=0;i<10;i++)
    {
        if (listaAux->elemento[i].valor == R && i == listaAux->ultimo)
        {
            return 1;
        }
    }
    return 0;
}

//quantas reservas por ano
//funcao verifica a entrada, calcula o ano adiciona ao ponteiro
void qualAno(int *pont, int Ra)
{
    if ((Ra/10000)==6)
    {
        pont[0]++;
    }
    if ((Ra/10000)==7)
    {
        pont[1]++;
    }
    if ((Ra/10000)==8)
    {
        pont[2]++;
    }
    if ((Ra/10000)==9)
    {
        pont[3]++;
    }
    if ((Ra/10000)==10)
    {
        pont[4]++;
    }
    if ((Ra/10000)==11)
    {
        pont[5]++;
    }
    if ((Ra/10000)==12)
    {
        pont[6]++;
    }
    if ((Ra/10000)==13 || (Ra/10000)==14)
    {
        pont[7]++;
    }
}



// ############################ Principal ###################################
int main ()
{
int i, j, L, N, R, k;
int procedimento, posicao;
int vetor[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};


tipoListaEE minhaLista;
tipoListaEE *pontLista;
pontLista = &minhaLista;
int vetAnos[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int anos[8] = {2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018};
int *pontVetoriAnos;
pontVetoriAnos = vetAnos;
inicializaLista(pontLista);
scanf("%d",&L);
int n = sizeof(vetor) / sizeof(vetor[0]);
if (0<L<=100)
{
    for (i=0; i<L; i++)
    {
        scanf("%d %d",&procedimento, &R);
        if (procedimento==1 && 66000 <= R && R <= 140000)
        {
            if (pontLista->tamanhoLista < 10)
            {
                qualAno(pontVetoriAnos, R);
                posicao = proxPosLivre(pontLista);
                insereElementoFinal(pontLista, posicao, R);
                //ordena copiando pra um vetor


                j = 0;
                while (j >= 0 && vetor[j] != -1) {
                    j++;
                }
                vetor[j] = R;
                insertionSort(vetor, 10);
                printArray(vetor, 10);
            }
            else
            {
                printf("lista cheia\n");
                printArray(vetor, 10);
            }

        }
        if (procedimento==2 && 66000 <= R && R <= 140000 && pontLista->tamanhoLista <= 10)
        {
            if (reservou(vetor, R) == 1 )//verifica se o elemento existe na lista, se falso imprime 'nao existe'
            {
                j, k = 0;
                while (j<=10 && k<1)
                {
                    if (j == pontLista->primeiro && pontLista->elemento[j].valor == R){
                        removePrimeiroE(pontLista, R);
                        k++;
                    }
                    else if (j == pontLista->ultimo && pontLista->elemento[j].valor == R){
                        removeUltimo(pontLista);
                        k++;
                    }
                    else if (j!=pontLista->primeiro && j != pontLista->ultimo){
                        removeElemento(pontLista, R);
                        k++;
                    }
                    else {
                        reservou(vetor, R); //verifica se o elemento existe na lista, se falso imprime 'nao existe'
                    }
                    j++;
                }
            }

            k = 0;
            while(k<10 && vetor[k]!=R){
                k++;
            }
            vetor[k] = -1;
            insertionSort(vetor, 10);
            printArray(vetor, 10);
        }

    }

for (i=0; i<7; i++){
    printf("%d: %d\n", anos[i], vetAnos[i]);
}
printf("%d: %d", anos[7], vetAnos[7]);

}

}
