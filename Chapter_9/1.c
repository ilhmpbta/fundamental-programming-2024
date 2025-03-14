#include <stdio.h>

// initialize global variables to simplify the code (instead of using pointers)
int undefined = 1000;
int size = 0;
int blobman = 0;
int counter = 0;

void blob_checker(int array[undefined][undefined], int i, int j);
int valid_checker(int array[undefined][undefined], int i, int j);

int main(){
    printf("Input the length/width of your picture (it is a square) ==> ");
    scanf("%d", &size); int matrix[undefined][undefined];
    int blob_amount[undefined];

    // Scan the blobs
    printf("Input the pixels (0) for no pixel (1) if there is a pixel on the location specified\n");
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("Input for (%d,%d) ==> ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    } printf("\n"); // separator for cleaner output

    // Print the blobs
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("%d ", matrix[i][j]);
        } printf("\n"); // line separator
    }

    // Check for blobs
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (matrix[i][j] == 1) blob_checker(matrix, i, j);
            if (counter != 0) {
                blob_amount[blobman] = counter; // store the blob count
                blobman += 1; // switch to next blob index array after recursion
                counter = 0; // reset to 0
            }
        }
    }

    // Output the amount of blobs
    printf("Amount of blobs: %d\n", blobman);
    for(int i = 0; i < blobman; i++){
        printf("Blob chain - %d: %d blobs\n", i+1, blob_amount[i]);
    }
}

int valid_checker(int array[undefined][undefined], int i, int j){
    if ((i <= size && i >= 0) && (j <= size && j >= 0)) return 1;
    return 0;
}

void blob_checker(int array[undefined][undefined], int i, int j){
    if (array[i][j] == 0 || valid_checker(array, i, j) == 0) {return;
    } else {
        array[i][j] = 0;
        counter++;
    }

    // recurse 8 times for all diagonal directions
    blob_checker(array, i+1, j);
    blob_checker(array, i-1, j);
    blob_checker(array, i, j+1);
    blob_checker(array, i, j-1);
    blob_checker(array, i+1, j+1); // upper right diagonal
    blob_checker(array, i-1, j+1); // lower right diagonal
    blob_checker(array, i+1, j-1); // upper left diagonal
    blob_checker(array, i-1, j-1); // lower left diagonal
}