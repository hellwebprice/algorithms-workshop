<center><h1>D. Range Minimum Query</h1></center>
    
<p><center>Ограничение по времени на тест: <b>6 секунд</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 мегабайт</b></center></p>

<h2>Условие:</h2>

<div><p>Массив $a$ изначально пуст. На вход поступает $k \leq 200 000$ запросов одного из двух типов:</p><p>1) $+\ i\ x $ вставить элемент $x$ ($|x| \leq 10^9$) после i-го элемента массива (нумерация элементов с единицы!). Если $i=0$, то элемент добавляется в начало массива.</p><p>2) $?\ l\ r$ найти $\min(a_l,\ldots, a_r)$ ($1 \leq l \leq r \leq 10^9$).</p><p>Требуется вывести ответ на каждый запрос второго типа.</p></div>

<h2>Решение:</h2>

Время: $O(k\log n)$

Память: $O(n)$

[Код](solution.cpp)

Реализация дерамиды с поддержкой минимума в дереве (дерамида тут нужна, чтобы добавлять очередной элемент за $O(\log n)$ в среднем)

<h2>Входные данные:</h2>

<p>$k$</p>

<h2>Выходные данные:</h2>

<p>Ответы на $?$-запросы — минимум от $l$-го до $r$-го элемента массива $a$ (включительно).</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>
8
+ 0 5
+ 1 3
+ 1 4
? 1 2
+ 0 2
? 2 4
+ 4 1
? 3 5
</pre>

Выход:

<pre>
4
3
1
</pre>