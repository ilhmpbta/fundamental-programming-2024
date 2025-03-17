#include <stdio.h>
#include <string.h>
#define header "================================================================================="

// Microbiologists estimating the number of bacteria in a sample that contains 
// bacteria that do not grow well on solid media may use a statistical technique 
// called the most probable number (MPN) method. Each of five tubes of nutri-
// ent medium receives 10 ml of the sample. A second set of five tubes receives 
// 1 ml of sample per tube, and in each of a third set of five tubes, only 0.1 ml of 
// sample is placed. Each tube in which bacterial growth is observed is recorded 
// as a positive, and the numbers for the three groups are combined to create a 
// triplet such as 5-2-1, which means that all five tubes receiving 10 ml of sam-
// ple show bacterial growth, only two tubes in the 1-ml group show growth, 
// and only one of the 0.1-ml group is positive. A microbiologist would use this 
// combination-of-positives triplet as an index to a table like the table below to 
// determine that the most probable number of bacteria per 100 ml of the sample
// is 70, and 95% of the samples yielding this triplet contain between 30 and 210 
// bacteria per 100 ml. Define a structure type to represent one row of the MPN table. The 
// structure will include one string component for the combination-of-positives 
// triplet and three integer components in which to store the associated most 
// probable number and the lower and upper bounds of the 95% confidence 
// range. Write a program to implement the following algorithm for generating 
// explanations of combination-of-positives triplets.
// a. Load the MPN table from a file into an array of structures called mpn_table.
// b. Repeatedly get from the user a combination-of-positives triplet, search 
//     for it in the combination-of-positives components of mpn_table, and then 
//     generate a message such as:
//     For 5-2-1, MPN = 70; 95% of samples contain between 30 and 210 bacteria/ml.
// c. Define and call the following functions.
//     load_Mpn_Table—Takes as parameters the name of the input file, the 
//     mpn_table array and its maximum size. Function opens the file, fills 
//     the mpn_table array, and closes the file. Then it returns the actual 
//     array size as the function result. If the file contains too much data, the 
//     function should store as much data as will fit, display an error mes-
//     sage indicating that some data has been ignored, and return the array’s 
//     maximum size as its actual size.
// search—Takes as parameters the mpn_table array, its actual size, and a 
// target string representing a combination-of-positives triplet. Returns 
// the subscript of the structure whose combination-of-positives compo-
// nent matches the target or 21 if not found

typedef struct {char combination[5]; int mpn_index, lower, upper;} mpn_table;
mpn_table table_of_bacterial_concentrations[17] = {
    {"4-2-0", 22, 9, 56}, {"4-2-1", 26, 12, 65}, {"4-3-0", 27, 12, 67},
    {"4-3-1", 33, 15, 77}, {"4-4-0", 34, 16, 80}, {"5-0-0", 23, 9, 86},
    {"5-0-1", 30, 10, 110}, {"5-0-2", 40, 20, 140}, {"5-1-0", 30, 10, 120},
    {"5-1-1", 50, 20, 150}, {"5-1-2", 60, 30, 180}, {"5-2-0", 50, 20, 170},
    {"5-2-1", 70, 30, 210}, {"5-2-2", 90, 40, 250}, {"5-3-0", 80, 30, 250},
    {"5-3-1", 110, 40, 300}, {"5-3-2", 140, 60, 360} // declaring the data that was already given by the pdf
};

int search (mpn_table bact_data[], char input[]){
    int index, found = 0; for(index = 0; index < 17; index++){
        if(strcmp(input, bact_data[index].combination) == 0){
            found = 1; break;
        }
    } if (found == 1){
        printf("For %s, MPN = %d, 95%% of samples contain between %d and %d bacteria\n\n",
        bact_data[index].combination, bact_data[index].mpn_index, bact_data[index].lower, bact_data[index].upper);
        found = 0;
    } else if (found == 0) printf("Combination %s not found on the MPN table\n\n", input);
    return 1;
}

int main(){
    char input[5], command;
    printf("%s\nInput a positive-triplet-combination and we shall find MPN (input cancel to stop)\n%s\n", header, header);
    do{
        printf("(example: 4-2-0 or 'cancel' to stop) => "); scanf("%s", input);
        if (strcmp(input, "cancel") == 0) break;
        search(table_of_bacterial_concentrations, input);
    } while(1);
    return 0;
}