#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp, *prevnode;

void insertAtFirst() {
    newnode = malloc(sizeof(struct node));
    printf("Enter the data for New Node: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
        head = newnode;
        newnode->next = NULL;
    } else {
        newnode->next = head;
        head = newnode;
    }
    printf("Data Inserted Succesfully!") ;
}

void insertAtLast() {
    temp = head;
    newnode = malloc(sizeof(struct node));
    printf("Enter the Data for New Node: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
        head = newnode;
        newnode->next = NULL;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
    printf("Data Inserted Succesfully!") ;
}

void deleteAtFirst() {
    if (head == NULL) {
        printf("SLL is Empty!\n");
    } else {
        temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    printf("Data Deleted Succesfully!") ;
}

void deleteAtLast() {
    if (head == NULL) {
        printf("SLL is Empty!\n");
    } else {
        temp = head;
        while (temp->next != NULL) {
            prevnode = temp;
            temp = temp->next;
        }
        prevnode->next = NULL;
        free(temp);
    }
    printf("Data Deleted Succesfully!") ;
}

void display() {
    if(head == NULL) {
        printf("SLL is Empty!") ;
    }
    temp = head ;
    printf("\nLinked List Data:\n");
    while (temp != NULL) {
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Insert at First\n2. Insert At Last\n3. Delete At First\n4. Delete At Last\n5.Display\n6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertAtFirst();
                break;
            case 2:
                insertAtLast();
                break;
            case 3:
                deleteAtFirst();
                break;
            case 4:
                deleteAtLast();
                break;
            case 5:
                display() ;
                break;
            case 6: 
                printf("Exiting the program.\n");
                break ;    
            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 6); 

    return 0;
}
