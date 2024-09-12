#include <stdio.h>
#include <conio.h>

int main() {
    // Definindo as dimensões da matriz tridimensional
    int profundidade = 2;
    int linhas = 3;
    int colunas = 4;

    // Declarando a matriz tridimensional
    int matriz[profundidade][linhas][colunas];

    // Inicializando a matriz tridimensional com valores
    int valor = 1;
    for (int i = 0; i < profundidade; i++) {
        for (int j = 0; j < linhas; j++) {
            for (int k = 0; k < colunas; k++) {
                matriz[i][j][k] = valor++;

            }
        }
    }

    // Imprimindo a matriz tridimensional
    for (int i = 0; i < profundidade; i++) {
        printf("Camada %d:\n", i + 1);
        for (int j = 0; j < linhas; j++) {
            for (int k = 0; k < colunas; k++) {
                printf("%4d ", matriz[i][j][k]);
                getch();
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
