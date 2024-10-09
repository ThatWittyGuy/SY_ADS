#include <stdio.h>

int insertionSort(int arr[], int n)
{   
    int c = 0;
	int i, key, j;
	for (i = 1; i < n; i++) 
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) 
		{
			arr[j + 1] = arr[j];
			c++;
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	return c;
}

int main()
{
	int arr[] = {19, 11, 13, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	int swaps = insertionSort(arr, n);
    for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\nSwaps = %d", swaps);
	return 0;
}


// #include <stdio.h>

// int insertionSort(int arr[], int n)
// {   
//     int c = 0, comp = 0;
// 	int i, key, j;
// 	for (i = 1; i < n; i++) 
// 	{
// 		key = arr[i];
// 		j = i - 1;

// 		while (j >= 0)
// 		comp++;
// 		{
// 			arr[j + 1] = arr[j];
// 			c++;
// 			j = j - 1;
// 		}
// 		arr[j + 1] = key;
// 	}
// 	 printf("Comparsions = %d\n", comp);
// 	return c;
// }

// int main()
// {
// 	int arr[] = {19, 11, 13, 5, 6};
// 	int n = sizeof(arr) / sizeof(arr[0]);

// 	int swaps = insertionSort(arr, n);
//     for (int i = 0; i < n; i++){
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\nSwaps = %d", swaps);
// 	return 0;
// }

// #include <stdio.h>

// int insertionSort(int arr[], int n)
// {   
//     int c = 0, comp =0;
// 	int i, key, j;
// 	for (i = 1; i < n; i++) 
// 	{
// 		key = arr[i];
// 		j = i - 1;

// 		while (j >= 0) 
// 		{   
// 		    comp++;
// 		    if(arr[j]>key)
// 			{
// 			    arr[j + 1] = arr[j];
//     			c++;
//     			j = j - 1;
// 			}
// 		}
// 		arr[j + 1] = key;
// 	}
// 	printf("Comparsions = %d\n", comp);
// 	return c;
// }

// int main()
// {
// 	int arr[] = {19, 11, 13, 5, 6};
// 	int n = sizeof(arr) / sizeof(arr[0]);

// 	int swaps = insertionSort(arr, n);
//     for (int i = 0; i < n; i++){
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\nSwaps = %d", swaps);
// 	return 0;
// }


// #include <stdio.h>

// int insertionSort(int arr[], int n)
// {   
//     int c = 0, comp =0;
// 	int i, key, j;
// 	for (i = 1; i < n; i++) 
// 	{
// 		key = arr[i];
// 		j = i - 1;

// 		while (j >= 0 && arr[j] > key) 
// 		{
// 			arr[j + 1] = arr[j];
// 			c++;
// 			j = j - 1;
// 		}
// 		arr[j + 1] = key;
// 	}
// 	return c;
// }

// int main()
// {
// 	int arr[] = {19, 11, 13, 5, 6};
// 	int n = sizeof(arr) / sizeof(arr[0]);

// 	int swaps = insertionSort(arr, n);
//     for (int i = 0; i < n; i++){
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\nSwaps = %d", swaps);
// 	return 0;
// }
