package ds_10_11

fun main(args: Array<String>) {
    val a = Polynomial("3x^3 + 5x^2 + 6x + 7")
    val b = Polynomial("7x^3 + 5x^2 + 9")
    val c = a + b
//    println(a.eval(1.0))
//    println(b.eval(2.0))
//    println(c.leadExp())
//    println(c.eval(4.0))
    val test = Polynomial("3x^3 - 5x^2 + 4")
    val test2 = Polynomial("2x^2 + 100")
    val test3 = test + test2
    test3.print()
    println(test3.eval(10.0))
}