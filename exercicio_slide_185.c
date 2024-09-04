#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "");

    int n = 1, contador = 0, soma = 0;

    while(contador < 10){
        soma += n;
        printf("\n%dº ímpar: %d -- Soma = %d\n", contador + 1, n, soma);
        n += 2;
        contador++;
    }
}
