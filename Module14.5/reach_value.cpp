#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool can_reach(ll cur, ll n){
  if(cur == n) return true;
  if(cur> n) return false;

  return can_reach(cur*10,n) || can_reach(cur*20,n);
}

int main () {
  int t;
  cin >> t;
  while(t--){
    ll n; cin >> n;
    if(can_reach(1,n)) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
