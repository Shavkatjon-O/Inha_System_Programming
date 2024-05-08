// INTEGER MATRIX TRANSPOSE ROUTINE

void imattrans(int n, int a[n][n], int c[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[j][i] = a[i][j];
        }
    }
}
