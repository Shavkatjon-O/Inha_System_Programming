// REAL NUMBER VECTOR MULTIPLICATION ROUTINE

void rmul_vec(double p[], double q[], double r[], int m) {
    for (int i = 0; i < m; i++) {
        r[i] = p[i] * q[i];
    }
}
