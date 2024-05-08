// INTEGER VECTOR REVERSAL ROUTINE

void irev_vec(int x[], int y[], int n) {
    for (int i = 0; i < n; i++) {
        y[i] = x[n - 1 - i];
    }
}
