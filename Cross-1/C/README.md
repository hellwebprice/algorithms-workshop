<center><h1>C. Building an Aquarium</h1></center>
    
<p><center>Ограничение по времени на тест: <b>2 seconds</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 megabytes</b></center></p>

<h2>Условие:</h2>

<div><p>You love fish, that's why you have decided to build an aquarium. You have a piece of coral made of $n$ columns, the $i$-th of which is $a_i$ units tall. Afterwards, you will build a tank around the coral as follows: </p><ul> <li> Pick an integer $h \geq 1$ — the <span class="tex-font-style-it">height</span> of the tank. Build walls of height $h$ on either side of the tank. </li><li> Then, fill the tank up with water so that the height of each column is $h$, unless the coral is taller than $h$; then no water should be added to this column. </li></ul> For example, with $a=[3,1,2,4,6,2,5]$ and a height of $h=4$, you will end up using a total of $w=8$ units of water, as shown. <center> <img class="tex-graphics" src="https://espresso.codeforces.com/5a69329b8d22a26c9f4de9eb96076db3e8c712ba.png" style="max-width: 100.0%;max-height: 100.0%;"/> </center> You can use at most $x$ units of water to fill up the tank, but you want to build the biggest tank possible. What is the largest value of $h$ you can select?</div>

<h2>Решение:</h2>

Время: $O(n\log n)$

Память: $O(1)$

[Код](solution.cpp)

Сортирую куски коралла и с помощью бинарного поиска пытаюсь найти подходящую высоту

<h2>Входные данные:</h2>

<p>The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.</p>

<h2>Выходные данные:</h2>

<p>For each test case, output a single positive integer $h$ ($h \geq 1$) — the maximum height the tank can have, so you need at most $x$ units of water to fill up the tank.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>
<div class="test-example-line test-example-line-even test-example-line-0">5</div><div class="test-example-line test-example-line-odd test-example-line-1">7 9</div><div class="test-example-line test-example-line-odd test-example-line-1">3 1 2 4 6 2 5</div><div class="test-example-line test-example-line-even test-example-line-2">3 10</div><div class="test-example-line test-example-line-even test-example-line-2">1 1 1</div><div class="test-example-line test-example-line-odd test-example-line-3">4 1</div><div class="test-example-line test-example-line-odd test-example-line-3">1 4 3 4</div><div class="test-example-line test-example-line-even test-example-line-4">6 1984</div><div class="test-example-line test-example-line-even test-example-line-4">2 6 5 9 1 8</div><div class="test-example-line test-example-line-odd test-example-line-5">1 1000000000</div><div class="test-example-line test-example-line-odd test-example-line-5">1</div></pre>

Выход:

<pre>
4
4
2
335
1000000001
</pre>