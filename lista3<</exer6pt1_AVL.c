#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contador = 0;

typedef struct No{
  int numero;
  struct No *direita;
  struct No *esquerda;
  int fator;
}no;

int maior(int a, int b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}

int Altura(no *raiz){
    if(raiz == NULL){
        return 0;
    }
    else{
        return 1 + maior(Altura(raiz->esquerda), Altura(raiz->direita));
    }
}

void rot_dir(no** r) {
  no* b = *r;
  no* a = b->esquerda;
  b->esquerda = a->direita;
  a->direita = b;
  a->fator = 0;
  b->fator = 0;
  *r = a;
}

void rot_esq(no** raiz) {
  no* a = *raiz;
  no* b = a->direita;
  a->direita = b->esquerda;
  b->esquerda = a;
  a->fator = 0;
  b->fator = 0;
  *raiz = b;
}

void rot_dir_esq(no** r) {
     no *a = *r;
     no *c = a->direita;
     no *b = c->esquerda;
     c->esquerda = b->direita;
     a->direita = b->esquerda;
     b->esquerda = a;
     b->direita = c;
     if(b->fator == -1){
       a->fator = 0;
       c->fator = 1;
     }
     else if(b->fator == 0){
       a->fator = 0;
       c->fator = 0;
     }
     else if(b->fator == 1){
       a->fator = -1;
       c->fator = 0;
     }
     b->fator = 0;
     *r = b;
}

void rot_esq_dir(no** raiz) {
     no *c = *raiz;
     no *a = c->esquerda;
     no *b = a->direita;
     c->esquerda = b->direita;
     a->direita = b->esquerda;
     b->esquerda = a;
     b->direita = c;
     if(b->fator == -1){
       a->fator = 0;
       c->fator = 1;
     }
     else if(b->fator == 0){
       a->fator = 0;
       c->fator = 0;
     }
     else if(b->fator == 1){
       a->fator = -1;
       c->fator = 0;
     }
     b->fator = 0;
     *raiz = b;
}

void Balanceia(no** raiz){

    (*raiz)->fator = Altura((*raiz)->esquerda) - Altura((*raiz)->direita);

    if((*raiz)->fator == 2 && (*raiz)->esquerda->fator == -1){
        rot_esq_dir(&(*raiz));
        contador = contador + 2;
    }
    else if((*raiz)->fator == 2 && (*raiz)->esquerda->fator == 1){
        rot_dir(&(*raiz));
        contador++;
    }
    else if((*raiz)->fator == -2 && (*raiz)->direita->fator == 1){
        rot_dir_esq(&(*raiz));
        contador = contador + 2;
    }
    else if ((*raiz)->fator == -2 && (*raiz)->direita->fator == -1) {
        rot_esq(&(*raiz));
        contador++;
    }
}

void InserirArvore(no **raiz, int numero){
     if(*raiz == NULL){
         *raiz = (no*) malloc(sizeof(no));
         (*raiz)->direita = NULL;
         (*raiz)->esquerda = NULL;
         (*raiz)->numero = numero;
         (*raiz)->fator = 0;
     }else{
         if(numero < (*raiz)->numero){
             InserirArvore(&(*raiz)->esquerda, numero);
         }
         else{
             InserirArvore(&(*raiz)->direita, numero);
         }
     }
     Balanceia(&(*raiz));
 }


int main(){

  int vector[1000];
  int i = 0;
  no *n;
  n = NULL;

  srand(time(NULL));

  int vector_size = sizeof(vector) / sizeof(int);

  printf("\nVetor:\n\n[");

  for(i = 0;i < vector_size - 1;i++){
    vector[i] = rand() % 10000;
    printf("%d, ",vector[i]);
  }
  vector[vector_size - 1] = rand() % 10000;
  printf("%d]\n\n",vector[i]);

  for(i = 0;i < vector_size ;i++){
      InserirArvore(&n,vector[i]);
  }

  printf("\n\n\n--- Arvore AVL ----");
  printf("\n\nNumero de Rotações: %d\n\n",contador);


  return 0;

}
