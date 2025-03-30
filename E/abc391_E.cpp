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

int compress2(queue<int> ans) {
  if(ans.size() == 1) return ans.front();
  queue<int> ret;
  while(!ans.empty()) {
    int sum = 0, minus = 0;
    rep(i, 3) {
      sum += ans.front();
      minus = max(minus, ans.front());
      ans.pop();
    }
    ret.push(sum-minus);
  }
  return compress2(ret);
}

int compress(int n, queue<bool> q, queue<int> &worth) {
  if(n==1) {
    worth.push(1);
    return q.front()*2-1;
  }
  queue<bool> ooi, oii, p;
  queue<int> worth2;
  while(!q.empty()) {
    int tmp = 0;
    rep(i, 3) {
      tmp += q.front();
      q.pop();
    }
    p.push(tmp>=2);
    ooi.push(tmp%3==1);
    oii.push(tmp%3==2);
  }
  int ret = compress(n/3, p, worth);
  queue<int> ans;
  if(ret>0) while(!oii.empty()) {
    rep(i, (n<27 ? 1 : 3)) {
      int tmp = worth.front()*2;
      rep(j, min(n/3, 3)) {
        if(worth.front()) {
          tmp -= oii.front();
          worth2.push(p.front()*2-oii.front());
        }
        else worth2.push(0);
        oii.pop();
        p.pop();
      }
      tmp = max(worth.front(), tmp);
      worth.pop();
      ans.push(tmp);
    }
  }
  else while(!ooi.empty()) {
    rep(i, (n<27 ? 1 : 3)) {
      int tmp = worth.front()*2;
      rep(j, min(n/3, 3)) {
        if(worth.front()) {
          tmp -= ooi.front();
          worth2.push((1-p.front())*2-ooi.front());
        }
        else worth2.push(0);
        ooi.pop();
        p.pop();
      }
      tmp = max(worth.front(), tmp);
      worth.pop();
      ans.push(tmp);
    }
  }
  worth = worth2;
  return (ret>0 ? 1 : -1) * compress2(ans);
}

int main() {
  int n;
  cin >> n;
  queue<bool> q;
  queue<int> worth;
  n = pow(3, n);
  rep(i, n) {
    char tmp;
    cin >> tmp;
    q.push(tmp=='1');
  }
  int ans = compress(n, q, worth);
  cout << max(ans, -ans) << endl;
  return 0;
}