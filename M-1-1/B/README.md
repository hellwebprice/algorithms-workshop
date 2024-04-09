<center><h1>B. Максимальное произведение кратное 15</h1></center>
    
<p><center>Ограничение по времени на тест: <b>2 секунды</b></center></p>

<p><center>Ограничение по памяти на тест: <b>4 мегабайта</b></center></p>

<h2>Условие:</h2>

<div><p>Дана последовательность чисел <span class="tex-span"><i>a</i><sub class="lower-index">1</sub>, <i>a</i><sub class="lower-index">2</sub>, ..., <i>a</i><sub class="lower-index"><i>n</i></sub></span>. Вам нужно найти два числа из этой последовательности, чьё произведение делится на <span class="tex-span">15</span> и при этом максимально.</p></div>

<h2>Решение:</h2>

Время: $O(n)$

Память: $O(1)$

[Код](solution.cpp)

Ищу 4 максимума: делящихся на 3, 5, 15 и общий $\neq$ тому, что делится на 15. Среди произведений этих чисел и будет искомый максимум

<h2>Входные данные:</h2>

<p>На вход подаётся число <span class="tex-span"><i>n</i></span> (<span class="tex-span">2 ≤ <i>n</i> ≤ 10<sup class="upper-index">6</sup></span>). Далее идёт <span class="tex-span"><i>n</i></span> строк, в <span class="tex-span"><i>i</i></span>-й из них строк записано число <span class="tex-span"><i>a</i><sub class="lower-index"><i>i</i></sub></span> (<span class="tex-span">1 ≤ <i>a</i><sub class="lower-index"><i>i</i></sub> ≤ 10<sup class="upper-index">7</sup></span>). Гарантируется, что искомые числа найдутся.</p>

<h2>Выходные данные:</h2>

<p>Выведите наибольшее произведение двух чисел из последовательности, которое делится на <span class="tex-span">15</span>.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>4<br/>30<br/>1<br/>3<br/>5<br/></pre>

Выход:

<pre>150<br/></pre>
