// REAL NUMBER VECTOR ADDITION ROUTINE

void radd_vec(double p[], double q[], double r[], int m) {
    for (int i = 0; i < m; i++) {
        r[i] = p[i] + q[i];
    }
}
