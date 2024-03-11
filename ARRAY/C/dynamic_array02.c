//dynamic memory allocation of 2D array
//using a single pointer and a 1D array with pointer arithmetic

#include<stdio.h>
#include<stdlib.h>

int main(){
    int r,c; // r = rows, c = columns
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    int *p=(int *)malloc(r*c*sizeof(int));
    if (p==NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    else{
        printf("Memory allocation successful\n");
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter the value of %d row and %d column: ", i, j);
            scanf("%d", (p+i*c+j));
        }
        
    }
    
    printf("The elements of the array are: \n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", *(p+i*c+j));
        }
        printf("\n");
    }

    free(p);
    return 0;
}