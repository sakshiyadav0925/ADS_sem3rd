#include<iostream>
using namespace std ;
#define MAXSIZE 50 

   int arr[MAX_PATH];
   int priority[MAXSIZE] ;
   int size =0 ;

void insert() {
 
    if(size == MAXSIZE){
    cout<<"Queue is Full";}
    return ;
    int p, value ;
    cout<<"Enter a Value:";
    cin>>value ;
    
    arr[size] = value;
    priority[size] = p;
    size++ ;

    cout<<"Element inserted succesfully"<<endl ;
 }

void delete