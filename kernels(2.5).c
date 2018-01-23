/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
/* 
 * Please fill in the following student struct 
 */
team_t team = {
    "2171643",              /* Student ID */

    "Muhammed Furkan İnalcık",     /* full name */
    "m.furkaninalcik@gmail.com",  /* email address */

    "",                   /* leave blank */
    ""                    /* leave blank */
};


/***************
 * CONVOLUTION KERNEL
 ***************/

/******************************************************
 * Your different versions of the convolution functions  go here
 ******************************************************/

/* 
 * naive_conv - The naive baseline version of convolution 
 */
char naive_conv_descr[] = "naive_conv: Naive baseline implementation";
void naive_conv(int dim,int *src, int *ker,int *dst) {
    int i,j,k,l;

    for(i = 0; i < dim-8+1; i++)
        for(j = 0; j < dim-8+1; j++) {
            dst[j*dim+i] = 0;
            for(k = 0; k < 8; k++)
                for(l = 0; l < 8; l++) {
                    dst[j*dim+i] = dst[j*dim+i] +src[(j+l)*dim+(i+k)]*ker[l*dim+k];
                }
        }
            
        
}

/* 
 * convolution - Your current working version of convolution
 * IMPORTANT: This is the version you will be graded on
 */
char convolution_descr[] = "Dot product: Current working version";
void convolution(int dim,int *src, int *ker,int *dst) 
{

        naive_conv(dim,src,ker,dst);





}

/*********************************************************************
 * register_conv_functions - Register all of your different versions
 *     of the convolution functions  with the driver by calling the
 *     add_conv_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_conv_functions() {
    add_conv_function(&naive_conv, naive_conv_descr);   
    add_conv_function(&convolution, convolution_descr);   
    /* ... Register additional test functions here */
}




/***************
 * MATRIX MULTIP KERNEL
 ***************/

/******************************************************
 * Your different versions of the matrix multiplications  go here
 ******************************************************/

/* 
 * naive_matrix_multiplication - The naive baseline version of matrix multiplication 
 */
char naive_matrix_multiplication_descr[] = "Naive_matrix_multiplication: Naive baseline implementation";
void naive_matrix_multiplication(int dim,int *src, int *src2,int *dst) {
    int i,j,k;

    for(i = 0; i < dim; i++)
        for(j = 0; j < dim; j++) {
            dst[j*dim+i]=0;
            for(k = 0; k < dim; k++) 
                dst[j*dim+i] = dst[j*dim+i] + src[j*dim+k]*src2[i+k*dim];
        }    
}


/* 
 * matrix_multiplication - Your current working version of matrix_multiplication
 * IMPORTANT: This is the version you will be graded on
 */


//#define mult(k) total += src[i*dim+(k++)]*src2[(k++)*dim+j];
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

char matrix_multiplication_descr[] = "Matrix multiplications: Current working version";
void matrix_multiplication(int dim,int *src, int *src2,int *dst) 
{

    int i,j,k, total;
    //int deneme1;

/*
    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            dst[i*dim+j] = 0;
        }
    }

    */
    transp(src2,dim);
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++) {
           
            dst[i*dim+j] = 0;
            
            //int loop_count = dim / 32;

            total = dst[i*dim+j];

            for (k = 0; k < dim; k += 32)
            {

                total += src[i*dim+k]*src2[k+dim*j];
                total += src[i*dim+(k+1)]*src2[(k+1)+dim*j];
                total += src[i*dim+(k+2)]*src2[(k+2)+dim*j];
                total += src[i*dim+(k+3)]*src2[(k+3)+dim*j];
                total += src[i*dim+(k+4)]*src2[(k+4)+dim*j];
                total += src[i*dim+(k+5)]*src2[(k+5)+dim*j];
                total += src[i*dim+(k+6)]*src2[(k+6)+dim*j];
                total += src[i*dim+(k+7)]*src2[(k+7)+dim*j];
                total += src[i*dim+(k+8)]*src2[(k+8)+dim*j];
                total += src[i*dim+(k+9)]*src2[(k+9)+dim*j];
                total += src[i*dim+(k+10)]*src2[(k+10)+dim*j];
                total += src[i*dim+(k+11)]*src2[(k+11)+dim*j];
                total += src[i*dim+(k+12)]*src2[(k+12)+dim*j];
                total += src[i*dim+(k+13)]*src2[(k+13)+dim*j];
                total += src[i*dim+(k+14)]*src2[(k+14)+dim*j];
                total += src[i*dim+(k+15)]*src2[(k+15)+dim*j];
                total += src[i*dim+(k+16)]*src2[(k+16)+dim*j];
                total += src[i*dim+(k+17)]*src2[(k+17)+dim*j];
                total += src[i*dim+(k+18)]*src2[(k+18)+dim*j];
                total += src[i*dim+(k+19)]*src2[(k+19)+dim*j];
                total += src[i*dim+(k+20)]*src2[(k+20)+dim*j];
                total += src[i*dim+(k+21)]*src2[(k+21)+dim*j];
                total += src[i*dim+(k+22)]*src2[(k+22)+dim*j];
                total += src[i*dim+(k+23)]*src2[(k+23)+dim*j];
                total += src[i*dim+(k+24)]*src2[(k+24)+dim*j];
                total += src[i*dim+(k+25)]*src2[(k+25)+dim*j];
                total += src[i*dim+(k+26)]*src2[(k+26)+dim*j];
                total += src[i*dim+(k+27)]*src2[(k+27)+dim*j];
                total += src[i*dim+(k+28)]*src2[(k+28)+dim*j];
                total += src[i*dim+(k+29)]*src2[(k+29)+dim*j];
                total += src[i*dim+(k+30)]*src2[(k+30)+dim*j];
                total += src[i*dim+(k+31)]*src2[(k+31)+dim*j];                
            }


            
            dst[i*dim+j] = total;
            /*
            for(k = 0; k < dim; k++){
                total += src[i*dim+k]*src2[k*dim+j];
            }

            dst[i*dim+j] = total;
            */



        }
    }

    transp(src2,dim);    
            







        //naive_matrix_multiplication(dim,src,src2,dst);

}

/*********************************************************************
 * register_matrix_multiplication_functions - Register all of your different versions
 *     of the matrix multiplication  with the driver by calling the
 *     add_matrix_multiplication_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_matrix_multiplication_functions() {
    add_matrix_multiplication_function(&naive_matrix_multiplication, naive_matrix_multiplication_descr);   
    add_matrix_multiplication_function(&matrix_multiplication, matrix_multiplication_descr);   
    /* ... Register additional test functions here */
}

