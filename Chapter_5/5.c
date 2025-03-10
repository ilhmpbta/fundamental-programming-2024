#include <stdio.h>
#include <stdlib.h>

/*
The greatest common divisor (gcd) of two integers is the product of the integers' common factors. Write a program that inputs two numbers and implements the following approach to finding their gcd. We will use the numbers −252 and 735. Working with the numbers' absolute values, we find the remainder of one divided by the other.

    0
735 252
    0
    252

Now we calculate the remainder of the old divisor divided by the remainder found.

    2
252 735
    504
    231

We repeat this process until the remainder is zero.

    1
231 252
    231
    21

    11
21  231
    211
    21
    21
    0
The last divisor (21) is the gcd.*/

int main(){
    int number1, number2, remainder;
    scanf("%d %d", &number1, &number2);
    number1 = abs(number1);   // problem requires using absolute values: "Working with the numbers' absolute values, we find the remainder of one divided by the other"
    number2 = abs(number2);

    while(number2 != 0){
        remainder = number1 % number2;
        // number2 becomes the new divisor, and the remainder becomes number2
        
        number1 = number2;
        number2 = remainder;
        // loop continues until number2 becomes 0, ensuring number1 doesn't become 0 to avoid infinite loop
    }

    printf("The last divisor (%d) is the GCD", number1);

    return 0;
}