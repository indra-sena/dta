#include<iostream>
using namespace std;

#define MAX 100

typedef struct tuple{
  int i;
  int j;
}tup;

typedef struct stack{
  tup items[MAX];
  int top;
}st;

void creatStack(st *s){
  s->top=-1;
}

int isEmpty(st *s){
  if(s->top==-1){
    return 1;
  }
  else{
    return 0;
  }
}

int isFull(st *s){
  if(s->top == MAX-1){
    return 1;
  }
  else{
    return 0;
  }
}

void push(st *s, tup item){
  if(isFull(s)){
    cout<<"stack is full cant add elemnets"<<endl;
  }
  else{
    s->top++;
    s->items[s->top] = item;
  }
}

tup pop(st *s){
  tup temp;
  if(isEmpty(s)){
    cout<<"stack is already empty"<<endl;
  }
  else{
    temp = s->items[s->top];
    s->top--;
  }
  return temp;
}

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

void merge_sort(int arr[], int size, st *s){
  tup init1 = {0,1-size};
  tup init2 = {0,size-1};
  push(s,init1);
  push(s,init2);
  while(!isEmpty(s)){
    tup temp = pop(s);
    if(temp.i<0 || temp.j<0){
      int mid = (-1*temp.i + -1*temp.j)/2;
      merge(arr,-1*temp.i,mid,-1*temp.j);
      continue;
    }
    if(temp.i==temp.j){
      continue;
    }
    else{
      int mid = (temp.i + temp.j)/2;
      tup merge_item = {-1*temp.i,-1*temp.j};
      tup item1 = {mid+1,temp.j};
      tup item2 = {temp.i,mid};
      push(s,merge_item);
      push(s,item1);
      push(s,item2);
    }
  }
}

int main(){
  int n;
  cin>>n;
  for(int x=0;x<n;x++){
    int size;
    cin>>size;
    int a[size];
    for(int y=0;y<size;y++){
      cin>>a[y];
    }
    st *s = (st*)malloc(sizeof(st));
    creatStack(s);
    merge_sort(a,size,s);
    for(int i=0; i<size; i++){
      cout<<a[i]<<'';
    }
    cout<<endl;
  }
}
