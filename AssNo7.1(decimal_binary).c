#include <stdio.h>
int stack[20] ; 
int top=-1; 

void push(int value) {  
    top++ ;  
    stack[top]=value ; 
} 

void pop() {   
    top-- ; 
}

void decimalToBinary(int num) { 
    if(num==0) {
        printf("0") ;
        return ;
    }
    while(num>0) {
        push(num%2); 
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
    
    decimalToBinary(num) ; 
    return 0 ;
}
