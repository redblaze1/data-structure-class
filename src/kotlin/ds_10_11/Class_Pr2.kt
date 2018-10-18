package ds_10_11

fun main(args: Array<String>) {
    val list: MutableList<Int> = ArrayList(6)
    list.add(0, 3)
    list.add(0, 4)
    list.add(1, 5)
    list.add(0, 9)
    println(list)
    val x = list[3]
    println("x = $x")
    list.removeAt(1)
    println(list)
}