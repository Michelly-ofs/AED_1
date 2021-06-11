/* Programa: AED1_LES
   Autor: Michelly Oliveira
   Versao: 2.0 - 30/05/2021
*/

// ##################### Bibliotecas Externas ##############################

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// ########################## TAD X.h ######################################


   // coloque o codigo da sua implementação e definicao da TAD aqui

// Estrutura e definição da TAD
typedef struct listaES {
    int ultimo;
    int tamanhoLista;
    int lista[10];
}tipoListaES;


// Inicialização da Lista
void inicializaLista (tipoListaES *listaAux)
{
    int i;
    //zerar a lista
    listaAux->tamanhoLista = 0;
    for (i=0; i<10; i++)
    {
        listaAux->lista[i]=0;

    }
    //inicializa ultimo
    listaAux->ultimo = 0;
}

//insere elemento no fim da lista
int insereElemento (tipoListaES *listaAux, int livro)
{
    if (listaAux->tamanhoLista<10)
    {
        //atualiza a lista
        listaAux->tamanhoLista++;
        //insere o elemento no final da lista
        listaAux->lista[listaAux->tamanhoLista-1] = livro ;
        //atualiza o ultimo
        listaAux->ultimo = listaAux->tamanhoLista-1;
        return 0;
    }
    else
    {
        return 1;
    }
}

//remove um elemento da lista
int removeElemento (tipoListaES *listaAux, int livro)
{
    int i,k ;
    //busca o elemento
    for (i=0; i<listaAux->tamanhoLista; i++)
    {
        //se achar remove(zera o elemento)
        if (listaAux->lista[i] == livro)
        {
            listaAux->lista[i] = 0;
            //desloca
            for (k = i; k < listaAux->tamanhoLista; k++) {
                listaAux->lista[k] = listaAux->lista[k+1];
            }
            //atualiza
            listaAux->tamanhoLista--;
            listaAux->ultimo = listaAux->tamanhoLista-1;
            return 1;
        }
    }
return 0;
}


// ###################### Funcoes e Procedimentos do programa ##############



// ############################ Principal ###################################
int main (){
    int N, L;
    int i, procedimento, titulo, reservas, retiradas;
    retiradas = 0;
    reservas = 0;
    //tipoListaES minhaLista;
    tipoListaES *pontLista = (tipoListaES*) malloc(sizeof(tipoListaES));
    inicializaLista(pontLista);
    scanf("%d",&L);
    if (0<L<=MAX)
    {
        //lê os procedimentos a serem feitos
        for(i=0; i<L; i++)
        {
            scanf("%d %d",&procedimento, &titulo);
            if (procedimento==1 && 0<titulo<=MAX)
            {
                if (insereElemento(pontLista, titulo)==0)
                {
                    printf("Sua reserva foi realizada\n");
                    reservas++;
                }
                else
                {
                    printf("Lista de reserva cheia\n");
                }

            }
            else if (procedimento==2)
            {

                if (removeElemento(pontLista, titulo) == 1)
                {
                    printf("O livro foi retirado com sucesso\n");
                    retiradas++;
                }
                else
                {
                    printf("Voce nao possui reserva desse livro\n");
                }
            }
        }
    }
printf("Voce realizou %d reservas e %d retiradas\n", reservas, retiradas);
return 0;
}
