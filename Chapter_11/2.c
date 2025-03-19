#include <stdio.h>

// Write a program that merges the contents of two text files in such a way that 
// the contents of file 2 must be followed by the contents of file 1. Here is an 
// example:  If the contents of file1 are “A binary file is a file created by executing a program that stores directly in the 
// file the computer’s internal representation of each file component.”
//and the contents of file 2 are “A pointer whose value equals NULL is called a null pointer.”
//the final output should be “A pointer whose value equals NULL is called a null pointer"
//A binary file is a file created by executing a program that stores directly in the 
// file the computer’s internal representation of each file component.

int main() {
    FILE *file1 = fopen("file1.txt", "r");
    FILE *file2 = fopen("file2.txt", "r");
    FILE *output = fopen("merged.txt", "w");

    if (!file1 || !file2 || !output) {
        printf("Error opening files.\n");
        return 1;
    }

    char ch;
    while ((ch = fgetc(file2)) != EOF) fputc(ch, output); fputc('\n', output);
    while ((ch = fgetc(file1)) != EOF) fputc(ch, output);

    fclose(file1);
    fclose(file2);
    fclose(output);

    printf("Files merged successfully.\n");
    return 0;
}
