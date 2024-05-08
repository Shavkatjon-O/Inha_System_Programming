#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <dlfcn.h>

#include "../include/matrix.h"


void printLine(char c) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    for (int i = 0; i < w.ws_col; i++) {
        printf("%c", c);
    }
    printf("\n");
}

void printIntegerMatrix(int size, int matrix[size][size]) {
    for (int i = 0; i < size; i++) {
        printf("ROW [%d]: ", i);
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printRealNumberMatrix(int size, double matrix[size][size]) {
    for (int i = 0; i < size; i++) {
        printf("ROW [%d]: ", i);
        for (int j = 0; j < size; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void takeIntegerMatrix(const char* name, int size, int matrix[size][size]) {
    printf("[INTEGER] ENTER %d ELEMENTS OF %dx%d MATRIX [%s]\n", size * size, size, size, name);
    printLine('-');

    for (int i = 0; i < size; i++) {
        printf("[INTEGER] ENTER ROW (separated with space \" \") - [%d]: ", i);
        int c;
        for (int j = 0; j < size; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Insufficient input provided.\n");
                return;
            }
        }
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
}

void takeRealNumberMatrix(const char* name, int size, double matrix[size][size]) {
    printf("[REAL NUMBER] ENTER %d ELEMENTS OF %dx%d MATRIX [%s]\n", size * size, size, size, name);
    printLine('-');

    for (int i = 0; i < size; i++) {
        printf("[REAL NUMBER] ENTER ROW (separated with space \" \") - [%d]: ", i);
        int c;
        for (int j = 0; j < size; j++) {
            if (scanf("%lf", &matrix[i][j]) != 1) {
                printf("Insufficient input provided.\n");
                return;
            }
        }
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
}

void performIntegerMatrix(
    int size,
    int a[size][size],
    int b[size][size],
    int c[size][size],
    void* lib
) {
    void (*imatadd)   (int n, int[n][n], int[n][n], int[n][n]) = dlsym(lib, "imatadd");
    void (*imatmult)  (int n, int[n][n], int[n][n], int[n][n]) = dlsym(lib, "imatmult");
    void (*imatsub)   (int n, int[n][n], int[n][n], int[n][n]) = dlsym(lib, "imatsub");
    void (*imattrans) (int n, int[n][n], int[n][n]) = dlsym(lib, "imattrans");

    printf("[INTEGER] ADDITION\n");
    printLine('-');
    imatadd(size, a, b, c);
    printIntegerMatrix(size, c);
    printLine('-');

    printf("[INTEGER] MULTIPLICATION\n");
    printLine('-');
    imatmult(size, a, b, c);
    printIntegerMatrix(size, c);
    printLine('-');

    printf("[INTEGER] SUBTRACTION\n");
    printLine('-');
    imatsub(size, a, b, c);
    printIntegerMatrix(size, c);
    printLine('-');

    printf("[INTEGER] TRANSPOSE\n");
    printLine('-');
    imattrans(size, a, c);
    printIntegerMatrix(size, c);
}

void performRealNumberMatrix(
    int size,
    double a[size][size],
    double b[size][size],
    double c[size][size],
    void* lib
) {
    void (*rmatadd)   (int n, double[n][n], double[n][n], double[n][n]) = dlsym(lib, "rmatadd");
    void (*rmatmult)  (int n, double[n][n], double[n][n], double[n][n]) = dlsym(lib, "rmatmult");
    void (*rmatsub)   (int n, double[n][n], double[n][n], double[n][n]) = dlsym(lib, "rmatsub");
    void (*rmattrans) (int n, double[n][n], double[n][n]) = dlsym(lib, "rmattrans");

    printf("[REAL NUMBER] ADDITION\n");
    printLine('-');
    rmatadd(size, a, b, c);
    printRealNumberMatrix(size, c);
    printLine('-');

    printf("[REAL NUMBER] MULTIPLICATION\n");
    printLine('-');
    rmatmult(size, a, b, c);
    printRealNumberMatrix(size, c);
    printLine('-');

    printf("[REAL NUMBER] SUBTRACTION\n");
    printLine('-');
    rmatsub(size, a, b, c);
    printRealNumberMatrix(size, c);
    printLine('-');

    printf("[REAL NUMBER] TRANSPOSE\n");
    printLine('-');
    rmattrans(size, a, c);
    printRealNumberMatrix(size, c);
}

int main() {

    /************************ LOAD SHARED LIBRARY *************************/

    void *lib = dlopen("./lib/shared/libmatrix.so", RTLD_LAZY);

    if (!lib) {
        fprintf(stderr, "error loading library: %s\n", dlerror());
        return 1;
    }

    /*************************** INTEGER MATRIX ***************************/
    
    int n;

    printLine('*');
    printf("[INTEGER] ENTER SIZE OF MATRICIES (min 15): ");
    scanf("%d", &n);

    int a[n][n], b[n][n], c[n][n];

    printLine('-');
    takeIntegerMatrix("A", n, a);
    printLine('-');
    takeIntegerMatrix("B", n, b);
    printLine('-');

    performIntegerMatrix(n, a, b, c, lib);


    /************************ REAL NUMBER MATRIX **************************/

    int m;

    printLine('*');
    printf("[REAL NUMBER] ENTER SIZE OF MATRICIES (min 15): ");
    scanf("%d", &m);

    double p[m][m], q[m][m], r[m][m];

    printLine('-');
    takeRealNumberMatrix("P", m, p);
    printLine('-');
    takeRealNumberMatrix("Q", m, q);
    printLine('-');

    performRealNumberMatrix(m, p, q, r, lib);
    printLine('*');

    dlclose(lib);

    return 0;
}