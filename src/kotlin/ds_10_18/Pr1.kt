package ds_10_18

fun main(args: Array<String>) {
//    val a = SparseMatrix(7,7,10)
//    a.storeSum(8,0,5)
//    a.storeSum(1, 2, 2)
//    a.storeSum(3, 5, 6)
//    a.print()
//    println(a.smArray)
    val a = SparseMatrix(3,3, 6)
    a.storeSum(3, 0,0)
    a.storeSum(5, 0,2)
    a.storeSum(17, 1,0)
    a.storeSum(7, 1,1)
    a.storeSum(55, 2,1)
    a.storeSum(9, 2,2)
    a.print()
    println("轉置之後")
    a.transpose().print()
}

