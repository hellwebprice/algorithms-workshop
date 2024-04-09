<center><h1>D. Students and Shoelaces</h1></center>
    
<p><center>Ограничение по времени на тест: <b>2 seconds</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 megabytes</b></center></p>

<h2>Условие:</h2>

<div><p>Anna and Maria are in charge of the math club for junior students. When the club gathers together, the students behave badly. They've brought lots of shoe laces to the club and got tied with each other. Specifically, each string ties together two students. Besides, if two students are tied, then the lace connects the first student with the second one as well as the second student with the first one.</p><p>To restore order, Anna and Maria do the following. First, for each student Anna finds out what other students he is tied to. If a student is tied to exactly one other student, Anna reprimands him. Then Maria gathers in a single group <span class="tex-font-style-bf">all</span> the students who have been just reprimanded. She kicks them out from the club. This group of students immediately leaves the club. These students takes with them the laces that used to tie them. Then again for every student Anna finds out how many other students he is tied to and so on. And they do so until Anna can reprimand at least one student.</p><p>Determine how many groups of students will be kicked out of the club.</p></div>

<h2>Решение:</h2>

Время: $O(n\log m)$

Память: $O(n)$

[Код](solution.cpp)

Реализовал наивный алгоритм, потому что $n$ очень маленькое

<h2>Входные данные:</h2>

<p>The first line contains two integers <span class="tex-span"><i>n</i></span> and <span class="tex-span"><i>m</i></span> — the initial number of students and laces (<img align="middle" class="tex-formula" src="https://espresso.codeforces.com/c0f4b517c1454fa53ac04e10a468e8c02ed79905.png" style="max-width: 100.0%;max-height: 100.0%;"/>). The students are numbered from <span class="tex-span">1</span> to <span class="tex-span"><i>n</i></span>, and the laces are numbered from <span class="tex-span">1</span> to <span class="tex-span"><i>m</i></span>. Next <span class="tex-span"><i>m</i></span> lines each contain two integers <span class="tex-span"><i>a</i></span> and <span class="tex-span"><i>b</i></span> — the numbers of students tied by the <span class="tex-span"><i>i</i></span>-th lace (<span class="tex-span">1 ≤ <i>a</i>, <i>b</i> ≤ <i>n</i>, <i>a</i> ≠ <i>b</i></span>). It is guaranteed that no two students are tied with more than one lace. No lace ties a student to himself.</p>

<h2>Выходные данные:</h2>

<p>Print the single number — the number of groups of students that will be kicked out from the club.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>3 3<br/>1 2<br/>2 3<br/>3 1<br/></pre>

Выход:

<pre>0<br/></pre>