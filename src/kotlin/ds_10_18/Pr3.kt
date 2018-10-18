package ds_10_18

fun main(args: Array<String>) {
    val a = Olist<Double>()
    a.insert(0, 34.5)
    a.insert(1, 44.7)
    a.insert(2,3.14159)
    a.insert(3, 66.7)
    println(a.length)
    println(a)
    a.sort()
    println(a)
    val b = Olist<Char>()
    var c = 0
    b.insert(c++,'a')
    b.insert(c++,'x')
    b.insert(c++,'g')
    b.insert(c++,'o')
    b.insert(c++,'o')
    b.insert(c,'d')
    println(b.length)
    println(b)
    b.sort()
    println(b)
}