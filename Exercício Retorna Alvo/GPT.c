#include <stdio.h>
#include <locale.h>

#define MAX_PAIRS 100  // Define um tamanho m�ximo para o array de pares

int main() {
    setlocale(LC_ALL, "");

    int numeros[] = {2, 4, 5, 7, 11, 15, 1, 8, 9, 0, 6, 3, 2, 7};
    int alvo = 9;
    int length = sizeof(numeros) / sizeof(numeros[0]);
    int resultado[MAX_PAIRS][2];  // Array para armazenar os pares que resultam no alvo
    int index = 0;

    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            int soma = numeros[i] + numeros[j];

            if (soma == alvo) {
                // Armazena o par de n�meros que somados resultam no alvo
                if (index < MAX_PAIRS) {
                    resultado[index][0] = numeros[i];
                    resultado[index][1] = numeros[j];
                    index++;
                } else {
                    printf("N�mero m�ximo de pares alcan�ado.\n");
                    break;
                }
            }
        }
    }

    // Imprime todos os pares que resultam em 9
    if (index > 0) {
        printf("\nOs n�meros que somados resultam em %d s�o:\n", alvo);
        for (int i = 0; i < index; i++) {
            printf("Par %d: %d e %d\n", i + 1, resultado[i][0], resultado[i][1]);
        }
    } else {
        printf("\nNenhuma combina��o de n�meros soma %d.\n", alvo);
    }

    return 0;
}
