#include<stdio.h> 
#include<stdlib.h> 
int MAX,stack[1000]; 
int top = -1;

void push(){ 
    int value; 
    if(top==MAX-1){
        printf("\nStack Overflow...\n");
    } 
    else{ 
        top=top+1; 
        printf("\nEnter the value : "); 
        scanf("%d",&value); 
        stack[top]=value;
    }
    
} 
void pop(){ 
    if(top==-1){
        printf("\n Stack Underflow...\n");
    } 
    else{
        printf("pop element is %d\n",stack[top]); 
        top=top-1;
    }
    
}      
void display(){ 
    while(1){
        if(top>=0){
            printf("%d\n",stack[top]); 
            top=top-1;  
        } 
        else{
            break;
        }
    } 
}

int main(){
    int n,ch; 
    printf("\nEnter the number of elements in stack : "); 
    scanf("%d",&n);
    MAX=n; 
    while(1){
        printf("1:Push 2:Pop 3:Display 4:Exit...   ");
        scanf("%d",&ch); 
        switch(ch){
            case 1 : push();break; 
            case 2 : pop();break; 
            case 3 : display();break; 
            case 4 : exit(1);break;
        }
    }
}