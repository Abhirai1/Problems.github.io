#include<stdio.h> 
#include<stdlib.h> 

struct node{
    int info; 
    struct node *next;
};

struct node *top=NULL; 

void push(){ 
    int value;
    struct node *temp; 
    temp=(struct node *)malloc(sizeof(struct node)); 
    printf("Enter the value : "); 
    scanf("%d",&value); 
    temp->info=value;
    if(temp==NULL){
        top=temp;
    } 
    else{
        temp->next=top;
        top=temp;
    }    
}
void pop(){ 
    struct node *ptr;
    if(top==NULL){
        printf("underflow\n");
    }
     
    else{
        ptr=top;
        printf("poped element is : %d\n",top->info); 
        top=top->next;
        free(ptr);
    }
} 
void display(){ 
    while(1){
        if(top!=NULL){
        printf("%d\n",top->info); 
        top=top->next;
        } 
        else{
            break;
        }
    }
    
}

int main(){
    int ch; 
    while(1){
        printf("1:push 2:pop 3:display 4:exit...\n"); 
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