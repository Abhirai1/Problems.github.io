#include<stdlib.h> 
#include<stdio.h> 
#define Max 5  

// Concept hai eska ek 
// insertion (enqueue) ka matlab -> rear me changes 
// deletion (dequeue) ka matlab -> front me chnages

int front =-1; 
int rear=-1; 
int queue[Max];

void enQueue(){ 
    int value;
    if(rear==Max-1){
        printf("Queue is full\n"); 
    } 
    else{
        if(front==-1){
            front=0;
        } 
        rear++; 
        printf("Enter the value : "); 
        scanf("%d",&value); 
        queue[rear]=value;
    }
} 

void deQueue(){
    if(front==-1 || front==rear+1){
        printf("Queue is empty\n"); 
    } 
    else{ 
        printf("Queued element : %d\n",queue[front]);
        front++; 

    }
}

void display(){
    if(front==-1 || front==rear+1){
        printf("Queue is empty\n"); 
    } 
    else{ 
        printf("Elements of the Queue :");
        for(int i=front ; i<rear+1;i++){
            printf(" %d",queue[i]);
        } 
        printf("\n");
    } 
}

int main(){
    int n; 
    while(1){
        printf("1-Enqueue , 2-Dequeue , 3-Display , 0-exit\n");
        scanf("%d",&n); 
        switch(n){
            case 1 : enQueue(); break; 
            case 2 : deQueue(); break;
            case 3 : display(); break; 
            case 0 : exit(0); break;
            default : printf("Wrong Choice\n");
        }
    }    
}