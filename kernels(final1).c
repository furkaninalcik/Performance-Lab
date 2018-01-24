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

    //naive_conv(dim,src,ker,dst);
    int y0 = 0;
    int y1 = dim;
    int y2 = y1+dim;
    int y3 = y2+dim;
    int y4 = y3+dim;
    int y5 = y4+dim;
    int y6 = y5+dim;
    int y7 = y6+dim;


    int i,j,j0,total;

    for(i = 0; i < dim-8+1; i++){
        for(j = 0; j < dim-8+1; j++) {

            j0 = j*dim;
            //dst[j0+i] = 0;

            total = 0;
            //k => 0-7

            //// dst[j*dim+i] = dst[j*dim+i] +src[(j+l)*dim+(i+k)]*ker[l*dim+k]; //////

            //total += src[j*dim+ 0*dim +(i+0)]*ker[0*dim+0];



            int x0 = j0+i; // j0
            int x1 = x0+dim;
            int x2 = x1+dim;
            int x3 = x2+dim;
            int x4 = x3+dim; //(j+4)*dim+i
            int x5 = x4+dim;
            int x6 = x5+dim;
            int x7 = x6+dim;





            
            total += src[x0]*ker[y0];
            total += src[x1]*ker[y1];
            total += src[x2]*ker[y2];
            total += src[x3]*ker[y3];
            total += src[x4]*ker[y4];
            total += src[x5]*ker[y5];
            total += src[x6]*ker[y6];
            total += src[x7]*ker[y7];

            total += src[x1+1]*ker[y1+1];
            total += src[x2+1]*ker[y2+1];
            total += src[x3+1]*ker[y3+1];
            total += src[x4+1]*ker[y4+1];
            total += src[x5+1]*ker[y5+1];
            total += src[x6+1]*ker[y6+1];
            total += src[x7+1]*ker[y7+1];

            total += src[x0+2]*ker[y0+2];
            total += src[x1+2]*ker[y1+2];
            total += src[x2+2]*ker[y2+2];
            total += src[x3+2]*ker[y3+2];
            total += src[x4+2]*ker[y4+2];
            total += src[x5+2]*ker[y5+2];
            total += src[x6+2]*ker[y6+2];
            total += src[x7+2]*ker[y7+2];

            total += src[x0+3]*ker[y0+3];
            total += src[x1+3]*ker[y1+3];
            total += src[x2+3]*ker[y2+3];
            total += src[x3+3]*ker[y3+3];
            total += src[x4+3]*ker[y4+3];
            total += src[x5+3]*ker[y5+3];
            total += src[x6+3]*ker[y6+3];
            total += src[x7+3]*ker[y7+3];

            total += src[x0+4]*ker[y0+4];
            total += src[x1+4]*ker[y1+4];
            total += src[x2+4]*ker[y2+4];
            total += src[x3+4]*ker[y3+4];
            total += src[x4+4]*ker[y4+4];
            total += src[x5+4]*ker[y5+4];
            total += src[x6+4]*ker[y6+4];
            total += src[x7+4]*ker[y7+4];

            total += src[x0+5]*ker[y0+5];
            total += src[x1+5]*ker[y1+5];
            total += src[x2+5]*ker[y2+5];
            total += src[x3+5]*ker[y3+5];
            total += src[x4+5]*ker[y4+5];
            total += src[x5+5]*ker[y5+5];
            total += src[x6+5]*ker[y6+5];
            total += src[x7+5]*ker[y7+5];

            total += src[x0+6]*ker[y0+6];
            total += src[x1+6]*ker[y1+6];
            total += src[x2+6]*ker[y2+6];
            total += src[x3+6]*ker[y3+6];
            total += src[x4+6]*ker[y4+6];
            total += src[x5+6]*ker[y5+6];
            total += src[x6+6]*ker[y6+6];
            total += src[x7+6]*ker[y7+6];

            total += src[x0+7]*ker[y0+7];
            total += src[x1+7]*ker[y1+7];
            total += src[x2+7]*ker[y2+7];
            total += src[x3+7]*ker[y3+7];
            total += src[x4+7]*ker[y4+7];
            total += src[x5+7]*ker[y5+7];
            total += src[x6+7]*ker[y6+7];
            total += src[x7+7]*ker[y7+7];
/*
            total += src[(j+0)*dim+(i+1)]*ker[0*dim+1];
            total += src[(j+1)*dim+(i+1)]*ker[1*dim+1];
            total += src[(j+2)*dim+(i+1)]*ker[2*dim+1];
            total += src[(j+3)*dim+(i+1)]*ker[3*dim+1];
            total += src[(j+4)*dim+(i+1)]*ker[4*dim+1];
            total += src[(j+5)*dim+(i+1)]*ker[5*dim+1];
            total += src[(j+6)*dim+(i+1)]*ker[6*dim+1];
            total += src[(j+7)*dim+(i+1)]*ker[7*dim+1];

            total += src[(j+0)*dim+(i+2)]*ker[0*dim+2];
            total += src[(j+1)*dim+(i+2)]*ker[1*dim+2];
            total += src[(j+2)*dim+(i+2)]*ker[2*dim+2];
            total += src[(j+3)*dim+(i+2)]*ker[3*dim+2];
            total += src[(j+4)*dim+(i+2)]*ker[4*dim+2];
            total += src[(j+5)*dim+(i+2)]*ker[5*dim+2];
            total += src[(j+6)*dim+(i+2)]*ker[6*dim+2];
            total += src[(j+7)*dim+(i+2)]*ker[7*dim+2];

            total += src[(j+0)*dim+(i+3)]*ker[0*dim+3];
            total += src[(j+1)*dim+(i+3)]*ker[1*dim+3];
            total += src[(j+2)*dim+(i+3)]*ker[2*dim+3];
            total += src[(j+3)*dim+(i+3)]*ker[3*dim+3];
            total += src[(j+4)*dim+(i+3)]*ker[4*dim+3];
            total += src[(j+5)*dim+(i+3)]*ker[5*dim+3];
            total += src[(j+6)*dim+(i+3)]*ker[6*dim+3];
            total += src[(j+7)*dim+(i+3)]*ker[7*dim+3];

            total += src[(j+0)*dim+(i+4)]*ker[0*dim+4];
            total += src[(j+1)*dim+(i+4)]*ker[1*dim+4];
            total += src[(j+2)*dim+(i+4)]*ker[2*dim+4];
            total += src[(j+3)*dim+(i+4)]*ker[3*dim+4];
            total += src[(j+4)*dim+(i+4)]*ker[4*dim+4];
            total += src[(j+5)*dim+(i+4)]*ker[5*dim+4];
            total += src[(j+6)*dim+(i+4)]*ker[6*dim+4];
            total += src[(j+7)*dim+(i+4)]*ker[7*dim+4];

            total += src[(j+0)*dim+(i+5)]*ker[0*dim+5];
            total += src[(j+1)*dim+(i+5)]*ker[1*dim+5];
            total += src[(j+2)*dim+(i+5)]*ker[2*dim+5];
            total += src[(j+3)*dim+(i+5)]*ker[3*dim+5];
            total += src[(j+4)*dim+(i+5)]*ker[4*dim+5];
            total += src[(j+5)*dim+(i+5)]*ker[5*dim+5];
            total += src[(j+6)*dim+(i+5)]*ker[6*dim+5];
            total += src[(j+7)*dim+(i+5)]*ker[7*dim+5];

            total += src[(j+0)*dim+(i+6)]*ker[0*dim+6];
            total += src[(j+1)*dim+(i+6)]*ker[1*dim+6];
            total += src[(j+2)*dim+(i+6)]*ker[2*dim+6];
            total += src[(j+3)*dim+(i+6)]*ker[3*dim+6];
            total += src[(j+4)*dim+(i+6)]*ker[4*dim+6];
            total += src[(j+5)*dim+(i+6)]*ker[5*dim+6];
            total += src[(j+6)*dim+(i+6)]*ker[6*dim+6];
            total += src[(j+7)*dim+(i+6)]*ker[7*dim+6];

            total += src[(j+0)*dim+(i+7)]*ker[0*dim+7];
            total += src[(j+1)*dim+(i+7)]*ker[1*dim+7];
            total += src[(j+2)*dim+(i+7)]*ker[2*dim+7];
            total += src[(j+3)*dim+(i+7)]*ker[3*dim+7];
            total += src[(j+4)*dim+(i+7)]*ker[4*dim+7];
            total += src[(j+5)*dim+(i+7)]*ker[5*dim+7];
            total += src[(j+6)*dim+(i+7)]*ker[6*dim+7];
            total += src[(j+7)*dim+(i+7)]*ker[7*dim+7];
*/
            dst[j0+i] = total;


        }
    }

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
        int i0 = i*dim;
        for (int j = i+1; j < dim; ++j)
        {
            //swap(&(array[i0+j]), &(array[j*dim+i]));
            //int* a = &(array[i0+j]);
            //int* b = &(array[j*dim+i]);
            int c = (array[i0+j]);
            array[i0+j]=array[j*dim+i]; 
            array[j*dim+i]=c;
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
           
            //dst[i*dim+j] = 0;
            

            total = 0;

            int i0 = i*dim;
            int j0 = j*dim; 

            for (k = 0; k < dim; k += 32)
            {

                total += src[i0]*src2[j0];
                total += src[i0+1]*src2[1+j0];
                total += src[i0+2]*src2[2+j0];
                total += src[i0+3]*src2[3+j0];
                total += src[i0+4]*src2[4+j0];
                total += src[i0+5]*src2[5+j0];
                total += src[i0+6]*src2[6+j0];
                total += src[i0+7]*src2[7+j0];
                total += src[i0+8]*src2[8+j0];
                total += src[i0+9]*src2[9+j0];
                total += src[i0+10]*src2[10+j0];
                total += src[i0+11]*src2[11+j0];
                total += src[i0+12]*src2[12+j0];
                total += src[i0+13]*src2[13+j0];
                total += src[i0+14]*src2[14+j0];
                total += src[i0+15]*src2[15+j0];
                total += src[i0+16]*src2[16+j0];
                total += src[i0+17]*src2[17+j0];
                total += src[i0+18]*src2[18+j0];
                total += src[i0+19]*src2[19+j0];
                total += src[i0+20]*src2[20+j0];
                total += src[i0+21]*src2[21+j0];
                total += src[i0+22]*src2[22+j0];
                total += src[i0+23]*src2[23+j0];
                total += src[i0+24]*src2[24+j0];
                total += src[i0+25]*src2[25+j0];
                total += src[i0+26]*src2[26+j0];
                total += src[i0+27]*src2[27+j0];
                total += src[i0+28]*src2[28+j0];
                total += src[i0+29]*src2[29+j0];
                total += src[i0+30]*src2[30+j0];
                total += src[i0+31]*src2[31+j0];  
                
                i0 += 32;              
                j0 += 32;              
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

