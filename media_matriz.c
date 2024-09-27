#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");

    float media, soma;
    float a[5][3] = {{5.0, 5.0, 5.0},
                     {6.0, 7.0, 8.0},
                     {4.0, 5.0, 6.0},
                     {8.0, 8.0, 8.0},
                     {9.0, 7.0, 9.0}};

    for(int i = 0; i < 5; i++){
        media = 0;
        soma = 0;
        for(int j = 0; j < 3; j++){
            soma += a[i][j];
        }
        media = soma / 3;
        printf("\n%.1f", media);
    }
}

//calcular e exibir a média da turma na mesma variável
