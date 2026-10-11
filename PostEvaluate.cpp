#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#define MAXSIZE 50

int St[MAXSIZE];
int top = -1;

void push(int a)
{
    if (top == MAXSIZE - 1)
    {
        cout << "Stack Overflow\n";
        return;
    }
    St[++top] = a;
}

int pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow\n";
        return -1;
    }
    return St[top--];
}

int main()
{
    string exp;
    cout << "Enter postfix expression: ";
    getline(cin, exp);

    int i = 0;

    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            int num = 0;

            while (exp[i] != ',' && exp[i] != '\0')
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
        }
        else if (exp[i] == '+' || exp[i] == '-' ||
                 exp[i] == '*' || exp[i] == '/')
        {
            int n1 = pop();   
            int n2 = pop();  
            int res;

            switch (exp[i])
            {
                case '+':
                    res = n2 + n1;
                    break;

                case '-':
                    res = n2 - n1;
                    break;

                case '*':
                    res = n2 * n1;
                    break;

                case '/':
                    res = n2 / n1;
                    break;
            }

            push(res);
        }

        if (exp[i] == ',')
            i++;
        else if (exp[i] != '\0')
            i++;
    }

    cout << "Result = " << pop() << endl;

    return 0;
}