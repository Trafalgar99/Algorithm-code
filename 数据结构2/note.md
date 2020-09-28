# Trie

用来高效的`存储`和`查找`字符串集合的数据结构
![](image/2020-09-26-21-37-07.png)
[AcWing 835. Trie 字符串统计](https://www.acwing.com/solution/content/3531/)<br>
[143. 最大异或对](https://www.acwing.com/problem/content/145/)

# 并查集

1. 将两个集合合并
2. 询问两个元素是否在一个集合当中

`基本原理：`每个集合用一棵树来表示。树根的编号就是整个集合的编号。每个节点存储它的父节点，p[x]表示它的父节点

q1: 如何判断树根？
if(p[x] == x)
q2: 如何求 x 的集合编号？
while(p[x] != x) x=p[x];
q3: 如何合并两个集合？
px 是 x 的集合编号，py 是 y 的集合编号。合并：p[x] = y;

优化 q2：当一个节点查询完集合编号时，将其在查询时所经过的路径上的所有的节点直接连到祖先节点下面（`路径压缩`）

[836. 合并集合](https://www.acwing.com/problem/content/838/)

# 堆
