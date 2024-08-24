#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

int continuar, time; //declarar as variáveis fora da main pra virar variável global e usar nas duas funções

int main(){
    setlocale(LC_ALL, "Portuguese");

    escolheTime(); //chama a função que pergunta o time
                   //independente da resposta vai perguntar depois se quer continuar

    do{ //vai ficar perguntando se quer continuar enquanto a variável 'continuar' for igual a 1

        printf("\n\nDeseja continuar? ");
        printf("\n(1) - Sim \n(2) - Não");
        printf("\n\nOpção escolhida: ");
        scanf("%i", &continuar); //se sim, a variavel vai ser igual a 1 e vai dar início ao loop

        switch(continuar){

            case 1:
                printf("\n --- \n"); //frescura só pra ficar mais fácil de enxergar na tela
                escolheTime(); //chama a função novamente para escolher outro time
                //por isso criar a função de escolher o time separada, pra não ter que digitar tudo de novo aqui
            break;

            case 2:
                printf("\n\nPrograma encerrado\n");
                continuar = 0; //dá o valor 0 à variável 'continuar' para encerrar o loop
            break;

            default:
                printf("\n|\n\nOpção inválida!");
                continuar = 1; //dá o valor 1 pro loop continuar enquanto não digitar o número certo
            break;
        }
    } while(continuar == 1); //condição para que o loop continue rodando
                             //por isso ele encerra quando atribui o valor 0 pra variável 'continuar'
}

int escolheTime(){ //função para escolher o time

    printf("\nDigite o número do time: ");
    printf("\n(1) - Corinthians \n(2) - Palmeiras");
    printf("\n\nOpção escolhida: ");
    scanf("%d", &time);

    switch(time){
        case 1:
            printf("\n|\n\nVocê escolheu Corinthians");
        break;

        case 2:
            printf("\n|\n\nVocê escolheu Palmeiras");
        break;

        default:
            printf("\n|\n\n\Opção inválida!");
        break;
    }
}



