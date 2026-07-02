#include <stdio.h>
int main(void) {


    // printf("hello\n");
    // int num1;
    // int num2;
    // int num3;
    // printf("Enter first number\n");
    // scanf("%d", &num1);
    // printf("enter second number\n");
    // scanf("%d", &num2);
    // printf("now try to guess their sum\n");
    // scanf("%d", &num3);
    // int output = num1+num2;

    // if(output>num3){
    //     printf("nah the sum of %d and %d numbers is greater than %d 😒",num1,num2, num3);
    
    // }
    // else if(output<num3){
    //     printf("nah the sum of %d and %d numbers is smaller than %d 😒",num1,num2, num3);
    // }
    // else{
    //     printf("you summed them right!!😁👍");
    // }

   //typecasttinggg!!!!
   int num1;
   int num2;
   int num3;

   printf("enter first number\n");
   scanf("%d", &num1);
   
   printf("enter second number\n");
   scanf("%d", &num2);
   
   printf("try to guess the absolute ratio between %d and %d\n", num1, num2);
   scanf("%d", &num3);
   
   
   float output= num1/num2;
   float exactoutput = (float)num1/num2;
   
   
   if (output>num3){
    printf("the absolute ratio between %d and %d is greater than %d",num1, num2, num3);
   }
   else if (output<num3){
    printf("the absolute ratio between %d and %d is smaller than %d",num1, num2, num3);
   }
   else {
    printf("you've divided %d and %d right!!(the exact value of the ratio is %.2f)",num1, num2, exactoutput);
   }






    return 0;
}