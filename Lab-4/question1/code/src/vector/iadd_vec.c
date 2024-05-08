// INTEGER VECTOR ADDITION ROUTINE

void iadd_vec(int p[], int q[], int r[], int m) {
    for (int i = 0; i < m; i++) {
        r[i] = p[i] + q[i];
    }
}
