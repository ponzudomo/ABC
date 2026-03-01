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

import kotlin.collections.ArrayDeque

fun main() {
    val s = readLn()
    val queueA = ArrayDeque<Int>()
    val queueB = ArrayDeque<Int>()
    val queueC = ArrayDeque<Int>()

    for (i in s.indices) {
        when (s[i]) {
            'A' -> queueA.add(i)
            'B' -> queueB.add(i)
            'C' -> queueC.add(i)
        }
    }

    var ans = 0
    while (queueA.isNotEmpty()) {
        val firstA = queueA.removeFirst()

        while (queueB.isNotEmpty() && queueB.first() < firstA) {
            queueB.removeFirst()
        }
        if (queueB.isEmpty()) break
        val firstB = queueB.removeFirst()

        while (queueC.isNotEmpty() && queueC.first() < firstB) {
            queueC.removeFirst()
        }
        if (queueC.isEmpty()) break
        queueC.removeFirst()
        
        ans++
    }
    println(ans)
}

/* ---------- 入力 ---------- */
fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map { it.toInt() }