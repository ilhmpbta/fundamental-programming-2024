#include <stdio.h>
#include <string.h>
#define header "================================================"       // defined here to avoid cluttering below

// Design and implement a structure type to model an ideal transformer. If 
// you have a single iron core with wire 1 coiled around the core N1 times and 
// wire 2 wound around the core N2 times, and if wire 1 is attached to a source 
// of alternating current, then the voltage in wire 1 (the input voltage V1) is 
// related to the voltage in wire 2 (the output voltage V2) as [V1 / V2 = N1 / N2]
// and the relationship between the input current I1 and the output current I2 is [I1 / I2 = N1 / N2]
// A variable of type transformer_t should store N1, N2, V1, and I1. Also, define 
// functions v_out and i_out to compute the output voltage and current of a 
// transformer. In addition, define functions that set each of the transformer's 
// components to produce a desired output voltage or current. For example, 
// function set_n1_for_v2 should take a desired output voltage as an input 
// parameter and a transformer as an input/output parameter and should change 
// the component representing N1 to produce the desired current. Also, define 
// set_v1_for_v2, set_n2_for_v2, and set_n2_for_i2. Include scan_
// transformer and print_transformer functions to facilitate I/O.

typedef struct {int N1, N2; double I1, I2, V1, V2;} transformer;        // This is the struct that will be used
void scan_transformer(transformer *scanned);                            // Declaration of functions that will be used
void print_transformer(transformer print);
double i_out(transformer transformed);
double v_out(transformer transformed);
transformer set_n1_for_v2(transformer setter, double desired_v2);
transformer set_n2_for_v2(transformer setter, double desired_v2);
transformer set_n1_for_i2(transformer setter, double desired_i2);
transformer set_n2_for_i2(transformer setter, double desired_i2);

int main() {
    printf("%s\nThis is a dynamic transformator value calculator\n%s\n", header, header);
    transformer transformator;
    scan_transformer(&transformator);
    transformator.V2 = v_out(transformator);    // calculate v2 result using formula v2 = v1 * n2/n1
    transformator.I2 = i_out(transformator);    // calculate i2 result using formula i2 = i1 * n2/n1
    print_transformer(transformator);

    char continue_loop = 'Y'; // Variable to control the loop
    while (continue_loop == 'Y' || continue_loop == 'y') {
        int command = 0;
        printf("\nWhich part of the transformer would you like to modify?\n");
        printf("1. Set N1 based on V2 input\n");
        printf("2. Set N2 based on V2 input\n");
        printf("3. Set N1 based on I2 input\n");
        printf("4. Set N2 based on I2 input\n");
        printf("Enter your choice => ");
        scanf("%d", &command);

        char your_wish_is_my_command[100]; switch (command){
            case 1: case 2: strcpy(your_wish_is_my_command, "V2"); break;
            case 3: case 4: strcpy(your_wish_is_my_command, "I2"); break;
            default: strcpy(your_wish_is_my_command, "??"); break;
        } // this is just a clarification (in case the user forgets their own choice)

        double modified_value;
        printf("Enter the desired value for %s => ", your_wish_is_my_command); scanf("%lf", &modified_value);

        switch (command) {
            case 1: transformator = set_n1_for_v2(transformator, modified_value); break;
            case 2: transformator = set_n2_for_v2(transformator, modified_value); break;
            case 3: transformator = set_n1_for_i2(transformator, modified_value); break;
            case 4: transformator = set_n2_for_i2(transformator, modified_value); break;
            default: printf("Invalid choice. Try again.\n"); continue; // to repeat the switch
        }

        transformator.V2 = v_out(transformator); transformator.I2 = i_out(transformator); // permanent replacement with modified values
        print_transformer(transformator); // display current transformer specifications

        printf("\nWould you like to modify another value? (Y/N): "); scanf(" %c", &continue_loop); // main() looping command
    }

    printf("\nFinal transformer configuration:\n"); print_transformer(transformator);
    return 0;
}

// Function implementations
void scan_transformer(transformer *scanned) {
    printf("Input N1 value => "); scanf("%d", &scanned->N1);
    printf("Input N2 value => "); scanf("%d", &scanned->N2);
    printf("Input V1 value => "); scanf("%lf", &scanned->V1);
    printf("Input I1 value => "); scanf("%lf", &scanned->I1);
    printf("\nCalculating.."); for (int i = 0; i <= 10; i++) {printf(".");if (i == 10) printf("\n\n");} // simple loading animation
}

double v_out(transformer transformed) {
    return transformed.V1 * (double)transformed.N2 / (double)transformed.N1;
} double i_out(transformer transformed) {
    return transformed.I1 * (double)transformed.N2 / (double)transformed.N1;
}

transformer set_n1_for_v2(transformer setter, double desired_v2) {
    setter.N1 = (int)(setter.N2 * setter.V1 / desired_v2); return setter;
} transformer set_n2_for_v2(transformer setter, double desired_v2) {
    setter.N2 = (int)(desired_v2 * setter.N1 / setter.V1); return setter;
} transformer set_n1_for_i2(transformer setter, double desired_i2) {
    setter.N1 = (int)(setter.N2 * setter.I1 / desired_i2); return setter;
} transformer set_n2_for_i2(transformer setter, double desired_i2) {
    setter.N2 = (int)(desired_i2 * setter.N1 / setter.I1); return setter;
}


void print_transformer(transformer print) {
    printf("\nCurrent transformer configuration\n");
    printf("N1 value is %d\n", print.N1);
    printf("N2 value is %d\n", print.N2);
    printf("V1 value is %.1lf\n", print.V1);
    printf("V2 Value is %.1lf\n", print.V2);
    printf("I1 value is %.1lf\n", print.I1);
    printf("I2 value is %.1lf\n", print.I2);
}
