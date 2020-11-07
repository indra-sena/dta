#include<iostream>

using namespace std;

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *arr, int i, int j){
  int pivot = arr[i];
  int k = i;
  for(int x=i+1; x<=j; x++){
    if(arr[x] <= pivot){
      k++;
      swap(&arr[x],&arr[k]);
    }
  }
  swap(&arr[i],&arr[k]);
  return k;
}

void QuickSort(int *arr, int i, int j){
  if(i>=j){
    return;
  }
  int p = partition(arr,i,j);
  QuickSort(arr,i,p-1);
  QuickSort(arr,p+1,j);
}

int main(){
  int n;
  cin>>n;
  int A[n];
  for(int i=0; i<n; i++){
    cin>>A[i];
  }
  QuickSort(A,0,n-1);
  for(int i=0; i<n; i++){
    cout<<A[i]<<endl;
  }
  return 0;
}
