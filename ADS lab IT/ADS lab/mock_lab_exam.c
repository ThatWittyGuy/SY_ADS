// q1 sort in ascending order using quicksort
/*
#include<stdio.h>

int main() {
 int arr[30];
 int i,n;
 printf("enter size: ");
 scanf("%d",&n);
 printf("enter elements: ");
 for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
 }
 printf("Original array: \n");
 for(i=0;i<n;i++){
    printf("%d\t",arr[i]);
 }

 quickSort (arr,0,n-1); //p=0 ,q=n-1
 printf("\nsorted array: \n");
 for(i=0;i<n;i++){
    printf("%d\t",arr[i]);
 }
 return 0;
}

void quickSort(int arr[],int p, int q){
  if(p<q){
    int i = partition (arr,p,q);  //the partition index
    quickSort(arr,p,i-1);
    quickSort(arr,i+1,q);
  }
}

int partition (int arr[],int p, int q){
  int pivot =arr[p]; //fisrt elemnt
  int i=p;
  int j= q;

  while(i<j){
    while(arr[i]<=pivot && i<=q-1){ //i will traverse to right to find 1st large element
        i++;
    }
    while (arr[j]>pivot && j>= p+1){
        j--;
    }
    if(i<j){
        swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[p],&arr[j]);
  return j;
}

void swap(int *a, int *b){
 int temp = *a;
 *a = *b;
 *b = temp;
}
*/

// q3 linear search string
#include <stdio.h>
#include <string.h>

#define MAX 10
#define MAX_LEN 20


int linearSearch(char arr[][MAX_LEN], int size, char k[]) {
for (int i = 0; i < size; i++) {
    if (strcmp(arr[i], k) == 0) {
        return (i+1);
    }
}
return -1;
}

int main() {
    int n;
    char arr[MAX][MAX_LEN], k[MAX_LEN];

    printf("enter number of strings: ");
    scanf("%d", &n);

    printf("enter strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    printf("enter the string to search: ");
    scanf("%s", k);

    int res = linearSearch(arr, n, k);
    if (res != -1) {
        printf("String '%s' found at %d.\n", k, res);
    } else {
        printf("String '%s' not found in array.\n", k);
    }

    return 0;
}






