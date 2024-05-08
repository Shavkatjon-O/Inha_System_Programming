// REAL NUMBER DIVISION BY CONSTANT ROUTINE

void rdivk_vec(double p[], double j, double r[], int m) {
    for (int i = 0; i < m; i++) {
        r[i] = p[i] / j;
    }
}
