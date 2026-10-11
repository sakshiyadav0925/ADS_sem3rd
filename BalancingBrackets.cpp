#include<iostream>
#include<stack>
using namespace std ;
bool isBalanced(string &str)
{
    stack<char>s;
    for(char x: str)
    {
        if(x=='(' || x=='{' || x=='[' )
        s.push(x) ;
        else
        {
            if(s.empty()==true)
            return false ;
         if(isMatched(s.top(),x) == false)
         {
            return false ;
         }   
         else
         s.pop() ;

        }
        return(s.empty() == true) ;
     }
}
 bool isMatched(char a,char b)
 {
    return ( a=='('&& b==')'||
             a=='[' && b==']' ||
            a=='{' && b=='}') ;

    
 }
 int main() 
 {
    string str ;
    cin>>str ;
    if(isBalanced(str)==true)
    cout<<"Balanced"<<endl;
    else
    cout<<"Not Balanced" ;
    return 0 ;

 }