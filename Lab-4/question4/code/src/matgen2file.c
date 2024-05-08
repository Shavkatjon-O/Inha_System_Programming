#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <float.h>
#include <math.h>

clock_t clock(void);

int main(int argc, char *argv[])
{
FILE *fp1;
int i, n, nxn;
float lr = 1000.0, mel;
double total_t;
clock_t start_t, end_t;
start_t = clock();
if (argc == 3)
{

fp1 = fopen(argv[1], "w");
n = atoi(argv[2]);
nxn = n*n;
/* Intializes random number generator */
srand((unsigned int) time(NULL));
/* Print nXn random numbers */

printf("-------------------------------\n");
for( i = 0; i < nxn; i++ )
{
mel= ((float) rand() / (float) (RAND_MAX))*lr;
fprintf(fp1, "%f ",mel);
}
fclose(fp1);
end_t = clock();


total_t = (double)((double)end_t - (double)start_t) / (double)CLOCKS_PER_SEC;

fp1 = fopen(argv[1], "r");
while( !feof(fp1))
{
fscanf(fp1, "%f ",&mel);
printf("%f ", mel);
}
printf("\n\n");
printf("--------------------------------------------------\n");
fclose(fp1);
printf("START TIME - TIME BEFORE THE START OF FILE CREATION = %lf clock cycles\n", (double)start_t);
printf("START OF FILE %s CREATION :\n", argv[1]);
printf("END OF FILE %s CREATION :\n", argv[1]);
printf("END TIME - TIME AFTER THE END OF FILE CREATION = %lf clock cycles\n", (double)end_t);
printf("CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC);
printf("TOTAL TIME TAKEN BY CPU FOR %s FILE CREATION: %lf secs\n",argv[1], total_t);
printf("--------------------------------------------------\n");
printf("ELEMENTS OF %d x %d MATRIX %s :\n", n, n, argv[1]);
printf("--------------------------------------------------\n");
}
else
{
printf("wrong arguments - use the format \n $matgen2file filename N\n");
}
}