#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char *argv[]) {
    FILE*   file_ptr;
    int     N;
    float   lower_range = 1000.0, matrix_element;
    clock_t start_time, end_time;
    double  total_time;

    if (argc != 3) {
        printf("Usage: %s <filename> <n>\n", argv[0]);
        return 1;
    }

    start_time = clock(); 

    printf("===> START TIME - TIME BEFORE THE START OF FILE CREATION = %lf clock cycles\n\n", (double)start_time);

    file_ptr = fopen(argv[1], "w");
    if (file_ptr == NULL) {
        printf("error opening file for writing.\n");
        return 1;
    }

    N = atoi(argv[2]);

    srand((unsigned int)time(NULL));

    printf("===> START OF FILE %s CREATION\n\n", argv[1]);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix_element = ((float)rand() / (float)(RAND_MAX)) * lower_range;
            fprintf(file_ptr, "%f ", matrix_element);
        }
        fprintf(file_ptr, "\n");
    }

    fclose(file_ptr);

    end_time = clock();

    total_time = (double)((double)end_time - (double)start_time) / (double)CLOCKS_PER_SEC;

    printf("===> END OF FILE %s CREATION\n\n", argv[1]);

    printf("===> END TIME - TIME AFTER THE END OF FILE CREATION = %lf clock cycles\n\n", (double)end_time);
    
    printf("===> CLOCKS_PER_SEC = %ld\n\n", CLOCKS_PER_SEC);
    
    printf("===> TOTAL TIME TAKEN BY CPU FOR %s FILE CREATION: %lf secs\n\n", argv[1], total_time);
        
    printf("===> ELEMENTS OF %d x %d MATRIX %s :\n\n", N, N, argv[1]);

    file_ptr = fopen(argv[1], "r");
    if (file_ptr == NULL) {
        printf("error opening file for reading.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(file_ptr, "%f", &matrix_element);
            printf("%.2f\t", matrix_element);
        }
        printf("\n");
    }

    fclose(file_ptr);

    return 0;
}