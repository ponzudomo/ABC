#include <bits/stdc++.h>
using namespace std;
#include  <boost/dynamic_bitset.hpp>
using namespace boost;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); } }init;
using ll = long long;
using ull = unsigned long long;
using si = set<int>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vvvll = vector<vector<vector<ll>>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
const double pi = 3.141592653589793238;
const int inf = 1073741823;
const ll infl = 1LL << 60;
const int mod = 998244353;
#define fore(x, a) for (auto &x : a)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

auto scan(int n, int m) {
  map<int, map<int, dynamic_bitset<>>> s;
  rep(i, n) {
    dynamic_bitset<> sum(m*m);
    rep(j, n) {
      char tmp;
      cin >> tmp;
      sum <<= 1;
      if(tmp=='#') sum.set(0);
      if(m*m>m) sum.reset(m);
      if(j>=m-1) s[i][j-m+1] = sum;
    }
  }
  for(int i=n-2; i>=0; i--) rep(j, n-m+1) {
    s[i][j] ^= (s[i+1][j] << m);
  }
  return s;
}

int main() {
  int n, m;
  cin >> n >> m;
  auto s = scan(n, m), t = scan(m, m);
  rep(i, n-m+1) rep(j, n-m+1) if(s[i][j]==t[0][0]) {
    cout << i+1 << ' ' << j+1 << endl;
    return 0;
  }
  return 0;
}