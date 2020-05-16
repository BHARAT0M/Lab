#include<bits/stdc++.h>
using namespace std;
int power(int a,int b){
    int res;
if(b==0){
  return 1;
}
else if(b==1){
    return a;
}
res=power(a,b/2);
if(b%2==0){
    return res*res;
}
else{
    return a*res*res;
}

}
int main(){
    int n1,n2;
    cout<<"enter two number "<<endl;
    cin>>n1>>n2;
    cout<<"Value of "<<n1<<"^"<<n2<<" = "<<power(n1,n2);
return 0;
}
