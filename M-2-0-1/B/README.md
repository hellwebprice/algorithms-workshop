<center><h1>B. Multiset</h1></center>
    
<p><center>Ограничение по времени на тест: <b>3.0 s</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 MB</b></center></p>

<h2>Условие:</h2>

<div><p><span class="tex-font-style-bf">Note that the memory limit is unusual.</span></p><p>You are given a multiset consisting of $n$ integers. You have to process queries of two types:</p><ul> <li> add integer $k$ into the multiset; </li><li> find the $k$-th order statistics in the multiset and remove it. </li></ul><p>$k$-th order statistics in the multiset is the $k$-th element in the sorted list of all elements of the multiset. For example, if the multiset contains elements $1$, $4$, $2$, $1$, $4$, $5$, $7$, and $k = 3$, then you have to find the $3$-rd element in $[1, 1, 2, 4, 4, 5, 7]$, which is $2$. If you try to delete an element which occurs multiple times in the multiset, only one occurence is removed. </p><p>After processing all queries, print <span class="tex-font-style-bf">any</span> number belonging to the multiset, or say that it is empty.</p></div>

<h2>Решение:</h2>

Время: $O(n\log n)$

Память: $O(n)$

[Код](solution.cpp)

Создаю дерево фенвика над массивом, в котором хранится количество раз сколько элемент добавлялся в мультимножество. После этого также за $O(\log n)$ ищу $k$-ую порядковую статистику средствами дерева Фенвика

<h2>Входные данные:</h2>

<p>The first line contains two integers $n$ and $q$ ($1 \le n, q \le 10^6$) — the number of elements in the initial multiset and the number of queries, respectively.</p>

<h2>Выходные данные:</h2>

<p>If the multiset is empty after all queries, print $0$.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>
5 5
1 2 3 4 5
-1 -1 -1 -1 -1
</pre>

Выход:

<pre>
0
</pre>