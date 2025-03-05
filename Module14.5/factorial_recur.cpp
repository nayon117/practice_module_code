#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll fact(ll n){
  if(n <= 1) return n;
  return n * fact(n-1);
}

int main () {
  ll n;
  cin >> n;
  cout << fact(n);

  return 0;
}
