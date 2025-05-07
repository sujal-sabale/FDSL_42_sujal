#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insertAtFirst() {
    struct node *newnode = malloc(sizeof(struct node));
    printf("Enter Data for newnode: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
}

void insertAtLast() {
    struct node *newnode = malloc(sizeof(struct node));
    printf("Enter Data for newnode: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insertAtpos() {
    int pos, count = 0;
    struct node *temp = head;
    struct node *newnode = malloc(sizeof(struct node));

    printf("Enter Data for newnode: ");
    scanf("%d", &newnode->data);

    printf("Enter position: ");
    scanf("%d", &pos);

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (pos < 1 || pos > count + 1) {
        printf("Invalid Position\n");
        free(newnode);
        return;
    }

    if (pos == 1) {
        newnode->prev = NULL;
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode;
        head = newnode;
    } else {
        temp = head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        newnode->next = temp->next;
        newnode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newnode;

        temp->next = newnode;
    }
}

void deleteFirst() {
    if (head == NULL) {
        printf("DLL is Empty!\n");
    } else {
        struct node *temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        free(temp);
    }
}

void deleteLast() {
    if (head == NULL) {
        printf("DLL is Empty!\n");
        return;
    }

    struct node *temp = head;

    if (temp->next == NULL) {
        head = NULL;
        free(temp);
    } else {
        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        free(temp);
    }
}

void deleteAtPos() {
    int pos, count = 0;
    struct node *temp = head;

    printf("Enter the Position: ");
    scanf("%d", &pos);

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (pos < 1 || pos > count) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {
        deleteFirst();
    } else if (pos == count) {
        deleteLast();
    } else {
        temp = head;
        for (int i = 1; i < pos; i++)
            temp = temp->next;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void display() {
    if (head == NULL) {
        printf("DLL is Empty!\n");
        return;
    }

    struct node *temp = head;
    printf("\nDLL Data: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    do {
        printf("\n1. Insert at First\n2. Insert At Last\n3. Insert At Position\n4. Delete At First\n5. Delete At Last\n6. Delete At Position\n7. Display\n8. Exit\n");
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
                insertAtpos();
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                deleteAtPos();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 8);

    return 0;
}
