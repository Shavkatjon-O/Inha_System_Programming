// REAL NUMBER VECTOR MULTIPLICATION BY CONSTANT ROUTINE

void rmulk_vec(double p[], double j, double r[], int m) {
    for (int i = 0; i < m; i++) {
        r[i] = p[i] * j;
    }
}
