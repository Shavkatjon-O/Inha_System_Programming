#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void multiplyMatrices(float **A, float **B, float **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

void transposeMatrix(float **B, float **Bt, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Bt[i][j] = B[j][i];
        }
    }
}


int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <N> <MatrixA_File> <MatrixB_File> <MatrixC_File>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char *matrixA_file = argv[2];
    char *matrixB_file = argv[3];
    char *matrixC_file = argv[4];

    float **A = (float **)malloc(n * sizeof(float *));
    float **B = (float **)malloc(n * sizeof(float *));
    float **Bt = (float **)malloc(n * sizeof(float *));
    float **C = (float **)malloc(n * sizeof(float *));

    for (int i = 0; i < n; i++) {
        A[i] = (float *)malloc(n * sizeof(float));
        B[i] = (float *)malloc(n * sizeof(float));
        Bt[i] = (float *)malloc(n * sizeof(float));
        C[i] = (float *)malloc(n * sizeof(float));
    }

    FILE *fileA = fopen(matrixA_file, "r");
    FILE *fileB = fopen(matrixB_file, "r");

    if (fileA == NULL || fileB == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fileA, "%f", &A[i][j]);
            fscanf(fileB, "%f", &B[i][j]);
        }
    }

    fclose(fileA);
    fclose(fileB);

    transposeMatrix(B, Bt, n);

    clock_t start = clock();

    multiplyMatrices(A, Bt, C, n);
    
    clock_t end = clock();
    
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    FILE *fileC = fopen(matrixC_file, "w");
    if (fileC == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(fileC, "%f ", C[i][j]);
            printf("%f\t", C[i][j]);
        }
        fprintf(fileC, "\n");
        printf("\n");
    }

    fclose(fileC);

    FILE *time_file = fopen("time_taken.txt", "a");
    if (time_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(time_file, "N=%d: Time taken = %f seconds\n", n, cpu_time_used);
    printf("N=%d: Time taken = %f seconds\n", n, cpu_time_used);

    fclose(time_file);

    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(Bt[i]);
        free(C[i]);
    }
    
    free(A);
    free(B);
    free(Bt);
    free(C);

    return 0;
}
