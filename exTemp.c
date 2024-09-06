#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");

    float temp, C, F, K;
    char escolha;

    printf("\nDigite o valor da temperatura sem a letra: ");
    scanf("%f", &temp);
    fflush(stdin);
    printf("\nEscolha a escala: ");
    escolha = getchar();

    switch(escolha){
        case 'c':
            C = temp;

            F = (9 * C + 160) / 5;
            K = C + 273;

            printf("\n%.2fºC = %.2fºF = %.2fºK\n", C, F, K);
        break;

        case 'f':
            printf("%c", escolha);
            
            F = temp;
            
            C = (5 * F - 160) / 9;
            
            
        break;

        case 'k':
            printf("%c", escolha);
        break;

        default:
            printf("Opção inválida!");
        break;
    }
}
