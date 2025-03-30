#include <bits/stdc++.h>
using namespace std;
#define fore(x, a) for (auto &x : a)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vs vector<string>
#define vvs vector<vector<string>>

bool check2(const vc &t, int i, int k) {
  rep(j, k / 2) {
    if (t[i + j] != t[i + k - 1 - j]) return false;
  }
  return true;
}

bool check1(const vc &t, int n, int k) {
  for (int i = 0; i <= n - k; ++i) {
    if (check2(t, i, k)) return false;
  }
  return true;
}

int main() {
  int n, k; 
  string s; 
  cin >> n >> k >> s;
  vc t(n); 
  rep(i, n) t[i] = s[i]; 
  sort(all(t));
  int ans = 0;
  
  do {
    if (check1(t, n, k)) ans++;
  } while (next_permutation(all(t)));
  
  cout << ans << endl;
  
  return 0;
}
