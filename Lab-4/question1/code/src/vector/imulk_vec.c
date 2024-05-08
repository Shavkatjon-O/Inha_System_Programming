// INTEGER VECTOR MULTIPLICATION BY CONSTANT ROUNTINE

void imulk_vec(int x[], int k, int z[], int n) {
    for (int i = 0; i < n; i++) {
        z[i] = x[i] * k;
    }
}
