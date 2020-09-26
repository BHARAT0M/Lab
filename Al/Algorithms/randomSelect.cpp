/*
Roll no :- 194CA014
random seect
In this task Using random Select algorithm to find kthSmallest element
*/
#include<bits/stdc++.h>
using namespace std;
int partition(int a[], int p, int r){
    int x = a[r];
    int i = p-1;
    for(int j = p; j < r; j++){
        if(a[j] <= x){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}
int Randomized_Partition(int a[], int p, int r){
    int i = rand() % r + 1;
    swap(a[i], a[r]);
    return partition(a, p, r);
}
int Randomized_Select(int a[], int p, int r, int i)
{
    if(p==r)
        return a[p];
    int q = Randomized_Partition(a,p,r);
    int k = q-p+1;
    if(i == k)
        return a[q];
    else if(i < k)
        return Randomized_Select(a, p, q-1, i);
    else return Randomized_Select(a, q+1, r, i-k);
}
int main(){
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
    cout<<k<<"'th smallest element is  "<< Randomized_Select(A, 0, n-1, k)<<endl;
cout<<"\nProgram End"<<endl;
}
