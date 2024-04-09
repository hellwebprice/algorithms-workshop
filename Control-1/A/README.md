<center><h1>A. Recent Actions</h1></center>
    
<p><center>Ограничение по времени на тест: <b>1 second</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 megabytes</b></center></p>

<h2>Условие:</h2>

<div><p>On Codeforces the "Recent Actions" field shows the last $n$ posts with recent actions.</p><p>Initially, there are posts $1, 2, \ldots, n$ in the field (this is in order from top to down). Also there are infinitely many posts not in the field, numbered with integers $n + 1, n + 2, \ldots$.</p><p>When recent action happens in the post $p$:</p><ul> <li> If it is in the "Recent Actions" field, it moves from its position to the top position. </li><li> Otherwise, it is added to the top position, and the post on the down position is removed from the "Recent Actions" field. </li></ul><p>You know, that the next $m$ recent actions will happen in the posts $p_1, p_2, \ldots, p_m$ ($n + 1 \leq p_i \leq n + m$) in the moments of time $1, 2, \ldots, m$. <span class="tex-font-style-bf">Note</span>, that recent actions only happen with posts with numbers $\geq n + 1$.</p><p>For each post $i$ ($1 \leq i \leq n$), find the first time it will be removed from the "Recent Actions" field or say, that it won't be removed.</p></div>

<h2>Решение:</h2>

Время: $O(m\log n)$

Память: $O(n)$

[Код](solution.cpp)

Поддерживаю множество удалённых. Если очередной индекс был удалён, то пишу в какой момент это случилось в ответ

<h2>Входные данные:</h2>

<p>The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Descriptions of test cases follow.</p>

<h2>Выходные данные:</h2>

<p>For each test case print $n$ integers $t_1, t_2, \ldots, t_n$, where $t_i=-1$ if the post $i$ won't be removed or $t_i$ equals to the first moment of time the post $i$ will be removed ($1 \leq t_i \leq m$).</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>
<div class="test-example-line test-example-line-even test-example-line-0">10</div><div class="test-example-line test-example-line-odd test-example-line-1">1 1</div><div class="test-example-line test-example-line-odd test-example-line-1">2</div><div class="test-example-line test-example-line-even test-example-line-2">3 2</div><div class="test-example-line test-example-line-even test-example-line-2">5 4</div><div class="test-example-line test-example-line-odd test-example-line-3">4 5</div><div class="test-example-line test-example-line-odd test-example-line-3">5 9 9 5 7</div><div class="test-example-line test-example-line-even test-example-line-4">5 5</div><div class="test-example-line test-example-line-even test-example-line-4">6 7 8 9 10</div><div class="test-example-line test-example-line-odd test-example-line-5">3 4</div><div class="test-example-line test-example-line-odd test-example-line-5">4 4 4 4</div><div class="test-example-line test-example-line-even test-example-line-6">4 4</div><div class="test-example-line test-example-line-even test-example-line-6">5 5 6 6</div><div class="test-example-line test-example-line-odd test-example-line-7">3 5</div><div class="test-example-line test-example-line-odd test-example-line-7">4 5 5 5 4</div><div class="test-example-line test-example-line-even test-example-line-8">4 20</div><div class="test-example-line test-example-line-even test-example-line-8">5 5 24 24 24 5 6 7 8 9 10 12 13 14 15 16 17 18 19 20</div><div class="test-example-line test-example-line-odd test-example-line-9">5 7</div><div class="test-example-line test-example-line-odd test-example-line-9">7 8 7 11 7 12 10</div><div class="test-example-line test-example-line-even test-example-line-10">6 7</div><div class="test-example-line test-example-line-even test-example-line-10">8 11 7 8 8 8 12</div></pre>

Выход:

<pre>
1 
-1 2 1 
-1 5 2 1 
5 4 3 2 1 
-1 -1 1 
-1 -1 3 1 
-1 2 1 
8 7 3 1 
7 6 4 2 1 
-1 -1 7 3 2 1 
</pre>