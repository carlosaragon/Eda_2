#include <cstdio>
#include <string>
using std::string;

size_t getMax(string arr[], int n){
    size_t max = arr[0].size();
    for (int i = 1; i < n; i++){
        if (arr[i].size()>max)
            max = arr[i].size();
    }
    return max;
}

void countSort(string a[], int size, size_t k){
    string *b = NULL; int *c = NULL;
    b = new string[size];
    c = new int[257];

    for (int i = 0; i <257; i++){
        c[i] = 0;
    }
    for (int j = 0; j <size; j++){
        c[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;
    }

    for (int f = 1; f <257; f++){
        c[f] += c[f - 1];
    }

    for (int r = size - 1; r >= 0; r--){
        b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
        c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
    }

    for (int l = 0; l < size; l++){
        a[l] = b[l];
    }

    delete[] b;
    delete[] c;
}


void radixSort(string b[], int r){
    size_t max = getMax(b, r);
    for (size_t digit = max; digit > 0; digit--){ // size_t is unsigned, so avoid using digit >= 0, which is always true
        countSort(b, r, digit - 1);
    }

}

int main(void) {
    string data[] = {
        "Abda Silva",
        "Abigail Santos",
        "Acácia Silva",
        "Adalgisa  Santos",
        "Adeilce Silva",
        "Adelaide Santos",
        "Adélia Silva",
        "Alécya",
        "Alessandra Dias",
        "Ananda",
        "Anastácia",
        "Andréa",
        "Andressa",
        "Anete",
        "Angela",
        "Angélica",
        "Angelina",
        "Anita",
        "Antonia",
        "Antonieta",
        "Antuérpia",
        "Aparecida",
        "Araci",
        "Ariane",
        "Ariene",
        "Arisla",
        "Arissa",
        "Arlette",
        "Arminda",
        "Aryana",
        "Audrey",
        "Adelinda",
        "Assunção",
        "Audrey",
        "Augusta",
        "Aura",
        "Aurelia",
        "Aarão",
        "Abdala",
        "Abdemis",
        "Abel",
        "Abelardo",
        "Abraão",
        "Acácio",
        "Adalberto",
        "Adamastor",
        "Adão"
    };
    std::cout << "Antes do sorting" << '\n';
    for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        printf("    %s\n", data[i].c_str());
    }
    radixSort(data, (int)(sizeof(data) / sizeof(data[0])));
    std::cout << "Depois do sorting" << '\n';
    for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        printf("    %s\n", data[i].c_str());
    }
    return 0;
}
