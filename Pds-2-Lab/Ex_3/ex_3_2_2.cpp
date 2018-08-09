#include<iostream>
using namespace std;
class Two;
class One
{
public:
    int a;
    void multiply(Two);
};
class Two
{
public:
    int b;
    friend void multiply(Two);
};
void One :: multiply(Two t) //Type 2: multiply is the method of class One and it's declared as a friend function in class Two
{
    cout << "Answer is "<< (a * t.b);
}
int main()
{   One x;
    Two y;
    cout << "Enter number 1 : ";
    cin >> x.a;
    cout << "Enter number 2 : ";
    cin >> y.b;
    x.multiply(y);
}

