<center><h1>A. News Distribution</h1></center>
    
<p><center>Ограничение по времени на тест: <b>2 seconds</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 megabytes</b></center></p>

<h2>Условие:</h2>

<div><p>In some social network, there are $n$ users communicating with each other in $m$ groups of friends. Let's analyze the process of distributing some news between users.</p><p>Initially, some user $x$ receives the news from some source. Then he or she sends the news to his or her friends (two users are friends if there is at least one group such that both of them belong to this group). Friends continue sending the news to their friends, and so on. The process ends when there is no pair of friends such that one of them knows the news, and another one doesn't know.</p><p>For each user $x$ you have to determine what is the number of users that will know the news if initially only user $x$ starts distributing it. </p></div>

<h2>Решение:</h2>

Время: $O(m)$

Память: $O(n)$

[Код](solution.cpp)

С помощью DSU разделяю людей на классы эквивалетности. Для каждого человека вывожу размер класса, к которому он принадлежит

<h2>Входные данные:</h2>

<p>The first line contains two integers $n$ and $m$ ($1 \le n, m \le 5 \cdot 10^5$) — the number of users and the number of groups of friends, respectively.</p>

<h2>Выходные данные:</h2>

<p>Print $n$ integers. The $i$-th integer should be equal to the number of users that will know the news if user $i$ starts distributing it.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>
7 5
3 2 5 4
0
2 1 2
1 1
2 6 7
</pre>

Выход:

<pre>
4 4 1 4 4 2 2 </pre>