/*#include <stdio.h>

int freeDays(int days, int meetings[][2], int n);

int main() {
    int days, num;

    printf("Number of days: ");
    scanf("%d", &days);

    printf("Number of meetings: ");
    scanf("%d", &num);

    int meetings[num][2];

    printf("Enter meeting days in the format [start end]:\n");
    for (int i = 0; i < num; i++) {
        printf("%d: ", i + 1);
        scanf("%d , %d", &meetings[i][0], &meetings[i][1]);
    }

    int free = freeDays(days, meetings, num);
    printf("Output: %d\n", free);

    return 0;
}

int freeDays(int days, int meetings[][2], int n) {
    int workDays[days + 1];

    for (int i = 1; i <= days; i++) {
        workDays[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int start = meetings[i][0];
        int end = meetings[i][1];

        for (int j = start; j <= end; j++) {
            workDays[j] = 1;
        }
    }

    int free = 0;
    for (int i = 1; i <= days; i++) {
        if (workDays[i] == 0) {
            free++;
        }
    }

    return free;
}*/

// 2d matrix

/*#include <stdio.h>
int main(){
  int arr[10][10];
    int r, c;

    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Output: ");
    matrix(arr, r, c);

    return 0;
}

void matrix(int arr[10][10], int rows, int cols) {
    int i, top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {

        for (i = left; i <= right; i++) {
            printf("%d ", arr[top][i]);
        }
        top++;

        for (i = top; i <= bottom; i++) {
            printf("%d ", arr[i][right]);
        }
        right--;


        if (top <= bottom) {
            for (i = right; i >= left; i--) {
                printf("%d ", arr[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            for (i = bottom; i >= top; i--) {
                printf("%d ", arr[i][left]);
            }
            left++;
        }
    }
}*/

#include<stdio.h>

int main (){
int a[4]={21,38,12,1};
int size = sizeof(a)/ sizeof(a[0]);


for (int i=0; i<= size-2; i++){
    for (int j=i; j<=size-1;j++){
        if (a[j]<a[i]){
            int temp = a[i];
            a[i] = a[j];
            a[j]=temp;
        }
    }
}
printf("sotred arr is");
for(int i=0; i<=size-1; i++){
    printf("%d\t",a[i]);
}
}
