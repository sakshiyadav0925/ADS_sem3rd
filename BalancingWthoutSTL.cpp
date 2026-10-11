#include<iostream>
using namespace std ;
bool isbalanced(string &str)
{
    int i =0 ;
    while(str[i]!='\0')
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        push(str[i]);
    else{
        if(top == -1)

         return false ; 
       if(ismatched(pop(),str[i]) == false)
       {
        return false ;
       }
       i++ ;
    }
      return(isEmpty()==true) ;
}
}
bool ismatched(char a ,char b)
{
    return (a=='(' && b==')'||
            a=='{' && b=='}'||
            a=='[' && b==']' ) ;

        
}
void push(char a)
{
    top=top+1;
    stack[top] = a;

}
int pop() {
    int x =stack[top] ;
    top=top-1;
    return x ;
}
int main() {
    char stack[100] ;
    int top = -1;

    string str ;
    cin>>str ;
    if(isbalanced(str)==true)
    cout<<"Balanced"<<endl ;
    else
    cout<<"Inbalanced"<<endl;
    return 0 ;

}