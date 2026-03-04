/**
 * @file
 * ABC446_C Omelette Restaurant 
 * https://atcoder.jp/contests/abc446/tasks/abc446_c
 * 
 * KotlinでAC済
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
 */

fun main() {
    // AIが直してくれた
    // Tが2*10＾５の時、printlnを毎回呼ぶと出力が遅くなるらしい
    val sb = StringBuilder()
    val t = readInt()
    repeat(t) {
        val (n, d) = readInts()
        val a = readInts()
        val b = readInts()

        var sum = 0
        var used = 0
        var expired = 0

        for (i in 0 until n) {
            var bToday = b[i]
            sum += a[i]
            used += bToday
            if (i - d >= 0) {
                expired += a[i - d]
                if (expired > used) {
                    bToday += expired - used
                    used = expired
                }
            }
            sum -= bToday
        }
        sb.appendLine(sum)
    }
    print(sb)
}

/* ---------- 入力 ---------- */
fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map { it.toInt() }