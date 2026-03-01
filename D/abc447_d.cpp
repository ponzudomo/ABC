/**
 * @file
 * ABC447_D Take ABC 2
 * https://atcoder.jp/contests/abc447/tasks/abc447_d
 * 
 * 正解
 * 
 * @brief
 * queue
 *
 * @note
 * Problem Statement:
 * 'A', 'B', 'C' からなる文字列Sから、順序を保ったまま {'A', 'B', 'C'} を取り出すことを考える
 * 何回取り出せる？
 * 
 * Constraints:
 * |S| <= 10^6
 * 
 * Input:
 * S
 * 
 * Output:
 * 回数
 * 
 * @todo
 * - Kotlinに翻訳
 */

// include
#include <bits/stdc++.h>
using namespace std;

// define
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); } }init;


int main() {
    string s;
    cin >> s;

    queue<int> a, b, c;
    rep(i, s.size()) {
        switch(s[i]) {
            case 'A':
                a.push(i);
                break;
            case 'B':
                b.push(i);
                break;
            case 'C':
                c.push(i);
                break;
        }
    }

    int ans = 0;
    while(!a.empty()) {
        int af = a.front();
        while(!b.empty() && b.front() < af) {
            b.pop();
        }
        int bf = b.front();
        while(!c.empty() && c.front() < bf) {
            c.pop();
        }
        if(b.empty() || c.empty()) {
            break;
        }
        a.pop();
        b.pop();
        c.pop();
        ans++;
    }

    cout << ans << endl;

  return 0;
}