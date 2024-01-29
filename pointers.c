#include<stdio.h>

int main()
{
    int B[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    int (*P)[3] = B;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            printf("B[%d][%d]= %d ", i, j, B[i][j]);

        printf("\n\nB\t:\t%d\n*B\t:\t%d\n&B\t:\t%d\nB[0]\t:\t%d\n&B[0]\t:\t%d\n&B[0][0]:\t%d\n\n", B, *B, &B, B[0], &B[0],&B[0][0]);

        printf("*B[0]\t:\t%d\nB[0][0]\t:\t%d\n",*B[0], B[0][0]);
        printf("*B[1]\t:\t%d\nB[1][0]\t:\t%d\n\n",*B[1], B[1][0]);

        printf("*(*(B+1)+1):\t%d\n", *(*(B+1)+1));
        printf(" (*(B+1)+1):\t%d\n",  (*(B+1)+1));
        printf("&B[1][1]:\t%d\n", &B[1][1]);
        printf("B[1][1]\t:\t%d\n\n", B[1][1]);

        printf("*( (B+1)+1):\t%d\n", *( (B+1)+1));
        printf("&B[2][0]:\t%d\n", &B[2][0]);
        printf("*(B+2)\t:\t%d\n", *(B+2));
        printf("*(*(B+2)):\t%d\n", *(*(B+2)));
        printf("*(*( (B+1)+1)):\t%d\n", *(*( (B+1)+1)));
        printf("B[2][0]\t:\t%d\n", B[2][0]);
        printf("*B[2]\t:\t%d\n\n", *B[2]);

        printf("*(*B+1)\t:\t%d\n", *(*B+1));
        printf(" (*B+1)\t:\t%d\n", (*B+1));
        printf("&B[0][1]:\t%d\n", &B[0][1]);
        printf("B[0][1]\t:\t%d\n\n", B[0][1]);


}
