#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contador = 0;
#define RUB 0
#define NEG 1
#define N_MAX 1027

typedef struct No{
    int dado;
    char cor;
    struct No *noPai;
    struct No *noEsquerdo;
    struct No *noDireito;
}No;

typedef struct tipoArvore{
    No *topo;
}tipoArvore;

tipoArvore arvore;

void criarArvore(tipoArvore *arvore){
    arvore->topo = NULL;
}

No* noAvo(No *n){
    if(n == NULL){
        return NULL;
    }

    if(n->noPai == NULL){
        return NULL;
    }

    else{
        return n->noPai->noPai;
    }
}

No* noIrmao(No *n){
    if(n == NULL){
        return NULL;
    }

    if(n->noPai == NULL){
        return NULL;
    }

    if(n == n->noPai->noEsquerdo){
        return n->noPai->noDireito;
    }

    else{
        return n->noPai->noEsquerdo;
    }
}

No* noTio(No *n){
    if(n == NULL){
        return NULL;
    }

    return noIrmao(n->noPai);
}


No* rotacaoEsquerda(No* raiz, No* n){
    No* r = n->noDireito;

    if(n == NULL){
        return raiz;
    }

    if(raiz == n){
        raiz = r;
    }

    else if(n == n->noPai->noEsquerdo){
        n->noPai->noEsquerdo = r;
    }

    else{
        n->noPai->noDireito = r;
    }

    n->noDireito = r->noEsquerdo;

    if(r->noEsquerdo != NULL){
        r->noEsquerdo->noPai = n;
    }

    r->noEsquerdo = n;
    r->noPai = n->noPai;
    n->noPai = r;

    return raiz;
}

void rotacaoEsquerdaRR(No **x){

    No *y;
    y = *x;
    *x = (*x)->noDireito;
    (*x)->noPai = y->noPai;
    y->noDireito = (*x)->noEsquerdo;
    if(y->noDireito)    y->noDireito->noPai = y;
    (*x)->noEsquerdo = y;
    y->noPai = *x;

}


No* rotacaoDireita(No* raiz, No* n){
    No* l = n->noEsquerdo;

    if(n == NULL){
        return raiz;
    }

    if(raiz == n){
        raiz = l;
    }

    else if(n == n->noPai->noEsquerdo){
        n->noPai->noEsquerdo = l;
    }

    else{
        n->noPai->noDireito = l;
    }

    n->noEsquerdo = l->noDireito;

    if(l->noDireito != NULL){
        l->noDireito->noPai = n;
    }

    l->noDireito = n;
    l->noPai = n->noPai;
    n->noPai = l;

    return raiz;
}

void rotacaoDireitaRR(No **x){
    No *y;
    y = *x;
    *x = (*x)->noEsquerdo;
    (*x)->noPai = y->noPai;
    y->noEsquerdo = (*x)->noDireito;
    if(y->noEsquerdo)   y->noEsquerdo->noPai = y;
    (*x)->noDireito = y;
    y->noPai = *x;
}

int verificaCor(No* n){
    if(n == NULL){
        return NEG;
    }

    else{
        return n->cor;
    }
}

No* balanceamentoCaso5(No* raiz, No* n){
    n->noPai->cor = NEG;
    noAvo(n)->cor = RUB;

    if(n == n->noPai->noEsquerdo && n->noPai == noAvo(n)->noEsquerdo){
        raiz = rotacaoDireita(raiz, noAvo(n));
        contador++;
    }

    else if(n == n->noPai->noDireito && n->noPai == noAvo(n)->noDireito){
        raiz = rotacaoEsquerda(raiz, noAvo(n));
        contador++;
    }

    return raiz;
}

No* balanceamentoCaso4(No* raiz, No* n){
    if(n == n->noPai->noDireito && n->noPai == noAvo(n)->noEsquerdo){
        raiz = rotacaoEsquerda(raiz, n->noPai);
        contador++;
        n = n->noEsquerdo;
    }

    else if(n == n->noPai->noEsquerdo && n->noPai == noAvo(n)->noDireito){
        raiz = rotacaoDireita(raiz, n->noPai);
        contador++;
        n = n->noDireito;
    }

    return balanceamentoCaso5(raiz, n);
}

No* balanceamentoCaso1(No* raiz, No* n);

No* balanceamentoCaso3(No* raiz, No* n){
    if(verificaCor(noTio(n)) == RUB){
        n->noPai->cor = NEG;
        noTio(n)->cor = NEG;
        noAvo(n)->cor = RUB;
        return balanceamentoCaso1(raiz, noAvo(n));
    }

    else{
        return balanceamentoCaso4(raiz, n);
    }
}

No* balanceamentoCaso2(No* raiz, No* n){
    if(n->noPai->cor == NEG){
        return raiz;
    }

    else{
        return balanceamentoCaso3(raiz, n);
    }
}

No* balanceamentoCaso1(No* raiz, No* n){
    if(n->noPai == NULL){
        n->cor = NEG;
        return raiz;
    }

    else{
        return balanceamentoCaso2(raiz, n);
    }
}

No* noNovo(int dado){
    No* aux;

    aux = (No *) malloc (sizeof(No));
    aux->dado = dado;
    aux->cor = RUB;
    aux->noEsquerdo = NULL;
    aux->noDireito = NULL;
    aux->noPai = NULL;
    return aux;
}

No* inserirElemento(int numero, No *raiz){
    No* novo = noNovo(numero);

    if(raiz == NULL){
        novo->cor = NEG;
        return novo;
    }

    No* aux = raiz;

    while(1){
        if(novo->dado == aux->dado){
            free (novo);
            return raiz;
        }

        else if(novo->dado < aux->dado){
            if(aux->noEsquerdo == NULL){
                aux->noEsquerdo = novo;
                novo->noPai = aux;
                return balanceamentoCaso1(raiz, novo);
            }

            else{
                aux = aux->noEsquerdo;
            }
        }

        else {
            if (aux->noDireito == NULL){
                aux->noDireito = novo;
                novo->noPai = aux;
                return balanceamentoCaso1(raiz, novo);
            }

            else{
                aux = aux->noDireito;
            }
        }
    }
}

void inserirArvore(int numero, tipoArvore* arvore){
    arvore->topo = inserirElemento(numero, arvore->topo);
}

int main(){

  int vector[1000];
  int i = 0;
  criarArvore(&arvore);

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
      inserirArvore(vector[i], &arvore);
  }

  printf("\n\n\n--- Arvore V&P ----");
  printf("\n\nNumero de Rotações: %d\n\n",contador);


  return 0;

}
