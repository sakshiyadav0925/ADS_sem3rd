#include<iostream>
#include<stack>
using namespace std ;
 
int pop() {
    int top =-1 ;
    
    stack<char>stack ;
    if(top == -1){
    cout<<"Underflow"<<endl;
    }
    else{
        int x = stack (top);
        top =top -1 ;
        return x ;
    }
}
    void display(){
        
        for(int i= top ;i>=0;i++)
        cout<<stack[i];


    }
  
    #define MAXSIZE 50
    int stack[MAXSIZE];
    int top =-1 ;
    void push() 
    {
        if(top>MAXSIZE -1)
        cout<<"Overflow"<<endl ;
        else{
            int x ;
            cin>>x;
            top = top+1 ;
            stack[top] = x ;
        }
    }

       int main() 
       {
        do
        {
            cin>>choice ;
           switch(choice) ;
           {
            case1 : push() ;
            break ;
            case2 : cout<<pop() ;
            break ;
            case3 : display() ;
            break ;
            default: cout<<"You have entered wrong choice" ;
            exit() ;

           }
        }
        while(choice< =3) ;
        
        

       }

