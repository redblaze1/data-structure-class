package ds_11_08

fun main(args: Array<String>) {
    val list = ChainList<Int>()

    for (x in 10..40 step 10)
        list.add(x)

    println("reversed 前 : $list")
    list.reversed()
    println("reversed 後 : $list")
}