#include <stdio.h>

/*
The table below shows the normal boiling points of several substances. Write a program that prompts the user for the observed boiling point of a substance in °C and identifies the substance if the observed boiling point is within 5% of the expected boiling point. If the data input is more than 5% higher or lower than any of the boiling points in the table, the program should output the message Substance unknown.
Substance
Water   100°C
Mercury 357°C
Copper  1187°C
Silver  2193°C
Gold    2660°C
Your program should define and call a function within_x_percent that takes as parameters a reference value ref, a data value data, and a percentage value x and returns 1 meaning true if data is within x% of ref— thatis,(ref – x% * ref) ≤ data ≤ (ref + x% * ref). Otherwise within_x_percent would return zero, meaning false. For example, the call within_x_percent(357, 323, 10)would return true, since 10% of 357 is 35.7, and 323 falls between 321.3 and 392.7.
*/

double limit_calculator(double ref, double data, double x){
    double bottom_limit = ref - x/100 * ref;
    double top_limit = ref + x/100 * ref;
    return (data <= top_limit && data >= bottom_limit);
}

int main(){
    double data;
    printf("Input the boiing point of this unidentified aqueous: ... °C\n");
    scanf("%lf", &data);

    double persen = 5.0;
    double water = 100, mercury = 357, copper = 1187, silver = 2193, gold = 2660;
    printf("The data substance you have provided ");
    if(limit_calculator(water, data, persen))          printf("is similar to the properties of water\n");
    else if(limit_calculator(mercury, data, persen)) printf("is similar to the properties of mercury\n");
    else if(limit_calculator(copper, data, persen)) printf("is similar to the properties of copper\n");
    else if(limit_calculator(silver, data, persen))  printf("is similar to the properties of silver\n");
    else if(limit_calculator(gold, data, persen))    printf("is similar to the properties of gold\n");
    else                                        printf("is unknown for now\n");

    return 0;
}

