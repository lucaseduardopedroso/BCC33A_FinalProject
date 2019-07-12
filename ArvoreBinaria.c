#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node* ArvBin; //ponteiro tipo ArvBin.

struct Node{
    int info;
    struct Node *esq;
    struct Node *dir;
};
////////////////////////////////////// FUNCÇÕES DE CRIAÇÃO //////////////////////////////////////
    ArvBin* cria_ArvBin() //Função criar arvore.
    {
        ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
        if(raiz != NULL)
        *raiz = NULL;
    return raiz;
    }

    int libera_Node(struct Node* no) //libera no.
    {
        if(no == NULL)
        return 0;
        libera_Node(no->esq);
        libera_Node(no->dir);
        free(no);
        no == NULL;
    }

    void libera_ArvBin(ArvBin* raiz)//libera arvore.
    {
        if (raiz == NULL)
            return;
        libera_Node(*raiz);
        free(raiz);
    }
    int insere_arv(ArvBin*raiz, int valor)//inserindo um valor na arvore;
    {

        if(raiz == NULL)
        return 0;

        struct Node* novo;
        novo = (struct Node*)malloc(sizeof(struct Node));

        if(novo == NULL)
            return 0;

        novo->info = valor;
        novo->dir = NULL;
        novo->esq = NULL;

        if(*raiz == NULL)
            *raiz = novo;
        else {
            struct Node* atual = *raiz;
            struct Node* ant = NULL;

            while(atual != NULL)
                {
                    ant = atual;
                    if(valor == atual->info){
                    free(novo);
                return 0;
                }
                if(valor > atual->info)
                    atual = atual->dir;
                else
                    atual = atual->esq;
                }
            if(valor > ant->info)
            ant->dir = novo;
            else
            ant->esq = novo;
                }
    return 1;
    }

    //Percorre e mostra a arvore;

    void percorre(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        percorre(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        percorre(&((*raiz)->dir));
    }
    }
//função auxiliar para percorrer e excluir.
    struct Node* remove_atual(struct Node* atual){
        struct Node *no1, *no2;
        if(atual->esq == NULL){
            no2 = atual->dir;
            free(atual);
            return no2;
        }
        no1 = atual;
        no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
    }
