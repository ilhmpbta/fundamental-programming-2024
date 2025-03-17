#include <stdio.h>
#include <math.h>

// (a fraction) and its exponent (an integer). Define a type sci_not_t that has
// separate components for these two parts. Define a function scan_sci sci_not_tthat
// takes from the input source a string representing a positive number in scientific
// notation, and breaks it into components for storage in a sci_not_t structure. The
// mantissa of an input value (m) should satisfy this condition: 0.1 <= m < 1.0.
// Also, write functions to compute the sum, difference, product, and quotient
// of two sci_not_t values. All these functions should have a result type of
// sci_not_t and should ensure that the result’s mantissa is in the prescribed
// range. Define a print_sci function as well. Then, create a driver program to
// test your functions. Your output should be of this form:
// Values input: 0.25000e3 0.20000e1
// Sum: 0.25200e3
// Difference: 0.24800e3
// Product: 0.50000e3
// Quotient: 0.12500e3

typedef struct {double mantissa; int exponent;} sci_not_t;
sci_not_t scan_sci(double input);
sci_not_t sum_sci(sci_not_t a, sci_not_t b);
sci_not_t diifference_sci(sci_not_t a, sci_not_t b);
sci_not_t prdoduct_sci(sci_not_t a, sci_not_t b);
sci_not_t quotient_sci(sci_not_t a, sci_not_t b);
sci_not_t normalize_sci(sci_not_t value);
void print_sci(sci_not_t value);

int main() {
    double input1, input2;
    printf("Enter thy's mantissa and exponent (e.g., 0.25000e3 0.20000e1):\n");
    printf("Value 1 => "); scanf("%lf", &input1);
    printf("Value 2 => "); scanf("%lf", &input2);

    // Konversi input menjadi struct
    sci_not_t val1 = scan_sci(input1);
    sci_not_t val2 = scan_sci(input2);
    sci_not_t sum = sum_sci(val1, val2);
    sci_not_t diff = diifference_sci(val1, val2);
    sci_not_t prod = prdoduct_sci(val1, val2);
    sci_not_t quot = quotient_sci(val1, val2);

    // Output hasil
    printf("\nValues input:\n");
    printf("- "); print_sci(val1);
    printf("- "); print_sci(val2);
    printf("\nResults:\n");
    printf("Sum\t\t: "); print_sci(sum);
    printf("Difference\t: "); print_sci(diff);
    printf("Product\t\t: "); print_sci(prod);
    printf("Quotient\t: "); print_sci(quot);

    return 0;
}

sci_not_t scan_sci(double input) {
    sci_not_t value; value.exponent = 0;

    while (input >= 1.0) {
        input /= 10.0; value.exponent++; // to count the exponent by dividing it to 10
    } while (input < 0.1 && input > 0) {
        input *= 10.0; value.exponent--; // for a case where the exponent is 0 < x < 1
    } value.mantissa = input; // the final count is returned into the struct
    return value;
}

// Function to normalize a sci_not_t value
sci_not_t normalize_sci(sci_not_t value) {
    while (value.mantissa >= 1.0) {
        value.mantissa /= 10.0; value.exponent++;
    } while (value.mantissa < 0.1 && value.mantissa > 0) {
        value.mantissa *= 10.0; value.exponent--; // for a case where the exponent is 0 < x < 1
    } return value;
}

void print_sci(sci_not_t value) {
    printf("%.5lfe%d\n", value.mantissa, value.exponent);
}

sci_not_t sum_sci(sci_not_t a, sci_not_t b) {
    while (a.exponent > b.exponent) {
        b.mantissa /= 10.0; b.exponent++; // equalizing the exponent to make the operation easier
    } while (b.exponent > a.exponent) {
        a.mantissa /= 10.0; a.exponent++;
    } sci_not_t result = {a.mantissa + b.mantissa, a.exponent}; // result struct
    return normalize_sci(result);
}

// Function to subtract two sci_not_t values
sci_not_t diifference_sci(sci_not_t a, sci_not_t b) {
    while (a.exponent > b.exponent) {
        b.mantissa /= 10.0; b.exponent++;
    } while (b.exponent > a.exponent) {
        a.mantissa /= 10.0; a.exponent++;
    } sci_not_t result = {a.mantissa - b.mantissa, a.exponent}; // struct hasil operasi
    return normalize_sci(result);
}

// Function to multiply two sci_not_t values
sci_not_t prdoduct_sci(sci_not_t a, sci_not_t b) {
    sci_not_t result = {a.mantissa * b.mantissa, a.exponent + b.exponent}; // struct hasil operasi
    return normalize_sci(result);
}

// Function to divide two sci_not_t values
sci_not_t quotient_sci(sci_not_t a, sci_not_t b) {
    sci_not_t result = {a.mantissa / b.mantissa, a.exponent - b.exponent}; // struct hasil operasi
    return normalize_sci(result);
}
