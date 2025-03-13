#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    char COLOR_CODES[10][7] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"};
    char input[100]; int index[3]; int looploop = 0; char input_looploop;

    printf("\nEnter the colors of the resistor's three bands, beginning with the band nearest the end. Type the colors in lowercase letters only, NO CAPS.\n");

    do{
    looploop = 1;
    int invalid = 0; char invalid_input[3][20];
    for (int i = 0; i < 3; i++){
        printf("Band %d => ", i+1); scanf("%s", input); // scan input three times
        for (int j = 0; j < 10; j++){
            if (strcmp(input, COLOR_CODES[j]) == 0){
                index[i] = j; // printf("%s = %d\n", input, index[i]); // for debugging purposes
                break;  // immediately break from loop to avoid next condition
            }
            if (j == 9) {
                index[i] = 999;
                sprintf(invalid_input[i], "%s", input); invalid++;
            } // to find invalid input
        }
    }

    if (invalid > 0){
        printf("You have invalid input: ");
        for (int i = 0; i < 3; i++){
            if (index[i] == 999) printf("(%s) ", invalid_input[i]);
        }
        printf("\n");
    }

    else printf("Resistance value: %.1Lf kilo-ohm\n", ((long double)index[0] * 10 + (long double)index[1]) * pow(10, index[2]) / 1000);
   
    printf("Input Y/y to do another conversion: \n");
    scanf(" %c", &input_looploop);
   
    if(!(input_looploop == 'Y' || input_looploop == 'y')){
        looploop = 0;
        printf("\nThank you for using our program\n");
    }

    else printf("\n\n");

    } while (looploop != 0);
}