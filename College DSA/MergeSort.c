//MERGE SORT
#include <stdio.h>

void mergeSort(int a[],int i, int j) {
   int mid;
   if(i==j)
      return;
   else
   {
      mid=(i+j)/2;
      mergeSort(a,i,mid);
      mergeSort(a,mid+1,j);
      merging(a,i, mid,mid+1,j);
   } 
}

void merging(int a[],int i, int mid,int k, int j) 
{
   int b[50];
   int p;
   p=i;
   while(i<=mid && k<=j ) 
   {
      if(a[i]<=a[k])
        b[p++]=a[i++];
	  else
        b[p++]=a[k++];
   } 
   while(i<=mid) //copying remaining elements of first past of array a into array b.   
      b[p++]=a[i++];
      
   while(k<=j)   
      b[p++]=a[k++];
      
   for(i=0;i<=j;i++)
      a[i]=b[i];
}

int main()
{
  int arr[]={38,27,43,3,9,82,10},n,i;
    n=sizeof(arr)/sizeof(arr[0]);
    printf ("\nArray before sorting:\n") ;
	for (i=0;i<n;i++)
		printf ("%d ",arr[i] ) ;
	mergeSort(arr,0,n-1);
	
	printf ("\nArray after sorting in ascending order:\n") ;
	for (i=0;i<n;i++)
		printf ("%d ",arr[i] ) ;
	return 0;
}