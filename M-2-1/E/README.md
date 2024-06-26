<center><h1>E. Компоненты сильной связности</h1></center>
    
<p><center>Ограничение по времени на тест: <b>5 секунд</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 мегабайт</b></center></p>

<h2>Условие:</h2>

<div><p>На вход подаётся описание ориентированного графа — необходимо найти число его компонент сильной связности. Компонентой сильной связности называется максимальное по включению множество вершин, каждые две вершины которого достижимы друг из друга.</p></div>

<h2>Решение:</h2>

Время: $O(N^2)$

Память: $O(N)$

[Код](solution.cpp)

Обычная реализация алгоритма поиска компонент сильной связности через DFS

<h2>Входные данные:</h2>

<p><span class="tex-span"><i>N</i> ≤ 1000</span> – число вершин</p>

<h2>Выходные данные:</h2>

<p><span class="tex-span"><i>M</i></span> – число компонент сильной связности</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>3<br/>0 1 1<br/>1 0 1<br/>0 0 0<br/></pre>

Выход:

<pre>2<br/></pre>