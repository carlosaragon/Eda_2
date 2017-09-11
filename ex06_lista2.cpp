#include <iostream>


void siftDown(int numbers[], int root, int bottom) {
  int done, maxChild, temp;

  done = 0;
  while ((root*2 <= bottom) && (!done)) {
    if (root*2 == bottom)
      maxChild = root * 2;
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;

    if (numbers[root] < numbers[maxChild]) {
      temp = numbers[root];
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else
      done = 1;
  }
}

void heapSort(int numbers[], int array_size) {
    int i, temp;

    for (i = (array_size / 2)-1; i >= 0; i--) {
        siftDown(numbers, i, array_size);
    }

    for (i = array_size-1; i >= 1; i--) {
        temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i-1);
    }
}

int main(int argc, char const *argv[]) {
    int numberVetctor [10] = {1,2,5,8,5,42,7,6,234,21};

    heapSort(numberVetctor, 10);

    for (size_t i = 0; i < 10; i++) {
        std::cout << numberVetctor[i] << '\n';
    }


    return 0;
}
