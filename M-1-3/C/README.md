<center><h1>C. Трамп строит стену</h1></center>
    
<p><center>Ограничение по времени на тест: <b>5 секунд</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 мегабайт</b></center></p>

<h2>Условие:</h2>

<div><p>Трамп пообещал построить стену на границу с Мексикой. Настало время исполнить обещание. Граница представляет собой отрезок из $n \leq 2\times10^5$ километров. </p><p>Стену возводят поэтапно. На i-ом этапе отрезок стены с $l_i$ по $r_i$километр (включительно) увеличивают на $a_i$ метров ($1 \leq a_i \leq 10^4$). Километры нумеруются с $1$ до $n$. Всего будет $m\leq2\times 10^5$ этапов.</p><p>Команда Трампа будет проводить контроль по ходу строительства: в ходе контроля нужно определить максимальную высоту стены с $l_i$ по $r_i$ километр (включительно).</p><p>Напишите программу, которая позволит сверить текущий контроль с ожидаемым результатом</p></div>

<h2>Решение:</h2>

Время: $O(m\log n)$

Память: $O(n)$

[Код](solution.cpp)

Обычная реализация RMQ с помощью дерева отрезков с изменением на отрезке

<h2>Входные данные:</h2>

<p>В первой строке приведены числа $n$ и $m$. Далее идёт $m$ строк-запросов. </p>

<h2>Выходные данные:</h2>

<p>Для каждого запроса второго типа, выведите результат проверки.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>
5 6
build 1 4 2
build 2 5 1
test 1 1
test 1 5
build 3 4 10
test 2 3
</pre>

Выход:

<pre>
2
3
13
</pre>