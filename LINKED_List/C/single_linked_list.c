#include<stdio.h>
#include<stdlib.h>
#include"list.h"


LINK create_node(int val){
    LINK newp;
    newp = (LINK)malloc(sizeof(ELEMENT));
    newp->d=val;
   return newp;
}

LINK insert(int value,LINK ptr){
    LINK newp,prev,first;
    newp = create_node(value);
    if (ptr==NULL||value<=ptr->d)
    {
        newp->next=ptr;
        return newp;
    }
    else{
        first=ptr;
        prev=NULL;
        while(ptr!=NULL&&value>ptr->d){
            prev=ptr;
            ptr=ptr->next;
        }
        prev->next=newp;
        newp->next=ptr;
        return first;
    }
    
}

void display(LINK ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->d);
        ptr=ptr->next;
    }
    printf("\n");
}

int main(){
    LINK start=NULL;
    int val;
    while(1){
        printf("Enter the value to be inserted: ");
        scanf("%d",&val);
        if(val==-1){
            break;
        }
        start=insert(val,start);
        display(start);
    }
    return 0;
}
