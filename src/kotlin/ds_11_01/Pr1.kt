package ds_11_01

import java.util.*

fun main(args: Array<String>) {

    while (true) {
        val input = readLine() ?: break

        val stack = Stack<Int>()

        // split input and get output
        input.map(Char::toString).forEach { token ->
            when (token) {
                "$" -> return@forEach
                "+" -> with(stack) { push(pop().let { pop() + it }) }
                "-" -> with(stack) { push(pop().let { pop() - it }) }
                "*" -> with(stack) { push(pop().let { pop() * it }) }
                "/" -> with(stack) { push(pop().let { pop() / it }) }
                "%" -> with(stack) { push(pop().let { pop() % it }) }
                else -> stack.push(token.toInt())
            }
        }

        println("$input = ${stack.first()}")

    }

}