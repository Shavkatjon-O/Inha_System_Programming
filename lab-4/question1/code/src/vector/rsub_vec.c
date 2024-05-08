// REAL NUMBER VECTOR SUBTRACTION ROUTINE

void rsub_vec(double p[], double q[], double r[], int m) {
    for (int i = 0; i < m; i++) {
        r[i] = p[i] - q[i];
    }
}
