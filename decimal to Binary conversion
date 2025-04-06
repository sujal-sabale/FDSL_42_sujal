#include <stdio.h>
int stack[20] ; // for storing binary number
int top=-1; // initally stack iis empty, then declare top equal to -1

void push(int value) {  // push the element into the stack
    top++ ;  // increment top value by 1
    stack[top]=value ; // store the top element of stack into the variable value 
} 

void pop() {   // pop function to delete the top value of stack
    top-- ;  // decrement the top value by 1
}

void decimalToBinary(int num) { 
    if(num==0) {
        printf("0") ;
        return ;
    }
    while(num>0) {
        push(num%2); // push remainder in stack
        num = num/2 ; 
    }
    while(top!=-1) {
        printf("%d",stack[top]) ;
        pop() ;
    }
}

int main() {
    int num ;
    printf("Enter a Decimal No. to Convert into Binary:");
    scanf("%d",&num) ;
    
    decimalToBinary(num) ; // function calling
    return 0 ;
}
