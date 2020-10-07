#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAX 5

class Queue{
  private:
    int items[MAX],end,start;
  public:
    Queue(){
      start = -1;
      end = -1;
    }
    isEmpty(){
      if(start==-1){
        return 1;
      }
      else{
        return 0;
      }
    }
    isFull(){
      if(end==MAX-1){
        return 1;
      }
      else{
        return 0;
      }
    }
    void enQueue(int item){
      if(isFull()){
        cout<<"Queue is fill"<<endl;
      }
      else if(start ==-1){
        start = 0;
        end = 0;
        items[end] = item;
      }
      else{
        end++;
        items[end] = item;
      }
    }
    void deQueue(){
      if(isEmpty()){
        cout<<"Queue is already empty"<<endl;
      }
      else{
        start++;
        if(start>=end){
          start = -1;
          end = -1;
        }
      }
    }
    void display(){
      if(start!=-1){
        for(int i=start; i<=end; i++){
          printf("%d ",items[i]);
        }
      }
      else{
        printf("Queue is empty");
      }
      cout<<endl;
    }
};


int main(){
  Queue q;

  //deQueue is not possible on empty queue
  q.deQueue();

  //enQueue 5 elements
  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);

  //6th element can't be added to queue because queue is full
  q.enQueue(6);

  q.display();

  //deQueue removes element entered first i.e. 1
  q.deQueue();


  q.display();
  /* This is a limitation of this queue because even though
  queue has only 4 elements since last is filled items cant be added*/
  q.enQueue(6);  //this also cant be added
  //Now we have just 4 elements
  q.display();
  return 0;
}
