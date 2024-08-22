#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    float n1, n2, soma;
    int continuar;

    printf("Digite um número: ");
    scanf("%f", &n1);

    printf("\nDigite outro número: ");
    scanf("%f", &n2);

    soma = n1 + n2;

    printf("\nSoma: %.2f + %.2f = %.2f \n", n1, n2, soma);

    do{
        int opcaoValida = 0;

        do{

            printf("\nDeseja continuar? \n(1) Sim \n(2) Não\n\nOpção: ");
            scanf("%d", &continuar);

            switch(continuar){
                case 1:
                    printf("\nDigite outro número: ");
                    scanf("%f", &n2);

                    n1 = soma;

                    soma += n2;

                    printf("\nSoma: %.2f + %.2f = %.2f\n", n1, n2, soma);
                    opcaoValida = 1;
                break;

                case 2:
                    printf("\nSoma final: %.2f\n", soma);
                    opcaoValida = 1;
                break;

                default:
                    printf("\nOpção inválida!\n");
                break;
            }
        }
        while(!opcaoValida);
    }
    while(continuar == 1);

    return 0;
}
