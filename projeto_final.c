// Universidade Tecnologica Federal do Paraná
// Bacharelado em Ciencia da Computacao - Estrutura de Dados 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

isMaxHeap();
isMinHeap();
isBST();
isAVL();
isComplete();
lowestValue();//gabriel
highestValue();//gabriel
mirrorTree();
areCousins();
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
int highestValue(struct Node* root) 
{  
    if (root == NULL) 
      return INT_MIN; 

    int res = root->data; 
    int lres = findMax(root->left); 
    int rres = findMax(root->right); 
    if (lres > res) 
      res = lres; 
    if (rres > res) 
      res = rres; 
    return res; 
} 

//Função que retorna menor valor. 
int lowestValue(struct Node* root) 
{ 

    if (root == NULL) 
      return INT_MAX; 
  
    int res = root->data; 
    int lres = findMin(root->left); 
    int rres = findMin(root->right); 
    if (lres < res) 
      res = lres; 
    if (rres < res) 
      res = rres; 
    return res; 
} 
