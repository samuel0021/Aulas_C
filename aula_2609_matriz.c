#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");

    int l, c;

    printf("\nDigite a quantidade de linhas: ");
    scanf("%d", &l);
    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &c);

    int m[l][c];

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("\nDigite o valor do elemento m[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("m[%d][%d] = %d\t", i, j, m[i][j]);
        }
        printf("\n");
    }
}
