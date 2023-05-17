#include<stdio.h>
void quicksort(int [],int,int);
int main()
{
  int a[20],n,i;
  printf("Enter size of the array: ");
  scanf("%d",&n);
  printf("Enter %d elements: ",n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  quicksort(a,0,n-1);
  printf("Sorted elements: ");
  for(i=0;i<n;i++)
    printf(" %d",a[i]);
  return 0;
}
void quicksort(int a[10],int first,int last)
{
    int pivot,j,t,i;
     if(first<last)
	 {
         pivot=first;
         i=first;
         j=last;
         while(i<j)
		 {    
             while(a[i] <= a[pivot]) 
                 i++; 
             while(a[j]>a[pivot])
                 j--;			 
             if(i<j)
			 {
                 t=a[i];
                  a[i]=a[j];
                  a[j]=t;
             }
         }
		 t=a[pivot];
         a[pivot]=a[j];
         a[j]=t;
         quicksort(a,first,j-1);
         quicksort(a,j+1,last);
     }
}
