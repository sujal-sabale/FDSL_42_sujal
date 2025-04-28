#include <stdio.h>
#include <stdlib.h>

struct node {
    int data ;
    struct node *next ;
} ;

struct node *newnode, *front, *rear, *temp ;
rear = front = NULL ;
void enQueue() {
    temp = rear ;
    newnode = malloc(sizeof(struct node)) ;
    printf("Enter a Data for newnode:") ;
    scanf("%d",&newnode->data) ;

    if(rear == NULL) {
        rear = newnode ;
        newnode->next = NULL ;
    } else {
        while(temp->next != NULL) {
            temp = temp->next ;
        }
        temp->next = newnode ;
        newnode->next = NULL ;
    }
    printf("Data Inserted Succesfully!") ;
}

void deQueue() {
    if (front == NULL) {
        printf("Stack is Empty!\n");
    } else {
        temp = front ;
        front = front->next;
        temp->next = NULL;
        free(temp);
    }
    printf("Data Deleted Succesfully!") ;
}

void display() {
    temp = front ;

    if(front == NULL && rear == NULL) {
        printf("Queue is Empty!") ;
    } else {
        printf("\nQueue Data\n");
        while (temp != NULL) {
            printf("Data: %d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main () {
    int choice;

    do {
        printf("\n1. enQueue\n2. deQueue\n3. Display\n4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enQueue();
                break;
            case 2:
                deQueue();
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
