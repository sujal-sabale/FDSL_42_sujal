#include <stdio.h>
#include <stdlib.h>

struct node {
    int data ;
    struct node *next ;
} ;

struct node *newnode, *top, *temp ;

void push() {
    newnode = malloc(sizeof(struct node)) ;
    printf("Enter a Data for newnode:") ;
    scanf("%d",&newnode->data) ;

    if(top == NULL) {
        top = newnode ;
        newnode->next = NULL ;
    } else {
        newnode->next = top ;
        top = newnode ;
    }
    printf("Data Inserted Succesfully!") ;
}

void pop() {
    if (top == NULL) {
        printf("Stack is Empty!\n");
    } else {
        temp = top ;
        top = top->next;
        temp->next = NULL;
        free(temp);
    }
    printf("Data Deleted Succesfully!") ;
}

void display() {
    if(top == NULL) {
        printf("Stack is Empty!") ;
    } else {
        temp = top ;
        printf("\nStack Data\n");
        while (temp != NULL) {
            printf("Data: %d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main () {
    int choice;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4: 
                printf("Exiting the program.\n");
                break ;    
            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 4); 

    return 0;
}
