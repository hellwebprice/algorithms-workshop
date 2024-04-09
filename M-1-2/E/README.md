<center><h1>E. Усиление героев</h1></center>
    
<p><center>Ограничение по времени на тест: <b>2 s.</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 MB</b></center></p>

<h2>Условие:</h2>

<div><p>Есть колода из $n$ карт, каждая из которых характеризуется своей силой. Бывают карты двух видов:</p><ul> <li> карта героя, сила такой карты всегда равна $0$; </li><li> карта бонуса, сила такой карты всегда положительна. </li></ul><p>Вы можете делать с колодой следующее:</p><ul> <li> взять карту сверху колоды; </li><li> если эта карта является картой бонуса, вы можете положить её <span class="tex-font-style-bf">на верх</span> своей колоды с бонусами либо в сброс; </li><li> если эта карта является картой героя, то к его силе прибавляется сила <span class="tex-font-style-bf">верхней</span> карты из вашей колоды с бонусами (если она не пуста), после этого герой добавляется к вашей армии, а использованный бонус уходит в сброс. </li></ul><p>Ваша задача с помощью таких действий собрать армию с наибольшей суммарной силой.</p></div>

<h2>Решение:</h2>

Время: $O(n\log n)$

Память: $O(n)$

[Код](solution.cpp)

Поддерживаю очередь с приоритетами. Как только появляется очередной $0$ достаю самую сильную карту из очереди и использую её

<h2>Входные данные:</h2>

<p>Первая строка входных данных содержит единственное число $t$ ($1 \le t \le 10^4$) — количество наборов входных данных в тесте. </p>

<h2>Выходные данные:</h2>

<p>Выведите $t$ чисел, каждое из которых является ответом на соответствующий набор входных данных — максимальную возможную суммарную силу армии, которой можно добиться.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>
<div class="test-example-line test-example-line-even test-example-line-0">5</div><div class="test-example-line test-example-line-odd test-example-line-1">5</div><div class="test-example-line test-example-line-odd test-example-line-1">3 3 3 0 0</div><div class="test-example-line test-example-line-even test-example-line-2">6</div><div class="test-example-line test-example-line-even test-example-line-2">0 3 3 0 0 3</div><div class="test-example-line test-example-line-odd test-example-line-3">7</div><div class="test-example-line test-example-line-odd test-example-line-3">1 2 3 0 4 5 0</div><div class="test-example-line test-example-line-even test-example-line-4">7</div><div class="test-example-line test-example-line-even test-example-line-4">1 2 5 0 4 3 0</div><div class="test-example-line test-example-line-odd test-example-line-5">5</div><div class="test-example-line test-example-line-odd test-example-line-5">3 1 0 0 4</div></pre>

Выход:

<pre>
6
6
8
9
4
</pre>