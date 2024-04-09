<center><h1>D. Итеративное решение Диофантовых уравнений</h1></center>
    
<p><center>Ограничение по времени на тест: <b>2 секунды</b></center></p>

<p><center>Ограничение по памяти на тест: <b>64 мегабайта</b></center></p>

<h2>Условие:</h2>

<div><p>Требуется найти решение уравнения в целых числах вида <span class="tex-span"><i>ax</i> + <i>by</i> = <i>c</i></span>, где <span class="tex-span"><i>a</i></span>, <span class="tex-span"><i>b</i></span>, <span class="tex-span"><i>c</i></span> – целые входные параметры. </p><p>Реализуйте в решении итеративный расширенный алгоритм Евклида (мы отдельно проверим, что реализован именно этот алгоритм).</p></div>

<h2>Решение:</h2>

Время: $O(\log \min (a, b))$

Память: $O(1)$

[Код](solution.cpp)

Обычная итеративная реализация решения диофантового уравнения через расширенный алгоритм Евклида

<h2>Входные данные:</h2>

<p>В единственной строке записаны три целых числа <span class="tex-span"><i>a</i></span>, <span class="tex-span"><i>b</i></span> и <span class="tex-span"><i>c</i></span> (<span class="tex-span"> - 10<sup class="upper-index">7</sup> ≤ <i>a</i>, <i>b</i>, <i>c</i> ≤ 10<sup class="upper-index">7</sup></span>).</p>

<h2>Выходные данные:</h2>

<p>Выведите <span class="tex-font-style-tt">No</span>, если уравнение неразрешимо или если у него нет решений с положительным целым <span class="tex-span"><i>x</i></span>. В противном случае выведите два числа <span class="tex-span"><i>x</i></span> и <span class="tex-span"><i>y</i></span>, такие что <span class="tex-span"><i>ax</i> + <i>by</i> = <i>c</i></span> и <span class="tex-span"><i>x</i></span> является положительным и при этом наименьшим возможным среди всех таких пар.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>3 4 5<br/></pre>

Выход:

<pre>3 -1<br/></pre>