#include <stdio.h>
#include <ctype.h>

// Write a program that reads the data from a text file and prints all the upper-
// case letters present in it into another text file. The program must generate an 
// error message if necessary. Modify the same program to read a text file and 
// print all the lines that start with letter “A” instead. This program too must
// generate an error message if necessary. (Hint: You may have to first create a file 
// and then pass its name in fopen function).

void extractUppercase(const char *inputFile, const char *outputFile);
void extractLinesStartingWithA(const char *inputFile, const char *outputFile);

int main() {
    extractUppercase("input.txt", "uppercase_output.txt");
    extractLinesStartingWithA("input.txt", "lines_starting_with_A.txt");
    return 0;
}

void extractUppercase(const char *inputFile, const char *outputFile) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "w");

    if (!input || !output) {
        printf("Error opening files.\n");
        return;
    }

    char ch;
    while ((ch = fgetc(input)) != EOF) {
        if (isupper(ch)) fputc(ch, output);
    }

    fclose(input);
    fclose(output);
    printf("Uppercase letters extracted successfully.\n");
}

void extractLinesStartingWithA(const char *inputFile, const char *outputFile) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "w");

    if (!input || !output) {
        printf("Error opening files.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), input)) {
        if (line[0] == 'A') fputs(line, output);
    }

    fclose(input);
    fclose(output);
    printf("Lines starting with 'A' extracted successfully.\n");
}