package ds_10_11

import kotlin.math.absoluteValue
import kotlin.math.pow

class Polynomial(private val terms: MutableMap<Int, Double>) {

    constructor(expression: String) : this(tranExpr(expression))

    operator fun plus(other: Polynomial): Polynomial = Polynomial(HashMap(terms).mergeTerms(other.terms))

    operator fun plusAssign(other: Polynomial) {
        this.terms.mergeTerms(other.terms)
    }

    operator fun minus(other: Polynomial): Polynomial = Polynomial(HashMap(this.terms).mergeTerms(other.terms.mapValues { -it.value }))

    operator fun minusAssign(other: Polynomial) {
        this.terms.mergeTerms(other.terms.mapValues { -it.value })
    }

    operator fun times(other: Polynomial): Polynomial = Polynomial(other.terms
            .map { pair -> this.terms.mapKeys { it.key + pair.key }.mapValues { it.value * pair.value } }
            .fold(HashMap<Int, Double>() as MutableMap<Int, Double>) { out, eachTerm -> out.mergeTerms(eachTerm) }
    )

    fun add(other: Polynomial): Polynomial = this + other

    fun print() {
        if (terms.isEmpty()) {
            println(0)
            return
        }

        fun format(base: Double, top: Int): String {
            val sb = StringBuilder()
            if (base < 0) sb.append("-")

            when {
                top != 0 && base.absoluteValue == 1.0 -> Unit
                base == Math.rint(base) -> sb.append(base.toInt().absoluteValue)
                else -> sb.append(base.absoluteValue)
            }

            if (top > 0) {
                sb.append("x")
                if (top > 1)
                    sb.append("^$top")
            }
            return sb.toString()
        }
//        println(terms)

        println(terms.asSequence().filterNot { it.value == 0.0 }
                .sortedByDescending { it.key }
                .map { format(it.value, it.key) }
                .reduce { sum, str -> if (str[0] == '-') "$sum - ${str.drop(1)}" else "$sum + $str" })
    }

    fun eval(x: Double) = terms.asSequence().map { x.pow(it.key) * it.value }.sum()

    fun leadExp(): Int = terms.keys.max() ?: 0

    // ToolKit


    companion object {
        /**
         * @return it self
         */
        private fun MutableMap<Int, Double>.mergeTerms(other: Map<Int, Double>): MutableMap<Int, Double> {
            other.forEach { key, value -> this.merge(key, value) { v1, v2 -> v1 + v2 } }
            // clean up (optional)
            this -= this.filter { it.value == 0.0 }.keys
            return this
        }

        private fun tranExpr(input: String): MutableMap<Int, Double> {
            val terms: MutableMap<Int, Double> = HashMap()

            input.replace(" ", "").split(Regex("[+]|(?=-)")).filter { it.isNotBlank() }.forEach { expr ->
                if (expr.matches(Regex("^-?[0-9]+(\\.[0-9]+)?$")))
                    terms[0] = expr.toDouble()
                else {
                    with(expr.split(Regex("\\^"), 2)) {
                        terms[getOrNull(1)?.toInt() ?: 1] = this[0].dropLastWhile { it.isLetter() }
                                .takeIf { it.isNotBlank() }?.toDouble() ?: 1.0
                    }
                }
            }
            return terms
        }
    }
}