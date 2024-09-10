#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");

    char palavra[6] = "samuel";
    char inverso[6];
    int j = 0;

    for(int i = 6; i >= 0; i--){
        inverso[j] = palavra[i];
        j++;
    }

    printf("\n%s\n", inverso);
}
