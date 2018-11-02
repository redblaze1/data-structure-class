package ds_11_01

class Chain<T : Number> {

    private data class ChainNode<R>(val link: ChainNode<R>?, val Data: R)

    private var first: ChainNode<T>? = null

    fun addFirst(value: T) {
        first = ChainNode(first, value)
    }

    fun traversal() {
        var tmp: ChainNode<T>? = first
        while (tmp != null) {
            print("${tmp.Data.toString()}\t")
            tmp = tmp.link
        }
        println()
    }

    private fun ChainNode<T>.toList(): List<T> {
        val list = mutableListOf<T>()
        var tmp: ChainNode<T>? = first
        while (tmp != null)
            tmp = tmp.also { list.add(it.Data) }.link
        return list
    }

    companion object {
        fun Chain<Int>.sum(): Int = this.first?.toList()?.sum() ?: 0
        fun Chain<Float>.sum(): Float = this.first?.toList()?.sum() ?: 0F
        fun Chain<Double>.sum(): Double = this.first?.toList()?.sum() ?: 0.0
        fun Chain<Int>.average(): Int = this.first?.toList()?.average()?.toInt() ?: 0
        fun Chain<Float>.average(): Float = this.first?.toList()?.average()?.toFloat() ?: 0F
        fun Chain<Double>.average(): Double = this.first?.toList()?.average() ?: 0.0
    }
}
