package ds_11_01

import java.util.*

fun main(args: Array<String>) {

    val a = ArrayLinkList<String>()
    a.add("bat")
    a.add("cat")
    a.add("eat")
    a.add("fat")
    a.add("hat")
    println(a)
    a.insert(4, "gat")
    println(a)

}