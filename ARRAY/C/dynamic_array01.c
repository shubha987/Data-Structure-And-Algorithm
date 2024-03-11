// it is a simple program to create a dynamic array(1-D) using malloc function

#include<stdio.h>
#include<stdlib.h>

int main(){
    int *p;
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    p = (int *)malloc(size * sizeof(int));

    if (p==NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    else{
        printf("Memory allocation successful\n");
    }

    for (int i = 0; i < size; i++)
    {
        printf("Enter the value of %d element: ", i);
        scanf("%d", &p[i]);
    }
    printf("The elements of the array are: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", p[i]);
    }
    free(p);
  return 0;
}