<center><h1>E. Little Girl and Maximum Sum</h1></center>
    
<p><center>Ограничение по времени на тест: <b>1 second</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 megabytes</b></center></p>

<h2>Условие:</h2>

<div><p>The little girl loves the problems on array queries very much.</p><p>One day she came across a rather well-known problem: you've got an array of $n$ elements (the elements of the array are indexed starting from 1); also, there are $q$ queries, each one is defined by a pair of integers $l_i$, $r_i$ $(1 \le l_i \le r_i \le n)$. You need to find for each query the sum of elements of the array with indexes from $l_i$ to $r_i$, inclusive.</p><p>The little girl found the problem rather boring. She decided to reorder the array elements before replying to the queries in a way that makes the sum of query replies maximum possible. Your task is to find the value of this maximum sum.</p></div>

<h2>Решение:</h2>

Время: $O(n\log n)$

Память: $O(n)$

[Код](solution.cpp)

Реализация RSQ с помощью дерева отрезков, в котором я считаю сколько раз число было использованно. Максимизирую сумму, выдавая самые большие числа ~ самым частым

<h2>Входные данные:</h2>

<p>The first line contains two space-separated integers $n$ ($1 \le n \le 2\cdot10^5$) and $q$ ($1 \le q \le 2\cdot10^5$) — the number of elements in the array and the number of queries, correspondingly.</p>

<h2>Выходные данные:</h2>

<p>In a single line print, a single integer — the maximum sum of query replies after the array elements are reordered.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>3 3<br/>5 3 2<br/>1 2<br/>2 3<br/>1 3<br/></pre>

Выход:

<pre>25<br/></pre>