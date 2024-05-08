#ifndef MATRIX_H
#define MATRIX_H

// INTEGER MATRIX OPERATION ROUTINES
void imatadd    (int n, int a[n][n], int b[n][n], int c[n][n]);
void imatsub    (int n, int a[n][n], int b[n][n], int c[n][n]);
void imatmult   (int n, int a[n][n], int b[n][n], int c[n][n]);
void imattrans  (int n, int a[n][n], int c[n][n]);

// REAL NUMBER MATRIX OPERATION ROUTINES
void rmatadd    (int n, double a[n][n], double b[n][n], double c[n][n]);
void rmatsub    (int n, double a[n][n], double b[n][n], double c[n][n]);
void rmatmult   (int n, double a[n][n], double b[n][n], double c[n][n]);
void rmattrans  (int n, double a[n][n], double c[n][n]);

#endif
