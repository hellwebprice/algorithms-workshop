<center><h1>F. New Year Transportation</h1></center>
    
<p><center>Ограничение по времени на тест: <b>2 seconds</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 megabytes</b></center></p>

<h2>Условие:</h2>

<div><p>New Year is coming in Line World! In this world, there are <span class="tex-span"><i>n</i></span> cells numbered by integers from <span class="tex-span">1</span> to <span class="tex-span"><i>n</i></span>, as a <span class="tex-span">1 × <i>n</i></span> board. People live in cells. However, it was hard to move between distinct cells, because of the difficulty of escaping the cell. People wanted to meet people who live in other cells.</p><p>So, user tncks0121 has made a transportation system to move between these cells, to celebrate the New Year. First, he thought of <span class="tex-span"><i>n</i> - 1</span> positive integers <span class="tex-span"><i>a</i><sub class="lower-index">1</sub>, <i>a</i><sub class="lower-index">2</sub>, ..., <i>a</i><sub class="lower-index"><i>n</i> - 1</sub></span>. For every integer <span class="tex-span"><i>i</i></span> where <span class="tex-span">1 ≤ <i>i</i> ≤ <i>n</i> - 1</span> the condition <span class="tex-span">1 ≤ <i>a</i><sub class="lower-index"><i>i</i></sub> ≤ <i>n</i> - <i>i</i></span> holds. Next, he made <span class="tex-span"><i>n</i> - 1</span> portals, numbered by integers from 1 to <span class="tex-span"><i>n</i> - 1</span>. The <span class="tex-span"><i>i</i></span>-th (<span class="tex-span">1 ≤ <i>i</i> ≤ <i>n</i> - 1</span>) portal connects cell <span class="tex-span"><i>i</i></span> and cell <span class="tex-span">(<i>i</i> + <i>a</i><sub class="lower-index"><i>i</i></sub>)</span>, and one can travel from cell <span class="tex-span"><i>i</i></span> to cell <span class="tex-span">(<i>i</i> + <i>a</i><sub class="lower-index"><i>i</i></sub>)</span> using the <span class="tex-span"><i>i</i></span>-th portal. Unfortunately, one cannot use the portal backwards, which means one cannot move from cell <span class="tex-span">(<i>i</i> + <i>a</i><sub class="lower-index"><i>i</i></sub>)</span> to cell <span class="tex-span"><i>i</i></span> using the <span class="tex-span"><i>i</i></span>-th portal. It is easy to see that because of condition <span class="tex-span">1 ≤ <i>a</i><sub class="lower-index"><i>i</i></sub> ≤ <i>n</i> - <i>i</i></span> one can't leave the Line World using portals.</p><p>Currently, I am standing at cell <span class="tex-span">1</span>, and I want to go to cell <span class="tex-span"><i>t</i></span>. However, I don't know whether it is possible to go there. Please determine whether I can go to cell <span class="tex-span"><i>t</i></span> by only using the construted transportation system.</p></div>

<h2>Решение:</h2>

Время: $O(n)$

Память: $O(n)$

[Код](solution.cpp)

Ищу ответ через проход по массиву

<h2>Входные данные:</h2>

<p>The first line contains two space-separated integers <span class="tex-span"><i>n</i></span> (<span class="tex-span">3 ≤ <i>n</i> ≤ 3 × 10<sup class="upper-index">4</sup></span>) and <span class="tex-span"><i>t</i></span> (<span class="tex-span">2 ≤ <i>t</i> ≤ <i>n</i></span>) — the number of cells, and the index of the cell which I want to go to.</p>

<h2>Выходные данные:</h2>

<p>If I can go to cell <span class="tex-span"><i>t</i></span> using the transportation system, print "<span class="tex-font-style-tt">YES</span>". Otherwise, print "<span class="tex-font-style-tt">NO</span>".</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>8 4<br/>1 2 1 2 1 2 1<br/></pre>

Выход:

<pre>YES<br/></pre>
