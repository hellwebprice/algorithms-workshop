<center><h1>A. Свапнем</h1></center>
    
<p><center>Ограничение по времени на тест: <b>2 секунды</b></center></p>

<p><center>Ограничение по памяти на тест: <b>64 мегабайта</b></center></p>

<h2>Условие:</h2>

<div><p>Все положительные целые числа записали в бесконечный массив: $N[i] = i$, $i \geq 1$. С массивом разрешено выполнять операцию $\texttt{swap}(a, b)$, которая меняет элементы массива со значениями $a$ и $b$ местами, а в качестве результата возвращает расстояние между этими элементами — модуль разности их индексов.</p><p>Нужно для последовательности операций $\texttt{swap}$ на входе записать последовательность значений операций.</p></div>

<h2>Решение:</h2>

Время: $O(n\log n)$

Память: $O(n)$

[Код](solution.cpp)

Храню числа из задачи в словаре, что помогает выиграть по памяти

<h2>Входные данные:</h2>

<p>$n$ — количество операций $1 \leq n \leq 200\ 000$.</p>

<h2>Выходные данные:</h2>

<p>Результаты операций по одной на каждую строку.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>
4
1 4
1 3
4 5
1 4
</pre>

Выход:

<pre>
3
1
4
2
</pre>