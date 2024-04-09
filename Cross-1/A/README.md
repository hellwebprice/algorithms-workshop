<center><h1>A. Сортировка по многим полям</h1></center>
    
<p><center>Ограничение по времени на тест: <b>2 секунды</b></center></p>

<p><center>Ограничение по памяти на тест: <b>64 мегабайта</b></center></p>

<h2>Условие:</h2>

<div><p>В базе данных хранится <span class="tex-span"><i>N</i></span> записей, вида <span class="tex-span">(<i>Name</i>, <i>a</i><sub class="lower-index">1</sub>, <i>a</i><sub class="lower-index">2</sub>, ..., <i>a</i><sub class="lower-index"><i>k</i></sub>)</span> – во всех записях одинаковое число параметров. На вход задачи подаётся приоритет полей – перестановка <span class="tex-span"><i>p</i><sub class="lower-index">1</sub>, ..., <i>p</i><sub class="lower-index"><i>k</i></sub></span> на числах <span class="tex-span">1, ..., <i>k</i></span> – записи нужно вывести в соответствии с этим приоритетом. Записи сравниваются по значению <span class="tex-span"><i>a</i><sub class="lower-index"><i>p</i><sub class="lower-index">1</sub></sub></span>, в случае равенства значений идёт сравнение по значению <span class="tex-span"><i>a</i><sub class="lower-index"><i>p</i><sub class="lower-index">2</sub></sub></span> и т.д.</p><p>В случае, если в БД две записи <span class="tex-span">(<i>A</i>, 3, 2)</span> и <span class="tex-span">(<i>B</i>, 1, 3)</span>, а приоритет полей <span class="tex-span">2, 1</span>, то запись <span class="tex-span"><i>B</i></span> должна быть выведена раньше записи <span class="tex-span"><i>A</i></span>, т.к. приоритет второго поля выше первого. В случае записей <span class="tex-span">(<i>A</i>, 3, 2)</span> и <span class="tex-span">(<i>B</i>, 1, 2)</span>, <span class="tex-span"><i>A</i></span> важнее <span class="tex-span"><i>B</i></span>, т.к. значение вторых компонент равно, а первая компонента у <span class="tex-span"><i>A</i></span> больше.</p></div>

<h2>Решение:</h2>

Время: $O(Nk\log N)$

Память: $O(N)$

[Код](solution.cpp)

Написал структуру данных с оператором $>$, с помощью которого сортирую

<h2>Входные данные:</h2>

<p><span class="tex-span"><i>N</i> ≤ 1000</span></p>

<h2>Выходные данные:</h2>

<p><span class="tex-span"><i>N</i></span> строк с именами в порядке, согласно приоритету</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>3<br/>3<br/>2 1 3<br/>A 1 2 3<br/>B 3 2 1<br/>C 3 1 2<br/></pre>

Выход:

<pre>B<br/>A<br/>C<br/></pre>