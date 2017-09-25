#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void Merge(int vector[], int start, int middle, int end, int vector_size){

  int i,k,j;
  k = start;
  i = start;
  j = middle + 1;
  int *vector_aux = (int*)malloc(vector_size * sizeof(int));
  int y = 0;

  while(y < vector_size){
      vector_aux[y] = vector[y];
      y++;
  }

  while(i <= middle && j <= end){

    printf("\nV[i] = %d | V[j] = %d",vector_aux[i],vector_aux[j]);

    if(vector_aux[i] < vector_aux[j]){
        printf("\nV[i] = >> %d << | V[j] = %d\n",vector_aux[i],vector_aux[j]);
        vector[k] = vector_aux[i];
        i++;
    }
    else{
        printf("\nV[i] = %d | V[j] = >> %d <<\n",vector_aux[i],vector_aux[j]);
        vector[k] = vector_aux[j];
        j++;
    }
    k++;
  }

  while(i <= middle){
      printf("\nV[i] = >> %d <<\n",vector_aux[i]);
      vector[k] = vector_aux[i];
      k++;
      i++;
  }
  while(j <= end){
      printf("\nV[j] = >> %d <<\n",vector_aux[j]);
      vector[k] = vector_aux[j];
      k++;
      j++;
  }

  printf("\n\n");

  y = 0;
  while(y < vector_size){
      printf("%d  ",vector[y]);
      y++;
  }

  printf("\n\n");

  free(vector_aux);
}


void MergeSortIterativo(int vector[], int vector_size){
  int i = 0,size = 0,slot = 0, subEnd = 0, middle = 0;

  slot = 2;

  while(slot/2 <= vector_size){
    for(i = 0 ; i < vector_size ; i+=slot){
      subEnd = i + (slot - 1);
      middle = (i + subEnd)/2;
      if(subEnd > vector_size - 1){
        subEnd = vector_size - 1;
      }

      Merge(vector,i,middle,subEnd, vector_size);
    }
    slot = slot * 2;
  }
}

int main(){

  int vector[13];
  int i = 0;

  srand(time(NULL));

  int vector_size = sizeof(vector) / sizeof(int);

  printf("\nVetor:\n\n[");

  for(i = 0;i < vector_size - 1;i++){
    vector[i] = rand() % 100;
    printf("%d, ",vector[i]);
  }
  vector[vector_size - 1] = rand() % 100;
  printf("%d]\n\n",vector[i]);

  MergeSortIterativo(vector, vector_size);

  return 0;

}
