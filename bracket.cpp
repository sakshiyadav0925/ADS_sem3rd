       
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool matching(char a, char b)
{
    if(a=='(' && b==')')
        return true;

    if(a=='{' && b=='}')
        return true;

    if(a=='[' && b==']')
        return true;

    return false;
}

int main()
{
    stack<char> s;
    string str;

    cout << "Enter the expression: ";
    cin >> str;

    for(auto x : str)
    {
        if(x=='(' || x=='{' || x=='[')
        {
            s.push(x);
        }
        else if(x==')' || x=='}' || x==']')
        {
            if(s.empty())
            {
                cout << "Not Balanced";
                return 0;
            }

            if(!matching(s.top(), x))
            {
                cout << "Not Balanced";
                return 0;
            }

            s.pop();
        }
    }

    if(s.empty())
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}