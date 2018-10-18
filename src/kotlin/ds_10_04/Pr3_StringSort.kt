package ds_10_04

fun main(args: Array<String>) {
    val stringList: MutableList<String> = listOf("apple", "google", "Alibaba", "Amazon", "IBM").toMutableList()
    println(stringList)
    stringList.sorT()
    println(stringList)

}

private fun MutableList<String>.sorT() {
    for (i in 1 until this.size) {
        var j = i
        while (j > 0 && compare(this[j - 1], this[j]) > 0) {
            this.swap(j, j - 1)
            j--
        }
    }
}

fun MutableList<String>.swap(index: Int, other: Int) {
    this[index] = this[other].also { this[other] = this[index] }
}

fun compare(str: String, other: String): Int {
    val len1 = str.length
    val len2 = other.length
    val lim = Math.min(len1, len2)

    for (k in 0 until lim) {
        val c1 = str[k]
        val c2 = other[k]
        if (c1 != c2)
            return c1 - c2
    }
    return len1 - len2
}