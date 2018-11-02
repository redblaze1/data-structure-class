package ds_11_01

import ds_11_01.Chain.Companion.sum
import ds_11_01.Chain.Companion.average

fun main(args: Array<String>) {

    val a = Chain<Int>()
    a.addFirst(13)
    a.addFirst(12)
    a.addFirst(1)
    a.addFirst(99)
    a.addFirst(8)
    a.addFirst(4)
    a.addFirst(3)

    val b = Chain<Float>()
    b.addFirst(4.5F)
    b.addFirst(7.8F)
    b.addFirst(5.69F)
    b.addFirst(3.14F)

    println("a.sum = ${a.sum()}")
    println("b.sum = ${b.sum()}")
    println("a.average = ${a.average()}")
    println("b.average = ${b.average()}")
    a.traversal()
    b.traversal()
}