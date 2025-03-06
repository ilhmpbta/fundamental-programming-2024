#include <stdio.h>
#define KMH_TO_MS 1000/3600  // 1 km = 1000 m, 1 hour = 3600 s -> conversion from km/h to m/s

// This program calculates the acceleration of a jet during takeoff based on runway length and required speed.

int main(){
    double speed, acceleration, time, distance;

    printf("This program calculates the acceleration of a jet during takeoff.\n");
    printf("Enter the required takeoff speed (km/h):\n");
    scanf("%lf", &speed);

    printf("Enter the runway length (meters):\n");
    scanf("%lf", &distance);

    // Convert speed from km/h to m/s
    speed = speed * KMH_TO_MS;

    // Calculate time using the formula "t = 2s / v"
    time = 2 * distance / speed;

    // Calculate acceleration using "a = v/t"
    acceleration = speed / time;

    printf("Calculation results:\n\tAcceleration: %.2lf m/s^2\n\tTime until takeoff: %.2lf seconds\n", acceleration, time);

    return 0;
}

// Program limitations:
//  1. No input validation (non-numeric input will result in 0).
//  2. The formula does not account for external factors such as friction or air resistance.
//  3. Results may slightly vary due to rounding in calculations.
