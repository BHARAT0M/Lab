#include<bits/stdc++.h>
using namespace std;
int fib(int n){
if(n==0||n==1){
 return n;
}
else{
    return fib(n-1)+fib(n-2);
}
}
int main(){
    int num;
    cout<<"enter a number for term "<<endl;
    cin>>num;
    cout<<"Fibonacci number = "<<fib(num);
return 0;
}
