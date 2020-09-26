#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int l, int r, int k);
// only for an array of size 5 in this program.
int findMedian(int arr[], int n)
{
    sort(arr, arr+n);
   return arr[n/2];
}
int kthSmallest(int arr[], int l, int r, int k)
{
    // If k is smaller than number of elements in array
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
       // Find median of all medians using recursive call.
        // If median[] has only one element, then no need
        // of recursive call
        int medOfMed = (i == 1)? median[i-1]:kthSmallest(median, 0, i-1, i/2);

        // Partition the array around a random element and
        // get position of pivot element in sorted array
        int pos = partition(arr, l, r, medOfMed);
        // If position is same as k
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1) // If position is more, recur for left
            return kthSmallest(arr, l, pos-1, k);
        // Else recur for right subarray
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
    // If k is more than number of elements in array
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
int main(){
srand(time(NULL));
ofstream out("output.txt");


for(int n = 1000; n <=10000; n+=500)
{

int A[n];
for(int i = 0; i < n; i++) //intialize array of random size to random elements
     A[i] = rand();

time_t start_time = time(NULL);
time_t current_time = time(NULL);
double count = 0;

while(current_time - start_time < 1)
{
    int k=10;
    cout<<kthSmallest(A, 0, n-1,k)<<" ";
    current_time = time(NULL);
    count ++;
}
out << "Array Size: " << n << " T(n): " << 1/count<< "  T(n)/n: " << (1/count)/n << endl;
 }
}
