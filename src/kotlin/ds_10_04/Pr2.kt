package ds_10_04

fun main(args: Array<String>) {
    println(ack(3, 2))
    println(ack(3, 6))
    println(f(15))
}

fun ack(m: Int, n: Int): Int = when {
    m == 0 -> n + 1
    n == 0 -> ack(m - 1, 1)
    else -> ack(m - 1, ack(m, n - 1))
}

private val fibonacciCache = Array(1000) { 0 }.apply {
    this[0] = 1
    this[1] = 1
}

fun f(n: Int): Int = if (fibonacciCache[n - 1] != 0) fibonacciCache[n - 1] else (f(n - 1) + f(n - 2)).also { fibonacciCache[n-1] = it }