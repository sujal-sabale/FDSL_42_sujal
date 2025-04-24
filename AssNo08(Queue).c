#include <stdio.h>
#define max 5
int rear = -1, front = -1 ;
int queue[max] ;

void enQueue(int element) {
     if(rear == max-1) {
       printf("Queue is Full!") ;
     } else { 
       rear++ ;
       queue[rear] = element ;
     } 
}

void deQueue() {
     if(front == rear) {
       printf("Queue is Empty !") ;
     } else {
       front++ ;
       printf("%d Element is Deleted",queue[front] ) ;
     }
}

void display() {
     if(front == rear) {
        printf("Queue is Empty!") ;
     } else {
       printf("Elements in Queue are:\n" ) ;
       for(int i=front+1; i<=rear; i++) {
         printf("%d\t",queue[i] ) ;
       } 
     }
}

int main () {

int element ;
int choice ;
do{
printf("\n-----QUEUE OPERATIONS-----\n");
printf("\n1.push\n2.pop\n3.Display\n4.Exit\n") ;
printf("Enter Your Choice:") ;
scanf("%d",&choice) ; 

switch(choice) {
case 1:
      printf("Enter a number: ") ;
      scanf("%d",&element ) ;
      enQueue(element);
      break ;
case 2:
      deQueue();
      break ;
case 3:
      display() ;
      break ;
case 4:
      printf("Exiting The program") ;
      break ;
default:
      printf("Invalid Choice!") ;     
}
} while(choice != 4) ;

return 0 ;
}
 
            
