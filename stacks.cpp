#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 100

typedef struct stack{
  int items[MAX];
  int top;
}st;
//typedef struct stack st;

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

void push(st *s, int item){
  if(isFull(s)){
    cout<<"stack is full cant add elemnets"<<endl;
  }
  else{
    s->top++;
    s->items[s->top] = item;
  }
}

void pop(st *s){
  if(isEmpty(s)){
    cout<<"stack is already empty"<<endl;
  }
  else{
    s->top--;
  }
}

void printStack(st *s){
  printf("Stack : ");
  for(int i=0; i<=s->top; i++){
    printf("%d ",s->items[i]);
  }
  cout<<endl;
}

int main(){
  st *s = (st *)malloc(sizeof(st));

  creatStack(s);

  push(s,1);
  push(s,2);
  push(s,3);
  push(s,4);

  printStack(s);

  pop(s);

  printStack(s);
  return 0;
}
