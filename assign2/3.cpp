#include<bits/stdc++.h>
using namespace std;
int print(int n){
  if(n>50){
    return 1;
  }
  cout<<n<<" ";
  return print(++n);
}
int main(){
    int num=1;
    cout<<"Number for 1 to 50 are "<<endl;
    print(num);
    return 0;
    }
