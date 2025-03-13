#include <stdio.h>
#include <string.h>

/*Write a function fact_calc that takes a string output argument and an integer input argument n and returns a string showing the calculation of n!. For example, if the value supplied for n were 6, the string returned would be “6! 5 6 3 5 3 4 3 3 3 2 3 1 5 720”. Write a program that repeatedly prompts the user for an integer between 0 and 9, calls fact_calc and outputs the resulting string in a box of asterisks of the right size to surround the result. If the user inputs an invalid value, the program should display an error message and reprompt for valid input. Input of the sentinel -1 should cause the input loop to exit. Sample run:
Enter an integer between 0 and 9 or -1 to quit => 6
**************************************
* 6! = 6 x 5 x 4 x 3 x 2 x 1 = 720 *
**************************************
Enter an integer between 0 and 9 or -1 to quit => 12
Invalid entry
Enter an integer between 0 and 9 or -1 to quit => 0
************
* 0! = 1 *
************
Enter an integer between 0 and 9 or -1 to quit => -1
*/
void display_factorial(int n);
void display_box(int n, const char* result);

int main(){
     int N;
    do {
        printf("\nEnter an integer between 0 and 9 (or -1 to quit) ==> ");
        scanf("%d", &N);
        
        if (N < -1 || N > 9) {
            printf("Invalid entry\n");
            continue;
        }

        if (N == -1) {
            printf("\nThank you for using our program\n");
            return 0;
        }

        display_factorial(N);

    } while (1);
}

void display_factorial(int n) {
    int factorial = 1;
    char result[100] = "";  // Buffer to hold the result string
    char temp[20];

    // Creating the factorial string and calculating the factorial value
    sprintf(temp, "%d! = ", n);
    strcat(result, temp);
    
    for (int i = n; i > 0; i--) {
        factorial *= i;
        sprintf(temp, "%d%s", i, (i > 1) ? " x " : " = ");
        strcat(result, temp);
    }
    
    sprintf(temp, "%d", factorial);
    strcat(result, temp);

    display_box(n, result);
}

void display_box(int n, const char* result) {
    int length = strlen(result) + 4;  // Calculate length for the box
    printf("%.*s\n", length + 2, "****************************************************************");
    printf("* %s *\n", result);
    printf("%.*s\n", length + 2, "****************************************************************");
}