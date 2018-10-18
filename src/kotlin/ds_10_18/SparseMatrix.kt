package ds_10_18

class SparseMatrix(val rows: Int, val cols: Int, t: Int) {

    constructor(rows: Int, cols: Int, vararg elements: Int) : this (rows, cols, elements.count { it != 0 }) {
        for (r in 0 until rows) for (c in 0 until cols)
            storeSum(elements[r*rows + c], r, c)
    }

    val smArray: MutableList<Term> = ArrayList(t)

    data class Term(var row: Int, var col: Int, var value: Int) {
        override fun toString(): String = "($row,$col,$value)"
    }

    fun transpose(): SparseMatrix = SparseMatrix(cols, rows, smArray.size)
            .also { new -> this.smArray.asSequence().map { Term(it.col, it.row, it.value) }.sortedBy { it.row }.forEach { new.smArray.add(it) } }

//    fun fastTranspose(): SparseMatrix {
//
//    }

    fun add(other: SparseMatrix): SparseMatrix = SparseMatrix(rows, cols, smArray.size)
            .also { new -> new.smArray.addAll(this.smArray.map { it.copy() }) }
            .also { new -> other.smArray.forEach { this.storeSum(it.value, it.row, it.col) } }

//    fun multiply(other: SparseMatrix): SparseMatrix {
//
//    }

    fun storeSum(sum: Int, r: Int, c: Int) {
        if (sum == 0)
            return
        if (smArray.any { it.row == r && it.col == c })
            with(smArray.find { it.row == r && it.col == c }!!) { value += sum }
        else
            smArray.add(SparseMatrix.Term(r, c, sum))
    }

    fun multiply_constant(v: Double): SparseMatrix = SparseMatrix(rows, cols, smArray.size)
            .also { new -> new.smArray.addAll(this.smArray.map { it.copy(value = (it.value * v).toInt()) }) }

    fun print() {
        for (y in 0 until rows) {
            for (x in 0 until cols)
                print("${smArray.find { it.row == y && it.col == x }?.value ?: 0}\t")
            println()
        }
    }
}