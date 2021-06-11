/* Programa: LDE
   Autor: michelly
   Versao: 1.0 - 10/6/2021
*/


// ##################### Bibliotecas Externas ##############################

#include<stdio.h>
#include<stdlib.h>

// ########################## TAD X.h ######################################
struct produto{
    int idProduto;
    int qtdProduto;
    float precoProduto;
    float lucroComProduto;
};
typedef struct elemento *Lista;
/////////////////////////////////////
struct elemento{
    struct produto info;
    struct elemento *proximo;
};
typedef struct elemento Elem;


// ###################### Funcoes e Procedimentos do programa ##############
Lista* criaLista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL) // se alocação for bem sucedida inicialize o ponteiro 'cabeça da lista'
        *li = NULL;
    return li;
}

int tamanhoLista(Lista *li){
    if (li == NULL) return 0;
    int i = 0;
    Elem *nodeAux = *li;
    while(nodeAux != NULL){
        i++;
        nodeAux = nodeAux->proximo;
    }
    return i;
}

int listaVazia(Lista *li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

int insereInicio(Lista * li, struct produto prod) {
    if(li == NULL) return 0; // se a lista existe continua, senão, para
    Elem *novoElem = (Elem*) malloc(sizeof(Elem));
    if(novoElem == NULL) return 0;
    novoElem->info = prod;
    novoElem->proximo = *li;
    *li = novoElem;
    return 1;
}

int insereFinal(Lista *li, struct produto prod) {
    if(li == NULL) return 0;
    Elem *novoElem = (Elem*) malloc(sizeof(Elem));
    if(novoElem == NULL) return 0;
    novoElem->info = prod;
    novoElem->proximo = NULL; //atualiza o proximo
    if(*li == NULL){ //se a lista for vazia, insere no inicio
        *li = novoElem; //inicio é o novo elemento
    }else{
        Elem *aux = *li;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novoElem;
    }
    return 1;
}

int insereOrdem(Lista *li, struct produto prod){
    if(li == NULL) return 0;
    Elem *novoElem = (Elem*) malloc(sizeof(Elem));
    if(novoElem == NULL) return 0;
    novoElem->info = prod;
    novoElem->info.lucroComProduto = 0;
    if(listaVazia(li)){
        novoElem->proximo = *li;
        *li = novoElem;
        return 1;
    }
    else{//procura onde deve ser inserido
        Elem *ant, *atual = *li; //auxiliares
        while(atual != NULL && atual->info.precoProduto > prod.precoProduto){
            ant = atual;
            atual = atual->proximo;
        }
        if(atual == *li){ // insere no começo
            novoElem->proximo = (*li);
            *li = novoElem;
        }else{
            novoElem->proximo = ant->proximo;
            ant->proximo = novoElem;
        }
        return 1;
    }
}

int removeMeio(Lista *li, int id){
    if(li == NULL) return 0;
    Elem *ant, *node = *li;
    while(node != NULL && node->info.idProduto != id){
        ant = node;
        node = node->proximo;
    }
    if(node == NULL) return 0; //nao encontrou o elemento
    if(node == *li)//remover o primeiro?
        *li = node->proximo;
    else
        ant->proximo = node->proximo;
    free(node);
    return 1;
}
/////////consulta por id
int alteraQtd(Lista *li, int id, int qtd){
    if(li == NULL) return 0;
    Elem *nodeAux = *li;
    while(nodeAux != NULL && nodeAux->info.idProduto != id){
        nodeAux = nodeAux->proximo;
    }
    if(nodeAux == NULL)
        return 0;
    else{
        nodeAux->info.qtdProduto = nodeAux->info.qtdProduto + qtd;
        //printf("qtdNovaEh: %d", nodeAux->info.qtdProduto);
        return 1;
    }

}
///////compra
int compraProduto(Lista *li, int id){
    if(li == NULL) return 0;
    Elem *nodeAux = *li;
    while(nodeAux != NULL && nodeAux->info.idProduto != id){
        nodeAux = nodeAux->proximo;
    }
    if(nodeAux == NULL)
        return 0;
    if(nodeAux->info.qtdProduto == 0) printf("nao existe\n");
    else{
        nodeAux->info.qtdProduto--;
        nodeAux->info.lucroComProduto = nodeAux->info.lucroComProduto + nodeAux->info.precoProduto;
        return 1;
    }
}

void imprimeLista(Lista *li){
   Elem *pont = *li;
   while(pont != NULL){
        printf("%d %f\n", pont->info.idProduto, pont->info.lucroComProduto);
        pont = pont->proximo;
   }
   printf("\n");
}

int verifExistencia(Lista *li, int id){// verifica se o produto ja esta na lista
    if(li == NULL) return 0;
    Elem *nodeAux = *li;
    while(nodeAux != NULL && nodeAux->info.idProduto != id){
        nodeAux = nodeAux->proximo;
    }
    if(nodeAux == NULL)
        return 0;
    else{
        return 1; // achou o produto na lista, retorna 1
    }
}
//toda vez que compro um item

// ############################ Principal ###################################
int main (){
Lista *li; //ponteiro para ponteiro
li = criaLista();
//int tam = tamanhoLista(li);
// if(listaVazia(li))
//int x = insereInicio(li, dadosProduto);
int i,l,procedimento, id, qtd;
float preco;
struct produto p;
scanf("%d", &l);
for(i=0;i<l;i++){
    scanf("%d",&procedimento);
    switch(procedimento)
    {
    case 1:
        scanf("%d %d %f", &id, &qtd, &preco);
        if (verifExistencia(li, id) == 1) printf("ja existe\n");
        else{
            p.idProduto = id;
            p.qtdProduto = qtd;
            p.precoProduto = preco;
            insereOrdem(li, p);
        }
        break;
    case 2:
        scanf("%d %d", &id, &qtd);
        if(verifExistencia(li, id)==0) printf("nao existe\n");
        else alteraQtd(li, id, qtd);
        break;
    case 3:
        scanf("%d", &id);
        if(verifExistencia(li, id)==0) printf("nao existe\n");
        else compraProduto(li, id);
        break;
    case 4:
        scanf("%d", &id);
        if(verifExistencia(li, id)==0) printf("nao existe\n");
        else removeMeio(li, id);
        break;
    }
}
imprimeLista(li);
return 0;
}
