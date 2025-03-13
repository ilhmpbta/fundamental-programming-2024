#include <stdio.h>
#include <string.h>

/*Write a program that processes a data file of names in which each name is on a separate line of at most 80 characters. Here are two sample names:
Hartman-Montgomery, Jane R.
Doe, J. D.
On each line the surname is followed by a comma and a space. Next comes the first name or initial, then a space and the middle initial. Your program
should scan the names into three arrays—surname, first, and middle_init.
If the surname is longer than 15 characters, store only the first 15. Similarly, limit the first name to ten characters. Do not store periods in the first and middle_init arrays. Write the array's contents to a file, aligning the contents of each column:
Hartman-Montgom Jane R
Doe J D
*/

int main(){
    char names[3][16]; //initialize array for 3 parts of the name
    char temp[80];
    printf("Name speller program that works like magic!\nFormat: lastname, firstname middlename. (write '-1' to quit the prgoram)\n");

    do {
    for(int i = 0; i < 3; i++){
        names[i][0] = '\0';
    } // to clear the string each time the loop runs

    for(int i = 0; i < 3; i++){
        scanf("%s", temp);
        if(temp[strlen(temp) - 1] == '.' || temp[strlen(temp) - 1] == ',') temp[strlen(temp) - 1] = '\0'; //remove commas and periods
        if(strcmp(temp, "-1") == 0){
            printf("Thank you for using our program\n");
            return 0;
        }
        
        if(i == 1) {
            strncpy(names[i], temp, 10); //first name can only be 10 characters
            names[i][10] = '\0';
        } else if (i != 1){
            strncpy(names[i], temp, 15); //names other than firstname can hold up to 15 characters
            names[i][15] = '\0';
        }
    }

    printf("%-15s   %-10s   %-15s\n", names[0], names[1], names[2]);
    } while (1);
}