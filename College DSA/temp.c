#include<stdio.h> 
#include<stdlib.h>

struct node *head=NULL;


struct node {
    int data; 
    struct node *next;
} 

// Good shi hai ye mza aaya

void insert(){
    struct node *temp,*ptr; 
    prt=head;
    temp = (stuct node *)malloc(sizeof(struct node)); 
    temp->data=value; 
    temp->next=NULL; 
    if(head==NULL){
        head=temp;
    } 
    else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        } 
        ptr->next=temp;
    }
}

// display function is done 

void display(){
    struct node *ptr; 
    ptr=head;
    while(ptr!=NULL){
        printf("%d",ptr->data); 
        ptr=ptr->next;
    } 

    
}

void insertAtBeg(){

    struct node *temp,*ptr; 
    prt=head;
    int data; 
// scaf kr lo
    temp = (stuct node *)malloc(sizeof(struct node)); 
    temp->data=value; 
    temp->next=NULL;

    head=temp;
    temp->next=head;

}










// End of Universty


/* Singly Linked List */

// struct node{
//     int data; 
//     struct node *next;
// }; 

// struct node *head=NULL; 

// void insert(){
//     printf("Enter the value "); 
//     int data; 
//     scanf("%d",&data); 
//     struct node *temp; 
//     temp=(struct node *)malloc(sizeof(struct node)); 
//     temp->data=data; 
//     temp->next=NULL; 
//     if(head==NULL)
//     head=temp;
//     else{
//         struct node *ptr; 
//         ptr=head; 
//         while(ptr->next!=NULL){
//             ptr=ptr->next;
//         }
//         ptr->next=temp;
//     }
// }

// void display(){
//     struct node *ptr; 
//     ptr=head; 
//     printf("Values\n ");
//     while(ptr!=NULL){
//         printf("%d ",ptr->data); 
//         ptr=ptr->next;
//     } 

// }

// void insertAtbegining(){
//     printf("Enter the value to insert at begining "); 
//     int data; 
//     scanf("%d",&data); 
//     struct node *temp; 
//     temp=(struct node *)malloc(sizeof(struct node)); 
//     temp->data=data; 
//     temp->next=NULL; 
//     if(head==NULL){
//         head=temp;
//     } 
//     else{
//         temp->next=head; 
//         head=temp;
//     }
// }

// void insertAtKthPos(){
//     int k;
//     printf("Enter pos "); 
//     scanf("%d",&k);
//     printf("Enter the value "); 
//     int data; 
//     scanf("%d",&data); 
//     struct node *temp; 
//     struct node *ptr; 
//     ptr=head;
//     temp=(struct node *)malloc(sizeof(struct node)); 
//     temp->data=data; 
//     temp->next=NULL; 
//     k=k-2;
//     while(k--){
//         ptr=ptr->next;
//     }
//     temp->next=ptr->next; 
//     ptr->next=temp;
// }


// int main(){
//     insert(); 
//     insert(); 
//     display();
//     printf("\n");
//     insertAtbegining();
//     printf("\n");
//     display();
//     insertAtKthPos();
//      printf("\n");
//     display();
// }





// #define Max 3
/* Queue using Array */

// int front=-1,rear=-1;
// int queue[3];

// void enqueue(){
//     // element addition pe rear update hoga
//     int data; 
//     if(rear==Max-1){
//         printf("Full\n");
//     }
//     else{
//         printf("Enter data "); 
//         scanf("%d",&data);
//         if(front==-1)
//         front++; 
//         rear++; 
//         queue[rear]=data;
//     }
// }

// void dequeue(){
//     if(front==-1 || front==rear+1){
//         printf("empty\n");
//     } 
//     else{
//         printf("Dequeued element %d\n",queue[front]); 
//         front++;
//     }
// }

// void display(){
//     if(front==-1)
//     printf("empty\n");
//     else{
//         for(int i=front;i<=rear;i++){
//             printf("%d ",queue[i]);
//         }
//     } 
// }

// int main(){
//     enqueue(); 
//     enqueue(); 
//     display(); 
//     dequeue(); 
//     display();
// }





/* Stack using LinkList */

// struct node{
//     struct node *next; 
//     int data;
// }; 

// struct node *top=NULL;

// void push(){
//     int x; 
//     printf("Enter data "); 
//     scanf("%d",&x); 
//     struct node *temp; 
//     temp=(struct node *)malloc(sizeof(struct node)); 
//     if(temp==NULL)
//     printf("Overflow\n"); 
//     else{
//         temp->data=x; 
//         temp->next=NULL;
//         if(top==NULL)
//         top=temp; 
//         else{ 
//             temp->next=top; 
//             top=temp;
//         }
//     }
    
// }

// void pop(){
//     if(top==NULL)
//     printf("Underflow\n");
//     printf("Valued popped  %d",top->data); 
//     top=top->next;
// }


// void display(){
//     struct node *ptr; 
//     ptr=top; 
//     while(ptr!=NULL){
//         printf("%d\n",ptr->data); 
//         ptr=ptr->next;
//     }
// }


// int main(){
//     push();
//     push();
//     push(); 
//     display();
// }