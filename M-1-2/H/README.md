<center><h1>H. Same Differences</h1></center>
    
<p><center>Ограничение по времени на тест: <b>2 seconds</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 megabytes</b></center></p>

<h2>Условие:</h2>

<div><p>You are given an array $a$ of $n$ integers. Count the number of pairs of indices $(i, j)$ such that $i &lt; j$ and $a_j - a_i = j - i$.</p></div>

<h2>Решение:</h2>

Время: $O(n\log n)$

Память: $O(n)$

[Код](solution.cpp)

Делаю словарик с ответами для каждого $j$. Их сумма и будет ответом

<h2>Входные данные:</h2>

<p>The first line contains one integer $t$ ($1 \le t \le 10^4$). Then $t$ test cases follow.</p>

<h2>Выходные данные:</h2>

<p>For each test case output the number of pairs of indices $(i, j)$ such that $i &lt; j$ and $a_j - a_i = j - i$.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>
4
6
3 5 1 4 6 6
3
1 2 3
4
1 3 3 4
6
1 6 3 4 5 6
</pre>

Выход:

<pre>
1
3
3
10
</pre>