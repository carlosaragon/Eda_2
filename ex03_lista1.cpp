#include <iostream>
#include <cstdlib>

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

void buscaInterpolada(int vetorPrincipal[], int tamanhoVetor) {
    int numeroBuscado = 0;
    std::cin >> numeroBuscado;
    int resultado = 0;
    resultado = 0 + tamanhoVetor * ((numeroBuscado - vetorPrincipal[0]) / (vetorPrincipal[tamanhoVetor] - vetorPrincipal[0]));
    while (vetorPrincipal[resultado] < numeroBuscado) {
        resultado = resultado + 1;
    }
    while (vetorPrincipal[resultado] > numeroBuscado) {
        resultado = resultado - 1;
    }
    if (vetorPrincipal[resultado] == numeroBuscado) {
        std::cout << "Achou! Posição:" << resultado  <<  '\n';
    }
    else {
        std::cout << "Numero nao esta presente" << '\n';
    }
}

int main(int argc, char const *argv[]) {
    int vetorPrincipal[10];
    for (size_t i = 0; i < 10; i++) {
        vetorPrincipal[i] = rand() % 10 + 0 ;
    }

    shellSort(vetorPrincipal, 10);

    for (size_t i = 0; i < 10; i++) {
        std::cout << vetorPrincipal[i] << '\n';
    }

    buscaInterpolada(vetorPrincipal, 9);

    return 0;
}
