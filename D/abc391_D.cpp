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
  int n, w, q;
  cin >> n >> w;
  unordered_map<int, priority_queue<int, vi, greater<int>>> c; //coordinate
  unordered_map<int, unordered_map<int, int>> cto; //coordinate to order
  unordered_map<int, vi> ntc; //number to coordinate
  unordered_map<int, int> ott; //order to time
  int d = n; //orderがここまでだったら消えうる
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    c[x].push(y);
    ntc[i+1] = {x, y};
  }
  
  int check = w;
  fore(tmp, c) {
    check--;
    int x = tmp.first, i = 1;
    auto &ys = tmp.second;
    d = min(int(ys.size()), d);
    while(!ys.empty()) {
      auto &y = ys.top();
      cto[x][y] = i;
      if(!ott.count(i)) ott[i] = y;
      else ott[i] = max(ott[i], y);
      i++;
      ys.pop();
    }
  }
  if(check) d = 0;
  
  cin >> q;
  rep(i, q) {
    int t, a;
    cin >> t >> a;
    if(cto[ntc[a][0]][ntc[a][1]] > d) {
      cout << "Yes" << endl;
      continue;
    }
    cout << (ott[cto[ntc[a][0]][ntc[a][1]]] > t ? "Yes" : "No") << endl;
  }
  
  return 0;
}