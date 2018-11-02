package ds_10_25.maze

enum class Direction(val modX: Int, val modY: Int) {
    N(0, 1),
    S(0, -1),
    E(1, 0),
    W(-1, 0),
    NE(N, E),
    NW(N, W),
    SE(S, E),
    SW(S, W),
    ;
    val oppositeWay : Direction by lazy {
        values().find { it.modX == -this.modX && it.modY == -this.modY }!!
    }
    constructor(d1: Direction, d2: Direction) : this(d1.modX + d2.modX, d1.modY + d2.modY)
}