// Linear Search 
#include <stdio.h>
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; }
int main() {
    int n, key;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); }
    printf("Enter the element to search for: ");
    scanf("%d", &key);
    int result = linearSearch(arr, n, key);
    if (result == -1) {
        printf("Element not found\n"); } 
    else {
        printf("Element found at index: %d\n", result); }
    return 0;
}
