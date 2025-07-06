/**
 * @file
 * ABC413_C Large Queue
 * https://atcoder.jp/contests/abc413/tasks/abc413_c
 * 
 * コンテスト中にAC済
 * 
 * @brief
 * ランレングス圧縮された状態で文字列を追加
 * そこから指定された個数の文字を取り出していく
 * queueで少し捻った文字列の管理をする問題
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
  int q;
  cin >> q;
  queue<pair<ll, ll>> que;
  rep(i, q) {
    int t;
    cin >> t;
    if (t == 1) {
      ll c, x;
      cin >> c >> x;
      que.push({c, x});
    } 
    else {
      ll k, sum = 0;
      cin >> k;
      while(k) {
        if(que.front().first > k) {
          que.front().first -= k;
          sum += que.front().second * k;
          break;
        } 
        else {
          k -= que.front().first;
          sum += que.front().second * que.front().first;
          que.pop();
        }
      }
      cout << sum << endl;
    }
  }
  return 0;
}
