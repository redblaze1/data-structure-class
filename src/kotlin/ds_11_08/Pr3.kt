package ds_11_08

fun main(args: Array<String>) {
    val list = CircularList<Int>().apply {
        add(45)
        add(67)
        add(12)
        add(0, 30)
        add(0, 20)
    }

    println(list.toString())
    println(list.removeAt(0))
    println(list.removeAt(0))
    println(list.removeAt(list.size))
    println(list.removeAt(list.size))
}