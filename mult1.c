#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

void matrix_multiplication(int dim,int *src, int *src2,int *dst) 
{

    int i,j,k, deneme1, block_size, total;

    block_size = 2;

    int en = block_size * (dim/block_size); /* Amount that fits evenly into blocks */

    FILE *fp;
    fp = fopen("test_output.txt", "w+");


    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            dst[i*dim+j] = 0;
        }
    }

    for (int k0 = 0; k0 < en; k0 += block_size)
    {
        for (int j0 = 0; j0 < en; j0 += block_size)
        {
            for(i = 0; i < dim; i++){
                for(j = j0; j < j0 + block_size; j++) {

                    dst[i*dim+j] = 0;
                    
                    total = dst[i*dim+j];
                    for(k = k0; k < k0 + block_size; k++){ 
                        printf("k0: %d, j0: %d \n", k0, j0 );
                        total += src[i*dim+k]*src2[k*dim+j];
                    }

                    //printf("j = %d, j0 = %d \n", j,j0);
                    
                    //fprintf(fp , "j = %d, j0 = %d \n", j,j0);

                    //fprintf(fp , "%d | ", total );
                 

                   
                   //fprintf(fp, "This is testing for fprintf...\n");
                   //fputs("This is testing for fputs...\n", fp);
                   
                    printf("TOTAL: %d\n", total );
                    dst[i*dim+j] = total;

                    //fprintf(fp,"Dim: %d, Total: %d\n", dim, total);

                }      
            }
        }
    }


    ///////////////PRINT/////////
    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            
            fprintf(fp , "%d | ", dst[i*dim+j] );
        }
        
        fprintf(fp , "\n" );


    }


    fclose(fp);

            







        //naive_matrix_multiplication(dim,src,src2,dst);

}

void naive_matrix_multiplication(int dim,int *src, int *src2,int *dst) {
    int i,j,k;

    FILE *fp;
    fp = fopen("mult_result.txt", "w+");

    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++) {
            dst[j*dim+i]=0;
            for(k = 0; k < dim; k++){
                if (src[j*dim+k]*src2[i+k*dim] == 0)
                {
                    printf("i: %d, j: %d, k: %d \n", i,j,k );

                }
                dst[j*dim+i] = dst[j*dim+i] + src[j*dim+k]*src2[i+k*dim];
            }
            
        }

    }

    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            
            fprintf(fp , "%d | ", dst[i*dim+j] );
        }
        
        fprintf(fp , "\n" );


    }
    fclose(fp);


}


int main(int argc, char const *argv[])
{
    
    int dst[9] = {7,7,7,7,7,7,7,7,7};
    int src1[9] = {3,7,1,0,8,2,6,2,9};
    int src2[9] = {4,0,1,2,6,8,9,1,3};
    int dim = 3;
    //naive_matrix_multiplication(dim,src1,src2,dst);

    matrix_multiplication(dim,src1,src2,dst);



    return 0;
}