<center><h1>G. k-й элемент</h1></center>
    
<p><center>Ограничение по времени на тест: <b>1 секунда</b></center></p>

<p><center>Ограничение по памяти на тест: <b>128 мегабайт</b></center></p>

<h2>Условие:</h2>

<div><p>На вход подается массив целых чисел. После получения каждого числа нужно вывести <span class="tex-span"><i>k</i></span>-е по величине число среди уже полученных (иными словами, то число, которое стояло бы на <span class="tex-span"><i>k</i></span>-м месте, если бы мы отсортировали уже полученную часть массива по возрастанию).</p></div>

<h2>Решение:</h2>

Время: $O(n \log n)$

Память: $O(n)$

[Код](solution.cpp)

Поддерживаю очередь с приоритетами, где на выходе k-й элемент. С помощью удаления очередного, когда размер очереди становится равным k

<h2>Входные данные:</h2>

<p>В первой строке даны натуральные числа <span class="tex-span"><i>n</i></span> — количество чисел и <span class="tex-span"><i>k</i></span> — номер элемента, который надо выводить (<span class="tex-span">1 ≤ <i>n</i> ≤ 10<sup class="upper-index">5</sup></span>, <span class="tex-span">1 ≤ <i>k</i> ≤ 10</span>). Далее идут <span class="tex-span"><i>n</i></span> чисел <span class="tex-span"><i>a</i><sub class="lower-index"><i>i</i></sub></span> (<span class="tex-span"> - 10<sup class="upper-index">9</sup> ≤ <i>a</i><sub class="lower-index"><i>i</i></sub> ≤ 10<sup class="upper-index">9</sup></span>), по одному в строке.</p>

<h2>Выходные данные:</h2>

<p>Выведите <span class="tex-span"><i>n</i></span> чисел, <span class="tex-span"><i>i</i></span>-е из них равно <span class="tex-span"><i>k</i></span>-му в порядке возрастания среди первых <span class="tex-span"><i>i</i></span> элементов массива <span class="tex-span"><i>a</i></span>. Если <span class="tex-span"><i>i</i> &lt; <i>k</i></span>, то выведите максимальный из первых <span class="tex-span"><i>i</i></span> элементов.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>3 1<br/>3<br/>2<br/>1<br/></pre>

Выход:

<pre>3<br/>2<br/>1<br/></pre>