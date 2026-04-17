/**
 * @file
 * ABC453_C (タイトル)
 * https://atcoder.jp/contests/abc453/tasks/abc453_c
 * 
 * 解説を読んでAC
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

/// 全探索中の各移動パターンについて、原点を超過した回数を返す
ll calc(int n, vll &dists, bitset<20> &patterns) {
  /**
   * 小数を扱いたくないので、現在地を常に-0.5して扱う (=0始まり)
   * -0.5地点を通過した回数について考えることになるので、
   *  - prevからcurrentの移動で正負が変わるパターン -> prev*current < 0
   *  - prevとcurrentのうち、どちらかが0でもう一方が-1以下のパターン -> prev*current==0 && prev+current<0
   * のいずれかの条件を満たしたときにカウントを増やす
   * 
   * オーバーフロー注意！！！！(1ミス)
   */

  /// @brief 現在地 常に-0.5して扱う
  ll current = 0;

  /// @brief 原点(-0.5とする)を通過した回数
  ll ret = 0;

  rep (i, n) {
    ll prev = current;
    current += dists[i] * (patterns[i] ? 1 : -1);

    /// オーバーフロー対策の圧縮
    int prev_sign = (prev > 0) - (prev < 0);
    int current_sign = (current > 0) - (current < 0);

    if(prev_sign * current_sign < 0 || (prev_sign * current_sign == 0 && prev_sign + current_sign < 0)) ret++;
  }
  return ret;
}

int main() {
  /// @brief 移動回数
  int n;
  cin >> n;

  /// @brief 各移動の距離一覧
  vll dists(n);
  rep(i, n) cin >> dists[i];

  /// @brief 探索結果の最大値を常に保存
  ll ans = 0;

  rep(i, (1 << n)) {
    /// @brief 各移動の正負のパターンを表すビットセット
    bitset<20> pattern(i);
    ll ret = calc(n, dists, pattern);
    ans = max(ans, ret);
    cerr << "pattern: " << pattern << ", ret: " << ret << endl;
  }

  cout << ans << endl;
  return 0;
}
