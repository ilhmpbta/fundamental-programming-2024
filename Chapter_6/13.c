#include <stdio.h>
#include <ctype.h>

#define START 0
#define IDENTIFIER 1
#define NUMBER 2
#define STOP 3

/*
A finite state machine (FSM) consists of a set of states, a set of transitions, and a string of input data. In the FSM of Fig. 6.19, the named ovals represent states, and the arrows connecting the states represent transitions. The FSM is designed to recognize a list of C identifiers and nonnegative integers, assuming that the items are ended by one or more blanks and that a period marks the end of all the data. The following table traces how the diagrammed machine would process a string composed of one blank, the digits 9 and 5, two blanks, the letter K, the digit 9, one blank, and a period. The machine begins in the Start state.
Write a program that uses an enumerated type to represent the names of the states. Your program should process a correctly formatted line of data, identifying each data item. Here is a sample of correct input and output.
 Input:
 rate  R2D2 48    2 time    555666
 Output:
 rate – Identifier
 R2D2 – Identifier
 48 – Number
 2 – Number
 time – Identifier
 555666 – Number
Use the following code fragment in main, and design function transition to return the next state for all the numbered transitions of the finite state machine. If you include the header file ctype.h, you can use the library function isdigit, which returns 1 if called with a digit character, 0 otherwise. Similarly, the function isalpha checks whether a character is a letter. When your program correctly models the behavior of the FSM shown, extend the FSM and your program to allow optional signs and optional fractional parts (i.e., a decimal point followed by zero or more digits) in numbers.

current_state = Start;
do {
    if (current_state == identifier) {
          printf(" - Identifier\n");
          current_state = Start;
    } else if (current_state == number) {
          printf(" - Number\n");
          current_state = Start;
    }
    scanf("%c", &transition_char);
    if (transition_char != ' ')
          printf("%c", transition_char);
    current_state = transition(current_state, transition_char);
} while (current_state != stop);
*/

int transition(int current_state, char input_char) {
    if (current_state == START) {
        if (isalpha(input_char)) return IDENTIFIER;
        else if (isdigit(input_char)) return NUMBER;
        else if (input_char == '.')  return STOP;
    }

    else if (current_state == IDENTIFIER) {
        if (isalnum(input_char)) return IDENTIFIER;
        else if (input_char == ' ') return START;
        else if (input_char == '.') return STOP;
    }
    else if (current_state == NUMBER) {
        if (isdigit(input_char)) return NUMBER;
        else if (input_char == ' ') return START;
        else if (input_char == '.') return STOP;
    }

    return STOP;
}

int main() {
    int current_state = START;
    char transition_char;
    char buffer[100];
    int buffer_index = 0;

    printf("Enter input (end with a period): ");

    while (1) {
        scanf("%c", &transition_char);

        if (transition_char == '.') {
            if (buffer_index > 0) {
                buffer[buffer_index] = '\0';
                if (isdigit(buffer[0])) printf("%s - Number\n", buffer);
                else printf("%s - Identifier\n", buffer);
            }
            break;
        }

        if (transition_char == ' ') {
            if (current_state == IDENTIFIER || current_state == NUMBER) {
                buffer[buffer_index] = '\0';
                if (isdigit(buffer[0])) printf("%s - Number\n", buffer);
                else printf("%s - Identifier\n", buffer);

                buffer_index = 0;
            }
            current_state = START;
            continue;
        }

        buffer[buffer_index++] = transition_char;
        current_state = transition(current_state, transition_char);
    }

    return 0;
}