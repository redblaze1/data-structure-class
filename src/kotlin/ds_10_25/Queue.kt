package ds_10_25

import java.io.IOException

class Queue<T>(val capacity: Int) {
    private val data: Array<Any?> = Array(capacity) {}
    private var front: Int = 0
    private var rear: Int = capacity - 1
    private var full : Boolean = false

    @Suppress("UNCHECKED_CAST")
    fun pop(): T? =
            if (front == rear.next() && !full)
                null
            else
                data[front.also { front = front.next() ; full = false}] as? T

    fun push(element: T) {
        if (rear.next() == front && full)
            throw IOException("Queue is full!!")
        rear = rear.next()
        data[rear] = element

        if (rear.next() == front)
            full = true
    }

    fun isFull(): Boolean = full

    fun isEmpty(): Boolean = !full

    private fun Int.next(): Int = (this + 1) % capacity

}