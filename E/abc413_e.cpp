/**
 * @file
 * ABC413_E Reverse 2^i
 * https://atcoder.jp/contests/abc413/tasks/abc413_e
 * 
 * @brief
 * なんじゃこれ
 * 
 *
 * @note
 * Problem Statement:
 * - (1, 2, 3, ..., 2^N) の順列Pが与えられる
 * - 次の操作を0回以上行うことができる
 *   - Pの a*2^b番目 ~ (a+1)*2^b-1番目 の要素をreverseする
 *   - a, b は正負整数、0 <= a*2^b <= 2^N
 * - 操作を繰り返して得られるPのうち、辞書順最小のものを出力する
 * - このテストケースがT個与えられる
 * 
 * Constraints:
 * - 1 <= T <= 10^5
 * - 1 <= N <= 18
 * - For each input file, the sum of 2^N over all test cases is at most 3*10^5
 * - All input values are integers
 * 
 * Input:
 *  The input is given from standard input in the following format:
 *  > T
 *  > case1
 *  > case2
 *  > ...
 *  > caseT
 *  case_i represents the i-th test case and is given in the following format:
 *  > N
 *  > P_1 P_2 ... P_{2^N-1}
 * 
 * Output:
 *  > case1
 *  > case2
 *  > ...
 *  > caseT
 * 
 * @todo
 * 1. reverseでもってこれる数のうち、最も小さいものを左から順に詰めていきたい
 * 2. reverseできる範囲について整理
 *  - 始点は a*2^b ← これはなんでも作れそう
 *  - reverseできる個数は 2^b ← こっちの制約のが厳しそう
 *  - 例えば、a*2^b を奇数にしようと思うとreverseできる個数が1個になっちゃって意味がない → reverseの始点rev_firstとして考えられるのは0と偶数のみ
 *  - 始点rev_firstに対して、reverseできる個数は 2 ~ gcd(rev_first, 2^N)
 *   - rev_firstが0の場合のみreverseできる個数が 2 ~ 2^N
 *  - reverseの終点rev_lastとして考えられるのは rev_first + (2 ~ gcd(rev_first, 2^N))
 *   - rev_firstが0の場合のみrev_lastは 2 ~ 2^N
 *   - まあrev_firstの制限はあるものの割と自由度は高い
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
    vll p(n);
    rep(j, n) cin >> p[j];
    vll ans(n);
    ll rev_first = 0;
    while (rev_first < n) {
      
    }
  }
  return 0;
}
