// INTEGER VECTOR SORTING ROUTINE (Bubble SOrt)

void isort_vec(int x[], int s, int z[], int n) {
    if (s == 1) {
        // ASCENDING
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (x[j] > x[j + 1]) {
                    int temp = x[j];
                    x[j] = x[j + 1];
                    x[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            z[i] = x[i];
        }
    } else {
        // DESCENDING
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (x[j] < x[j + 1]) {
                    int temp = x[j];
                    x[j] = x[j + 1];
                    x[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            z[i] = x[i];
        }
    }
}
