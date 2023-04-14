#include<stdio.h> 
#include<stdlib.h> 
struct node{
    int info; 
    struct node *next;
}; 
struct node *head=NULL; 
void create(){
    struct node *temp,*ptr; 
    temp=(struct node *)malloc(sizeof(struct node));
    int data; 
    printf("Enter the value : "); 
    scanf("%d",&data); 
    temp->info=data; 
    temp->next=NULL; 
    if(head==NULL){
        head=temp;
    } 
    else{ 
        ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        } 
        ptr->next=temp;
    } 
} 
void display(){
    struct node *ptr;
    ptr=head; 
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr=ptr->next;
    } 
    printf("\n");
} 
void insertAtbeg(){
    struct node *ptr,*temp; 
    temp=(struct node *)malloc(sizeof(struct node)); 
    int data; 
    printf("Enter the value : "); 
    scanf("%d",&data); 
    temp->info=data; 
    temp->next=NULL; 
    ptr=head; 
    head=temp; 
    temp->next=ptr;
} 
void insertAtKthpos(){
    struct node *ptr,*temp; 
    temp=(struct node *)malloc(sizeof(struct node )); 
    int data , pos  ,i; 
    printf("Enter the value : "); 
    scanf("%d",&data); 
    printf("Enter the position : "); 
    scanf("%d",&pos); 
    temp->info=data; 
    temp->next=NULL; 
    ptr=head;
    i=1; 
    while(i<pos-1){
        ptr=ptr->next;
        ++i;
    } 
    temp->next=ptr->next;
    ptr->next=temp;
} 
void deleteAtBeg(){
    struct node *ptr; 
    ptr=head; 
    if(ptr==NULL){
        printf("\nUnderflow condition .... "); 
    } 
    else{
        head=ptr->next; 
        free(ptr); 
        printf("\nNode deleted at beginning successfully....\n");
    }
} 
void deleteAtEnd(){
    struct node *ptr,*preptr;
    ptr=head; 
    preptr=head; 
    if(head==NULL){
        printf("underflow...\n");
    } 
    else if (ptr->next=NULL){
        head=NULL;
        printf("deleted successfully...\n"); 
        free(ptr);
    } 
    else{
        while(ptr->next!=NULL){
            preptr=ptr;
            ptr=ptr->next;
        } 
        preptr->next=NULL;
        free(ptr);         
    }   
} 
void deleteAtKthPos(){
    struct node *ptr,*preptr,temp; 
    int pos; 
    printf("Enter the position for the deletion : "); 
    scanf("%d",&pos); 
    ptr=head;
    int i=1; 
    while(i<pos){
        preptr=ptr; 
        ptr=ptr->next; 
        ++i;
    } 
    preptr->next=ptr->next;
} 
void reversetheList(){
    struct node *preptr,*ptr; 
    if(head!=NULL){
        preptr=head; 
        ptr=head->next; 
        preptr->next=NULL; 
        while(head!=NULL){
            head=head->next; 
            ptr->next=preptr; 
            preptr=ptr; 
            ptr=head;
        } 
        head=preptr;
    }
}

int main(){
    int n; 
    while(1){ 
        printf("Enter 1:Create 2:Display 3:InsertAtbeg 4:InsertAtKthpos 5:DeleteAtbeg 6:DeleteAtEnd 7:DeleteAtKthPos 8:ReversetheList 0:Exit\n"); 
        printf("\nEnter your choice : ");
        scanf("%d",&n); 
        switch(n){ 
            case 1 : create() ; break;
            case 2 : display() ; break;
            case 3 : insertAtbeg() ; break;
            case 4 : insertAtKthpos() ; break;
            case 5 : deleteAtBeg() ; break;
            case 6 : deleteAtEnd() ; break;
            case 7 : deleteAtKthPos() ; break;
            case 8 : reversetheList() ; break;
            case 0 : exit(1) ; break;
            default : printf("Wrong choice...");
        }
    }
}