/**
 * @file
 * ABC453_C (タイトル)
 * https://atcoder.jp/contests/abc453/tasks/abc453_c
 * 
 * 貪欲法で解いて失敗: https://atcoder.jp/contests/abc453/submissions/74952059
 * 解説をちょっとだけ読んだ
 * 40 50 90 1 1 1 みたいなテストケースの時に、貪欲法だと負に行きすぎて3回しか通過できないが、負負正から始めると4回通過できるっぽい
 * Cがせいぜい20以下なので全探索しても間に合うっぽい
 * 
 * @brief
 * 与えられた距離だけ前進または後進を繰り返し、原点をできるだけ通過したい
 *
 * @note
 * Problem Statement:
 * スタート地点は0.5
 * ここからn回の移動を行う
 * i回目の移動では、L_iの距離だけ正または負の方向に移動できる
 * 座標0を何回通過できるか？
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
#include <atcoder/all>
using namespace atcoder;
#include <boost/dynamic_bitset.hpp>
using namespace boost;

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
  vll l(n);
  rep(i, n) cin >> l[i];
  ll current = 0, ans = 0;
  rep (i, n) {
    ll dist;
    if(current < 0) dist = -current-1;
    else dist = current;
    if(dist < l[i]) ans++;

    cerr << "current: " << current;
    if(current < 0) current += l[i];
    else current -= l[i];
    cerr << " -> " << current << ", l[i]: " << l[i] << ", ans: " << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
