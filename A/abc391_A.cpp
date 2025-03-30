#include <bits/stdc++.h>
using namespace std;
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


int main() {
  string d;
  cin >> d;
  vc news = {'N', 'E', 'W', 'S'};
  rep(i, d.size()) rep(j, 4) if(d[i] == news[j]) {
    d[i] = news[3-j];
    break;
  }
  cout << d << endl;
  return 0;
}