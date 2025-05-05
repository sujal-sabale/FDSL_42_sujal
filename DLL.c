#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
struct node *prev ;
};

struct node *head = NULL, *newnode,*temp, *prevnode;
int pos , count = 0 ,i = 1 ;

void insertAtFirst() {
newnode = malloc(sizeof(struct node)) ;

printf("Enter Data for newnode :") ;
scanf("%d",&newnode -> data) ;

if(head == NULL) {
    head = newnode ;
    newnode -> next = NULL ;
    newnode -> prev = NULL ;
} else {
    newnode -> next = head ;
    head -> prev = newnode ;
    head = newnode ;
    newnode -> prev = NULL ;
}

}

void insertAtLast() {
newnode = malloc(sizeof(struct node)) ;
printf("Enter Data for newnode: ") ;
scanf("%d",&newnode -> data) ;

if(head == NULL) {
    head = newnode ;
    newnode -> next = NULL ;
    newnode -> prev = NULL ;
} else {
    temp = head ;
    while (temp -> next != NULL) {
        temp = temp -> next ;
    }
    newnode -> next = NULL ;
    temp -> next = newnode ;
    newnode -> prev = temp ;
}

}

void insertAtpos() {
newnode = malloc(sizeof(struct node)) ;
printf("Enter Data for newnode:") ;
scanf("%d",&newnode -> data) ;

printf("Enter position:") ;
scanf("%d",&pos) ;

if(head == NULL) {
    head = newnode ;
    newnode -> next = NULL ;
    newnode -> prev = NULL ;
} else {
    count = 0 ;
    temp = head ;
    while(temp -> next != NULL) {
        temp = temp -> next ;
        count++ ;
    }

if(pos < 1 || pos > count) {
    printf("Invalid Position") ;
} else {
    temp = head ;
    while (i < pos) {
        prevnode = temp ;
        temp = temp -> next ;
        i++ ;
    }
    newnode -> next = temp ;
    temp -> prev = newnode ;
    prevnode -> next = newnode ;
    newnode -> prev = prevnode ;

}
}


}

void deleteFirst () {
if(head == NULL) {
printf("DLL is Empty!") ;
} else if (head -> next == NULL) {
temp = head ;
head = NULL ;
free(temp) ;
} else {
temp = head ;
head -> prev = NULL ;
temp -> next = NULL ;
free(temp) ;
}
}

void deleteLast() {
temp = head ;
while (temp -> next != NULL) {
prevnode = temp ;
temp = temp -> next ;
}
if(head == NULL) {
printf("DLL is Empty !") ;
} else if (temp == head) {
head = NULL ;
free(temp) ;
} else {
prevnode -> next = NULL ;
temp -> prev = NULL ;
free(temp) ;
}
}

void deleteAtPos() {
printf("Enter the Position:") ;
scanf("%d",&pos) ;


temp = head ;
while(temp -> next != NULL) {
    temp = temp ->next ;
}
if (pos<1 || pos>count) {
    printf("Invalid Position") ;
} else if(pos == 1) {
    deleteFirst () ;
} else if(pos == count) {
    deleteLast() ;
} else {
    temp = head ;
    while (i<pos) {
        prevnode = temp ;
        temp = temp -> next ;
        i++ ;
    }
    prevnode -> next = temp -> next ;
    temp -> next -> prev = prevnode ;
    temp -> prev = NULL ;
    temp -> next = NULL ;
    free(temp) ;
}

}

void display () {
if(head == NULL) {
printf("DLL is Empty !") ;
}
temp = head ;
printf("\nDLL Data\n") ;
while(temp != NULL) {
printf("%d ",temp->data) ;
temp = temp -> next ;
}
printf("\n") ;

}

int main() {
int choice;

do {
    printf("\n1. Insert at First\n2. Insert At Last\n3. insert At Position\n4. Delete At First\n5. Delete At Last\n6. Delete At Position\n7. Display\n8. Exit\n");
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
            insertAtpos() ;
            break ;
        case 4:
            deleteFirst();
            break;
        case 5:
            deleteLast();
            break;
        case 6:
            deleteAtPos() ;
            break ;
        case 7:
            display() ;
            break;
        case 8: 
            printf("Exiting the program.\n");
            break ;    
        default:
            printf("Invalid Choice!\n");
    }

} while (choice != 8); 

return 0;
} 
