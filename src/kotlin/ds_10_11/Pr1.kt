package ds_10_11

fun main(args: Array<String>) {
    val a = Olist<Int>()
    a.insert(0, 3)
    a.insert(0, 4)
    a.insert(0, 5)
    a.insert(1, 9)
    print(a.read(2))
    with(a) {
//        average()
//        sum()
        sort()
        length
    }
    a.readAll()
    a.del(2)
    a.insert(2, 99)
    a.insert(0, 88)
    a.readAll()
    with(a) {
//        average()
//        sum()
        sort()
        length
    }
    a.readAll()
}