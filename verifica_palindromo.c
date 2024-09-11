#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

int main(){
    setlocale(LC_ALL, "");

    char word[20], invert[20];
    int i, lengthWord, j = 0;

    printf("\n\t - Verifica Palíndromo -\n");
    printf("\nDigite uma palavra: ");
    gets(word);

    lengthWord = strlen(word);

    printf("\nComprimento da palavra digitada: %d\n", lengthWord);

    for(i = lengthWord - 1; i >= 0; i--){
        //printf("%c", word[i]);

        invert[j] = word[i];

        //strcpy(invert[j], word[i]);
        //printf("%c", invert[j]);
        //printf("%s", invert);
        j++;
    }

    invert[j] = '\0';

    printf("\nPalavra invertida: %s\n", invert);

    if(strcasecmp(word, invert) == 0){
        printf("\n\nA palavra é um palíndromo!\n\n");
    }else{
        printf("\n\nA palavra não é um palíndromo!\n\n");
    }
}



