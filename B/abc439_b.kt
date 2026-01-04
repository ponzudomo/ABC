/**
 * @file
 * ABC439_B - Happy Number
 * https://atcoder.jp/contests/abc439/tasks/abc439_b
 * 
 * @brief
 * 既出かどうかをmutableSetOfで管理しながら1か既出の数字を待ち続ける
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

fun Int.calculateNext(): Int {
    var sum = 0
    var num = this
    while (num > 0) {
        val digit = num % 10
        sum += digit * digit
        num /= 10
    }
    return sum
}

fun main() {
    var n = readInt()
    val seen = mutableSetOf<Int>()
    while (n != 1 && seen.add(n)) {
        n = n.calculateNext()
    }
    println(if (n == 1) "Yes" else "No")
}

/* ---------- 入力 ---------- */
fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map { it.toInt() }