package ds_10_04

fun main(args: Array<String>) {
    hanoi(5, "M", "W", "P")
}

fun hanoi(level: Int, start: String, goal: String, temp: String) {
    if (level == 1) {
        println("move one from $start to $goal")
    } else {
        hanoi(level - 1, start, temp, goal) // move all 1+ to temp
        println("move one from $start to $goal")
        hanoi(level - 1, temp, goal, start) // move all temp to goal
    }

}