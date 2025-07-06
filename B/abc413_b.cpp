/**
 * @file
 * ABC413_B cat 2
 * https://atcoder.jp/contests/abc413/tasks/abc413_b
 * 
 * コンテスト中にAC済
 * 芸術点の低い解き方なので後で考え直したい
 * 
 * @brief
 * vector<string> が与えられる
 * 文字列2つの組み合わせがいくつあるかを求める
 * setで重複を消して解いた
 *
 * @note
 * Problem Statement:
 * 
 * Constraints:
 * 
 * Input:
 * 
 * Output:
 * 
 * @todo
 *
 */

// include
#include <bits/stdc++.h>
using namespace std;


// define
#define fore(x, a) for (auto &x : a)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

// typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;

const double pi = 3.141592653589793238;
const int inf = 1073741823;
const ll infl = 1LL << 60;
const int mod = 998244353;
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); } }init;


int main() {
  int n;
  cin >> n;
  vs s(n);
  set<string> ans;
  rep(i, n) {
    cin >> s[i];
  }
  rep(i, n) {
    for(int j = i+1; j < n; j++) {
      string t = s[i] + s[j];
      string r = s[j] + s[i];
      ans.insert(t);
      ans.insert(r);
    }
  }
  cout << ans.size() << endl;
  return 0;
}
