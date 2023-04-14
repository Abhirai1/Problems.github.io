#include<stdio.h> 
#include<stdlib.h> 

struct node{
    int data; 
    struct node *next;
}; 

struct node *top=NULL;

void push(){
    struct node *temp; 
    temp=(struct node *)malloc(sizeof(struct node)); 
    if(temp==NULL)
    printf("Stack Overflow\n"); 
    else{ 
        int value;
        printf("enter data : "); 
        scanf("%d",&value);
        temp->data=value; 
        temp->next=top; 
        top=temp;
    }
} 

void pop(){
    if(top==NULL)
    printf("Stack Underflow\n");
    else{
        printf("%d",top->data); 
        top=top->next;
    }
} 

void display(){
    struct node *ptr=top;
    while(1){
        if(ptr!=NULL){ 
            printf("%d ",ptr->data);
            ptr=ptr->next;
        } 
        else{
            break;
        }

    }
}

int main(){
    int ch; 
    while(1){
        printf("\n1:push 2:pop 3:display 4:exit...\n"); 
        printf("Enter your choice : ");
        scanf("%d",&ch); 
        switch(ch){
            case 1 : push();break;
            case 2 : pop();break;
            case 3 : display();break;
            case 4 : exit(1);break; 
            default : printf("wrong choice...");
        }
    }
}