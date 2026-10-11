#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}
int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Factorial and Fibonacci are not defined for negative numbers.";
    }
    else
    {
        cout << "Factorial of " << n << " = " << factorial(n) << endl;
        cout << n << "th Fibonacci number = " << fibonacci(n);
    }
    return 0;
}