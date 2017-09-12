#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void swap(int vector[], int i, int j){

	int aux = vector[i];
	vector[i] = vector[j];
	vector[j] = aux;

}

int count_size(int start,int end){
	return ((end - start)+1);
}

void InsertionSort(int vector[], int vector_size){
  int i = 0, j = 0;
  int aux = 0;

  for (i = 1; i < vector_size ; i++){
    j = i;
    while(vector[j] < vector[j-1] && j != 0){
				swap(vector, j, j - 1);
        j--;
    }
  }

}

int Median(int vector[],int start, int end);

int Partition(int vector[], int start, int end, int pivot_aux){

	swap(vector, pivot_aux, end);

  int pivot = vector[end];

  int pivot_index = start;

  int i = 0;

  for(i = start;i < end;i++){
    if(vector[i] < pivot){
      swap(vector, i, pivot_index);
      pivot_index++;
    }
  }

  swap(vector, pivot_index, end);

  return pivot_index;

}

int QuickSelect(int vector[], int start, int end, int k){

	if(count_size(start,end) < 1){
		return start;
	}

	int pivot_index = Median(vector, start, end);
			pivot_index = Partition(vector, start, end, pivot_index);

	if(pivot_index == k){
		return pivot_index;
  }
	else if(pivot_index > k)
		return QuickSelect(vector, start, pivot_index - 1, k);

	return QuickSelect(vector, pivot_index + 1, end, k);

}

int Partition5(int vector[], int start, int end){

	int *vector_aux = (int*)malloc(count_size(start,end)*sizeof(int));
	int i = start, y = 0 , aux = 0;

	while(i <= end){
		vector_aux[y] = vector[i];
		i++;
		y++;
	}

	InsertionSort(vector_aux, y);

	int median = vector_aux[y/2];

	while(vector[aux] != median){
    aux++;
  }

	free(vector_aux);

	return aux;

}

int Median(int vector[],int start, int end){

	int i = 0, subEnd = 0, median5 = 0;

	if(end - start < 5){
		return Partition5(vector, start, end);
	}
	for(i = start; i <= end ; i += 5){
		subEnd = i + 4;
		if(subEnd > end){
			subEnd = end;
		}

		median5 = Partition5(vector, i, subEnd);
		swap(vector, median5, start + ((i - start)/5));
	}
	return QuickSelect(vector, start, start + ceil((end - start)/5) - 1, start + (end - start)/10);
}

void QuickSort(int vector[], int start, int end,int vector_size){

  if(start < end){
    int pivot_index;

		pivot_index = QuickSelect(vector, start, end, count_size(start, end)/2);

    QuickSort(vector, start, pivot_index - 1, vector_size);
		QuickSort(vector, pivot_index + 1, end, vector_size);
  }
}

int main(){

  int vector[50];
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

  QuickSort(vector, 0, vector_size - 1, vector_size);

  printf("\nVetor Ordenado:\n\n[");

  for(i = 0;i < vector_size - 1;i++){
    printf("%d, ",vector[i]);
  }
  printf("%d]\n\n",vector[vector_size - 1]);

  return 0;

}
