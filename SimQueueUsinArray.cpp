#include <iostream>
#include <cstring>
using namespace std;

#define MAX 50


int s[MAX];
int top = -1;


char op[MAX];
int topOp = -1;


void PUSH(int x)
{
    if (top == MAX - 1)
    {
        cout << "Overflow" << endl;
    }
    else
    {
        top++;
        s[top] = x;
    }
}

int POP()
{
    if (top == -1)
    {
        cout << "Underflow" << endl;
        return -1;
    }

    int x = s[top];
    top--;
    return x;
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is Empty" << endl;
        return;
    }

    cout << "Stack elements: ";

    for (int i = top; i >= 0; i--)
    {
        cout << s[i] << " ";
    }

    cout << endl;
}

void pushOperator(char ch)
{
    if (topOp == MAX - 1)
    {
        cout << "Operator Stack Overflow" << endl;
    }
    else
    {
        topOp++;
        op[topOp] = ch;
    }
}

char popOperator()
{
    if (topOp == -1)
    {
        return '\0';
    }

    char ch = op[topOp];
    topOp--;

    return ch;
}

char peekOperator()
{
    if (topOp == -1)
    {
        return '\0';
    }

    return op[topOp];
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i = 0;
    int j = 0;

    topOp = -1;

    while (infix[i] != '\0')
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if (ch == '(')
        {
            pushOperator(ch);
        }
        else if (ch == ')')
        {
            while (topOp != -1 && peekOperator() != '(')
            {
                postfix[j] = popOperator();
                j++;
            }

            if (topOp != -1)
            {
                popOperator();
            }
        }
        else
        {
            while (topOp != -1 &&
                   peekOperator() != '(' &&
                   precedence(peekOperator()) >= precedence(ch))
            {
                postfix[j] = popOperator();
                j++;
            }

            pushOperator(ch);
        }

        i++;
    }
    while (topOp != -1)
    {
        postfix[j] = popOperator();
        j++;
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[])
{
    top = -1;

    int i = 0;

    while (postfix[i] != '\0')
    {
        char ch = postfix[i];
        if (isdigit(ch))
        {
            PUSH(ch - '0');
        }
        else
        {
            int b = POP();
            int a = POP();

            int result = 0;

            if (ch == '+')
            {
                result = a + b;
            }
            else if (ch == '-')
            {
                result = a - b;
            }
            else if (ch == '*')
            {
                result = a * b;
            }
            else if (ch == '/')
            {
                result = a / b;
            }
            else if (ch == '^')
            {
                result = 1;

                for (int k = 0; k < b; k++)
                {
                    result = result * a;
                }
            }

            PUSH(result);
        }

        i++;
    }

    return POP();
}

int main()
{
    int n;

    cout << "Enter size of stack: ";
    cin >> n;

    if (n > MAX)
    {
        cout << "Stack size cannot be greater than " << MAX << endl;
        return 0;
    }

    cout << "Enter " << n << " elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        PUSH(x);
    }

    cout << "\nStack after PUSH:" << endl;
    display();

    cout << "\nPopped element: " << POP() << endl;

    cout << "Stack after POP:" << endl;
    display();

    
    char infix[MAX];
    char postfix[MAX];

    cout << "\nEnter infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

  
    int result = evaluatePostfix(postfix);

    cout << "Postfix evaluation result: " << result << endl;

    return 0;
}