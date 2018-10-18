package ds_10_11

import kotlin.math.pow

fun main(args: Array<String>) {

    val input = readLine()!!

    val terms = init(input)

}

private fun init(input: String): Map<Int, Long> {

    val terms: MutableMap<Int, Long> = HashMap()

    input.replace(" ", "").split("+", "-").filter { it.isNotBlank() }.forEach {
        if (it.matches(Regex("^[0-9]+$")))
            terms.put(0, it.toLong())
        else
            with(it.split(Regex("[a-zA-Z*^]]")).filter { it.isNotBlank() }) {
                terms[if (size == 1) 1 else this[1].toInt()] = this[0].toLong()
            }
    }
    return terms
}

private fun eval(x: Long, functionTerms: Map<Int, Long>) = functionTerms.toList().map { x.pow(it.first) * it.second }.sum()

private fun Long.pow(n: Int): Long = this.toDouble().pow(n).toLong()
