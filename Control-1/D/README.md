<center><h1>D. Считалка</h1></center>
    
<p><center>Ограничение по времени на тест: <b>9 секунд</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 мегабайт</b></center></p>

<h2>Условие:</h2>

<div><p>$N$ друзей стоят по кругу. Они начинают считать себя по часовой стрелке, начиная с первого. После того как было посчитано $P$ человек, $P$-й посчитанный покидает круг, а счёт продолжается со следующего за ним. Выведите последовательность номеров друзей в порядке их выбывания из круга.</p></div>

<h2>Решение:</h2>

Время: $O(N\log N)$

Память: $O(N)$

[Код](solution.cpp)

С помощью дерамиду ищу очередной индекс для удаления и удаляю

<h2>Входные данные:</h2>

<p>На вход даются два целых числа $N$ и $P$ ($1 \le N, P \le 5 \cdot 10^5$).</p>

<h2>Выходные данные:</h2>

<p>Выведите $N$ целых чисел — последовательность номеров в порядке выбывания из круга.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>
3 4
</pre>

Выход:

<pre>
1 3 2 </pre>