//função para excluir elemento.

    int remove_elemento(ArvBin *raiz, int valor){
        if(raiz == NULL) return 0;
        struct Node* ant = NULL;
        struct Node* atual = *raiz;
        while(atual != NULL){

            if(valor == atual->info){
                if(atual ==*raiz)
                *raiz = remove_atual(atual);
                else{
                    if(ant->dir == atual)
                        ant->dir = remove_atual(atual);
                    else
                        ant->esq = remove_atual(atual);
                }
                return 1;
            }
            ant = atual;
            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
    }
////////////////////////////////////////////////////// FUNÇÕES DO TRABALHO /////////////////////////////////////

//Função que retorna maior valor.
int highestValue(struct Node* node)
    {
    if (node == NULL)
    return 0;
    int res = node->info;
    int esqres = highestValue(node->esq); //chama recursivamente para a percorrer esquerda
    int dirres = highestValue(node->dir); //chama recursivamente para a percorrer direita
    if (esqres > res)
      res = esqres;
    if (dirres > res)
      res = dirres;
    return res;
}
//função que retorna o melhor valor
int lowestValue(struct Node* node)
{
    if (node == NULL)
      return 0;
    int res = node->info;
    int esqres = lowestValue(node->esq);  //chama recursivamente para a percorrer esquerda
    int dirres = lowestValue(node->dir); //chama recursivamente para a percorrer direita
    if (esqres < res)
      res = esqres;
    if (dirres < res)
      res = dirres;
    return res;
}
//função aux para soma dos valores
int soma(struct Node* node) //Soma dos valores
{
  if(node == NULL)
  return 0;
  return soma(node->esq)+ node->info + soma(node->dir);
}
//Função que retorna 1 (ou True) se a árvore for uma árvore SOMA. Uma árvore SOMA é aquela cujo valor do pai corresponde à soma de todos os valores nas subárvores esquerda e direita

int isSUM(struct Node* raiz)
{
    if (raiz == NULL || raiz->dir == NULL && raiz->esq == NULL)
    return 1;

   int somaesq = soma(raiz->esq); //chama soma pra somar a esquerda;
   int somadir = soma(raiz->dir);//chama soma pra somar a direita;

  if(raiz->info == somaesq + somadir && isSUM(raiz->esq) && isSUM(raiz->dir))
      return 1;

  return 0;
}
//Função IsBst

int isBST(struct Node* raiz){

  struct  Node* filhoEsq = raiz->esq;
  struct  Node* filhoDir = raiz->dir;

    if((filhoEsq != NULL) || (filhoDir != NULL)){
        /*faz a verificação da BST, se algum filho da esquerda for maior que a raiz
        ou filho da direita for menor que a raiz, sai do if e retorna 0 dizendo que não é BST */
        if((filhoEsq != NULL) && (raiz->info < filhoEsq->info))
        return 0;
        if ((filhoEsq !=NULL) && (raiz->info > filhoDir->info))
        return 0;
        //verifica todos os filhos do lado esquerdo e depois do lado direito
        return 1 && (isBST(filhoEsq)) && (isBST(filhoDir));
    }
    return 1;
}

//Funções MaxHeap e MinHeap
int isMaxHeap(struct Node* raiz){

   struct Node* filhoEsq = raiz->esq;
   struct Node* filhoDir = raiz->dir;

    //faz a verificação se os filhos são nulos
    if((filhoEsq != NULL) || (filhoDir != NULL)){
        //faz a verificação do Max heap se algum filho for maior que a raiz sai do if, e retorna 0 dizendo que não é o max heap
        if((filhoEsq != NULL) && (raiz->info < filhoEsq->info))
        return 0;
        if ((filhoDir != NULL) && (raiz->info < filhoDir->info))
        return 0;
        //verifica todos os filhos do lado esquerdo e depois do lado direito
        return 1 && ( (isMaxHeap(filhoEsq)) && (isMaxHeap(filhoDir)));
    }
    return 1;
}

int isMinHeap(struct Node* raiz){
    struct Node* filhoEsq = raiz->esq;
    struct Node* filhoDir = raiz->dir;

    //faz a verificação se os filhos são nulos
    if((filhoEsq != NULL) || (filhoDir != NULL)){
        //faz a verificação do Minheap se algum filho for maior que a raiz sai do if, e retorna 0 dizendo que não é minheap
        if((filhoEsq != NULL) && (raiz->info > filhoEsq->info))
            return 0;
        if ((filhoDir != NULL) && (raiz->info > filhoDir->info))
          return 0;
        //verifica todos os filhos do lado esquerdo e depois do lado direito
        return 1 && ( (isMinHeap(filhoEsq)) && (isMinHeap(filhoDir)));
    }
    return 1;
}
//Função isBalanced
int altura(struct Node* no);
/* Retorna true se a arvore arv é balanceada */
int isBalanced(struct Node*arv)
{
   int lh; /* altura da subarvore esq */
   int rh; /* altura da subarvore dir */

   /* se a arvore estiver vazia retorna true */
   if(arv == NULL)
    return 1;

   /* pega as alturas das subarvores esq e dir */
   lh = altura(arv->esq);
   rh = altura(arv->dir);

   if( abs(lh-rh) <= 1 && //retorna o valor absoluto de lh-rh
       isBalanced(arv->esq) &&
       isBalanced(arv->dir))
     return 1;

   /* arvore nao balanceada */
   return 0;
}
/* retorna no maximo dois inteiros */
int max(int a, int b)
{
  return (a >= b)? a: b;
}

/*  funcao que calcula a altura */
int altura(struct Node* no)
{
   /* caso base se arvore esta vazia */
   if(no == NULL)
       return 0;

        /* Se a arvore nao estiver vazia entao
        altura = 1 + max de altura esq e altura dir */
   return 1 + max(altura(no->esq), altura(no->dir));
}

/* Conta o numero de nos na arvore */
 int countNo(struct Node* raiz)
{
    if (raiz == NULL)
        return (0);
    return (1 + countNo(raiz->esq) + countNo(raiz->dir));
}
/* checa se a arvore é completa ou nao */
bool isComplete (struct Node* raiz, unsigned int indice, unsigned int num_nos)
{
    // Arvore vazia é completa
    if (raiz == NULL)
        return (true);

    /*  Se o indice atribuído ao nó atual for maior igual que o número de nós na árvore,
     a árvore não estará completa */
    if (indice >= num_nos)
        return (false);

    // calcula indices subarvores esq e dir
    return (isComplete(raiz->esq, 2*indice + 1, num_nos) &&
            isComplete(raiz->dir, 2*indice + 2, num_nos));
}
////////////////////////////////////////////////////////////////////////////////
    void main(){
    ArvBin* raiz = cria_ArvBin(); //ponteiro de ponteiro para criar raiz da arvore;
    int op=3;
    int x,i;
    while(op != 3){
        printf("\n");
        printf("--------------------\n");
        printf("----------Trabalho----------\n");
        printf("Digite sua opção:");
        printf("1-Inserir");
        printf("2-Remover");
        printf("3-Exibir");
        printf("4-Menor Valor");
        printf("5-Maior Valor");
        printf("6-Soma");
        printf("7-BST");
        printf("8-MaxHeap");
        printf("9-MinHeap");
        printf("10-AVL");
        printf("11-Completa");
        printf("--------------------\n");
    }
    scanf("%d", &x);
    switch(x){
case 1:
        printf("Arvore recebe:");
        scanf("%d", &i);
        insere_arv(raiz, i);
        break;
case 2:
        printf("Arvore exclui:");
        scanf("&d", &i);
        remove_elemento(raiz,i);
        break;
case 3:
        percorre(raiz);
        break;
case 4:
        printf("Menor valor: %d", lowestValue(raiz));
        break;
case 5:
        printf("Maior valor: %d", highestValue(raiz));
        break;
case 6:
        int soma = isSUM(raiz);
        if(soma == 0)
            printf("Não é soma.");
        else
        printf("É soma");
        break;
case 7:
        int bst = isBST(raiz);
        if(bst == 0) printf("Não é BST\n");
        else
            printf("É BST.");
        break;
case 8:
        int max = isMaxHeap(raiz);
        if(max == 0) printf("Não é MaxHeap\n");
        else
            printf("É MaxHeap.");
        break;
case 9:
        int mini = isBST(raiz);
        if(mini == 0) printf("Não é MinHeap\n");
        else
        printf("É MinHeap.");
        break;
case 10:
        if(isBalanced(raiz))
        printf("Arvore balanceada");
        else
        printf("Arvore nao balanceada");
        break;
case 11:

        int indice = 0;
        int no_count = countNo(raiz);
        if (isComplete(raiz, indice, no_count))
        printf("Arvore é completa\n");
        else
        printf("Arvore não é completa\n");
    }


    }
