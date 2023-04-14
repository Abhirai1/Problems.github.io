#include<stdio.h> 
#include<stdlib.h>  
#include<string.h>

struct node{
    int info; 
    struct node *next;
};
struct node *top=NULL; 
char ans[100];
int index=0;

void push(char value){ 
    // int value;
    struct node *temp; 
    temp=(struct node *)malloc(sizeof(struct node)); 
    // printf("Enter the value : "); 
    // scanf("%d",&value); 
    temp->info=value;
    if(top==NULL){
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
        ans[index++]=top->info;
       // printf("poped element is : %d\n",top->info); 
        top=top->next;
        free(ptr);
    }
} 

int main(){
    int n,i;
    char str[20];
   printf("Enter the string\n");
   scanf("%s",str);
   n=strlen(str);
   for(i=0;i<n;i++)
   {
       push(str[i]);
   } 
   for(i=0;i<n;i++)
   {
       pop();
   } 
   for(i=0;i<strlen(ans);i++)
   {
       printf("%c",ans[i]);
   }
}