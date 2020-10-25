#include<iostream>
using namespace std;

typedef struct Node{
  int value;
  Node *parent,*left,*right;
  int colour;
}Node;

class RBTree{
private:
  Node* root;
  Node* null;
  int black_height;
  Node* CreatNode(int val,Node *parent){
    Node *node = new Node;
    node->value = val;
    node->parent = parent;
    node->left = node->right = null;
    node->colour = 1;
    if(parent == null){
      root = node;
      node->parent = NULL;
    }
    else if(node->value<=parent->value){
      parent->left = node;
    }
    else if(node->value>parent->value){
      parent->right = node;
    }
    return node;
  }

  void printHelper(Node* node, string indent, bool last) {
    if (node != null) {
      cout << indent;
      if (last) {
        cout << "R----";
        indent += "   ";
      } else {
        cout << "L----";
        indent += "|  ";
      }

      string sColor = node->colour ? "RED" : "BLACK";
      cout << node->value << "(" << sColor << ")" << endl;
      printHelper(node->left, indent, false);
      printHelper(node->right, indent, true);
    }
  }

  void RotateRight(Node* node){
    Node *x,*y;
    x = node;
    y = node->left;
    x->left = y->right;
    if(y->right != null){
      y->right->parent = x;
    }
    y->parent = x->parent;
    if(x == root){
      root = y;
    }
    else if(x == x->parent->left){
      x->parent->left = y;
    }
    else{
      x->parent->right = y;
    }
    y->right = x;
    x->parent = y;

  }

