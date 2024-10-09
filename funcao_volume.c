#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <C:\Users\UNIP\Documents\function.h>

int main(){
    setlocale(LC_ALL, "");

    float v, a;

    printf("\nDigite o valor da aresta do cubo: ");
    scanf("%f", &a);

    //float calcVolume(float);

    v = calcVolume(a);

    printf("\n\nVolume do cubo = %f\n", v);

}

/*float calcVolume(float a){
    float v;

    v = pow(a, 3);

    return(v);
}*/
