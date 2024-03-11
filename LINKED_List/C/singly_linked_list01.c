//single linked list with all the functions in one file

#include<stdio.h>
#include<stdlib.h>

struct list
{
    int data;
    struct list *next;
};

void create_list(struct list **head){  
     /*the head and newnode pointers are passed by value to the create_list function, so any changes made to them inside the function will not be reflected outside of it. To reflect the changes outside the function, we need to pass the pointers by reference. This can be done by passing the address of the pointers to the function.*/
    struct list *temp,*newnode;
    *head = 0;
    while (1)
    {
        newnode = (struct list *)malloc(sizeof(struct list));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (*head == 0)
        {
            *head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue? (1/0): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
    }
}

void insert_at_beg(struct list **head){
    struct list *newnode;
    newnode = (struct list *)malloc(sizeof(struct list));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = *head;
    *head = newnode;
}

void insert_at_end(struct list **head){
    struct list *newnode, *temp;
    newnode = (struct list *)malloc(sizeof(struct list));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    temp = *head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insert_at_pos(struct list **head, int pos){
    struct list *newnode, *temp;
    newnode = (struct list *)malloc(sizeof(struct list));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    temp = *head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == 0)
        {
            printf("There are less than %d elements in the list\n", pos);
            return;
        }
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_at_beg(struct list **head){
    struct list *temp;
    temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_end(struct list **head){
    struct list *temp, *prevnode;
    temp = *head;
    while (temp->next != 0)
    {
        prevnode = temp;
        temp = temp->next;
    }
    if (temp == *head)
    {
        *head = 0;
    }
    else
    {
        prevnode->next = 0;
    }
    free(temp);
}

void delete_at_pos(struct list **head, int pos){
    struct list *temp, *prevnode;
    temp = *head;
    for (int i = 0; i < pos; i++)
    {
        prevnode = temp;
        temp = temp->next;
        if (temp == 0)
        {
            printf("There are less than %d elements in the list\n", pos);
            return;
        }
    }
    prevnode->next = temp->next;
    free(temp);
}

// searching the list
void search(struct list *head, int key){
    struct list *temp;
    temp = head;
    while (temp != 0)
    {
        if (temp->data == key)
        {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
}

void display(struct list *head){
    struct list *temp;
    temp = head;
    while (temp != 0)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
 struct list *head;
 int key;
 printf("::::This is a single linked list with all the functions in one file::::\n");
 int choice;
 printf("Enter 1 to create a list\nEnter 2 to insert a element in the list\nEnter 3 to delete a item from the list\nEnter 4 to display the list\nEnter 5 to exit\n");
 while (1)
 {  
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1: create_list(&head);
            break;
    case 2: 
    while (1){
        printf("Enter the position where you want to insert the element: ");
        int pos;
        scanf("%d", &pos);
        if (pos == 0)
         insert_at_beg(&head);
        else if (pos == -1)
         insert_at_end(&head);
        else
         insert_at_pos(&head, pos);

         int choice;
         printf("Do you want to continue? (1/0): ");
         scanf("%d", &choice);
        if (choice == 0)
                break;
    }
    break;
    case 3: while(1){
            printf("Enter the position where you want to delete the element: ");
            int pos;
            scanf("%d", &pos);
            if(pos==0){
                delete_at_beg(&head);
            }
            else if(pos==-1){
                delete_at_end(&head);
            }
            else{
                delete_at_pos(&head,pos);

            int choice;
            printf("Do you want to continue? (1/0): ");
            scanf("%d", &choice);
            if (choice == 0)
                break;
            }
            break;
    
    case 4:
            printf("Enter the element you want to search: ");
            scanf("%d", &key);
            search(head, key);
            break;
    
    case 5: display(head);
            break;
            
    case 6: exit(0);

    default: printf("Invalid choice\n");
        break;
    }
 }
 
}
}