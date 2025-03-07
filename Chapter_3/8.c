#include <stdio.h>

/*
A bullet train slows from a speed of 200 mi/hr to 150 mi/hr in one minute. Write a computer program that calculates the bullet train's constant rate of acceleration and determines how long the bullet train will take to come to rest, given an initial speed of 200 mi/hr.
(Hint: Use the equation a = (vf -vi) / t)
Where a is acceleration, t is time interval, vi is initial velocity, and vf is final velocity.) Write and call a function that displays instructions to the program user and a function that computes a, given t, vf, and vi.
*/

double calculateConstantAcceleration(double vi, double vf, double t){
    vf = vf / 3600;             // Convert miles per hour to miles per second
    vi = vi / 3600;             // Same conversion
    t = t * 60;                 // Convert minutes to seconds, as acceleration is typically in units/second^2
    return (vf - vi) / t;
}

// This version keeps acceleration in miles/hour, since the problem doesn't specify required units
double calculateConstantAccelerationHour(double vi, double vf, double t){
    vf = vf;           
    vi = vi;             
    t = t / 60;          // Convert minutes to hours
    return (vf - vi) / t;
}

void displayInstructions() {
    printf("Finding the average acceleration of an event\n");
    printf("Please input initial velocity in mi/hr (space) final velocity in mi/hr (space) and time in minutes\n");
}

int main(){
    double initialVelocity, finalVelocity, time, constantAcceleration;
    // Don't forget to declare variables

    displayInstructions();
    scanf("%lf%lf%lf", &initialVelocity, &finalVelocity, &time);

    // Calculate the acceleration value
    constantAcceleration = calculateConstantAcceleration(initialVelocity, finalVelocity, time);

    // If acceleration is positive, it's acceleration; if negative, it's deceleration
    if (constantAcceleration >= 0){
        printf("The constant acceleration is %lf mi/sec^2\n", constantAcceleration);    // Just for clarity
        printf("The acceleration in terms of hours is %lf mi/hr^2\n", calculateConstantAccelerationHour(initialVelocity, finalVelocity, time));
    }
    else{
        printf("The constant deceleration is %lf mi/sec^2\n", constantAcceleration);   // negative acceleration -> deceleration
        printf("The deceleration in terms of hours is %lf mi/hr^2\n", calculateConstantAccelerationHour(initialVelocity, finalVelocity, time));
    }
    
    // Calculate time to come to rest from 200 mi/hr
    double timeToRest = -200 / calculateConstantAccelerationHour(initialVelocity, finalVelocity, time);
    printf("Time required for the train to come to rest from 200 mi/hr: %.2f minutes\n", timeToRest * 60);

    return 0;
}