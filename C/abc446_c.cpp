/**
 * @file
 * ABC446_C Omelette Restaurant 
 * https://atcoder.jp/contests/abc446/tasks/abc446_c
 * 
 * C++でAC済
 * 
 * @brief
 * 累積和的に卵の総数を管理
 *
 * @note
 * Problem Statement:
 * T個のテストケースに対して、それぞれ以下の質問に答える。
 * N日に渡って、i日目にA_i個の卵を入荷し、B_i個の卵を使用する。
 * また、仕入れてからD日経った卵はその日の終わりに処分される。
 * N日目の終わりに、卵は何個残っているか？
 * 
 * Constraints:
 * 1 <= T <= 2*10^5
 * 1 <= D <= N <= 2*10^5
 * 1 <= A_i, B_i <= 10
 * 卵が足りなくなることはない
 * 
 * Input:
 * T
 * case_1
 *   N D
 *   A_1 A_2 ... A_N
 *   B_1 B_2 ... B_N
 * case_2
 * ...
 * case_T
 * 
 * Output:
 * T行出力する
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
  int t;
  cin >> t;
  while(t--) {
    int n, d, sum = 0, used = 0, expired = 0;
    cin >> n >> d;
    vi a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
      int b;
      cin >> b;
      sum += a[i];
      used += b;
      if(i-d >= 0) {
        expired += a[i-d];
        if(expired > used) {
          b += expired - used;
          used = expired;
        }
      }
      sum -= b;
    }
    cout << sum << endl;
  }
  return 0;
}
