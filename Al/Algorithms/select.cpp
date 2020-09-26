/*
Roll no :- 194CA014
implementation of worst case linear time Select algorithm
In this task Using Select algorithm to  find kthSmallest element
*/
#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int l, int r, int k);
int findMedian(int arr[], int n)
{
    sort(arr, arr+n);
   return arr[n/2];
}
int Select(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1;
        int i, median[(n+4)/5];;
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n)
        {
            median[i] = findMedian(arr+l+i*5, n%5);
            i++;
        }
        int medOfMed = (i == 1)? median[i-1]:Select(median, 0, i-1, i/2);
        int pos = partition(arr, l, r, medOfMed);
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return Select(arr, l, pos-1, k);
        return Select(arr, pos+1, r, k-pos+l-1);
    }
    return INT_MAX;
}
int partition(int arr[], int l, int r, int x)
{
    int i;
    for (i=l; i<r; i++)
        if(arr[i] == x)
            break;
    swap(arr[i], arr[r]);
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}
int main()
{
    srand(time(NULL));
    int n=100;
    int A[n];
    for(int i = 0; i < n; i++)
          A[i] = rand()%n+1;
    int k=10;
    cout<<"Array Values are"<<endl;
    for(int i = 0; i < n; i++)
      cout<<A[i]<<" ";
      cout<<"\n\n";
        cout<<k<<"'th smallest element is  "<<Select(A, 0, n-1, k)<<endl;
     cout<<"\nProgram End"<<endl;
    return 0;
}
