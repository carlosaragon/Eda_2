#include <iostream>
#include <vector>

void selectionSort(int vetorPrincipal[], int tamanhoVetor) {
  int indexMinimo;
  int auxiliar;
  for (int i = 0; i < tamanhoVetor; i++) {
    indexMinimo = i;
    for (int j = i + 1; j < tamanhoVetor; j++) {
      if (vetorPrincipal[j] < vetorPrincipal[indexMinimo]) {
        indexMinimo = j;
      }
    }
    if (indexMinimo != i) {
      auxiliar = vetorPrincipal[indexMinimo];
      vetorPrincipal[indexMinimo] = vetorPrincipal[i];
      vetorPrincipal[i] = auxiliar;
    }
  }
}

void insertionSort(int vetorPrincipal[], int tamanhoVetor) {
  int auxiliar;
  int j;
  for (int i = 0; i < tamanhoVetor; i++) {
    j = i;
    while (j != 0 && (vetorPrincipal[j] < vetorPrincipal[j - 1])) {
      auxiliar = vetorPrincipal[j];
      vetorPrincipal[j] = vetorPrincipal[j - 1];
      vetorPrincipal[j - 1] = auxiliar;
      j--;
    }
  }
}

void bubbleSort(int vetorPrincipal[], int tamanhoVetor) {
  bool swap;
  do {
    swap = false;
    for (int i = 0; i < tamanhoVetor-1; i++) {
      if (vetorPrincipal[i] > vetorPrincipal[i+1]) {
        int auxiliar;
        swap = true;
        auxiliar = vetorPrincipal[i];
        vetorPrincipal[i] = vetorPrincipal[i + 1];
        vetorPrincipal[i + 1] = auxiliar;
      }
    }
  } while(swap == true);
}

void shellSort(int vetorPrincipal[], int tamanhoVetor) {
  int gap;
  gap = tamanhoVetor / 2;
  while (gap > 0) {
    int numeroComparado;
    int indexAuxiliar;
    for (int i = gap; i < tamanhoVetor; i++) {
      numeroComparado = vetorPrincipal[i];
      indexAuxiliar = i;
      while (indexAuxiliar >= gap && vetorPrincipal[indexAuxiliar - gap] > numeroComparado) {
        vetorPrincipal[indexAuxiliar] = vetorPrincipal[indexAuxiliar - gap];
        indexAuxiliar = indexAuxiliar - gap;
      }
      vetorPrincipal[indexAuxiliar] = numeroComparado;
    }
    gap = gap / 2;
  }
}


int main() {
  int tamanhoVetor;
  std::cin >> tamanhoVetor;
  int * vetorPrincipal;
  vetorPrincipal = new int[tamanhoVetor];
  for (int i = 0; i < tamanhoVetor; i++) {
    std::cin >> vetorPrincipal[i];
  }

  // selectionSort(vetorPrincipal, tamanhoVetor);
  // insertionSort(vetorPrincipal, tamanhoVetor);
  // bubbleSort(vetorPrincipal, tamanhoVetor);
  // shellSort(vetorPrincipal, tamanhoVetor);

  for (int i = 0; i < tamanhoVetor; i++) {
    std::cout << vetorPrincipal[i] << '\n';
  }

  return 0;
}
