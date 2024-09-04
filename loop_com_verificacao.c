#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "");

    char r;

    do{
        printf("\nTeste de estrutura do...while");
        printf("\n\nDeseja continuar? (s) Sim - (n) Não\n");
        fflush(stdin);
        //scanf("%c", &r);
        r = getchar();
        if(r != 'n' && r != 'N' && r != 's' && r != 'S'){
            printf("\nOpção inválida\n");
            r = 's';
        }

    } while(r == 's' || r == 'S');

    printf("\nSaiu do loop\n");

}
