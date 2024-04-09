<center><h1>H. Максимальная подпоследовательность</h1></center>
    
<p><center>Ограничение по времени на тест: <b>1 секунда</b></center></p>

<p><center>Ограничение по памяти на тест: <b>128 мегабайт</b></center></p>

<h2>Условие:</h2>

<div><p>Даны две строки <span class="tex-span"><i>s</i></span> и <span class="tex-span"><i>t</i></span>. Для каждого суффикса строки <span class="tex-span"><i>s</i></span> определите, верно ли, что он содержит <span class="tex-span"><i>t</i></span> в качестве подпоследовательности.</p><p>Суффикс строки – это подстрока, на которую строка кончается. У строки столько же непустых суффиксов, какая у неё длина.</p></div>

<h2>Решение:</h2>

Время: $O(n)$

Память: $O(1)$

[Код](solution.cpp)

Иду справа налево в каждой из строку и ищу строку $t$

<h2>Входные данные:</h2>

<p>Строки <span class="tex-span"><i>s</i></span> и <span class="tex-span"><i>t</i></span>, состоящие из маленьких латинских букв. Длины обеих строк не менее 1 и не более <span class="tex-span">10<sup class="upper-index">5</sup></span>.</p>

<h2>Выходные данные:</h2>

<p>Пусть <span class="tex-span"><i>n</i></span> – длина строки <span class="tex-span"><i>s</i></span>. Для каждого <span class="tex-span"><i>i</i></span> от 1 до n выведите на отдельной строке слово <span class="tex-font-style-tt">yes</span>, если строка <span class="tex-span"><i>s</i>[<i>i</i>..<i>n</i>]</span> содержит <span class="tex-span"><i>t</i></span> в качестве подпоследовательности и слово <span class="tex-font-style-tt">no</span>, если не содержит.</p>

<h2>Публичные тесты:</h2>

Вход:

<pre>ab<br/>a<br/></pre>

Выход:

<pre>yes<br/>no<br/></pre>