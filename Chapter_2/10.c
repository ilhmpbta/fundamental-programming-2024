#include <stdio.h>

// This program calculates the equation of a perpendicular line from the given points

int main(){
    // Declare the necessary variables
    double xInput1, yInput1, xInput2, yInput2, xMidpoint, yMidpoint, mOriginal, mPerpendicular;

    printf("This program calculates the equation of a perpendicular line based on the points you input.\n");

    // Input the first coordinate (X1, Y1)
    printf("Please enter the X1 coordinate:\n");
    scanf("%lf", &xInput1);
    printf("Now enter the Y1 coordinate:\n");
    scanf("%lf", &yInput1);

    // Input the second coordinate (X2, Y2)
    printf("\nPlease enter the X2 coordinate:\n");
    scanf("%lf", &xInput2);
    printf("Now enter the Y2 coordinate:\n");
    scanf("%lf", &yInput2);

    // Process
    mOriginal = (yInput2 - yInput1) / (xInput2 - xInput1); // Calculate the slope of the given line
    mPerpendicular = -1 / mOriginal;                       // Since perpendicular slopes satisfy m1 * m2 = -1, we get m2 = -1/m1
    xMidpoint = (xInput1 + xInput2) / 2;                   // X-coordinate of the midpoint (average of both X values)
    yMidpoint = (yInput1 + yInput2) / 2;                   // Y-coordinate of the midpoint (average of both Y values)

    // Equation of the perpendicular line follows: y - yMidpoint = mPerpendicular * (x - xMidpoint)
    // Rewriting it into a cleaner form:
    // y - yMidpoint = (mPerpendicular)x - (mPerpendicular * xMidpoint)
    // y             = (mPerpendicular)x - (mPerpendicular * xMidpoint) + yMidpoint
    // y             = (mPerpendicular)x + constant

    double equationConstant;
    equationConstant = -1 * (mPerpendicular * xMidpoint) + yMidpoint;

    printf("The points you entered are (%.1lf,%.1lf) and (%.1lf,%.1lf)\n", xInput1, yInput1, xInput2, yInput2);
    printf("\tThe midpoint is (%.1lf,%.1lf)\n\tThe perpendicular slope is %.1lf\n\tSo the equation of the perpendicular line is y = %.1lfx + %.1lf\n", 
            xMidpoint, yMidpoint, mPerpendicular, mPerpendicular, equationConstant);

    return 0;
}

// Issues with this program:
//  1. If the line is vertical or horizontal (x1 = x2 or y1 = y2), the result will be infinity since the slope of a vertical line is undefined.
//  2. If the equation's constant is negative, the output may show double signs (e.g., 2x + -2.1). This is mathematically correct but looks bad.
//  3. The program does not prevent the user from entering letters, which will result in 0 for all values.
