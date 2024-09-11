#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

int main(){
    setlocale(LC_ALL, "");

    int qtdNums, maior, menor;

    printf("\n\n Quantos números você deseja digitar? ");
    scanf("%d", &qtdNums);

    if(qtdNums <= 0){
        printf("\nMete o pé então\n");

        exit(0);
    }

    int numeros[qtdNums];

    for(int i = 0; i < qtdNums; i++){
        printf("\n - Digite o %dº número: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("\n\n - Números digitados - \n\n");

    for(int i = 0; i < qtdNums; i++){
        printf("    - %dº: %d\n", i + 1, numeros[i]);
    }

    maior = numeros[0];
    menor = numeros[0];

    for(int i = 1; i < qtdNums; i++){
        if(numeros[i] > maior){
            maior = numeros[i];
        }
        if(numeros[i] < menor){
            menor = numeros[i];
        }
    }
    printf("\n - Maior número: %d\n - Menor número: %d\n", maior, menor);
}
