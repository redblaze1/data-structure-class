package ds_11_01

import java.lang.StringBuilder

class ArrayLinkList<T> {

    val data: Array<Any?> = Array(100) { null }
    val link: Array<Int> = Array(100) { -1 }
    // -1 is not used
    // -2 is tail

    var tail = 0
    var head = 0

    fun isEmpty(): Boolean = link[head] == -1

    fun add(element: T) {
        // find next and linked
        findEmpty().let {
            link[tail] = it
            tail = it
            link[it] = -2
        }
        // put data to data
        data[tail] = element
    }

    fun insert(index: Int, element: T) {
        // find empty
        val nextEmpty = findEmpty()
        // update post
        if (index == 0) {
            link[nextEmpty] = head
            head = nextEmpty
        } else {
            val prePos = findPos(index - 1)
            link[nextEmpty] = link[prePos]
            link[prePos] = nextEmpty
            if (link[nextEmpty] == -2)
                tail = nextEmpty
        }
        data[nextEmpty] = element
    }

    operator fun get(index: Int): T {
        if (this.isEmpty())
            throw IndexOutOfBoundsException("Empty!")
        if (index < 0)
            throw IndexOutOfBoundsException("$index < 0")
        else {
            @Suppress("UNCHECKED_CAST")
            return data[findPos(index)] as T
        }
    }

    private fun findPos(index: Int): Int {
        var pos = head
        for (count in 1..index) {
            if (pos == -2) // loop end
                throw IndexOutOfBoundsException("$index out of range($count)")
            pos = link[pos]
        }
        return pos
    }

    private fun findEmpty(): Int {
        for (it in 0 until link.size)
            if (link[it] == -1)
                return it
        throw Throwable("Full!!")
    }

    override fun toString(): String {
        if (this.isEmpty())
            return "[]"
        val sb = StringBuilder("[")
        var pos = head
        sb.append(data[pos])
        for (count in 2..data.size) {
            pos = link[pos]
            if (pos == -2) // loop end
                break
            sb.append(", ").append(data[pos])
        }
        return sb.append("]").toString()
    }

//    private fun ListNode<T>.toList(): List<T> {
//        val list = mutableListOf<T>()
//        var tmp: ListNode<T>? = first
//        while (tmp != null)
//            tmp = tmp.also { list.add(it.Data) }.link
//        return list
//    }
}
