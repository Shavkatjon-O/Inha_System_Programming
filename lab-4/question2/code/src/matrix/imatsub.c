// INTEGER MATRIX SUBTRACTION ROUTINE

void imatsub(int n, int a[n][n], int b[n][n], int c[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}
