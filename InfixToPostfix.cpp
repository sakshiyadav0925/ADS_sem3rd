#include<iostream>
using namespace std ;


void push(char x)
{


top =top+1 ;
stack[top]=x ;
}
char pop()
{
    return stack[top--];

}
int priorty(char a)
{
    if(a=='(')
    return 0 ;


if(a=='+' || a=='-')
return 1 ;
if(a=='*' || a=='/')
return 2 ;
if(a=='^')
return 3 ;

return 0;
}
else if(exp[i] ==')')
{
    while( (x =pop())!='(')
    {
    cout<<x;
    }
else(priorty(stack[top])>= priorty(exp[i]))
x=pop() ;
cout<<x ;

}
push(exp[i])
i++ ;

while(top!=-1)
{
    x =pop() ;
    cout<< x ;
}
main() {
    string exp ;
    cin>> exp ;
    int i=o ;
    while(exp[i] !='\0')
    {
        if(isalpnum(exp[i]))
        cout<<exp[i] 
        else if(exp[i] =='(');
         push(exp[i] =='^')
         push(exp[i]) ;



    }
    return 0 ;
}