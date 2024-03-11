//using an array of pointers to create a 2D array

#include<stdio.h>
#include<stdlib.h>

int main(){
    int r,c; // r = rows, c = columns
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    int *arr[r];
    for (int i = 0; i < r; i++)
    {
        arr[i] = (int *)malloc(c*sizeof(int));
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter the value of %d row and %d column: ", i, j);
            scanf("%d", &arr[i][j]);
        }
        
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < r; i++)
    {
        free(arr[i]);
    }

    return 0;
}