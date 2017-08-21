#include <iostream>

typedef struct Index {
  int posicao;
  int * valor;
} index;

void buscaIndexada(index vetorIndex[], int vetorPrincipal[], int tamanhoVetor) {
  int numeroBuscado;
  std::cin >> numeroBuscado;
  int i;
  i = 0;

  while (numeroBuscado > * vetorIndex[i].valor) {
    if (vetorIndex[i+1].posicao != NULL)
      i++;
    else
      break;
  }
  int j;
  j = vetorIndex[i].posicao;

  while (numeroBuscado < vetorPrincipal[j]) {
    j--;
  }
  if (numeroBuscado == vetorPrincipal[j]) {
    std::cout << "Numero encontrado" << '\n';
  }
  if (numeroBuscado > vetorPrincipal[j]) {
    std::cout << "Numero nao encontrado" << '\n';
  }
}

int main() {
  int tamanhoVetor;
  std::cin >> tamanhoVetor;

  int * vetorPrincipal;
  vetorPrincipal = new int [tamanhoVetor];

  for(int i = 0; i < tamanhoVetor; i++) {
    std::cin >> vetorPrincipal[i];
  }

  index * vetorIndex;
  vetorIndex = new index[tamanhoVetor/3];
  int posicaoVetorPrincipal;
  posicaoVetorPrincipal = 2;

  for (int i = 0; i < (tamanhoVetor/3); i++) {
      vetorIndex[i].posicao = posicaoVetorPrincipal;
      vetorIndex[i].valor = &vetorPrincipal[posicaoVetorPrincipal];
      posicaoVetorPrincipal = posicaoVetorPrincipal + 3;
  }
  buscaIndexada(vetorIndex, vetorPrincipal, tamanhoVetor);

  return 0;
}
