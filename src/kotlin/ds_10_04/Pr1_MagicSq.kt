package ds_10_04

fun main(args: Array<String>) {
//    val size = readLine()?.toInt()!! // if you want input a number
    val size = 7
    val sq: Array<Array<Int>> = Array(size) { Array(size) { 0 } }
    magicSq(sq)
    sq.print()
    print(sq.checkMagic())
}

const val x_offset = 1
const val y_offset = -1

fun magicSq(sq: Array<Array<Int>>) {
    val size = sq.size
    var number = 1
    var x = size / 2
    var y = 0
    for (i in 0 until size) for (j in 0 until size) {
        // check hit
        if (sq[y][x] != 0) {
            x = (x + x_offset + size) % size
            y = (y + y_offset + size) % size
        }
        // assign
        sq[y][x] = number++
        // move pointer
        x = (x + 1) % size
        y = (y + 1) % size
    }
}

fun Array<Array<Int>>.print() {
    forEach { arr ->
        arr.forEach { print("$it\t") }
        println()
    }
}

fun Array<Array<Int>>.checkMagic(): String {
    var good = true
    val checkNumber = (size * size * size + size) / 2
    this.forEachIndexed { index, it -> println("第 $index 橫列的和是: ${it.reduce { acc, i -> acc + i }.also { if (it != checkNumber) good = false }}") }
    for (index in 0 until size)
        println("第 $index 直行的和是: ${this.map { it[index] }.reduce { sum, i -> sum + i }.also { if (it != checkNumber) good = false }}")
    return if (good) "檢查通過!!" else "檢查不通過!!"
}