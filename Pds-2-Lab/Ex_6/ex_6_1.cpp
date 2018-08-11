#include<iostream>
using namespace std;
class Parent
{
public:
    virtual void display()
    {
       cout << "Hi! This is Parent's Class.";
    }
};
class Child : public Parent
{
public:
    void display()
    {
        cout << "Hi! This is Child's Class.";
    }
};
int main()
{
    Parent *p;
    Child c;
    p = &c;
    p->display(); //without the virtual keyword in the Parent class's display method, the ocompiler will get the Parent's display..this is called Early Binding
    return 0;
}
