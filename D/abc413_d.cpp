/**
 * @file
 * ABC413_D Make Geometric Sequence
 * https://atcoder.jp/contests/abc413/tasks/abc413_d
 * 
 * コンテスト中にAC済
 * 余裕があればこれから手直しする予定
 * 
 * @brief
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
  int t;
  cin >> t;
  rep(i, t) {
    int n;
    cin >> n;
    vll a(0);
    vll b(0);
    rep(j, n) {
      ll tmp;
      cin >> tmp;
      (tmp > 0 ? a : b).push_back(tmp);
    }
    sort(all(a));
    sort(rall(b));
    if((a.size() - b.size()) * (a.size() - b.size()) > 1 && a.size() != 0 && b.size() != 0) {
      cout << "No" << endl;
      continue;
    }
    if(a.size() == b.size()) {
      ll tmp = a[0] * b[b.size()-1];
      rep(j, n/2) {
        if(a[j] * b[b.size()-1-j] != tmp) {
          cout << "No" << endl;
          break;
        }
        if(j == n/2 - 1) {
          cout << "Yes" << endl;
        }
      }
    }
    else {
      ll tmp;
      tmp = (a.size() != 0 ? a[0] * a[a.size()-1] : b[0] * b[b.size()-1]);
      bool flag = true;
      rep(j, a.size() / 2 + a.size() % 2) {
        if(a[j] * a[a.size()-1-j] != tmp) {
          flag = false;
          break;
        }
      }
      rep(j, b.size() / 2 + b.size() % 2) {
        if(b[j] * b[b.size()-1-j] != tmp) {
          flag = false;
          break;
        }
      }
      cout << (flag ? "Yes" : "No") << endl;
    }
  }
  return 0;
}
