#include <stdio.h>
#include <string.h> 
#define SIZE 5

struct Song {
    int id ;
    char name[100] ;
} ;

struct Song queue[SIZE] ;

int front = -1;
int rear = -1;

void enQueue(struct Song s) {
    if ((rear + 1) % SIZE == front) {
        printf("Playlist is full!\n");
    } else if (rear == -1 && front == -1) {  
        rear = 0;
        front = 0;
        queue[rear] = s;
        printf("Added: %s to ID: %d\n",s.name,s.id ) ;
        
    } else {
        rear = (rear + 1) % SIZE;
        queue[rear] = s;
        printf("Added: %s to ID: %d\n",s.name,s.id ) ;
    }
}

void deQueue() {
    if (rear == -1 && front == -1) {       
        printf("Playlist is Empty!\n");
    } else if (rear == front) { 
        printf("Deleted: %s (ID: %d)\n", queue[front].name, queue[front].id);
        rear = -1;
        front = -1;
    } else {       
        printf("Deleted: %s (ID: %d)\n", queue[front].name, queue[front].id);
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (rear == -1 && front == -1) { 
        printf("Playlist is Empty!\n");
    } 
    
    printf("playlist:\n");
    int i = front;
    while (i != rear) {
        printf("ID: %d, Name: %s\n", queue[i].id,queue[i].name);
        i = (i + 1) % SIZE;
    }
    printf("ID: %d, Name: %s\n", queue[rear].id,queue[rear].name); 
}

int main() {
    struct Song s ;
    int choice;
    while(1) {
        printf("\n-----MUSIC PLAYER-----\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Show Playlist\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a Song ID: ");
            scanf("%d", &s.id);
            printf("Enter song name: ") ;
            scanf(" %[^\n]",s.name) ;
            enQueue(s);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}

