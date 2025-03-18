#include <stdio.h>
// 4A untuk mengubah matrix tradisional menjadi sparse matrix
void scanMatrix(FILE *input, FILE *output) {
    int rows, cols, nonzero = 0, value;
    fscanf(input, "%d %d", &rows, &cols);
    fprintf(output, "%d %d\n", rows, cols);

    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(input, "%d", &matrix[i][j]);
            if (matrix[i][j] != 0) nonzero++;
        }
    }

    fprintf(output, "%d\n", nonzero);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0)
                fprintf(output, "%d %d %d\n", i, j, matrix[i][j]);
        }
    }
}

int main() {
    FILE *input = fopen("matrix.txt", "r");
    FILE *output = fopen("sparse.txt", "w");
    if (!input || !output) {
        printf("Error opening file.\n");
        return 1;
    }

    scanMatrix(input, output);
    fclose(input);
    fclose(output);
    printf("Matrix compressed successfully.\n");
    return 0;
}