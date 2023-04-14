#include <stdio.h> 
#include <stdlib.h> 
#define NULL 0 
struct node 
{ 
 int coeff; 
 int exp; 
 struct node *next; 
}; 
struct node * Allocate(int c, int e) 
{ 
 struct node * nn=(struct node *) malloc(sizeof(struct node )); 
 nn->coeff=c; 
 nn->exp=e; 
 nn->next=NULL; 
 return nn; 
} 
void print(struct node *head) 
{ 
 struct node *curr; 
 if(head==NULL) 
 printf("Empty list"); 
 else{ 
 for(curr=head;curr->next!=NULL;curr=curr->next){ 
 printf("%d x^ %d + ",curr->coeff, curr->exp); 
 } 
 if(curr->exp==0) 
 printf("%d ",curr->coeff); 
 else printf("%d x^ %d ",curr->coeff, curr->exp); 
 } 
} 
struct node * create(struct node *head) 
{ 
 int c,e; 
 struct node *n,*curr,*save; 
 printf("Enter the exponent & coefficient"); 
 scanf("%d %d",&c,&e); 
 
 do 
 { 
 struct node *n=Allocate(c,e); 
 if(head==NULL || e > head->exp) 
 { 
 n->next=head; 
 head=n; 
 } 
 else{ 
 curr=head; 
 while(curr && e<curr->exp){ 
 save=curr; 
 curr=curr->next; 
 } 
 if(curr==NULL || e!=curr->exp){ 
 save->next=n; 
 n->next=curr; 
 } 
 else 
 { 
 curr->coeff=curr->coeff + c; 
 free(n); 
 } 
 }
 int choice;
 printf("\ndo u want to add more element to expression then print Y else N\n");
 scanf("%d",&choice);
 if(choice!=-1){
     printf("Enter the exponent & coefficient"); 
     scanf("%d %d",&c,&e);
 }
 else break;
 }while(1); 
 return head; 
} 
struct node *insert(struct node *head3,int c, int e) 
{ 
 struct node *curr; 
 struct node *n=Allocate(c,e); 
 if(head3==NULL){ 
 head3=n; 
 } 
 else{ 
 curr=head3; 
 while(curr->next!=NULL) 
 curr=curr->next; 
 curr->next=n; 
 } 
 return head3; 
}; 
struct node *add(struct node *head1,struct node *head2,struct node *head3) 
{ 
 struct node *t1,*t2,*n; 
 t1=head1; 
 t2=head2; 
 while(t1!=NULL && t2!=NULL) 
 { 
 if(t1->exp > t2->exp){ 
 head3 = insert(head3,t1->coeff,t1->exp); 
 t1=t1->next; 
 } 
 else if(t2->exp > t1->exp){ 
 head3 = insert(head3,t2->coeff,t2->exp); 
 t2=t2->next; 
 } 
 else{ 
 head3 = insert(head3,t1->coeff + t2->coeff,t1->exp); 
 t1=t1->next; 
 t2=t2->next; 
 } 
 } 
 while(t1!=NULL) 
 { 
 head3 = insert(head3,t1->coeff,t1->exp); 
 t1=t1->next; 
 } 
 while(t2!=NULL) 
 { 
 head3 = insert(head3,t2->coeff,t2->exp); 
 t2=t2->next; 
 } 
 return head3; 
} 
int main() 
{ 
 struct node *head1=NULL,*head2=NULL,*head3=NULL; 
 printf("\nEnter the first polynomial\n"); 
 head1=create(head1); 
 printf("\nEnter the second polynomial\n"); 
 head2=create(head2); 
 printf("\nThe first polynomial: "); 
 print(head1); 
 printf("\nThe second polynomial: "); 
 print(head2); 
 head3=add(head1,head2,head3); 
 printf("\nThe Added Result: "); 
 print(head3); 
 return 0; 
}