// QUICK SORT

#include <stdio.h>

int partition (int arr[],int p, int q){

  int pivot = arr[p]; //pivot will be first element
  int i = p; //i will iterate through left
  int j=q; //j will iterate right

  while (i<j){
    while (arr[i]<=pivot && i<=q-1){
        i++; // incr i
    }

    while (arr[j]> pivot && j>= p+1){
        j--;
    }
    if (i<j){
        swap (&arr[i],&arr[j]);
    }
  }
  swap (&arr[p],&arr[j]);
  return j;
}

void swap (int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void quicksort(int arr[],int p, int q){
    if (p<q){
        int index = partition (arr, p, q);
        quicksort (arr, p, index-1);
        quicksort (arr, index+1,q);
    }
}

int main() {

   int arr[50];
   int i,n;

   printf("Enter the size of the array:");
   scanf("%d",&n);
   printf("Enter array elements:");
   for (i=0; i<n; i++){
        scanf("%d",&arr[i]);
   }

   printf("Original array is:\n");

   for(i=0; i<n; i++){
    printf("%d\t",arr[i]);
   }

   quicksort (arr, 0, n-1);

   printf("\nSorted array is:\n");
   for(int i=0; i<n; i++){
    printf("%d\t",arr[i]);
   }
return 0;
}
