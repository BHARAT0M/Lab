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
ofstream out("OUT.txt");
for(int n=1000; n<1000000; n+=100)
{
int A[n];
for(int i = 0; i < n; i++)
    A[i] = rand();
time_t start_time = time(NULL);
time_t current_time = time(NULL);
double count = 0;
//int x=10;
//cout <<x<<"'th smallest element is "<<Randomized_Select(A, 0, n-1, x)<<endl;
while(current_time - start_time < 1)
{
    Randomized_Select(A, 0, n-1, rand()%n + 1);
    current_time = time(NULL);
    count ++;
}
out << "Array Size: " << n << " T(n): " << 1/count<<"\t T(n)/n: " << (1/count)/n << endl;
 }
}
