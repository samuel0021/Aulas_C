#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");

    int numeros[] = {2, 4, 5, 7, 11, 15};
    int alvo = 9;
    int resultado[20];
    int length = sizeof(numeros) / sizeof(numeros[0]);
    int lengthRes = sizeof(resultado) / sizeof(resultado[0]);
    int soma, i1, i2, n1, n2, index = 0;
    int encontrou = 0;

    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            soma = numeros[i] + numeros[j];

            printf("\n%d + %d = %d\n",numeros[i], numeros[j], soma);

            if(soma == alvo){
                resultado[index] = soma;
                printf("\n\nResultados: %d\n", resultado[index]);
                index++;

                i1 = i;
                i2 = j;
                n1 = numeros[i];
                n2 = numeros[j];
                //encontrou = 1;

                //break;
            }
            if(encontrou){
                break;
            }
        }
    }
    printf("\n\nOs números que somados resultam em 9 estão nos índices: %d e %d\n\n", i1, i2);
    printf("São eles: %d e %d\n\n", n1, n2);

    /*for(int i = 0; i < index; i++){
            printf("Soma %d: %d\n", i + 1, resultado[i]);
    }*/
}

