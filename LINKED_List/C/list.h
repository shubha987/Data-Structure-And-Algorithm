#include<stdio.h>
#include<stdlib.h>

typedef char DATA;

struct list{
    DATA d;
    struct list *next;
};

typedef struct list ELEMENT;
typedef ELEMENT *LINK;