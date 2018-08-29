/*Infix to Prefix can be easily done by
1)Reversing the Expression
2)Interchanging '(' with ')' and vice versa
3)Change it to Postfix
4)Reverse the Postfix expression
5)Hence the Prefix
*/
#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
int check(char ch);
bool precedence(char ch1,char ch2);
int pre(char ch);
int main()
{
    string exp,result;
    stack <char> S;
    getline(cin,exp);
    int l = exp.length();
    int choice;
    reverse(exp.begin(),exp.end());
    for(int i =0;i<l;i++)
    {
    if(exp[i]==')')
    {
    exp[i] = '(';
    }
    else if(exp[i]=='(')
    {
    exp[i] = ')';
    }
    }
    char *e = &exp[0];
    while(l!=0)
    {
        choice = check(*e);
        switch(choice)
        {
        case 1:
        {
            result = result + *e;
            break;
        }
        case 2:
        {
            if(S.empty())
            {
                S.push(*e);
            }
            else
            {
                while(!S.empty()&& S.top()!= '(' && precedence(S.top(),*e))
                {
                    result = result + S.top();
                    S.pop();
                }
                S.push(*e);
            }
            break;
        }
        case 3:
        {
            while(!S.empty())
            {
                if(S.top()=='(')
                {
                    S.pop();
                    break;
                }
                result = result + S.top();
                S.pop();
            }
            break;
        }
        }
        e++;
        l--;
    }
    while(!S.empty())
    {
        result = result + S.top();
        S.pop();
    }
    reverse(result.begin(),result.end());
    cout << result;
}
int check(char ch)
{
    if((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
    {
        return 1;
    }
    else if(ch==')')
    {
        return 3;
    }
    else
    {
        return 2;
    }
}
bool precedence(char ch1,char ch2)
{
    int pre1 = pre(ch1);
    int pre2 = pre(ch2);
    if(pre1>=pre2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int pre(char ch)
{
    switch(ch)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    }
}
