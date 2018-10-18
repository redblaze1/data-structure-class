package ds_10_04

import java.util.*

fun main(args: Array<String>) {
    val list = SortArray(30)
    list.setInitia()
    println("排序前")
    list.print()
    list.bubbleSort()
    println("排序後")
    list.print()
}

class SortArray(size: Int) {
    private val list : Array<Int> = Array(size) {0}

    fun setInitia() {
        with(Random()) { for(i in 0 until list.size) { list[i] = nextInt(300) } }
    }

    fun bubbleSort() {
        for (intoIndex in 0 until list.size - 1)
            for (findIndex in (intoIndex + 1 until list.size).reversed())
                if (list[findIndex] < list[findIndex - 1]) list.swap(findIndex, findIndex - 1)
    }

    fun selectionSort() {
        for (intoIndex in 0 until list.size - 1) {
            var minIndex: Int = intoIndex
            for (findIndex in intoIndex + 1 until list.size)
                if (list[findIndex] < list[minIndex]) minIndex = findIndex
            list.swap(intoIndex, minIndex)
        }
    }

    private fun Array<Int>.swap(index: Int, other: Int) {
        this[index] = this[other].also { this[other] = this[index] }
    }

    fun print() {
        println(list.asList())
    }
}