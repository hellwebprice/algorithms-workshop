<center><h1>B. Mahmoud and Ehab and the bipartiteness</h1></center>
    
<p><center>Ограничение по времени на тест: <b>2 seconds</b></center></p>

<p><center>Ограничение по памяти на тест: <b>256 megabytes</b></center></p>

<h2>Условие:</h2>

<div><p>Mahmoud and Ehab continue their adventures! As everybody in the evil land knows, Dr. Evil likes bipartite graphs, especially trees.</p><p>A tree is a connected acyclic graph. A bipartite graph is a graph, whose vertices can be partitioned into <span class="tex-span">2</span> sets in such a way, that for each edge <span class="tex-span">(<i>u</i>, <i>v</i>)</span> that belongs to the graph, <span class="tex-span"><i>u</i></span> and <span class="tex-span"><i>v</i></span> belong to different sets. You can find more formal definitions of a tree and a bipartite graph in the notes section below.</p><p>Dr. Evil gave Mahmoud and Ehab a tree consisting of <span class="tex-span"><i>n</i></span> nodes and asked them to add edges to it in such a way, that the graph is still bipartite. Besides, after adding these edges the graph should be simple (doesn't contain loops or multiple edges). What is the maximum number of edges they can add?</p><p>A loop is an edge, which connects a node with itself. Graph doesn't contain multiple edges when for each pair of nodes there is no more than one edge between them. <span class="tex-font-style-bf">A cycle and a loop aren't the same</span> .</p></div>

<h2>Решение:</h2>

Время: $O(n)$

Память: $O(n)$

[Код](solution.cpp)

С помощью BFS крашу вершины дерева в 2 цвета. Тогда разность произведения мощности этих множеств и ребер, которые были в дереве, и будет ответом

<h2>Входные данные:</h2>

<p>The first line of input contains an integer <span class="tex-span"><i>n</i></span> — the number of nodes in the tree (<span class="tex-span">1 ≤ <i>n</i> ≤ 10<sup class="upper-index">5</sup></span>).</p>

<h2>Выходные данные:</h2>

<p>Output one integer — the maximum number of edges that Mahmoud and Ehab can add to the tree while fulfilling the conditions.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>3<br/>1 2<br/>1 3<br/></pre>

Выход:

<pre>0<br/></pre>