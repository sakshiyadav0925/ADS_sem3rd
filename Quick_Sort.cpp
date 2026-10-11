#include<iostream>
using namespace std ;

int partition(int A[], int l, int r)
{
    int pivot = A[l];
    int i = l + 1;
    int j = r;

    while (i <= j)
    {
        while (i <= r && A[i] <= pivot)
        {
            i++;
        }

        while (j >= l + 1 && A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(A[i], A[j]);
        }
    }
    swap(A[l], A[j]);

    return j;
}
void quickSort(int A[], int l, int r)
{
    if (l < r)
    {
        int p = partition(A, l, r);

        quickSort(A, l, p - 1);
        quickSort(A, p + 1, r);

    }
}
int main()
{
    int n;
    cin>>n;
    int A[n] ;
    cout<<"Enter the element:";
    for(int i=0;i<=n;i++)
    {
        cin>>A[i] ;

    }
     quickSort(A, 0, n - 1);
     cout<<"Sorted Array(Quick Sort) :";
     for(int i =0;i<n;i++)
     {
     cout<<A[i]<<" " ;
}
  return 0;

}