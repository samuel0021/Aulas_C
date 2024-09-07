#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");

    float temp, C, F, K;
    int escolha, continuar = 1;

    do{
        printf("\nDigite o valor da temperatura(somente números): ");
        scanf("%f", &temp);
        fflush(stdin);
        printf("\nEscolha a escala: ");
        printf("\n(1) - Celsius \n(2) - Fahrenheit \n(3) - Kelvin\n\n");
        //escolha = getchar();
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                C = temp;

                F = (9 * C + 160) / 5;
                K = C + 273;

                printf("\n%.1fºC = %.1fºF = %.1fºK\n", C, F, K);
            break;

            case 2:
                F = temp;

                C = (5 * F - 160) / 9;
                K = C + 273;

                printf("\n%.1fºF = %.1fºC = %.1fºK\n", F, C, K);
            break;

            case 3:
                K = temp;

                C = K - 273;
                F = (9 * C + 160) / 5;

                printf("\n%.1fºK = %.1fºF = %.1fºC\n", K, F, C);
            break;

            default:
                printf("\nOpção invalida!\n");
            break;
        }
        printf("\n----------------------------------------------");
        printf("\n\nDeseja tentar novamente?\n");
        printf("\n(1) - Sim \n(0) - Não\n");
        scanf("%d", &continuar);

    }while(continuar);
}





