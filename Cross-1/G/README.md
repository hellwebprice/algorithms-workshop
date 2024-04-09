<center><h1>G. Money Sharing</h1></center>
    
<p><center>Ограничение по времени на тест: <b>1.75 seconds</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 mebibytes</b></center></p>

<h2>Условие:</h2>

<div><p>It becomes more and more popular to share something instead of buying it.</p><p>One of the promising sharing systems is money sharing. There are numerous approaches to it, but we will deal with the one when there is a public entry point where money may be borrowed or returned free of charge. No need to say that the system quickly rose to be extremely popular.</p><p>Due to such popularity, it is hard to keep the system stable, so one has to request borrowing some money several days in advance. You are to develop an automatic managing system for money sharing. Consider a single day: during the day, you have $n$ requests for money lending, and there are also $m$ resupplies scheduled. They both may be described by non-zero integer $x$. Initially, the entry point has no money. On event described by $x$:</p><ul> <li> If $x&gt;0$, then it is a resupply, so the amount of money in the entry point is increased by $x$. </li><li> If $x&lt;0$, then it is a request to borrow the amount of money equal to $|x|$. If the request is approved, then the amount of money in the entry point is decreased by $|x|$. Otherwise, it does not change. </li></ul><p>Unfortunately, it is not always possible to satisfy all requests, because the entry point may eventually end up not having enough money to lend, so some requests may have to be declined. Your task is, given the description of all requests and resupplies, to choose for each request whether to accept or decline it, so that the entry point always has enough money to satisfy the accepted requests. If there are multiple possible answers, you should choose the one having the minimum possible number of requests declined. If there are still multiple possible answers, find any one of them.</p></div>

<h2>Решение:</h2>

Время: $O(m\log m + n\log n)$

Память: $O(n + m)$

[Код](solution.cpp)

Сортирую запросы и выдаю очередной запрос, если на момент этого запроса в копилке хватало денег. Количество денег в копилке поддерживается с помощью словаря

<h2>Входные данные:</h2>

<p>The first line of input contains two integers $n$ and $m$ ($1 \leq n, m \leq 10^5$).</p>

<h2>Выходные данные:</h2>

<p>Output your answer in $n+m$ lines.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>
4 1
+5
-3
-2
-1
-1
</pre>

Выход:

<pre>
resupplied
declined
approved
approved
approved
</pre>