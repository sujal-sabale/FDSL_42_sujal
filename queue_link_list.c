#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *newnode, *front = NULL, *rear = NULL, *temp;

void enQueue() {
    newnode = malloc(sizeof(struct node));
    printf("Enter data for new node: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode; 
    } else {
        rear->next = newnode;   
        rear = newnode;         
    }
    printf("Data inserted successfully!\n");
}

void deQueue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        temp = front;
        front = front->next;
        free(temp);

        if (front == NULL) {
            rear = NULL;  
        }

        printf("Data deleted successfully!\n");
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        printf("\nQueue Data:\n");
        temp = front;
        while (temp != NULL) {
            printf("Data: %d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice;

    do {
        printf("\n1. enQueue\n2. deQueue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
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
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
