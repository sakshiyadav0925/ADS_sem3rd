#include<iostream>     
using namespace std ;

void MergeSort(int A[], int B[],int m,int n,int C[])
{  int i=0,j=0, k=0 ;

        while(i<m && j<n)
        {
            if(A[i] < B[j])
            { int C[k]= A[i] ;
                 i++;
                 k++ ;

            }
            else
            {int C[k]= B[j] ;
                     j++;
                     k++ ;          
            
            }
        }
        while(i<m)
        {
            C[k] =A[i] ;
            i++;
            k++ ;
        }
      while(j<n)
      {
        C[k] = B[j] ;
        j++ ;
        k++ ;

      }
    
    }








































    //union,intersection,set diffrence , reverse of an array,palindrome