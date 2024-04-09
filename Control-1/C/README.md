<center><h1>C. Sasha and Array Coloring</h1></center>
    
<p><center>Ограничение по времени на тест: <b>1 second</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 megabytes</b></center></p>

<h2>Условие:</h2>

<div><p>Sasha found an array $a$ consisting of $n$ integers and asked you to paint elements.</p><p>You have to paint each element of the array. You can use as many colors as you want, but each element should be painted into exactly one color, and for each color, there should be at least one element of that color.</p><p>The <span class="tex-font-style-it">cost</span> of one color is the value of $\max(S) - \min(S)$, where $S$ is the sequence of elements of that color. The <span class="tex-font-style-it">cost</span> of the whole coloring is the <span class="tex-font-style-bf">sum</span> of costs over all colors.</p><p>For example, suppose you have an array $a = [\color{red}{1}, \color{red}{5}, \color{blue}{6}, \color{blue}{3}, \color{red}{4}]$, and you painted its elements into two colors as follows: elements on positions $1$, $2$ and $5$ have color $1$; elements on positions $3$ and $4$ have color $2$. Then:</p><ul> <li> the cost of the color $1$ is $\max([1, 5, 4]) - \min([1, 5, 4]) = 5 - 1 = 4$; </li><li> the cost of the color $2$ is $\max([6, 3]) - \min([6, 3]) = 6 - 3 = 3$; </li><li> the total cost of the coloring is $7$. </li></ul><p>For the given array $a$, you have to calculate the <span class="tex-font-style-bf">maximum</span> possible cost of the coloring.</p></div>

<h2>Решение:</h2>

Время: $O(n\log n)$

Память: $O(1)$

[Код](solution.cpp)

Сортирую массив и раскрашиваю $i$-ый и $n - i$-ый элемент в один цвет

<h2>Входные данные:</h2>

<p>The first line contains one integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.</p>

<h2>Выходные данные:</h2>

<p>For each test case output the maximum possible cost of the coloring.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>
<div class="test-example-line test-example-line-even test-example-line-0">6</div><div class="test-example-line test-example-line-odd test-example-line-1">5</div><div class="test-example-line test-example-line-odd test-example-line-1">1 5 6 3 4</div><div class="test-example-line test-example-line-even test-example-line-2">1</div><div class="test-example-line test-example-line-even test-example-line-2">5</div><div class="test-example-line test-example-line-odd test-example-line-3">4</div><div class="test-example-line test-example-line-odd test-example-line-3">1 6 3 9</div><div class="test-example-line test-example-line-even test-example-line-4">6</div><div class="test-example-line test-example-line-even test-example-line-4">1 13 9 3 7 2</div><div class="test-example-line test-example-line-odd test-example-line-5">4</div><div class="test-example-line test-example-line-odd test-example-line-5">2 2 2 2</div><div class="test-example-line test-example-line-even test-example-line-6">5</div><div class="test-example-line test-example-line-even test-example-line-6">4 5 2 2 3</div></pre>

Выход:

<pre>
7
0
11
23
0
5
</pre>