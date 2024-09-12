#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");

    int array1[5] = {1, 3, 5, 7, 9};
    int array2[5] = {2, 4, 6, 8, 10};
    int arraySoma[10];
    int length = sizeof(arraySoma) / sizeof(arraySoma[0]);

    for(int i = 0; i < 5; i++){
        arraySoma[i] = array1[i];
    }

    for(int i = 5; i < 10; i++){
        arraySoma[i] = array2[i - 5];
    }

    for(int i = 0; i < length; i++){
        printf("\n%d", arraySoma[i]);
    }

    printf("\n");
}
