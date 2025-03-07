#include <stdio.h>
#include <math.h>

/*
The ratio between successive speeds of a six-speed gearbox (assuming that the gears are evenly spaced to allow for whole teeth) is
 where M is the maximum speed in revolutions per minute and m is the mini- mum speed. Write a function speeds_ratio that calculates this ratio for any maximum and minimum speeds. Write a main function that prompts for maximum and minimum speeds (rpm), calls speeds_ratio to calculate the ratio, and displays the results in a sentence of the form of:  5th root of (maxSpeed/minSpeed)
The ratio between successive speeds of a six-speed gearbox with maximum speed __________ rpm and minimum speed __________ rpm is __________.
*/

double speeds_ratio (double x, double y){
    return pow(x/y,0.2);    // Math.h function uses exponentiation with 1/5 power (equivalent to 5th root)
}

int main(){
    double maximum, minimum;
    printf("Please input the maximum revolution (in rpm) and minimum revolution (in rpm) for a gearbox with 6 speed levels\n");
    scanf("%lf %lf", &maximum, &minimum);
    
    // Just to ensure there's no user error using if-else
    if(maximum>minimum){
        printf("The ratio between successive speeds of a six-speed gearbox with maximum speed %lf rpm and minimum speed %lf rpm is %lf\n", 
        maximum, minimum, speeds_ratio(maximum,minimum));
    }

    // Case where minimum rpm is somehow larger than maximum (makes no sense)
    else {
        printf("How can the maximum be smaller than the minimum? That makes no sense!\n");   
    }

    return 0;
}