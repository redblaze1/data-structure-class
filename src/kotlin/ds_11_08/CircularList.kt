package ds_11_08

/**
 * LinkList imp
 */
class CircularList<T> : Iterable<T> {
    private var last: ChainNode<T>? = null

    internal data class ChainNode<R>(var value: R, var link: ChainNode<R>? = null)

    val size: Int
        get() {
            if (this.isEmpty())
                return 0
            var count = 1
            var pointer: ChainNode<T> = last!!.link!!
            while (pointer != last) {
                pointer = pointer.link!!
                count++
            }
            return count
        }

//    operator fun contains(element: T): Boolean {
//        var pointer = first
//        while (pointer != null)
//            if (pointer.value == element)
//                return true
//            else
//                pointer = pointer.link
//        return false
//    }

//    fun containsAll(elements: Collection<T>): Boolean {
//        val toFind: MutableSet<T> = HashSet(elements)
//        var pointer = first
//        while (pointer != null && toFind.isNotEmpty()) {
//            toFind.remove(pointer.value)
//            pointer = pointer.link
//        }
//        return toFind.isEmpty()
//    }

//    operator fun get(index: Int): T {
//        if (index < 0 || last == null)
//            throw IndexOutOfBoundsException()
//        var count = index
//        var pointer = last!!.link
//        while (count-- != 0 && pointer != null)
//            pointer = pointer.link
//        return pointer?.value ?: throw IndexOutOfBoundsException()
//    }

//    fun indexOf(element: T): Int {
//        var count = 0
//        var pointer = first
//        while (pointer != null) {
//            if (pointer.value == element)
//                return count
//            pointer = pointer.link
//            count++
//        }
//        return -1
//    }

    fun isEmpty(): Boolean = last == null

    class ChainIterator<T> internal constructor(private var now: ChainNode<T>?, var size: Int) : Iterator<T> {

        override fun hasNext(): Boolean = size > 0 && now != null

        override fun next(): T {
            if (size == 0)
                throw Throwable("No next")
            size--
            now = now!!.link
            return now!!.value
        }

    }

    override fun iterator(): Iterator<T> {
        return ChainIterator(last, size)
    }

//    fun lastIndexOf(element: T): Int {
//        var find = -1
//        var count = 0
//        var pointer = first
//        while (pointer != null) {
//            if (pointer.value == element)
//                find = count
//            pointer = pointer.link
//            count++
//        }
//        return find
//    }

    fun add(element: T): Boolean {
        if (last == null) {
            last = ChainNode(element, null)
            last!!.link = last
        } else {
            last = ChainNode(element, last!!.link).also { last!!.link = it }
        }
        return true
    }

    fun add(index: Int, element: T) {
        if (index < 0)
            throw IndexOutOfBoundsException()

        if (index == 0) {
            if (last == null) {
                last = ChainNode(element, null)
                last!!.link = last
            } else {
                last!!.link = ChainNode(element, last!!.link)
            }
            return
        }
        var limit = size
        var count = index
        var pointer = last

        while (count-- != 0 && limit-- != 0)
            pointer = pointer!!.link

//        if (pointer == null)
//            throw IndexOutOfBoundsException()

        pointer!!.link = ChainNode(element, pointer.link)
        if (limit == 0)
            last = pointer
    }

//    private fun Collection<T>.makeChain(link: ChainNode<T>?): Pair<ChainNode<T>, ChainNode<T>> {
//        val iterator = this.reversed().iterator()
//        val end = ChainNode(iterator.next(), link)
//        var head = end
//        while (iterator.hasNext())
//            head = ChainNode(iterator.next(), head)
//        return head to end
//    }
//
//    fun addAll(index: Int, elements: Collection<T>): Boolean {
//        if (index < 0)
//            throw IndexOutOfBoundsException()
//
//        if (elements.isEmpty())
//            return true
//
//        if (index == 0) {
//            elements.makeChain(first).let {
//                first = it.first
//                if (it.second.link == null) // or last == null
//                    last = it.second
//            }
//            return true
//        }
//
//        var count = index
//        var pointer = first
//
//        while (--count != 0 && pointer != null)
//            pointer = pointer.link
//
//        if (pointer == null)
//            throw IndexOutOfBoundsException()
//
//        elements.makeChain(pointer.link).let {
//            pointer.link = it.first
//            if (it.second.link == null)
//                last = it.second
//        }
//        return true
//    }
//
//    fun addAll(elements: Collection<T>): Boolean {
//        if (elements.isEmpty())
//            return true
//
//        if (last == null) {
//            elements.makeChain(null).let {
//                first = it.first
//                last = it.second
//            }
//        } else {
//            elements.makeChain(null).let {
//                last!!.link = it.first
//                last = it.second
//            }
//        }
//        return true
//    }

    fun clear() {
        last = null
    }

//    override fun listIterator(): MutableListIterator<T> {
//        TO DO("not implemented") //To change body of created functions use File | Settings | File Templates.
//    }

//    override fun listIterator(index: Int): MutableListIterator<T> {
//        TO DO("not implemented") //To change body of created functions use File | Settings | File Templates.
//    }

//    fun remove(element: T): Boolean {
//        if (first == null)
//            return false
//
//        var pointer = first
//        var pre: ChainNode<T>? = null
//        while (pointer != null) {
//            if (pointer.value == element) {
//                if (pre != null)
//                    pre.link = pointer.link
//                else
//                    first = first!!.link
//                return true
//            }
//            pre = pointer
//            pointer = pointer.link
//        }
//        return false
//    }

//    fun removeAll(elements: Collection<T>): Boolean {
//        TO DO("not implemented") //To change body of created functions use File | Settings | File Templates.
//    }

    fun removeAt(index: Int): T {
        if (index < 0 || last == null)
            throw IndexOutOfBoundsException()

        var limit = size
        var count = index
        var pointer = last
        var pre: ChainNode<T>? = last
        while (limit-- != 0 && count-- != -1) {
            pre = pointer
            pointer = pointer!!.link
        }

//        if (pointer == null)
//            throw IndexOutOfBoundsException()

        return pointer!!.value.also {
            if (size == 1)
                last = null
            else {
                pre!!.link = pointer.link
                if (pointer == last)
                    last = pre
            }
        }
    }

//    fun retainAll(elements: Collection<T>): Boolean {
//        TO DO("not implemented") //To change body of created functions use File | Settings | File Templates.
//    }

//    operator fun set(index: Int, element: T): T {
//        if (index < 0 || first == null)
//            throw IndexOutOfBoundsException()
//        var count = index
//        var pointer = first
//        while (count-- != 0 && pointer != null)
//            pointer = pointer.link
//
//        if (pointer == null)
//            throw IndexOutOfBoundsException()
//
//        return pointer.value.also { pointer.value = element }
//    }

    override fun toString(): String = iterator().asSequence().toList().toString()

//    override fun subList(fromIndex: Int, toIndex: Int): MutableList<T> {
//        TO DO("not implemented") //To change body of created functions use File | Settings | File Templates.
//    }

//    fun reversed() {
//        var pre: ChainNode<T>? = last
//        var now: ChainNode<T>? = first
//        while (now != null) {
//            val next = now.link
//            now.link = pre
//            pre = now
//            now = next
//        }
//        first = last.also { last = first }
//    }

//    fun concatenate(other: ChainList<T>) {
//        plusAssign(other)
//    }

//    operator fun plusAssign(other: CircularList<T>) {
//        if (this.isEmpty()) {
//            first = other.first
//            last = other.last
//        } else {
//            last!!.link = other.first
//            last = other.last
//        }
//    }
}
