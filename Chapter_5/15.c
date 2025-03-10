#include <stdio.h>

/*
The value for π can be determined by the series equation:
4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + 1/13 - ..... + 1/(2n + 1) - 1/(2n+1)) and so on until the nth term
Write a program that prompts the user to enter the number of iterations to be executed to determine the value of π.
*/

int main(){
    long int input, i;
    scanf("%ld", &input);
    double result = 0.0;
    
    for (i = 0; i < input; i++){
        // first input based on the problem is +1, +1/5, +1/9, need index 0 to make 1/1 from 1/(2i +1)
        if (i % 2 == 0) result += (1.0 / (2 * i + 1)); // reversed because input starts from 0, so iteration 1 uses even
        else result -= (1.0 / (2 * i + 1));
    }
    double phi = 4 * result;
    printf("For %ld iteration, the value of π is %lf\n", input, phi);

return 0;
}