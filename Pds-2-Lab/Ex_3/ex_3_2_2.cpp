#include<iostream>
using namespace std;
class Two;
class One
{
public:
    void multiply(Two);
};
class Two
{
public:
    int a,b;
    void display();
    friend void multiply(Two);
};
void Two :: display()
{
    cout << "Variable 1: " <<a<< "\nVariable 2: " <<b<<endl;
}
void One :: multiply(Two t)
{
    cout << "Answer is "<< (t.a * t.b);
}
int main()
{   One x;
    Two y;
    cout << "Enter number 1 : ";
    cin >> y.a;
    cout << "Enter number 2 : ";
    cin >> y.b;
    y.display();
    x.multiply(y);
}

