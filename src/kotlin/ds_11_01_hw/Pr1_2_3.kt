package ds_11_01_hw

import ds_11_01_hw.TokenType.*
import ds_11_01_hw.TokenType.Number
import java.util.*
import kotlin.collections.ArrayList

enum class TokenType(val isOperator: Boolean, val priority: Byte = 0) {
    End(false),
    Plus(true, 1),
    Minus(true, 1),
    Times(true, 2),
    Div(true, 2),
    Rem(true, 1),
    BrStart(false),
    BrEnd(false),
    Number(false)
}

open class Token(val type: TokenType) {
    companion object {
        fun parseToken(str: String): Token = when (str) {
            "$" -> Token(End)
            "+" -> Token(Plus)
            "-" -> Token(Minus)
            "*" -> Token(Times)
            "/" -> Token(Div)
            "%" -> Token(Rem)
            "(" -> Token(BrStart)
            ")" -> Token(BrEnd)
            else -> TokenInt(str.toInt())
        }
    }
}

class TokenInt(val value: Int) : Token(Number)

fun eavlInFix(input: String): List<Token> {
    // 1 + 2 * 3
    // 1 2 3 * +
    val stack = Stack<Token>()
    val list: MutableList<Token> = ArrayList()
    input.toTokens().forEach {
        when {
            it.type == End -> {
                return@forEach
            }
            it.type == BrStart -> stack.push(it)
            it.type.isOperator -> {
                while (stack.isNotEmpty() && stack.peek().type.priority >= it.type.priority)
                    list.add(stack.pop())
                stack.push(it)
            }
            it.type == BrEnd -> {
                while (stack.isNotEmpty() && stack.peek().type != BrStart)
                    list.add(stack.pop())
                stack.pop()
            }
            else -> {
                list.add(it)
            }
        }
    }
    while (stack.isNotEmpty())
        list.add(stack.pop())
    return list
}

fun String.toTokens(): List<Token> = this.splitToSequence(",", " ").filter { it.isNotBlank() }.map(Token.Companion::parseToken).toList()

fun postFix(tokens: List<Token>): Int {
    val stack = Stack<Int>()
    tokens.forEach { token ->
//        print(if (token is TokenInt) " ${token.value}" else " ${token.type}")
        when (token.type) {
            End -> return@forEach
            Plus -> with(stack) { push(pop().let { pop() + it }) }
            Minus -> with(stack) { push(pop().let { pop() - it }) }
            Times -> with(stack) { push(pop().let { pop() * it }) }
            Div -> with(stack) { push(pop().let { pop() / it }) }
            Rem -> with(stack) { push(pop().let { pop() % it }) }
            Number -> stack.push((token as TokenInt).value)
        }
    }
    return stack.first()
}

fun calculateInfix(input: String): Int = postFix(eavlInFix(input))

fun main(args: Array<String>) {

    while (true) {
        val input = readLine() ?: break
        println("$input = ${calculateInfix(input)}")
    }

}