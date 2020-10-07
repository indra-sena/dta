#include<iostream>
#include<vector>

using namespace std;

void swap(int *p,int *q){
  int temp = *q;
  *q = *p;
  *p = temp;
}

void heapify(vector<int> &ht, int i){
  // this code is for max heapify
  int size = ht.size();
  int largest = i;
  int l = 2*i+1;
  int r = 2*i+2;
  if(l<size && ht[l]>ht[largest]){
    largest = l;
  }
  if(r<size && ht[r]>ht[largest]){
    largest = r;
  }
  if(largest != i){
    swap(&ht[i],&ht[largest]);
    heapify(ht,largest);
  }
}

void insert(vector<int> &ht,int item){
  if(ht.size()==0){
    ht.push_back(item);
  }
  else{
    ht.push_back(item);
    for(int i=ht.size()/2-1; i>=0; i--){
      heapify(ht,i);
    }
  }
}

void remove(vector<int> &ht, int num){
  int size = ht.size();
  if(size==0){
    cout<<"queue is empty"<<endl;
    return;
  }
  int i;
  for(i=0; i<ht.size(); i++){
    if(ht[i]==num){
      break;
    }
  }
  swap(&ht[size-1],&ht[i]);
  ht.pop_back();
  for(int i=ht.size()/2-1; i>=0; i--){
    heapify(ht,i);
  }
}

void print(vector<int> &ht){
  for(int i=0; i<ht.size(); i++){
    printf("%d ",ht[i]);
  }
  cout<<endl;
}

int main(){
  vector<int> heapTree;

  insert(heapTree, 3);
  cout << "Max-Heap array: ";
  print(heapTree);
  insert(heapTree, 4);
  cout << "Max-Heap array: ";
  print(heapTree);
  insert(heapTree, 9);
  cout << "Max-Heap array: ";
  print(heapTree);
  insert(heapTree, 5);
  cout << "Max-Heap array: ";
  print(heapTree);
  insert(heapTree, 2);

  cout << "Max-Heap array: ";
  print(heapTree);

  remove(heapTree, 4);

  cout << "After deleting an element: ";

  print(heapTree);
  return 0;
}
