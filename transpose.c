

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"


void swap(int *a, int *b){
    int c = *a;
    *a=*b; 
    *b=c;
}

void transp(int *array, int dim){

    for (int i = 0; i < dim; ++i)
    {
        for (int j = i+1; j < dim; ++j)
        {
            swap(&(array[i*dim+j]), &(array[j*dim+i]));
        }
    }

}


int main(int argc, char const *argv[])
{

	int src2[16] = {3,3,1,2,4,6,3,2,1,5,2,6,8,3,7,4};

	int dim = 4;

	transp(src2, dim);

	FILE *fp;
    fp = fopen("transpose_test.txt", "w+");


	for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            
            fprintf(fp , "%d | ", src2[i*dim+j] );
        }
        
        fprintf(fp , "\n" );


    }


    fclose(fp);


	return 0;
}