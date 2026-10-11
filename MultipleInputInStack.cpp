#include<iostream>
#include<stack>
using namespace std ;

#define MAXSIZE 50 
int St[MAXSIZE] ;
void push()
 {
    int top ;
    if(top > MAXSIZE -1)
    cout<<"Overflow"<<endl ;
    else{
        int x ;
        cin>> x ;
        top = top+ 1 ;
        St[top] = x ;
    }
}

int pop() 
{
    int top ;
    if( top == -1)
    cout<<"Underflow"<<endl ;
    else{
        int x = St[top] ;
        top = top -1 ;
        return x ;
    }

}
 void display()
 { int top ;
    for(int i =top; i>0; i--)
    cout<<St[i] ;
 }
 int main() 
 {
        int choice ;
    do { 
        
        cin>>choice ;
        switch(choice)
        {
         case1: push() ;
        break ;
        case2: cout<<pop() ;
        break ;
        case3: display() ;
        break ;
        default :cout<<"You have entered wrong choice "<<endl;
        }
    } 
    while(choice <=3) ;
    return 0 ;
 }