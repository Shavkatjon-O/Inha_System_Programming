#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void mmatijk(int N, double **A, double **B, double **C) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void mmatjik(int N, double **A, double **B, double **C) {
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void mmatjki(int N, double **A, double **B, double **C) {
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void mmatkji(int N, double **A, double **B, double **C) {
    for (int k = 0; k < N; k++) {
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void mmatkij(int N, double **A, double **B, double **C) {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void mmatikj(int N, double **A, double **B, double **C) {
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            for (int j = 0; j < N; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s N A_matrix_file B_matrix_file C_matrix_prefix\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    char *A_file = argv[2];
    char *B_file = argv[3];
    char *C_prefix = argv[4];

    double **A = (double **)malloc(N * sizeof(double *));
    double **B = (double **)malloc(N * sizeof(double *));
    double **C = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        A[i] = (double *)malloc(N * sizeof(double));
        B[i] = (double *)malloc(N * sizeof(double));
        C[i] = (double *)malloc(N * sizeof(double));
    }

    FILE *A_fp = fopen(A_file, "r");
    FILE *B_fp = fopen(B_file, "r");
    if (A_fp == NULL || B_fp == NULL) {
        printf("Error: Unable to open input files.\n");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(A_fp, "%lf", &A[i][j]);
            fscanf(B_fp, "%lf", &B[i][j]);
        }
    }
    fclose(A_fp);
    fclose(B_fp);

    clock_t start_time, end_time;
    for (int version = 1; version <= 6; version++) {
        char filename[100];
        sprintf(filename, "%s_version%d.txt", C_prefix, version);
        FILE *C_fp = fopen(filename, "w");
        if (C_fp == NULL) {
            printf("Error: Unable to open output file.\n");
            return 1;
        }

        start_time = clock();
        switch (version) {
            case 1:
                mmatijk(N, A, B, C);
                break;
            case 2:
                mmatjik(N, A, B, C);
                break;
            case 3:
                mmatjki(N, A, B, C);
                break;
            case 4:
                mmatkji(N, A, B, C);
                break;
            case 5:
                mmatkij(N, A, B, C);
                break;
            case 6:
                mmatikj(N, A, B, C);
                break;
            default:
                printf("Error: Invalid version number.\n");
                return 1;
        }
        end_time = clock();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                fprintf(C_fp, "%lf ", C[i][j]);
            }
            fprintf(C_fp, "\n");
        }
        fclose(C_fp);

        printf("Version %d CPU time: %.6f seconds\n", version, (double)(end_time - start_time) / CLOCKS_PER_SEC);
    }

    for (int i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
