#include<bits/stdc++.h>
using namespace std;
int len(string str,int j){
if(str[j]=='\0')
    return j;
 j++;
    return len(str,j);
}
int main(){
    string s;
    int i=0;
    cout<<"enter a string"<<endl;
    getline(cin,s);
    cout<<"Length of str ="<<len(s,i);
return 0;
}
