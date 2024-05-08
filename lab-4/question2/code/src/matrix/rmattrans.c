// REAL NUMBER MATRIX TRANSPOSE ROUTINE

void rmattrans(int n, double a[n][n], double c[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[j][i] = a[i][j];
        }
    }
}
