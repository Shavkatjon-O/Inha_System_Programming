// REAL NUMBER VECTOR SORTING ROUTINE (Bubble Sort)

void rsort_vec(double p[], int s, double r[], int m) {
    if (s == 1) {
        // ASCENDING
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < m - i - 1; j++) {
                if (p[j] > p[j + 1]) {
                    double temp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            r[i] = p[i];
        }
    } else {
        // DESCENDING
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < m - i - 1; j++) {
                if (p[j] < p[j + 1]) {
                    double temp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            r[i] = p[i];
        }
    }
}
