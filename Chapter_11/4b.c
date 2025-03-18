#include <stdio.h>

void scanSparse(FILE *input, FILE *output) {
    int rows, cols, nonzero;
    fscanf(input, "%d %d", &rows, &cols);
    fscanf(input, "%d", &nonzero);

    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < nonzero; i++) {
        int row, col, value;
        fscanf(input, "%d %d %d", &row, &col, &value);
        matrix[row][col] = value;
    }

    fprintf(output, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(output, "%d ", matrix[i][j]);
        }
        fprintf(output, "\n");
    }
}

int main() {
    FILE *input = fopen("sparse.txt", "r");
    FILE *output = fopen("matrix_out.txt", "w");
    if (!input || !output) {
        printf("Error opening file.\n");
        return 1;
    }

    scanSparse(input, output);
    fclose(input);
    fclose(output);
    printf("Sparse matrix decompressed successfully.\n");
    return 0;
}