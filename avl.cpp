#include<iostream>
#include<stdlib.h>

using namespace std;

class Node{
public:
  int value;
  Node *left, *right;
  int height;
};

Node* newNode(int value){
  Node* node = new Node();
  node->value = value;
  node->left = node->right = NULL;
  node->height = 1;
  return node;
}

int height(Node *node){
  if(node == NULL){
    return 0;
  }
  return node->height;
}

int getBalanceFactor(Node *node){
  if(node == NULL){
    return 0;
  }
  return height(node->left)-height(node->right);
}

Node* leftRotate(Node *x){
  Node *y = x->right;
  Node *T = y->left;
  y->left = x;
  x->right = T;
  x->height = max(height(x->left),height(x->right))+1;
  y->height = max(height(y->left),height(y->right))+1;
  return y;
}

Node* rightRotate(Node *x){
  Node *y = x->left;
  Node *T = y->right;
  y->right = x;
  x->left = T;
  x->height = max(height(y->left),height(y->right))+1;
  y->height = max(height(x->left),height(x->right))+1;
  return y;
}

Node* insert(Node* node, int value){
  if(node==NULL){
    return newNode(value);
  }
  if(node->value<value){
    node->right = insert(node->right, value);
  }
  else if(node->value>value){
    node->left = insert(node->left, value);
  }
  else{
    return node;
  }
  //change heights of all visited nodes respectively
  node->height = 1 + max(height(node->left),height(node->right));
  int balanceFactor = getBalanceFactor(node);

  if(balanceFactor>1){
    if(value<node->left->value){
      return rightRotate(node);
    }
    else if(value>node->left->value){
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  return node;
}

Node* getNextMini(Node *node){
  Node *current = node;
  while(current->left != NULL){
    current = current->left;
  }
  return current;
}

Node* remove(Node* root, int value){
  if(root == NULL){
    return root;
  }
  if(value<root->value){
    root->left = remove(root->left, value);
  }
  else if(value>root->value){
    root->right = remove(root->right, value);
  }
  else{
    if(root->left==NULL || root->right == NULL){

      Node *temp = root->left ? root->left : root->right;
      if(temp == NULL){
        temp = root;
        root = NULL;
      }
      else{
        *root = *temp;
      }
      free(temp);
    }
    else{
      Node *temp = getNextMini(root->right);
      root->value = temp->value;
      root->right = remove(root->right, temp->value);
    }
  }

  if(root == NULL){
    return root;
  }
  root->height = 1 + max(height(root->left),height(root->right));
  int balance = getBalanceFactor(root);
  if(balance>1){
    if(getBalanceFactor(root->left)>=0){
      root = rightRotate(root);
    }
    else{
      root->left = leftRotate(root->left);
      root = rightRotate(root);
    }
  }
  if(balance<-1){
    if(getBalanceFactor(root->right)>=0){
      root = leftRotate(root);
    }
    else{
      root->right = rightRotate(root->right);
      root = leftRotate(root);
    }
  }
  return root;
}

// void print(Node *root){
//   if(root == NULL){
//     return;
//   }
//   print(root->left);
//   printf("%d ",root->value);
//   print(root->right);
// }

void printTree(Node *root, string indent, bool last) {
  if (root != nullptr) {
    cout << indent;
    if (last) {
      cout << "R----";
      indent += "   ";
    } else {
      cout << "L----";
      indent += "|  ";
    }
    cout << root->value << endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
}


int main(){
  Node *root = NULL;
  root = insert(root,33);
  root = insert(root,13);
  root = insert(root,53);
  root = insert(root,9);
  root = insert(root,21);
  root = insert(root,61);
  root = insert(root,8);
  root = insert(root,11);
  // print(root);
  printTree(root, "", true);
  root = remove(root,13);
  printTree(root, "", true);
  return 0;
}
