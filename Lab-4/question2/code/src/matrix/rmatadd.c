// REAL NUMBER MATRIX ADDITION ROUTINE

void rmatadd(int n, double a[n][n], double b[n][n], double c[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
