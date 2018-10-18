package ds_10_18

fun main(args: Array<String>) {
    val a = SparseMatrix(2,2,
            3,4,
            5,6)
    val b = SparseMatrix(2,2,
            4,8,
            7,9)
    val c = b.transpose()
    val d = a.add(b)
    val e = a.multiply(b)
    d.print()
    e.print()
}