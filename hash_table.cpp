/* this is incomplete code fonosh when
you learn complete concept*/


#include<iostream>
#include<list>
using namespace std;

class HashTable{
  int capacity;
  list<int> *table;
public:
  HashTable(int n){
    int size = getPrime(n);
    capacity = size;
    table = new list<int>[capacity];
  }

  void insertItem(int key, int data){
    int index = hashFunction(key);
    table[index].push_back(data);
  }

  void deleteItem(int key){

  }

  int hashFunction(int key){
    return key%capacity;
  }
  int isPrime(int n){
    int i;
    if(n==0 || n==1){
      return 0;
    }
    for(i=2; i<n/2; i++){
      if(n%i==0) return 0;
    }
    return 1;
  }

  int getPrime(int n){
    if(n%2==0){
      n++;
    }
    while(!isPrime(n)){
      n+=2;
    }
    return n;
  }
};

int main(){
  HashTable h(2);

}
