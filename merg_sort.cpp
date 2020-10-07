//counting no of inversions in an
// array using merge sort algorithm
#include<iostream>
using namespace std;

//added element to merge sort algorithm to find no of inversions
//long inversions=0;

void merge(int arr[], int i, int j, int k){
  int s1=j-i+1,s2=k-j;
  int L[s1],R[s2];
  for(int x=0; x<s1; x++){
    L[x] = arr[x+i];
  }
  for(int x=0; x<s2; x++){
    R[x] = arr[x+1+j];
  }
  int array_start = i,x=0,y=0;
  while(x<s1 && y<s2){
    if(L[x]<=R[y]){
      arr[array_start] = L[x];
      x++;
      array_start++;
    }
    else{
      arr[array_start] = R[y];
      y++;
      array_start++;
      //added element to merge sort algorithm
      //inversions+=s1-x;
    }
  }
  while(x<s1){
    arr[array_start] = L[x];
    x++;
    array_start++;
  }
  while(y<s2){
    arr[array_start] = R[y];
    y++;
    array_start++;
  }
}

void merge_sort(int arr[],int i,int j){
  if(i>=j){
    return;
  }
  int middle = i+(j-i)/2;
  merge_sort(arr,i,middle);
  merge_sort(arr,middle+1,j);
  merge(arr,i,middle,j);
}

int main(){
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    inversions = 0;
    int m;
    cin>>m;
    int arr[m];
    for(int x=0; x<m; x++){
      cin>>arr[x];
    }
    merge_sort(arr,0,m-1);
    cout<<inversions<<endl;
  }
}
