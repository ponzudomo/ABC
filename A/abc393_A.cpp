#include <bits/stdc++.h>
using namespace std;
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); } }init;

int main() {
  int ans = 1;
  for(int i=2; i>0; i/=2) {
    string s;
    cin >> s;
    ans += i * (s[0]=='f');
  }
  cout << ans << endl;
  return 0;
}