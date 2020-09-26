/*
Roll no :- 194CA014
2*2 Matrix method 
In this task Fibonacci number
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll> > Mulitply(vector<vector<ll> > &a, vector<vector<ll> >& b) {
  vector<vector<ll> > tmp{{0,0}, {0,0}};
  int n = a.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        tmp[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return tmp;
}

vector<vector<ll>> MatrixPower(vector<vector<ll> > &v, int p) {
  if (p == 0) {
    return (vector<vector<ll> >{{1,0},{0,1}});
  }
  auto tmp = MatrixPower(v, p / 2);
  tmp = Mulitply(tmp, tmp);
  if (p & 1) {
    return (Mulitply(tmp, v));
  }
  return tmp;
}

int main(){
  ll n;
  cout<<"\tEnter a number\n \t ";
  cin >> n;
  vector<vector<ll> > v{{1,1},{1,0}};
  v = MatrixPower(v, n);
  cout <<"\tFibonacci value = "<< v[0][1] << "\n";
}
