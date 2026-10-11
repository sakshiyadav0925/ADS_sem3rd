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
            {int C[k]=B[j] ;
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

int main()
{
   int m,n;
   cin>>m>>n ;

   int A[m ] ;
   for (int i = 0; i < m; i++)
        cin >> A[i];
   
   int B[n] ;
   for(int i =0;i<n;i++)
   cin>>B[i] ;

   int C[m+n] ;
     MergeSort(A,B,m,n,C) ;

cout<<"Merged Array:" ;

   for(int i=0 ;i<m+n ;i ++) 
   {
   cout<<C[i]<<" " ;
   }
   return 0 ;


}