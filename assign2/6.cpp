#include<bits/stdc++.h>
using namespace std;
int reverse(int num);
int isPalindrome(int num);
int main()
{
    int num;
    cout<<"Enter any number: "<<endl;
    cin>>num;
    if(isPalindrome(num) == 1)
    {
        cout<<"Number is palindrome number\n";
    }
    else
    {
        cout<<"Number is NOT palindrome number\n";
    }
    return 0;
}
int isPalindrome(int num)
{
    if(num == reverse(num))
    {
        return 1;
    }
    return 0;
}
int reverse(int num){
    int digit = (int)log10(num);
    if(num == 0)
        return 0;

    return ((num%10 * pow(10, digit)) + reverse(num/10));
}
