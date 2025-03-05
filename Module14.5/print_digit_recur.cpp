#include <bits/stdc++.h>
using namespace std;

void print_digit(int num){
  if(num < 0) {
    cout << 0;
    return;
  }
  if(num < 10) {
    cout << num;
    return;
  }
  print_digit(num / 10);
  cout << " " << num % 10 ;
}

int main () {
  int t;
  cin >> t ;
 while(t--){
  int n;
  cin >> n;
  print_digit(n);
  cout << endl;
 }

  return 0;
}
