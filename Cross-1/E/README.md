<center><h1>E. Split Sort</h1></center>
    
<p><center>Ограничение по времени на тест: <b>1 second</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 megabytes</b></center></p>

<h2>Условие:</h2>

<div><p>You are given a permutation$^{\dagger}$ $p_1, p_2, \ldots, p_n$ of integers $1$ to $n$.</p><p>You can change the current permutation by applying the following operation several (possibly, zero) times:</p><ul> <li> choose some $x$ ($2 \le x \le n$); </li><li> create a new permutation by: <ul> <li> first, writing down all elements of $p$ that are less than $x$, without changing their order; </li><li> second, writing down all elements of $p$ that are greater than or equal to $x$, without changing their order; </li></ul> </li><li> replace $p$ with the newly created permutation. </li></ul><p>For example, if the permutation used to be $[6, 4, 3, 5, 2, 1]$ and you choose $x = 4$, then you will first write down $[3, 2, 1]$, then append this with $[6, 4, 5]$. So the initial permutation will be replaced by $[3, 2, 1, 6, 4, 5]$.</p><p>Find the minimum number of operations you need to achieve $p_i = i$ for $i = 1, 2, \ldots, n$. We can show that it is always possible to do so.</p><p>$^{\dagger}$ A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).</p></div>

<h2>Решение:</h2>

Время: $O(n\log n)$

Память: $O(1)$

[Код](solution.cpp)

Считаю количество инверсий

<h2>Входные данные:</h2>

<p>Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). The description of the test cases follows.</p>

<h2>Выходные данные:</h2>

<p>For each test case, output the answer on a separate line.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>
<div class="test-example-line test-example-line-even test-example-line-0">5</div><div class="test-example-line test-example-line-odd test-example-line-1">1</div><div class="test-example-line test-example-line-odd test-example-line-1">1</div><div class="test-example-line test-example-line-even test-example-line-2">2</div><div class="test-example-line test-example-line-even test-example-line-2">2 1</div><div class="test-example-line test-example-line-odd test-example-line-3">6</div><div class="test-example-line test-example-line-odd test-example-line-3">6 4 3 5 2 1</div><div class="test-example-line test-example-line-even test-example-line-4">3</div><div class="test-example-line test-example-line-even test-example-line-4">3 1 2</div><div class="test-example-line test-example-line-odd test-example-line-5">19</div><div class="test-example-line test-example-line-odd test-example-line-5">10 19 7 1 17 11 8 5 12 9 4 18 14 2 6 15 3 16 13</div></pre>

Выход:

<pre>
0
1
4
1
7
</pre>