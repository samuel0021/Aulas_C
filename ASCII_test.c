#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

main(){
    setlocale(LC_ALL, "Portuguese");

    char A;
    int continuar, opcaoValida;

    printf("Digite um caractere: ");
    scanf("%c", &A);

    printf("\nCaractere: %c", A);
    printf("\nCódigo ASCII: %d", A);

    do{
        opcaoValida = 0;

        do{
            printf("\n\nDeseja continuar?\n");
            printf("(1) Sim\n(2) Não");
            printf("\n\nOpção escolhida: ");
            scanf("%d", &continuar);

            switch(continuar){
                case 1:
                    fflush(stdin);
                    printf("\nDigite um caractere: ");
                    scanf("%c", &A);

                    printf("\nCaractere: %c", A);
                    printf("\nCódigo ASCII: %d", A);
                    opcaoValida = 1;
                break;

                case 2:
                    printf("\nPrograma finalizado\n");
                    opcaoValida = 1;
                break;

                default:
                    printf("Opção inváida!");
                break;
            }
        }
        while(!opcaoValida);
    }
    while(continuar == 1);
}
