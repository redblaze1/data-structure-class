package ds_10_25.maze

import java.util.*
import kotlin.collections.HashSet
import kotlin.math.pow
import kotlin.math.sqrt
import java.util.HashMap



class Map(val mapData: Array<Array<Int>>) {
    // TODO init with 2D array<Int>

    //    fun findFastestPath(start: Node, goal: Node): List<Node> {
//
//    }
//
    fun findPath(start: Node, goal: Node): List<Node>? {
        // AStar imp
        // check start and goal !is wall
        if (start.isWall() || goal.isWall())
            return null

        val closeSet: MutableSet<Node> = HashSet()
        val openSet: MutableSet<Node> = HashSet()

        val came_from : MutableMap<Node, Path> = HashMap()
        val g_score : MutableMap<Node, Int> = HashMap()
        val h_score : MutableMap<Node, Double> = HashMap()
        val f_score : MutableMap<Node, Double> = HashMap()

        fun Node.get_h(): Double = sqrt((x - goal.x).pow(2) + (y - goal.y).pow(2))
        fun Set<Node>.findMinFscore() : Node = this.minBy { f_score[it]!! }!!
        fun MutableMap<Node, Path>.reconstructPath(): List<Node> {
            kotlin.TODO()
        }

        openSet.add(start)
        g_score[start] = 0
        h_score[start] = start.get_h()
        f_score[start] = h_score[start]!!

        while(openSet.isNotEmpty()) {
            val x = openSet.findMinFscore()

            if (x == goal)
                return came_from.reconstructPath()
        }
        TODO()
    }

    private fun Node.canWalk(direction: Direction): Boolean {
        val node = this + direction
        return when {
            // check map board
            node.y >= mapData.size -> false
            node.x >= mapData[node.y].size -> false
            // check wall
            mapData[node.y][node.x] == 1 -> false
            else -> true
        }
    }

    private fun Node.isWall(): Boolean = mapData[this.y][this.x] == 1

    private fun Node.walkableDirection() : Set<Direction> = Direction.values().filter { this.canWalk(it) }.toSet()

    private fun Node.walkToNextBranch(direction: Direction): Path {
        val path = Path(this)
        // check safe
        if (!this.canWalk(direction))
            return path

        var head = path.walk(direction)
        var dir = direction
        while (true) {
            Direction.values().asSequence().dropWhile { it == dir.oppositeWay || !head.canWalk(it) }.let {
                if (it.count() != 1)
                    return path
                dir = it.first()
                head = path.walk(dir)
            }
        }

    }

    private class Path(start: Node) {
        private val path: Stack<Node> = Stack()

        init {
            path.add(start)
        }

        fun walk(direction: Direction): Node = path.peek().move(direction).also { path.push(it) }

        fun walk(to: Node): Node = to.also { path.push(it) }

        fun back() {
            path.pop()
        }

        fun pathLength(): Int = path.size - 1

        fun finish(): List<Node> = path.toList()
    }
}

fun Int.pow(n: Int): Double = this.toDouble().pow(n)