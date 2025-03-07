#include <stdio.h>
/*
Write a program to take a depth (in kilometers) inside the earth as input data; compute and display the temperature at this depth in degrees Celsius and degrees Fahrenheit. The relevant formulas are:

Celsius = 10 (depth) + 20                               (Celsius temperature at depth in km)
Fahrenheit = 1.8 (Celsius) + 32                         (Converts celcius to Farenheit)

Include two functions in your program. Function celsius_at_depth should compute and return the Celsius temperature at a depth measured in kilometers. Function fahrenheit should convert a Celsius temperature to Fahrenheit.
*/

double celsius_at_depth(double x){
    return 10 * x + 20;
}

double fahrenheit_conversion(double x){
    return 1.8 * x + 32;
}

int main(){
    double depth;                   // Hope depth isn't negative (because the formula isn't valid)
    double celsius, fahrenheit;     // Almost forgot to declare these

    // Get user input
    printf("Enter a depth inside the earth in km\n");
    scanf("%lf", &depth);
    
    if (depth >= 0){
    // Calculate using the formulas for better code readability and if-else to prevent user error when entering negative depth
    celsius = celsius_at_depth(depth);
    fahrenheit = fahrenheit_conversion(celsius);

    // .2lf so it's not too long (4 decimal places is excessive and less clean in my opinion)
    printf("Temperature at that depth is %.2lf celsius\nOr equivalent to %.2lf fahrenheit\n", celsius, fahrenheit);
    }

    else{
        printf("Sorry, for negative depth, this program is not valid\n");
    }
    return 0;
}