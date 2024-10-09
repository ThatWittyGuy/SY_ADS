    #include <stdio.h>  
      
    int bubble_sort(int arr[], int n) {  
      int i, j;  
      int c = 0, comp =0;
      for (i = 0; i < n - 1; i++) {  
        for (j = 0; j < n - i - 1; j++) {
            comp ++;
          if (arr[j] > arr[j + 1]) {  
            int temp = arr[j];  
            arr[j] = arr[j + 1];  
            arr[j + 1] = temp; 
            c++;
          }  
        }  
      } 
      printf("Comparsions = %d\n", comp);
      return c;
    }  
    int main() {  
      int arr[] = {1, 2, 3, 4, 5, 6, 7};  
      int n = sizeof(arr) / sizeof(arr[0]);  
      int swaps = bubble_sort(arr, n);  
      printf("Sorted array: ");  
      for (int i = 0; i < n; i++) {  
        printf("%d ", arr[i]);  
      }  
      printf("\nSwaps = %d", swaps);
      return 0;  
    }  

    // With Flag

    // #include <stdio.h>  
      
    // int bubble_sort(int arr[], int n) {  
    //   int i, j;  
    //   int c = 0, comp =0;
    //   for (i = 0; i < n - 1; i++) { 
    //       int flag = 0;
    //     for (j = 0; j < n - i - 1; j++) {
    //         comp ++;
    //       if (arr[j] > arr[j + 1]) {  
    //         int temp = arr[j];  
    //         arr[j] = arr[j + 1];  
    //         arr[j + 1] = temp; 
    //         flag = 1;
    //         c++;
    //       } 
    //       if (flag==0)
    //         break;
    //     }  
    //   } 
    //   printf("Comparsions = %d\n", comp);
    //   return c;
    // }  
    // int main() {  
    //   int arr[] = {1, 2, 3, 4, 5, 6, 7};  
    //   int n = sizeof(arr) / sizeof(arr[0]);  
    //   int swaps = bubble_sort(arr, n);  
    //   printf("Sorted array: ");  
    //   for (int i = 0; i < n; i++) {  
    //     printf("%d ", arr[i]);  
    //   }  
    //   printf("\nSwaps = %d", swaps);
    //   return 0;  
    // }  