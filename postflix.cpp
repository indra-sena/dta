#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
/*  The class stack defines an ADT stack.
    See Ref. Aho, Hopcroft and Ullmann : Data Structures and Algorithms,
    Addison Wesley, 1978. */

/* begin {Definition of class stack} */


#define STACK_SIZE 1000
#define EXPR_LENGTH 1000
typedef  int ElemType;

using namespace std;
class stack {
  ElemType stackArray[STACK_SIZE];        // A stack of characters
  int tos;              // A pointer to the top of stack.

public:
  ElemType Top();               // returns the element on Top of the stack
  void Push(ElemType x);      // Pushes an element on to the stack
  ElemType Pop();             // Pops an element from the stack
  int Empty();            // returns 1 if stack is Empty
  void MakeNull();        // creates an Empty stack
 };
/* end{Definition of class stack} */


/* begin{Implementation of the class stack} */

ElemType stack::Top() {

  if (tos < STACK_SIZE)
    return (stackArray[tos]);
  else
    return(0);
  }

int stack::Empty() {

  if (tos >= STACK_SIZE)
	 return 1;
  else
	 return 0;
}

void stack::Push(ElemType x) {

  tos--;
  stackArray[tos] = x;
}

ElemType stack::Pop() {

  ElemType tmp;

  if (tos >= STACK_SIZE)
    return (-1);
  else {
    tmp = stackArray[tos];
    tos++;
    return (tmp);
  }
}

void stack::MakeNull() {

  tos = STACK_SIZE;

}
/* end {Implementation of stack} */

int EvaluatePostFix(char **postFixExpr, int exprLength) {
   int result;

   stack st;
   st.MakeNull();
   st.Push(atoi(postFixExpr[0]));
   for(int i=1; i<exprLength;i++){
     int temp = atoi(postFixExpr[i]);
     if(temp!=0){
       st.Push(temp);
     }
     else{
       if(postFixExpr[i][0] == '+'){
         int temp1=st.Pop();
         int temp2 = st.Pop();
         st.Push(temp1 + temp2);
       }
       else if(postFixExpr[i][0] == '-'){
         int temp1=st.Pop();
         int temp2 = st.Pop();
         st.Push(temp2 - temp1);
       }
       else if(postFixExpr[i][0] == '*'){
         int temp1=st.Pop();
         int temp2 = st.Pop();
         st.Push(temp1 * temp2);
       }
       else if(postFixExpr[i][0] == '/'){
         int temp1=st.Pop();
         int temp2 = st.Pop();
         st.Push(temp2 / temp1);
       }
     }
   }
   result = st.Top();
   return result;
}


int main() {
  char **postFixExpr;
  int  n;
  int  i;
  /* Read the input postfix expression */
  cin>>n;
  postFixExpr = new char*[n];
  for(i=0;i<n;i++){
    postFixExpr[i] = new char();
    cin>>postFixExpr[i];
  }
  int value = (int) EvaluatePostFix(postFixExpr, n);
  cout << "The Result is :" << value << std::endl;
  return 0;
}
