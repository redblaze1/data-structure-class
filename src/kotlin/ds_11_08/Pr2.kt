package ds_11_08

fun main(args: Array<String>) {
    val lista = ChainList<Double>().apply {
        add(1.0)
        add(2.0)
        add(3.4)
        add(4.7)
    }


    val listb = ChainList<Double>().apply {
        add(500.0)
        add(60.6)
        add(70.0)
        add(80.0)
    }

    lista.concatenate(listb)

    println(lista.toString())
}