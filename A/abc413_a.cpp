/**
 * @file
 * ABC413_A Content Too Large 
 * https://atcoder.jp/contests/abc413/tasks/abc413_a
 * 
 * コンテスト中にAC済
 * 
 * @brief
 * 四則演算
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
  int n, m, sum = 0;
  cin >> n >> m;
  rep(i,n) {
    int a;
    cin >> a;
    sum += a;
    if(sum > m) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
