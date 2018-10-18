package ds_10_18

fun main(args: Array<String>) {
    val a = SparseMatrix(3, 3,
            3, 0, 5,
            17, 7, 0,
            0, 55, 9)
    val b = a.multiply_constant(3.0)
    b.print()
}

