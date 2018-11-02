package ds_10_25.maze

data class Node(val x: Int, val y: Int) {

    operator fun plus(direction: Direction): Node = Node(x + direction.modX, y + direction.modY)

    fun move(direction: Direction): Node = this + direction

}
