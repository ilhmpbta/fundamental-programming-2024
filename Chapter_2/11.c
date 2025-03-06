#include <stdio.h>
#include <math.h>                               // Using math.h only for fabs, to avoid negative side lengths looking messy

// This program generates a Pythagorean triple from two input numbers, treating them as the two sides of a right triangle

int main(){
    double m, n, side1, side2, hypotenuse;      // "Hypotenuse" is a less common word, so using "side" for clarity

    printf("This program generates a Pythagorean triple.\nPlease enter a random number:\n");
    scanf("%lf", &m);
    printf("One more random number:\n");
    scanf("%lf", &n);

    // Calculation process (formula is taken from a textbook, so it's straightforward)
    side1      = (m * m) - (n * n);
    side2      = 2 * (m * n);
    hypotenuse = (m * m) + (n * n);

    side1 = fabs(side1);
    side2 = fabs(side2);
    hypotenuse = fabs(hypotenuse);

    printf("Your generated Pythagorean triple:\n\tSide 1 = %.1lf\n\tSide 2 = %.1lf\n\tHypotenuse = %.1lf\n", 
    side1, side2, hypotenuse);

    return 0;
}

// Issues with this program:
//  1. Without the <math.h> header, side1 would be negative if m < n due to subtraction.
//  2. If non-integer values are input, precision may be slightly off due to floating-point rounding.
//  3. The program does not prevent users from entering letters, which results in all values being 0.
