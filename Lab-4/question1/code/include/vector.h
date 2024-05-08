#ifndef VECTOR_H
#define VECTOR_H

// INTEGER VECTOR OPERATIONS ROUTINES
void iadd_vec   (int x[], int y[], int z[], int n);
void isub_vec   (int x[], int y[], int z[], int n);
void imul_vec   (int x[], int y[], int z[], int n);
void idiv_vec   (int x[], int y[], int z[], int n);

void imulk_vec  (int x[], int k, int z[], int n);
void idivk_vec  (int x[], int k, int z[], int n);

void irev_vec   (int x[], int y[], int n);
void isort_vec  (int x[], int s, int z[], int n);

// REAL NUMBER VECTOR OPERATIONS ROUTINES
void radd_vec   (double x[], double y[], double z[], int n);
void rsub_vec   (double x[], double y[], double z[], int n);
void rmul_vec   (double x[], double y[], double z[], int n);
void rdiv_vec   (double x[], double y[], double z[], int n);

void rmulk_vec  (double x[], double j, double z[], int n);
void rdivk_vec  (double x[], double j, double z[], int n);

void rrev_vec   (double x[], double z[], int n);
void rsort_vec  (double x[], int s, double z[], int n);

#endif
