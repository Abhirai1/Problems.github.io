// Implementation of Quick Sort in C Language
#include <stdio.h>
void quickSort(int [],int ,int ); 
int partition(int [], int , int ); 
void exchange(int *,int *) ;
enum bool { FALSE,TRUE };
int main()
{
 int arr[50],n,i;
 printf("How many element you want to store in array:");
 scanf("%d",&n);
 printf("Enter array elements:");
 for (i=0;i<n;i++ )
scanf("%d",&arr[i] ) ;
printf ("\nArray before sorting:\n") ;
for (i=0;i<n;i++ )
printf ("%d\t",arr[i] ) ;
quickSort(arr,0,n-1);
printf ("\nArray after sorting in ascending order:\n") ;
for (i=0;i<n;i++)
printf ("%d\t",arr[i] ) ;
return 0;
 
}
void quickSort(int arr[],int start,int end) 
{
 int position;
 if (start<end) 
 {
 position=partition(arr,start, end);
 quickSort(arr,start,position-1);
 quickSort(arr,position+1,end);
 }
}
int partition(int arr[], int start, int end) 
{
    int j;
    int pivot=arr[end];
    int i =(start-1);
    for (j=start;j<end;j++) 
    {
        if (arr[j]<=pivot) 
        {
            i++;
            exchange(&arr[i],&arr[j]);
        }
    }
    exchange(&arr[i+1],&arr[end]);
    return (i+1);
}
void exchange(int *a,int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}