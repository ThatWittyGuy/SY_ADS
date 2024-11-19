// insertion sort

/*#include <stdio.h>

int main() {
   int arr[50];
   int i=0,j,k,key,size;

   printf("Enter the size of the array:");
   scanf("%d",&size);
   printf("Enter array elements:");
   for (i=0; i<size; i++){
        scanf("%d",&arr[i]);
   }

   printf("Original array is:\n");

   for(i=0; i<size; i++){
    printf("%d\t",arr[i]);
   }
 // insert sort

for (j=1; j<size; j++){
    key = arr[j];

    i = j-1;

while (i>=0 && arr[i]>key){
    arr[i+1] = arr[i];
    i--;
}
 arr [i+1] = key;

}

//display
printf("\n\nThe sorted array using Insertion Sort is\n");
for(i=0; i<size; i++){
    printf("%d\t",arr[i]);
}


return 0;
}*/

// selection sort
/*#include <stdio.h>

int main() {
   int arr[50];
   int i=0,j,temp,small,size=0;

   printf("Enter the size of the array:");
   scanf("%d",&size);
   printf("Enter array elements:");
   for (i=0; i<size; i++){
        scanf("%d",&arr[i]);
   }

 printf("Original array is:\n");
   for(i=0; i<size; i++){
    printf("%d\t",arr[i]);
   }

   for (i = 0; i < size - 1; i++) {
        small = i;

    for (j=i+1; j<size; j++){
      if (arr[small]>arr[j]){
         small = j;
    }
}

// swap with 1st elem
   if (small != i) {
     temp = arr[small];
     arr[small] = arr[i];
     arr[i] = temp;
    }
}

//display
printf("\n\nThe sorted array is\n");
for(i=0; i<size; i++){
    printf("%d\t",arr[i]);
}

return 0;
}*/

// bubble sort ascending order

/*#include <stdio.h>

int main() {
   int arr[50];
   int i,j,temp,size=0;

   printf("Enter the size of the array:");
   scanf("%d",&size);
   printf("Enter array elements:");
   for (i=0; i<size; i++){
        scanf("%d",&arr[i]);
   }

printf("The original array is: \n");
  for(i=0; i<size; i++){
    printf("%d\t",arr[i]);
  }

  for (i = 0; i < size; i++) {
    for (j = 0; j < size-1; j++) {
        if (arr[j] > arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
       }
    }
  }

  printf("\nThe sorted array is: \n");
  for (i=0; i<size; i++){
    printf("%d\t",arr[i]);
  }

return 0;
}*/

//merge sort

#include <stdio.h>

int main() {

   int arr[50];
   int i,size,p,r;

   printf("Enter the size of the array:");
   scanf("%d",&size);
   printf("Enter array elements:");
   for (i=0; i<size; i++){
        scanf("%d",&arr[i]);
   }

printf("The original array is: \n");
  for(i=0; i<size; i++){
    printf("%d\t",arr[i]);
  }
 p = 0;
 r = size-1;

  mergesort (arr,p,r);

  printf("\nThe sorted array is: \n");
  for (i=0; i<size; i++){
    printf("%d\t",arr[i]);
  }

return 0;
}

// recursive fn mergesort
void mergesort (int arr[],int p,int r){
    int q;
  if (p < r){
    q =(p+r)/2;
    mergesort (arr,p,q);
     mergesort (arr, q+1, r);

      merge (arr, p, q, r);

  }
}

void merge (int arr[],int p,int q,int r){
    int i,j,k,n1, n2;

    n1= q-p+1;
    n2 =r-q;

 int L[n1],R[n2]; //the left and right array to store divided arr elements

  for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];


    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

// rem elements in left and right arr will get copied
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}











