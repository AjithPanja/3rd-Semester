#include <iostream>
using namespace std;
#define SIZE 10
int A[SIZE];
int top = -1;

bool isempty()
{
  if(top==-1)
  return true;
  else
  return false;
}

void push(int value)
{
  if(top==SIZE-1)
  {    cout<<"Stack is full!\n";
  }
   else
  {
    A[++top]=value;
  }
}

void pop()
{
 if(isempty())
  cout<<"Stack is empty!\n";
 else
  cout << A[top--] << " is popped" << endl;
}

void displayStack()
{
  if(isempty())
 {
    cout<<"Stack is empty!\n";
 }
 else
 {
  for(int i=0 ; i<=top; i++)
    cout<<A[i]<<" ";
   cout<<"\n";

  }

}

int main()
{

 int choice, flag=1, value;
 while( flag == 1)
 {
 cout<<"\n1.PUSH 2.POP 3.DISPLAY_STACK 4.EXIT\n";
 cin>>choice;
 switch (choice)
 {
 case 1: cout<<"Enter Value:\n";
         cin>>value;
         push(value);
         break;
 case 2: pop();
         break;
 case 3: displayStack();
         break;
 case 4: flag = 0;
         break;
 default: cout<< "Enter correct choice ." << endl;
 }
 }
  return 0;
}
