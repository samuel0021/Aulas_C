#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

#define TAM 20

int main(){
    setlocale(LC_ALL, "");

    char word[TAM];
    int lengthWord; /*= sizeof(word) / sizeof(word[0]);*/
    //char invert[];
    //int lengthInvert = sizeof(invert) / sizeof(invert[0]);
    //int j = 0;

    printf("\nDigite uma palavra para inverter: ");
    //scanf("%s", &word);
    //scanf("%[^\n]", word);
    gets(word);

    printf("\n\nPalavra digitada: %s\n\n", word);
    printf("Palavra invertida: ");

    //lengthWord = sizeof(word) / sizeof(word[0]);
    lengthWord = strlen(word);

    for(int i = lengthWord - 1; i >= 0; i--){
        //invert[j] = word[i];
        printf("%c", word[i]);

        //j++;
    }

    printf("\n");

    //printf("\n %s ", invert);

    /*for(int k = 0; k <= lengthInvert; k++){
        printf("\n");
        printf("%c", invert[k]);
        printf("\n");
    }*/

    return 0;
}
