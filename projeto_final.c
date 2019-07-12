// Universidade Tecnologica Federal do Paraná
// Bacharelado em Ciencia da Computacao - Estrutura de Dados 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

isMaxHeap(); //Ilzimara
isMinHeap(); //Ilzimara
isBST();
isAVL(); //Gustavo
isComplete(); //Gustavo
lowestValue(); //Gabriel
highestValue(); //Gabriel
mirrorTree(); // Lucas Eduardo  
areCousins(); // Lucas Eduardo
isSUM();

 struct Node {
    int data; 
    struct Node* left, *right; 
}; 

struct Node*NovoNo(int data){ 
    struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return(node); 
} 

//Função que retorna maior valor.
int highestValue(struct Node* node) 
{  
    if (node == NULL) 
    return 0; 
    int res = node->data; 
    int esqres = highestValue(node->left); //chama recursivamente para a percorrer esquerda 
    int dirres = highestValue(node->right); //chama recursivamente para a percorrer direita 
    if (esqres > res) 
      res = esqres; 
    if (dirres > res) 
      res = dirres; 
    return res; 
} 

//Função que retorna menor valor. 
int lowestValue(struct Node* node) 
{ 
    if (node == NULL) 
      return 0; 
    int res = node->data; 
    int esqres = lowestValue(node->left);  //chama recursivamente para a percorrer esquerda 
    int dirres = lowestValue(node->right); //chama recursivamente para a percorrer direita 
    if (esqres < res) 
      res = esqres; 
    if (dirres < res) 
      res = dirres; 
    return res; 
} 

int soma(struct Node* node) //Soma dos valores
{
  if(node == NULL)
  return 0;
  return soma(node->left)+ note->data + soma(node->right);
}

int isSUM(struct Node* node) //retorna 1 (ou True) se a árvore for uma árvore SOMA. Uma árvore SOMA é aquela cujo valor do pai corresponde à soma de todos os valores nas subárvores esquerda e direita
{
    if (node == NULL || node->right == NULL && node->left == NULL)
    return 1;

   int somaesq = soma(node->left); //chama soma pra somar a esquerda;
   int somadir = soma(node->right);//chama soma pra somar a direita;

  if(node->data == somaesq+somadir && isSum(node->left) && isSum(node->right))
      return 1;

  return 0;
}
//isMaxHeap
//função recebe a arvore, a raiz e o tamanho
int isMaxHeap(int *arvore, int raiz ,int tam){
    int filhoEsq = (2*raiz) + 1;  //a variavel filhoEsq recebe o valor do indice do filho esquerdo da raiz
    int filhoDir = (2*raiz) + 2;  //a variavel filhoDir recebe o valor do indice do filho direito da raiz
    //faz a verificação se os filhos estão no parametro do tamanho (dentro da arvore), se não tiver não executa a recursão
    //ou seja essa condição vai ser a nossa condição de parada
    if(filhoEsq < tam || filhoDir < tam){
        //faz a verificação do Max heap se algum filho for maior que a raiz sai do if, e retorna 0 dizendo que não é o max heap
        if(arvore[raiz] < arvore[filhoEsq] || arvore[raiz] < arvore[filhoDir]){
            return 0;
        }
        //verifica todos os filhos do lado esquerdo e depois do lado direito
        return 1 && ( (isMaxHeap(arvore,filhoEsq,tam)) && (isMaxHeap(arvore,filhoDir,tam)));
    }   
}
//isMinHeap
//função recebe a arvore, a raiz e o tamanho
int isMinHeap(int Node* node, int raiz ,int tam){
    int filhoEsq = node->left;  //a variavel filhoEsq recebe o valor do indice do filho esquerdo da raiz
    int filhoDir = node->right;  //a variavel filhoDir recebe o valor do indice do filho direito da raiz
    //faz a verificação se os filhos estão no parametro do tamanho (dentro da arvore), se não tiver não executa a recursão
    //ou seja essa condição vai ser a nossa condição de parada
    if(filhoEsq < tam || filhoDir < tam){
        //faz a verificação do MinHeap se algum filho for menor que a raiz sai do if, e retorna 0 dizendo que não é o min heap
        if(arvore[raiz] < arvore[filhoEsq] || arvore[raiz] < arvore[filhoDir]){
            return 0;
        }
        //verifica todos os filhos do lado esquerdo e depois do lado direito
        return 1 && ( (isMinHeap(arvore,filhoEsq,tam)) && (isMinHeap(arvore,filhoDir,tam)));
    }
}
//isBST
int isBST(int Node* node ,int raiz ,int tam){
    int filhoEsq = node->left; //a variavel filhoEsq recebe o valor do indice do filho esquerdo da raiz
    int filhoDir = node->right; //a variavel filhoDir recebe o valor do indice do filho direito da raiz
     /*faz a verificação se os filhos estão no parametro do tamanho (dentro da arvore), se não tiver não executa a recursão
        ou seja essa condição vai ser a nossa condição de parada*/
    if(filhoEsq < tam && filhoDir < tam){

        /*faz a verificação da BST, se algum filho da esquerda for maior que a raiz 
            ou filho da direita for menor que a raiz, sai do if e retorna 0 dizendo que não é BST */
        if(arvore[raiz] < arvore[filhoEsq] || arvore[raiz] > arvore[filhoDir]){
            return 0;
        }
        //verifica todos os filhos do lado esquerdo e depois do lado direito
        return 1 && (isBST(arvore,filhoEsq,tam)) && (isBST(arvore,filhoDir,tam));
    }
}
