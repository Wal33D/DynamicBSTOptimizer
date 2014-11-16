#include <stdio.h>

   int main() {

     float num1,deno1;
     
     printf("Enter fraction 1: numerator denominator:");
     
     scanf("%f%f",&num1,&deno1);
  
     float result = num1/deno1;
     
     printf("[%f]/[%f] = %f",num1, deno1, result);  //display the result
     
     return 0;

    }