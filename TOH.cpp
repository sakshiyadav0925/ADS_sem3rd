#include<iostream>
using namespace std ;

void TOH(int n,char A,char B,char C)
{
    if(n==1)
    cout<<"move disk"<<n<<"from"<< A<<"to"<< C<<endl ;
   return ;

    TOH(n-1,'A','B','C') ;
     cout<<"move disk"<<n<<"from"<< A<<"to"<< C<<endl ; 
     TOH(n-1,'A','B','C') ;

    
}

int main()
{
  int n;
  cin>>n;
 char A,B,C ;
 cin>>A>>B>>C ;
 


  TOH(n,'A','B','C') ;
  return 0;

}