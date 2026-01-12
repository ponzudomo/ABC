/**
 * @file
 * ABC439_C 2026
 * https://atcoder.jp/contests/abc439/tasks/abc439_c
 * 
 * n以下の平方数の和を列挙
 * ただしnをx^2+y^2とするとき、xとyが一意に定まる
 * 
 * @brief
 * setで管理
 *
 * @note
 * Constraints:
 * X < Y
 * 1 <= N <= 10^7
 * 
 * Input:
 * N
 * 
 * Output:
 * k
 * a_1 a_2 ... a_k
 * 
 * @todo
 * まずは第一言語であるC++で解いて、勉強がてらKotlinに翻訳
 * このファイルはAC出た
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
  vector<int> seen(n+1, 0);

  int limit = (int)sqrt(n);
  int x = 1, y = 2;
  while(y <= limit) {
    x = 1;
    while(x < y) {
      int val = x*x + y*y;
      if(val > n) break;
      seen[val]++;
      x++;
    }
    y++;
  }

  vector<int> ans;
  rep(i, n+1) {
    if(seen[i] == 1) ans.push_back(i);
  }

  cout << ans.size() << endl;
  rep(i, ans.size()) {
    cout << ans[i] << " \n"[i==ans.size()-1];
  }

  return 0;
}
