/*******************************************************************
Name    : Burak                 Lecture     : Data Structures
Surname : Çetin                 Department  : Computer Engineering
Student Number: 22118080032
*******************************************************************/

#include<stdio.h>

void readUpperTriangularMatrix(FILE* inputFile, int* matrix, int n);
void productOfMatrices(int* matrix1, int* matrix2,int* matrix12 , int n);
void printUpperTriangularMatrix(int* matrix, int n);

int main(){
    int matrixN;    //number of elements on one edge of the matrix

    FILE* inputFile = fopen("input.txt", "r");  //opens input.txt file read-only ("r")
    if(inputFile == NULL){
        printf("***ERROR: File not found!***"); //if file does not exist
        return -1;
    }
    fscanf(inputFile, "%d", &matrixN);   //reading number of elements on one edge of the matrix

    //(matrixN * (matrixN + 1)) / 2 = matrix size equation
    int A[(matrixN * (matrixN + 1)) / 2];
    int B[(matrixN * (matrixN + 1)) / 2];
    int C[(matrixN * (matrixN + 1)) / 2];  //matrix C = matrix A  x  matrix B

    readUpperTriangularMatrix(inputFile, A, matrixN);   // reads matrix A from input.txt file

    readUpperTriangularMatrix(inputFile, B, matrixN);   // reads matrix B from input.txt file

    productOfMatrices(A, B, C, matrixN);   // C = A x B
    printUpperTriangularMatrix(C, matrixN); // prints matrix C

    fclose(inputFile);  //closes file
    return 0;
}

//reads elements of matrix from input.txt file
void readUpperTriangularMatrix(FILE* inputFile, int* matrix, int n){
    int i, j;   //i: row, j: column

    /***NOTE: this "for" loop is referenced from CENG 205 Data Structures Lecture 4 PDF (page 7). */
    //for loop -> row number returns up to the maximum row number
    for(i=0; i<n; i++){
    //for loop -> starts the loop by equating the row number to the column number according to the upper triangular matrix rule
        for(j=i; j<n; j++){
            fscanf(inputFile, "%d", &matrix[(n*i) + j - (i*(i+1))/2]);
            // (n*i) + j - (i*(i+1))/2 = index equation
            // i:row, j: column, n: number of elements on one edge of the matrix
            /** Reference: https://dongkwan-kim.github.io/blogs/indices-for-the-upper-triangle-matrix/ */
        }
    }
}

//multiplies matrices       matrix12 = matrix1 x matrix2
void productOfMatrices(int* matrix1, int* matrix2, int* matrix12, int n){
    int i,j, m;    //i: row, j: column

    /***NOTE: I constructed this "for" loop myself and
    I calculated, which one corresponds to the row and column for each matrix in my own notebook.*/
    for(i=0; i<n; i++){ //i: row for new product matrix
        for(j=i; j<n; j++){ //j: column for new product matrix
                matrix12[(n*i)+j-(i*(i+1))/2]=0;    // initializes each element to 0
            for(m=i; m<=j; m++){    // matrix1 ->  i: row, m: column
                                    // matrix2 ->  m: row, j: column
                                    // matrix12 -> i: row, j: column
                    matrix12[(n*i)+j-(i*(i+1))/2] += matrix1[(n*i)+m-(i*(i+1))/2] * matrix2[(n*m)+j-(m*(m+1))/2];
                    /* Reason for "+=" : Due to the rule of product of two matrices, each element in one column of the first matrix
                    is in turn multiplied by its corresponding element in one row of the second matrix
                    and then summed.  */
            }
        }
    }
}

//printing matrix
void printUpperTriangularMatrix(int* matrix, int n){
    int i, j;   //i: row, j: column

    /***NOTE: I constructed this "for" loop myself*/
    //for loop -> prints matrix (1D array)
    for(i=0; i<n; i++){
        for(j=i; j<n; j++){
            printf("%d ", matrix[(n*i) + j - (i*(i+1))/2]);
        }
    }
    printf("\n\n");

    /***NOTE: I made this "for" loop myself*/
    //for loop -> prints traditional matrix (2D array)
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            for(j; j<i; j++)    // for loop -> prints 0 in the upper triangular matrix
                printf("0\t");  //             where it is not in the index
            for(j=i; j<n; j++)  // for loop -> prints value where they are in index
                printf("%d\t", matrix[(n*i) + j - (i*(i+1))/2]);
        }
        printf("\n");
    }
    printf("\n");
}

/************************************************************************************
REFERENCES:

*   "for" loop in the readUpperTriangularMatrix() method is referenced from
    CENG205 Data Structures Lecture 4 PDF (page 7).

*   (n*i) + j - (i*(i+1))/2 = index equation for upper triangular matrix
    i:row, j: column, n: number of elements on one edge of the matrix
    from https://dongkwan-kim.github.io/blogs/indices-for-the-upper-triangle-matrix/
************************************************************************************/
