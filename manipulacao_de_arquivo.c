#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");

    FILE *pont_arq;
    char texto[1000];

    pont_arq = fopen("arquivo_texto.txt", "w");

    if(pont_arq == NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }
    else{
        printf("\nDigite o texto para gravar no arquivo: ");
        scanf("%s", &texto);

        fprintf(pont_arq, "Texto digitado: %s \n", texto);

        fclose(pont_arq);

        printf("\nDados gravados com sucesso! \n");
    }
}

