/**
 * @file
 * ABC387_D Snaky Walk
 * https://atcoder.jp/contests/abc387/tasks/abc387_d
 * 
 * まだ解いてる最中
 * 
 * @brief
 * 制限付きBFS / 移動が縦横交互の迷路探索
 * 
 * @note
 * Problem Statement:
 * - 障害物ありの迷路が渡される
 * - スタートマスとゴールマスが指定される
 * - 縦移動と横移動を交互に繰り返して、スタートからゴールまで辿り着けるかどうか判定
 * 
 * Constraints:
 * - 1 <= H, W <= 1000
 * - H and W are integers.
 * - Each S_i is a string of length W consisting of 'S', 'G', '.', '#'.
 * - There is exactly one 'S' and one 'G' in the input.
 * 
 * 
 * Input:
 *  > H W
 *  > S_1
 *  > S_2
 *  > S_3
 *  > ...
 *  > S_H
 * 
 * Output:
 *  > 最小移動回数 または -1
 * 
 * @todo
 * - まずは 1. BFS で解く
 *
 * 1. BFS
 *   1-1. STARTから近い順に探索、最小移動回数を保存
 *     STARTからそのマスに辿り着くまでの最小移動回数(縦/横) みたいなのを保存しておく
 *     (Dijkstra's algorithm を使おうかとも思ったが、辺に重みがないので普通に近い順に見ていけば良さそうだと思った)
 *   1-2. 探索するマスはqueueで管理
 *     辿れるマスがなくなるか、GOALにたどり着いたら終了
 *
 */


// include
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

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


/// @brief マスを表す構造体
struct Cell {
    int x;
    int y;
    int min_vertical_moves;
    int min_horizontal_moves;

    Cell(int x, int y, int min_vertical_moves, int min_horizontal_moves) 
      : x(x), y(y), min_vertical_moves(min_vertical_moves), min_horizontal_moves(min_horizontal_moves) {}
};

/// @brief 1. BFS
/// @param
/// @return int min_moves
int BFS(int ) {
    queue<Cell> 
    return 0;
}

int main() {
    return 0;
}
