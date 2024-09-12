#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");

    int nums[] = {1, 2, 3, 4, 4, 5, 2, 6, 5};
    int length = sizeof(nums) / sizeof(nums[0]);
    int numsUnicos[length];
    int lengthUnicos = 0;
    int duplicata;

    printf("\n\nArray com duplicatas: ");
    for(int i = 0; i < length; i++){
        printf("%d ", nums[i]);
    }

    for(int i = 0; i < length; i++){
        duplicata = 0;

        for(int j = 0; j < lengthUnicos; j++){
            if(nums[i] == numsUnicos[j]){
                duplicata = 1;
                break;
            }
        }
        if(!duplicata){
            numsUnicos[lengthUnicos] = nums[i];
            lengthUnicos++;
        }
    }
    printf("\n\nArray sem duplicatas: ");
    for(int i = 0; i < lengthUnicos; i++){
        printf("%d ", numsUnicos[i]);
    }
    printf("\n\n");
}
