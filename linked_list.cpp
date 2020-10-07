#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct Node{
  int value;
   Node* next = NULL;
}Node;

void insertAtBegin(Node** ref, int data){
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->value = data;
  new_node->next = (*ref);
  (*ref) = new_node;
}

void insertAtEnd(Node** ref, int data){
  Node* new_node = (Node*)malloc(sizeof(Node));
  Node* last = *ref;

  new_node->value = data;
  new_node->next = NULL;

  if (*ref == NULL) {
    *ref = new_node;
    return;
  }

  while (last->next != NULL)
    last = last->next;

  last->next = new_node;
  return;
}

void insertAfter(Node* prev, int data){
  if(prev == NULL){
    cout<<"previous Node cannot be NULL"<<endl;
    return;
  }
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->value = data;
  new_node->next = prev->next;
  prev->next = new_node;
}

void deleteNode(Node** ref, int key){
  Node *temp,*prev;
  temp = *ref;
  // if first node has that key
  if(temp != NULL && temp->value == key){
    *ref = temp->next;
    free(temp);
    return;
  }
  //search for key
  while(temp != NULL && temp->value != key){
    prev = temp;
    temp = temp->next;
  }
  //if key is no present
  if(temp == NULL){
    return;
  }
  //changing connections
  prev->next = temp->next;
  free(temp);
}


void printList(Node* start){
  cout<<"List : ";
  while(start != NULL){
    printf("%d ",start->value);
    start = start->next;
  }
  cout<<endl;
}
int main(){
  Node* head =NULL;
  
  insertAtEnd(&head, 1);
  insertAtBegin(&head, 2);
  insertAtBegin(&head, 3);
  insertAtEnd(&head, 4);
  insertAfter(head->next, 5);

  cout << "Linked list: ";
  printList(head);

  cout << "\nAfter deleting an element: ";
  deleteNode(&head, 4);
  printList(head);
  return 0;
}
