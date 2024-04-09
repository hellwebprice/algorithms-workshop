<center><h1>C. Party</h1></center>
    
<p><center>Ограничение по времени на тест: <b>3 seconds</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 megabytes</b></center></p>

<h2>Условие:</h2>

<div><p>A company has <span class="tex-span"><i>n</i></span> employees numbered from <span class="tex-span">1</span> to <span class="tex-span"><i>n</i></span>. Each employee either has no immediate manager or exactly one immediate manager, who is another employee with a different number. An employee <span class="tex-span"><i>A</i></span> is said to be the <span class="tex-font-style-underline">superior</span> of another employee <span class="tex-span"><i>B</i></span> if at least one of the following is true:</p><ul> <li> Employee <span class="tex-span"><i>A</i></span> is the immediate manager of employee <span class="tex-span"><i>B</i></span> </li><li> Employee <span class="tex-span"><i>B</i></span> has an immediate manager employee <span class="tex-span"><i>C</i></span> such that employee <span class="tex-span"><i>A</i></span> is the superior of employee <span class="tex-span"><i>C</i></span>. </li></ul><p>The company will not have a managerial cycle. That is, there will not exist an employee who is the superior of his/her own immediate manager.</p><p>Today the company is going to arrange a party. This involves dividing all <span class="tex-span"><i>n</i></span> employees into several groups: every employee must belong to exactly one group. Furthermore, within any single group, there must not be two employees <span class="tex-span"><i>A</i></span> and <span class="tex-span"><i>B</i></span> such that <span class="tex-span"><i>A</i></span> is the superior of <span class="tex-span"><i>B</i></span>.</p><p>What is the minimum number of groups that must be formed?</p></div>

<h2>Решение:</h2>

Время: $O(n)$

Память: $O(n)$

[Код](solution.cpp)

С помощью DFS ищу максимальную высоту дерева, она и будет ответом на задачу

<h2>Входные данные:</h2>

<p>The first line contains integer <span class="tex-span"><i>n</i></span> (<span class="tex-span">1 ≤ <i>n</i> ≤ 2000</span>) — the number of employees.</p>

<h2>Выходные данные:</h2>

<p>Print a single integer denoting the minimum number of groups that will be formed in the party.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>5<br/>-1<br/>1<br/>2<br/>1<br/>-1<br/></pre>

Выход:

<pre>3<br/></pre>