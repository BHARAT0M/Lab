/*
Roll no :- 194CA014
recursive Square
In this task Fibonacci number
*/
#include<bits/stdc++.h>
using namespace std;
double binet(unsigned int n)
{
    static const double phi = (1 + sqrt(5))*0.5;
    double fib = (pow(phi,n))/sqrt(5);
    return round(fib);
}
int main(){
unsigned int n;
cout<<"Enter the n for number of term "<<endl;
cin>>n;
cout<<n<<"'th term in Fibonacci series = "<<binet(n)<<endl;
}
