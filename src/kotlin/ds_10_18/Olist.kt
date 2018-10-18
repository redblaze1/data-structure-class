package ds_10_18

import java.io.IOException

class Olist<T : Comparable<T>>(capacity: Int = 100) {

    var capacity: Int = capacity; private set
    private var data: Array<Any?> = Array(capacity) { null }
    var length: Int = 0; private set

    fun sort() {
        // 簡易插入排序
        for (i in 1 until length) {
            for (j in i downTo 1) {
                if (data[j] as T > data[j - 1] as T)
                    break
                data.swap(j, j - 1)
            }
        }
    }

    fun Search(element: Int) {
        for (i in 0 until length)
            if (data[i] == element) {
                println("Found!")
                return
            }
        println("not found!")
    }

    fun read(i: Int): T {
        if (i >= length)
            throw IOException("out of range $i > $length")
        return data[i] as T
    }

    fun store(i: Int, element: T) {
        if (i >= length)
            throw IOException("out of range $i > $length")
        data[i] = element
    }

    fun insert(i: Int, v: T) {
        // TODO check capacity
        /* move rear portion */
        for (move in length - 1 downTo i) data[move + 1] = data[move]
        /* insert it */
        data[i] = v
        length++
    }

    fun del(i: Int): T {
        // check range
        if (i >= length)
            throw IOException("out of range $i > $length")
        return (data[i] as T).also {
            for (move in i until length - 1) data[move]  = data[move + 1]
            length--
        }
    }

    fun readAll() {
        for(i in 0 until length)
            print("${data[i]} ")
        println()
    }

    // Tool fun
    private fun Array<Any?>.swap(index: Int, other: Int) {
        this[index] = this[other].also { this[other] = this[index] }
    }

    override fun toString(): String = data.toList().take(length).toString()
}