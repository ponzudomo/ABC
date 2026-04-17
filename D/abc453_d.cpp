/**
 * @file
 * ABC453_D Go Straight
 * https://atcoder.jp/contests/abc453/tasks/abc453_d
 * 
 * @brief
 * (主に使ったアルゴリズム)
 *
 * @note
 * Problem Statement:
 *  迷路問題 SからGまでのパスを出力
 *  `#`: 出入りできない (0方向)
 *  `.`: 自由に出入りできる (4方向)
 *  `o`: 直前の移動方向にしか移動できない (1方向)
 *  `x`: 直前の移動方向以外にしか移動できない (3方向)
 *  `S`: スタート地点
 *  `G`: ゴール地点
 * 
 * Constraints:
 *  1 <= H, W <= 1000
 * 
 * Input:
 *  H W
 *  グラフの情報 (H行W列)
 * 
 * Output:
 *  Yes / No
 *  SからGまでの移動例 (U, D, L, R)
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
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef vector<string> vs;

const double pi = 3.141592653589793238;
const int inf = 1073741823;
const ll infl = 1LL << 60;
const int mod = 998244353;
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); } }init;

/**
 * 移動方向を数字で扱いたいので、出力用にint -> charのマッピングを用意しておく
 * dir_to_char[0] = 'D' のように使う
 */
const string dir_to_char = "DURL";

/// @brief 現在の状態を表す構造体 座標と直前の移動方向を持つ
struct State {
  int x;
  int y;

  /**
   * @brief
   * 直前の移動方向
   * 初期状態では適当に0とでもしておく
   * 0: 下 (x+=1)
   * 1: 上 (x-=1)
   * 2: 右 (y+=1)
   * 3: 左 (y-=1)
   */
  int prev_dir;

  State(int x, int y, int prev_dir) : x(x), y(y), prev_dir(prev_dir) {}

  /**
   * @brief 現在の状態からdir方向に移動できるかどうかを返す
   * @param dir 移動方向
   * @param h グラフの高さ
   * @param w グラフの幅
   * @param grid グラフの情報
   * @param visited 各状態について既に通ったことがあるかどうか
   */
  bool is_movable(int dir, int h, int w, vs &grid, vvvb &visited) {
    /// 範囲外に出ないか
    if(dir == 0 && x == h-1) return false;
    if(dir == 1 && x == 0) return false;
    if(dir == 2 && y == w-1) return false;
    if(dir == 3 && y == 0) return false;

    // 来訪済みでないか
    int next_x = x + (dir == 0) - (dir == 1);
    int next_y = y + (dir == 2) - (dir == 3);
    if(visited[next_x][next_y][dir]) return false;

    char cell = grid[x][y];
    if(cell == '#') return false;
    if(cell == '.') return true;
    if(cell == 'o') return dir == prev_dir;
    if(cell == 'x') return dir != prev_dir;
    return true; // SやGのマスは自由に出入りできる
  }
};

/**
 * @brief ゴールに到達したかどうかを再帰で判断
 * @param h グラフの高さ
 * @param w グラフの幅
 * @param grid グラフの情報
 * @param visited 各状態について既に通ったことがあるかどうかを保存する3次元配列
 * @param current 現在の状態
 * @param moves 現在までの移動の履歴
 * @return ゴールまでのパス or 空の文字列
 */
string find_path(int h, int w, vs &grid, vvvb &visited, State &current, string moves) {
  if (grid[current.x][current.y] == 'G') return moves;
  visited[current.x][current.y][current.prev_dir] = true;

  string result = "";
  rep(i, 4) {
    if(current.is_movable(i, h, w, grid, visited)) {
      State next_state(current.x, current.y, i);
      switch(i) {
        case 0:
          next_state.x++;
          break;
        case 1:
          next_state.x--;
          break;
        case 2:
          next_state.y++;
          break;
        case 3:
          next_state.y--;
          break;
      }
      string next_moves = moves + dir_to_char[i];
      string tmp = find_path(h, w, grid, visited, next_state, next_moves);
      if(tmp != "") {
        result = tmp;
        break;
      }
    }
  }
  return result;
}

int main() {
  int h, w;
  cin >> h >> w;

  State start(0, 0, 0);

  /**
   * @brief 
   * グラフの情報
   * `#`: 出入りできない (0方向)
   * `.`: 自由に出入りできる (4方向)
   * `o`: 直前の移動方向にしか移動できない (1方向)
   * `x`: 直前の移動方向以外にしか移動できない (3方向)
   * `S`: スタート地点
   * `G`: ゴール地点
   */
  vs grid(h);
  rep(i, h) {
    cin >> grid[i];
    rep(j, w) {
      if(grid[i][j] == 'S') {
        start = State(i, j, 0);
      }
    }
  }

  /**
   * @brief 
   * grid中の各マスについて、状態ごとに既に通ったかどうかを確認する
   * 例えばchecked[x][y][prev_dir] = true なら、Stateが(x, y, prev_dir)である状態は既に通ったことがある
   */
  vvvb visited(h, vvb(w, vb(4, false)));

  string path = find_path(h, w, grid, visited, start, "");

  if(path == "") {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    cout << path << endl;
  }

  return 0;
}
