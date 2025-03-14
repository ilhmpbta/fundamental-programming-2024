#include <stdio.h>
#include <string.h>
int undefined = 999;

/*
Write recursive functions that list all of the one-element, two-element, and 
three-element subsets of a given set of letters. For example,
one_ele_subs ("ACEG")
{A}, {C}, {E}, {G}

two_ele_subs ("ACEG")
{A, C}, {C, G}, {E, G}, {A, E}, {A, G}, {C, E}

three_ele_subs ("ACEG")
{A, C, E}, {A, C, G}, {A, E, G}, {C, E, G}
*/

void one_ele_subs(char inputs_made[undefined], int length);
void two_ele_subs(char inputs_made[undefined], int length);
void three_ele_subs(char inputs_made[undefined], int length);

int main(){
    char your_word[undefined];
    printf("Input the word that you'd like us to sub\n==> ");scanf("%s", your_word);
    int length = strlen(your_word);

    printf("One element subs:\n"); one_ele_subs(your_word, length); printf("\n\n");
    printf("Two element subs:\n"); two_ele_subs(your_word, length); printf("\n\n");
    printf("Three element subs:\n"); three_ele_subs(your_word, length); printf("\n\n");

}

void one_ele_subs(char inputs_made[undefined], int length){
    if (length <= 0) return;
    printf("{%c}\n", inputs_made[0]); one_ele_subs(&inputs_made[1], length-1);
}

void two_ele_subs(char inputs_made[undefined], int length){
    if (length <= 0) return;
    for(int i = 1; i < length; i++){
        printf("{%c, %c}\n", inputs_made[0], inputs_made[i]);
    } two_ele_subs(&inputs_made[1], length-1); // recursion to remove index 0 of array
}

void three_ele_subs(char inputs_made[undefined], int length){
    if (length <= 0) return;
    for(int i = 1; i < length; i++){
        for (int j = i + 1; j < length; j++){
            printf("{%c, %c, %c}\n", inputs_made[0], inputs_made[i], inputs_made[j]);
        }
    } three_ele_subs(&inputs_made[1], length-1); // recursion to remove index 0 of array
}
