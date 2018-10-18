package ds_10_04

fun main(args: Array<String>) {
    print(rdiv(19, 2))
}

fun rdiv(m: Int, n: Int):Int = if (m < n) 0 else 1 + rdiv(m - n, n)