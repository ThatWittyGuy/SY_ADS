#include<stdio.h>

int main(){
  int arr[10];
  int n,i;

  printf("Enter size of array: ");
  scanf("%d",&n);
  printf("enter array: ");
  for(i=0;i<n;i++ ){
    scanf("%d",&arr[i]);
  }

  swapped(arr,n);
  return 0;
}

void swapped(int arr[],int n){
  int f =-1, s=-1;
  int i;

  for (i=0;i<n-1;i++){
    if(arr[i]>arr[i+1]){
        if(f==-1){
            f = i;
        }
        else {
            s = i+1;
        }

        if (s==-1){
            s = f+1;
        }
    }
  }

  printf("swapped elements are: %d %d \n",arr[f],arr[s]);
  printf("positions are: %d %d",f   ,s);
}
