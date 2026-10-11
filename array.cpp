#include<bits/stdc++.h>
using namespace std;
struct MyStack 
{
    int *arr ;
     int sz ;
     int Top ;
     
     MyStack( int c ) 
     {  sz = c ;
        Top = -1 ;
     arr = new int [sz] ;
     }
     
     void push(int x) 
     {
         Top = Top +1 ;
         arr[Top] = x ;
         
     }
     int pop() 
     
     {
     int x = arr[Top] ;
     Top = Top-1 ;
     return x ;
     
     }
     int size()
     {
         return (Top +1) ;
     }
     int peek()
     {
         return arr[Top] ;
     }
     bool isEmpty()
     {
         return (Top== -1) ;
         
     }
} ;


int main() {
   MyStack s(5) ;
   
   s.push(10) ;
   s.push(20) ;
   s.push(30) ;
   
   cout<<s.pop()<<endl ;
   cout<<s.size()<<endl ;
   cout<<s.peek()<<endl ;
   cout<<( s.isEmpty() ? "Yes":"No")<<endl ;
   
   return 0 ;

}
