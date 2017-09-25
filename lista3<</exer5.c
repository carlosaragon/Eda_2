#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void swap(int vector[], int i, int j){

	int aux = vector[i];
	vector[i] = vector[j];
	vector[j] = aux;

}

int Partition(int vector[], int start, int end, int index_pivot){

  swap(vector,index_pivot,end);

  int pivot = vector[end];

  int i = start,j;

  for(j = start; j < end ; j++){
    if(vector[j] < pivot){
      swap(vector,i,j);
      i++;
    }
  }

  swap(vector,i,end);

  return i;

}

int MedianOfMedians(int vector[], int start, int end);

int QuickSelect(int vector[], int start, int end, int k){

  if((end - start) < 1){
    return start;
  }

  int pivot_index =  MedianOfMedians(vector,start,end);

  pivot_index = Partition(vector,start,end,pivot_index);

  if(pivot_index == k){
    return pivot_index;
  }
  else if(pivot_index > k){
    return QuickSelect(vector,start,pivot_index - 1,k);
  }
  else{
    return QuickSelect(vector,pivot_index + 1,end,k);
  }
}

int Partition7(int vector[], int start, int end){
	int i,j;

  for(i = start + 1; i <= end ; i++){
    j = i;
    while(vector[j] < vector[j - 1] && j > start){
      swap(vector,j,j-1);
			j--;
    }
  }

	return (start + end)/2;
}

int MedianOfMedians(int vector[], int start, int end){
	int subEnd , i, median7, index_7 = start;

	if((end - start)+1 <= 7){
		return Partition7(vector,start,end);
	}

 	for(i = start; i <= end ; i += 7){
		subEnd = i + 6;
		if(subEnd > end){
			subEnd = end;
		}

		median7 = Partition7(vector,i,subEnd);
		swap(vector,median7,index_7);
		index_7++;
	}
	return QuickSelect(vector,start,index_7 - 1,(start + (index_7 - 1))/2);
}


int main(){

  int vector[11];
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

  int pivot = QuickSelect(vector,0,vector_size - 1, (vector_size - 1)/2);

  printf("\nMediana das Medianas = >>%d<<\n",vector[pivot]);

  printf("\n\n[");

  for(i = 0;i < vector_size - 1;i++){
	if(i == (vector_size - 1)/2)
		printf(">>>%d<<< , ",vector[i]);
	else
    	printf("%d, ",vector[i]);
  }
  printf("%d]\n\n",vector[vector_size - 1]);

  return 0;

}
