#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

int top = -1;
int stack[50]; 

void push(int n){ 
    top=top+1; 
    stack[top]=n;  
}

int pop(){
    return stack[top--];
} 

int main(){ 
    int i=0,x,a,b,result;
    char str[50]; 
    printf("Enter the valid expression : "); 
    gets(str);
    int lenght = strlen(str);
    while(str[i]!='\0'){
        if(str[i]>=48 && str[i]<=57){
            x=str[i]-48; 
            push(x);
        } 
        else{
            a=pop(); 
            b=pop(); 
            switch(str[i]){
                case '+': 
                result = b+a;
                push(result); 
                break; 

                case '-': 
                result = b-a;
                push(result); 
                break; 

                case '*': 
                result = b*a;
                push(result); 
                break; 

                case '/': 
                result = b/a;
                push(result); 
                break;
            }
        } 
        ++i;
    } 
    printf("Result : %d",result);
}