package ds_11_08

/**
 * LinkList imp
 */
class ChainList<T> : Iterable<T> {

    private var first: ChainNode<T>? = null
    private var last: ChainNode<T>? = null

    internal data class ChainNode<R>(var value: R, var link: ChainNode<R>? = null)

    val size: Int
        get() {
            var count = 0
            var pointer = first
            while (pointer != null) {
                pointer = pointer.link
                count++
            }
            return count
        }

    operator fun contains(element: T): Boolean {
        var pointer = first
        while (pointer != null)
            if (pointer.value == element)
                return true
            else
                pointer = pointer.link
        return false
    }

    fun containsAll(elements: Collection<T>): Boolean {
        val toFind: MutableSet<T> = HashSet(elements)
        var pointer = first
        while (pointer != null && toFind.isNotEmpty()) {
            toFind.remove(pointer.value)
            pointer = pointer.link
        }
        return toFind.isEmpty()
    }

    operator fun get(index: Int): T {
        var count = index
        var pointer = first
        while (count-- != 0 && pointer != null)
            pointer = pointer.link
        return pointer?.value ?: throw IndexOutOfBoundsException()
    }

    fun indexOf(element: T): Int {
        var count = 0
        var pointer = first
        while (pointer != null) {
            if (pointer.value == element)
                return count
            pointer = pointer.link
            count++
        }
        return -1
    }

    fun isEmpty(): Boolean = first == null

    class ChainIterator<T> internal constructor(private var now: ChainNode<T>?) : Iterator<T> {

        override fun hasNext(): Boolean = now?.link != null

        override fun next(): T = now?.value.also { now = now?.link } ?: throw Throwable("No next")

    }

    override fun iterator(): Iterator<T> {
        return ChainIterator(first)
    }

    fun lastIndexOf(element: T): Int {
        var find = -1
        var count = 0
        var pointer = first
        while (pointer != null) {
            if (pointer.value == element)
                find = count
            pointer = pointer.link
            count++
        }
        return find
    }

    fun add(element: T): Boolean {
        if (last == null) {
            ChainNode(element, null).let {
                first = it
                last = it
            }
        } else {
            last = ChainNode(element).also { last!!.link = it }
        }
        return true
    }

    fun add(index: Int, element: T) {
        if (index < 0)
            throw IndexOutOfBoundsException()

        if (index == 0) {
            first = ChainNode(element, first)
            if (first!!.link == null)
                last = first
            return
        }

        var count = index
        var pointer = first

        while (--count != 0 && pointer != null)
            pointer = pointer.link

        if (pointer == null)
            throw IndexOutOfBoundsException()

        pointer.link = ChainNode(element, pointer.link)
        if (pointer.link == null)
            last = pointer
    }

    private fun Collection<T>.makeChain(link: ChainNode<T>?): Pair<ChainNode<T>, ChainNode<T>> {
        val iterator = this.reversed().iterator()
        val end = ChainNode(iterator.next(), link)
        var head = end
        while (iterator.hasNext())
            head = ChainNode(iterator.next(), head)
        return head to end
    }

    fun addAll(index: Int, elements: Collection<T>): Boolean {
        if (index < 0)
            throw IndexOutOfBoundsException()

        if (elements.isEmpty())
            return true

        if (index == 0) {
            elements.makeChain(first).let {
                first = it.first
                if (it.second.link == null) // or last == null
                    last = it.second
            }
            return true
        }

        var count = index
        var pointer = first

        while (--count != 0 && pointer != null)
            pointer = pointer.link

        if (pointer == null)
            throw IndexOutOfBoundsException()

        elements.makeChain(pointer.link).let {
            pointer.link = it.first
            if (it.second.link == null)
                last = it.second
        }
        return true
    }

    fun addAll(elements: Collection<T>): Boolean {
        if (elements.isEmpty())
            return true

        if (last == null) {
            elements.makeChain(null).let {
                first = it.first
                last = it.second
            }
        } else {
            elements.makeChain(null).let {
                last!!.link = it.first
                last = it.second
            }
        }
        return true
    }

    fun clear() {
        first = null
        last = null
    }

//    override fun listIterator(): MutableListIterator<T> {
//        TO DO("not implemented") //To change body of created functions use File | Settings | File Templates.
//    }

//    override fun listIterator(index: Int): MutableListIterator<T> {
//        TO DO("not implemented") //To change body of created functions use File | Settings | File Templates.
//    }

    fun remove(element: T): Boolean {
        if (first == null)
            return false

        var pointer = first
        var pre: ChainNode<T>? = null
        while (pointer != null) {
            if (pointer.value == element) {
                if (pre != null)
                    pre.link = pointer.link
                else
                    first = first!!.link
                return true
            }
            pre = pointer
            pointer = pointer.link
        }
        return false
    }

//    fun removeAll(elements: Collection<T>): Boolean {
//        TO DO("not implemented") //To change body of created functions use File | Settings | File Templates.
//    }

    fun removeAt(index: Int): T {
        if (index < 0 || first == null)
            throw IndexOutOfBoundsException()

        var count = index
        var pointer = first
        var pre: ChainNode<T>? = null
        while (count-- != 0 && pointer != null) {
            pre = pointer
            pointer = pointer.link
        }

        if (pointer == null)
            throw IndexOutOfBoundsException()

        return pointer.value.also {
            if (pre == null)
                first = first!!.link
            else
                pre.link = pointer.link
        }
    }

//    fun retainAll(elements: Collection<T>): Boolean {
//        TO DO("not implemented") //To change body of created functions use File | Settings | File Templates.
//    }

    operator fun set(index: Int, element: T): T {
        if (index < 0 || first == null)
            throw IndexOutOfBoundsException()
        var count = index
        var pointer = first
        while (count-- != 0 && pointer != null)
            pointer = pointer.link

        if (pointer == null)
            throw IndexOutOfBoundsException()

        return pointer.value.also { pointer.value = element }
    }

//    override fun subList(fromIndex: Int, toIndex: Int): MutableList<T> {
//        TO DO("not implemented") //To change body of created functions use File | Settings | File Templates.
//    }

    fun reversed() {
        var pre: ChainNode<T>? = null
        var now: ChainNode<T>? = first
        while (now != null) {
            now.link = pre
            pre = now
            now = now.link
        }
        first = last.also { last = first }
    }
}
