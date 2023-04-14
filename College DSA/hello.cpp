#include <iostream> 
#include <bits/stdc++.h>
using namespace std; 

#define lli long long int 

int main() {
    lli test;
    cin>>test;
    while(test--){
        int n,j=0,k=0; 
        cin>>n; 
        int *a=new int[n]; 
        int *b=new int[n];
        int *ONE=new int[n]; 
        int *ZERO=new int[n]; 
        int zero=0,one=0;
        for(int i=0;i<n;i++){ 
            cin>>a[i]; 
            if(a[i]==0){
                ++zero;
            } 
            else{
                ++one;
            }
        }  
        for(int i=0;i<n;i++){
            cin>>b[i]; 
            if(a[i]==0){
                ONE[j]=b[i];
                ++j;
            } 
            else{
                ZERO[k]=b[i];
                ++k;
            }
        } 
        sort(ONE,j); 
        sort(ZERO,k); 
        lli cnt = min(one,zero); 
        lli sum=0; 
        --j;
        --k;
        for(int i=0;i<cnt;i++){
            sum+=2*ZERO[j];
            --j;
        } 
        for(int i=0;i<cnt;i++){   
            sum+=2*ZERO[k];
            --k;
        } 
        for(int i=0;i<zero-cnt;i++){
            sum+=ZERO[i];
        } 
        for(int i=0;i<one-cnt;i++){
            sum+=ONE[i];
        } 
        cout<<sum<<endl;

    }
}
