// standard library header files
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

// custom library header file
#include "../include/vector.h"


void printLine(char s) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    for (int i = 0; i < w.ws_col; i++) {
        printf("%c", s);
    }
    printf("\n");
}

void printIntegerVector(int *vector, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", vector[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

void printRealNumberVector(double *vector, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%.2lf", vector[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

void takeIntegerVector(const char* name, int* vector, int size) {
    printf("[INTEGER] ENTER %d ELEMENTS OF INTEGER VECTOR <%s>\n", size, name);
    printLine('-');

    for (int i = 0; i < size; i++) {
        printf("[INTEGER] ENTER ELEMENT - %d: ", i + 1);
        scanf("%d", &vector[i]);
    }
}

void takeRealNumberVector(const char* name, double* vector, int size) {
    printf("[REAL NUMBER] ENTER %d ELEMENTS OF REAL NUMBER VECTOR <%s>\n", size, name);
    printLine('-');

    for (int i = 0; i < size; i++) {
        printf("[REAL NUMBER] ENTER ELEMENT - %d: ", i + 1);
        scanf("%lf", &vector[i]);
    }
}

void performIntegerVector(int* x, int* y, int* z, int size, int scalar) {
    iadd_vec(x, y, z, size);
    printf("[INTEGER] ADDITION: ");
    printIntegerVector(z, size);
    printLine('-');
    
    isub_vec(x, y, z, size);
    printf("[INTEGER] SUBTRACTION: ");
    printIntegerVector(z, size);
    printLine('-');

    imul_vec(x, y, z, size);
    printf("[INTEGER] MULTIPLICATION: ");
    printIntegerVector(z, size);
    printLine('-');

    idiv_vec(x, y, z, size);
    printf("[INTEGER] DIVISION: ");
    printIntegerVector(z, size);
    printLine('-');
    
    imulk_vec(x, scalar, z, size);
    printf("[INTEGER] SCALAR MULTIPLICATION: ");
    printIntegerVector(z, size);
    printLine('-');
    
    idivk_vec(x, scalar, z, size);
    printf("[INTEGER] SCALAR DIVISION: ");
    printIntegerVector(z, size);
    printLine('-');
    
    irev_vec(x, z, size);
    printf("[INTEGER] VECTOR REVERSAL: ");
    printIntegerVector(z, size);
    printLine('-');
    
    isort_vec(x, 1, z, size);
    printf("[INTEGER] VECTOR SORTING ASCENDING: ");
    printIntegerVector(z, size);
    printLine('-');

    isort_vec(x, 0, z, size);
    printf("[INTEGER] VECTOR SORTING DESCENDING: ");
    printIntegerVector(z, size);
}

void performRealNumberVector(double* x, double* y, double* z, int size, double scalar) {
    radd_vec(x, y, z, size);
    printf("[REAL NUMBER] ADDITION: ");
    printRealNumberVector(z, size);
    printLine('-');
    
    rsub_vec(x, y, z, size);
    printf("[REAL NUMBER] SUBTRACTION: ");
    printRealNumberVector(z, size);
    printLine('-');
    
    rmul_vec(x, y, z, size);
    printf("[REAL NUMBER] MULTIPLICATION: ");
    printRealNumberVector(z, size);
    printLine('-');
    
    rdiv_vec(x, y, z, size);
    printf("[REAL NUMBER] DIVISION: ");
    printRealNumberVector(z, size);
    printLine('-');
    
    rmulk_vec(x, scalar, z, size);
    printf("[REAL NUMBER] SCALAR MULTIPLICATION: ");
    printRealNumberVector(z, size);
    printLine('-');
    
    rdivk_vec(x, scalar, z, size);
    printf("[REAL NUMBER] SCALAR DIVISION: ");
    printRealNumberVector(z, size);
    printLine('-');
    
    rrev_vec(x, z, size);
    printf("[REAL NUMBER] VECTOR REVERSAL: ");
    printRealNumberVector(z, size);
    printLine('-');

    rsort_vec(x, 1, z, size);
    printf("[REAL NUMBER] VECTOR SORTING ASCENDING: ");
    printRealNumberVector(z, size);
    printLine('-');

    rsort_vec(x, 0, z, size);
    printf("[REAL NUMBER] VECTOR SORTING DESCENDING: ");
    printRealNumberVector(z, size);
}

int main() {

    /*************************** INTEGER VECTOR ***************************/

    int s;
    int n;
    int k;
    
    printLine('*');
    printf("[INTEGER] ENTER VECTOR SIZE (min 15): ");
    scanf("%d", &n);
    printf("[INTEGER] ENTER SCALAR: ");
    scanf("%d", &k);
    printf("[INTEGER] ENTER SORT OPTION (1 - ascending, 2 - descending): ");
    scanf("%d", &s);

    int x[n], y[n];

    printLine('-');
    takeIntegerVector("X", x, n);
    printLine('-');
    takeIntegerVector("Y", y, n);
    printLine('-');

    int z_i[n];

    performIntegerVector(x, y, z_i, n, k);
    printLine('*');

    /************************ REAL NUMBER VECTOR **************************/

    int m;
    double j;

    printf("[REAL NUMBER] ENTER VECTOR SIZE (min 15): ");
    scanf("%d", &m);
    printf("[REAL NUMBER] ENTER SCALAR: ");
    scanf("%lf", &j);
    printf("[REAL NUMBER] ENTER SORT OPTION (1 - ascending, 2 - descending): ");
    scanf("%d", &s);

    double p[m], q[m];

    printLine('-');
    takeRealNumberVector("P", p, m);
    printLine('-');
    takeRealNumberVector("Q", q, m);
    printLine('-');

    double z_r[m];

    performRealNumberVector(p, q, z_r, m, j);
    printLine('*');

    return 0;
}