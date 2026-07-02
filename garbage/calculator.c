#include <stdio.h>

int main(void){
    printf("enter first number");
    int num;
    scanf("%d", &num);
    int num2;
    scanf("%d", &num2);
    if (num>num2){
        printf("thhe number %d is greater than %d", num, num2);
    }
    else if (num<num2){
        printf("the number %d is smaller than %d", num, num2);

    


    }
    return 0;



}
