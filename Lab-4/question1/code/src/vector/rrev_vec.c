// REAL NUMBER VECTOR REVERSAL ROUTINE

void rrev_vec(double p[], double r[], int m) {
    for (int i = 0; i < m; i++) {
        r[i] = p[m - 1 - i];
    }
}
