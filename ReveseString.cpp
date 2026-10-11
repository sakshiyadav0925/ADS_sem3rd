#include<iostream>
using namespace std ;

void push()
{    string str ;

    int i = 0;
    while(str[i] ='/0')
    {
        push(str[i]) ;
        i++ ;
    }
}
void pop()
{  


    while(top != -1)
    {
        x = Stack[top] ;
        cout<< x ;
        top = top -1 ;

    }
}
int main()
{ 


}

