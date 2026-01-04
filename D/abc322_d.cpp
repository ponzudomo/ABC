/**
 * @file
 * ABC322_D Polyomino
 * https://atcoder.jp/contests/abc322/tasks/abc322_d
 * 
 * まだ解いてる最中
 * 
 * @brief
 * グリッドの問題 パズルっぽい
 *
 * Problem Statement:
 * - グリッドの中にポリオミノ(ブロック)を敷き詰めていく問題
 * - グリッドは4*4固定
 * - ポリオミノは3つ与えられる これも4*4のグリッドとして与えられる
 * - ポリオミノは移動と回転が可能だが、反転は不可能
 * - ぴったりはみ出しも重なりもなく敷き詰めることができるなら "Yes", そうでなければ "No" を出力
 * 
 * Constraints:
 * - ポリオミノが与えられるとき、'#' = ある, '.' = ない
 * - 与えられるポリオミノは連結であり、空ではない
 * - 与えられるポリオミノは、穴が空いている場合もある
 * 
 * Input:
 * ポリオミノ4つ
 *   P1,1,1 P1,1,2 P1,1,3 P1,1,4
 *   P1,2,1 P1,2,2 P1,2,3 P1,2,4
 *   P1,3,1 P1,3,2 P1,3,3 P1,3,4
 *   P1,4,1 P1,4,2 P1,4,3 P1,4,4
 *     (改行なし)
 *   P2,1,1 P2,1,2 P2,1,3 P2,1,4
 *   P2,2,1 P2,2,2 P2,2,3 P2,2,4
 *   P2,3,1 P2,3,2 P2,3,3 P2,3,4
 *   P2,4,1 P2,4,2 P2,4,3 P2,4,4
 *     (改行なし)
 *   P3,1,1 P3,1,2 P3,1,3 P3,1,4
 *   P3,2,1 P3,2,2 P3,2,3 P3,2,4
 *   P3,3,1 P3,3,2 P3,3,3 P3,3,4
 *   P3,4,1 P3,4,2 P3,4,3 P3,4,4
 *     (改行なし)
 *   P4,1,1 P4,1,2 P4,1,3 P4,1,4
 *   P4,2,1 P4,2,2 P4,2,3 P4,2,4
 *   P4,3,1 P4,3,2 P4,3,3 P4,3,4
 *   P4,4,1 P4,4,2 P4,4,3 P4,4,4
 * 
 * Output:
 *   "Yes" or "No"
 * 
 * @note
 * 1. 境界線？輪郭？で考える方針
 * - ポリオミノを敷き詰めた時、隣接するポリオミノは「一方の右辺-他方の左辺」または「一方の上辺-他方の下辺」のいずれかの組み合わせでしか結合していないことに着目
 * - 上下左右の辺の数を数え、最終的に残る辺が上下左右4個ずつになるようになるか否かを判定すればいいのではないか
 * - ただしこの場合。L字型に3つマスが並んだポリオミノと2*2の正方形が数値上等しくなってしまう → 個数判定が必要そう
 * - 辺の数え方と相殺の仕方が難しそう
 * 
 * 2. ピクロス (回転は容易だが正誤判定が難しい)
 * - ピクロスのように、各列・各行に存在するマスの個数が4つに揃えば敷き詰め可能であることに着目
 * - 各ポリオミノについて、上/左から見た時のマスの個数(それぞれ5進法*4桁=625までの整数で表せる)を保存
 * - 移動については、5進数におけるシフト演算 → /=5 で実現可能
 * - 回転については、「上, 左」「左rev, 上」「上rev, 左rev」「左, 上rev」の4種類状態があると考えればいい
 * - これを上手いこと組み合わせて各ポリオミノを敷き詰められるかどうかを判定する
 * 
 * 3. ビット (正誤判定はXORで終わるが回転が難しい)
 * - 4*4のグリッドは、16ビットで表現可能
 * - ビットのXOR演算をとって、答えが2^16-1(=65535)になるかどうかを判定する
 * - ポリオミノの左右の移動はビットシフト1回, 上下の移動はビットシフト4回で実現可能
 * - ポリオミノの回転が難しい → 予め4種類の状態を保存
 * 
 * @todo
 * - ひとまず 2.ピクロス で実装
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

/**
 * @brief ポリオミノを表すビットセット * 回転4バージョン
 * @note
 *   [0] = x, y
 *   [1] = y, x_rev
 *   [2] = x_rev, y_rev
 *   [3] = y_rev, x
 */
struct Polyomino {
    /// @brief ポリオミノを表すビットセット
    bitset<16> bits;
    /// @brief ポリオミノを右に動かせる回数
    int move_right;
    /// @brief ポリオミノを下に動かせる回数
    int move_down;
};

int main() {
    /// poly0は角度固定でいい、poly1-2は回転させて試す必要がある
    Polyomino *poly0 = new Polyomino();
    Polyomino *poly1 = new Polyomino[4];
    Polyomino *poly2 = new Polyomino[4];
    /// 一応ポリオミノに含まれるマスの個数を数える
    int count_square = 0;

    rep(i, 3) {
        Polyomino *poly;
        poly = (i == 0) ? &poly0 : (i == 1) ? &poly1 : &poly2;

        rep(j, 4) {
            string s;
            cin >> s;
            rep(k, 4) {
                if (s[k] == '#') count_square++;
                poly[0].bits[j*4+k] = (s[k] == '#');
                /// poly0は回転させる必要がないので、回転分は考えない
                if(i == 0) continue;
                poly[1].bits[k*4+(3-j)] = (s[k] == '#');
                poly[2].bits[(3-j)*4+(3-k)] = (s[k] == '#');
                poly[3].bits[(3-k)*4+j] = (s[k] == '#');
            }
        }
        if (i == 0) poly0 = poly[0];
        else if (i == 1) poly1 = poly;
        else poly2 = poly;
    }

    /* ポリオミノの敷き詰め可能性を判定 */
    if(count_square != 16) {
        cout << "No" << endl;
        return 0;
    }



    return 0;
}