  void RotateLeft(Node *node){
    Node *x,*y;
    x = node;
    y = node->right;
    x->right = y->left;
    if(y->left != null){
      y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent==NULL){
      root = y;
    }
    else if(x->parent->left==x){
      x->parent->left = y;
    }
    else{
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  Node* Minimum(Node* node){
    Node* current = node;
    while(current->left != null){
      current = current->left;
    }
    return current;
  }

  Node* FindUncle(Node* node){
    Node* parent = node->parent;
    if(parent==parent->parent->left){
      return parent->parent->right;
    }
    else{
      return parent->parent->left;
    }
  }

  void Transplant(Node *u, Node *v){
    if(u->parent==NULL){
      root = v;
    }
    else if(u == u->parent->left){
      u->parent->left = v;
    }
    else{
      u->parent->right = v;
    }
    v->parent = u->parent;
  }

  void DeFix(Node *x){
    // case-1 RB case which can be changed to B becouse removing Red does not make any problems
    if(x->colour==1){
      x->colour = 0;
      return;
    }
    if(x==root){
      black_height--;
      return;
    }
    // if does not exit from above if then x has double black(BB)
    Node *sibling,*parent;
    parent = x->parent;
    sibling = parent->left==x ? parent->right : parent ->left;
    // case-2 which may not give termination but makes new sibling that is black and can be solved using case-3,4.
    if(sibling->colour == 1){
      if(sibling == parent->right){
        RotateLeft(parent);
        //initially their colours are oppsite
        parent->colour = 1;
        sibling->colour = 0;
        DeFix(x);
      }
      else{
        RotateRight(parent);
        //initially their colours are oppsite
        parent->colour = 1;
        sibling->colour = 0;
        DeFix(x);
      }
    }
    else{
      // case-3 when both the children of sibling are black now shift one black
      if(sibling->left->colour == 0 && sibling->right->colour == 0){
        sibling->colour = 1;
        DeFix(parent);
      }
      if(sibling == parent->right){
        // case-4 when x is left child of parent and right child of sibling is red (sibiling.Left can be any colour)
        if(sibling->right->colour==1){
          sibling->right->colour=0;
          RotateLeft(parent);
          sibling->colour = parent->colour;
          parent->colour = 0;  //previous colour of sibiling
          return;
        }
        // case-5 which is later converted to as case-4.
        else if(sibling->left->colour == 1){
          sibling->colour = 1;
          sibling->left->colour = 0; // swapping colours of sibling and sibling.left
          RotateRight(sibling);
          DeFix(x);
        }
      }
      else{
        // case-4 when x is left child of parent and right child of sibling is red (sibiling.Left can be any colour)
        if(sibling->left->colour==1){
          sibling->left->colour=0;
          RotateRight(parent);
          sibling->colour = parent->colour;
          parent->colour = 0;  //previous colour of sibiling
          return;
        }
        // case-5 which is later converted to as case-4.
        else if(sibling->right->colour == 1){
          sibling->colour = 1;
          sibling->right->colour = 0; // swapping colours of sibling and sibling.left
          RotateLeft(sibling);
          DeFix(x);
        }
      }
    }
  }

  void InsertFix(Node* node){
    if (node==root){
      node->colour = 0;
      black_height++;
      return;
    }
    if(node->parent->colour == 0){
      return;
    }
    Node *parent = node->parent;
    Node *Grandpa = node->parent->parent;
    Node *u = FindUncle(node);
    //case-1: uncle is red colour
    if(u->colour == 1){
      Grandpa->colour = 1;
      u->colour = 0;
      parent->colour = 0;
      InsertFix(Grandpa);
    }
    //uncle colour is black
    else{
      if(parent == Grandpa->left){
        //case-2: left-left
        if(node == parent->left){
          RotateRight(Grandpa);
          Grandpa->colour = 1;
          parent->colour = 0;
        }
        //case-3: left-right
        else{
          RotateLeft(parent);
          RotateRight(Grandpa);
          Grandpa->colour = 1;
          node->colour = 0;
        }
      }
      else{
        //case-4: right-right
        if(node==parent->right){
          RotateLeft(Grandpa);
          Grandpa->colour = 1;
          parent->colour = 0;
        }
        //case-5: right-left
        else{
          RotateRight(parent);
          RotateLeft(Grandpa);
          Grandpa->colour = 1;
          node->colour = 0;
        }
      }
    }

  }
public:
  RBTree(){
    null = new Node;
    black_height = 0;
    null->value = 0;
    null->left = null->right = NULL;
    null->parent = NULL;
    null->colour = 0;
    root = null;
  }

  void insert(int val){
    Node *node,*parent,*current;
    current = root;
    parent = current;
    while(current !=null){
      parent = current;
      if(val<=current->value){
        current = current->left;
      }
      else{
        current = current->right;
      }
    }
    node = CreatNode(val,parent);

    InsertFix(node);
  }

  void Delete(int key){
    Node *x,*y,*z,*current;
    z = null;
    current = root;
    int origColY;
    while(current!=null){
      if(current->value<key){
        current=current->right;
      }
      else if(current->value>key){
        current = current->left;
      }
      else{
        z = current;
        break;
      }
    }
    if(z==null){
      cout<<"There is no such element in Tree Or Tree is empty"<<endl;
      return;
    }
    y=z;
    origColY = y->colour;
    if(z->left==null){
      x = z->right;
      Transplant(z,x);
      delete y;
    }
    else if(z->right == null){
      x = z->left;
      Transplant(z,x);
      delete y;
    }
    else{
      //assigning value of minimum to z and deleting that minimum from right tree;
      y = Minimum(z->right);
      origColY = y->colour;
      x = y->right;
      z->value = y->value;
      Transplant(y,x);
      delete y;
    }

    if(origColY==0){
      DeFix(x);
    }
  }

  int BHeight(){
    return black_height;
  }

  void printTree(){
     printHelper(root,"",true);
   }
};


int main(){
  RBTree bst;
  bst.insert(90);
  bst.insert(80);
  bst.insert(70);
  bst.insert(60);
  bst.insert(50);
  bst.insert(45);
  bst.insert(40);
  bst.Delete(60);
  // bst.Delete(45);
  // bst.Delete(90);
  // bst.Delete(50);
  // bst.Delete(80);
  // bst.Delete(70);
  // bst.Delete(40);
  // bst.Delete(40);
  bst.printTree();
  cout<<endl<<"Black height of this Red Black Tree is "<<bst.BHeight()<<endl;
  return 0;
}
