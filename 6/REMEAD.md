# 基本概念

正规型别(regular type):

同时兼具Assignable、Default Constructible和Equality Comparable的一个model。

除非有合理因素，否则用户自定义型别都应该是正规型别。

## 6.1 Assignable

如果能够复制某个型别的object，并且可以将数值赋予该型别的变量身上，则该型别便是Assignable.

**相等并不是赋值的必然结果**

原因：一个Assignable model的型别，并没有规定必须是Equality Comparable的model，因为他可以不需要任何operator==.

推论： 如果某个型别同时是Assignable 和 Equality Comparable的model，那么x的复制品和x的自身应该是相等的。

**注：在C++中相等和等价并不是同一个意思**

几乎所有C++内建类型都是Assignable model。但是const T和pair<const T, value>不属于Assignable。

## 6.2 Default Constructible

如果某个型别具有一个default constructor，也就是说不需要指定任何初始值便可以构造该对象，那么这个型别便属于Default Constructible。

## 6.3 Equality Comparable

如果可以使用operator==对某个型别做相等性比较，而且operator==系表示等价关系的话，该型别便是Equality Comparable。

Equality的model具有如下恒常特性（Invariants)

1. Identity(同一性)

&x == &y意味x == y

2. Reflexivity(自反性)

x == x

3. Symmetry(对称性)

如果x == y意味着 y == x

4. Transitivity(传递性)

如果x == y且 y==z，意味x == z

所谓等价关系是指**满足自反性、对称性和传递性等恒常特性**的关系。

## 6.4 可序性

如果某个型别能够以某种次序排列，它便隶属于LessThan Comparable. 它必须能够以operator< 作为比较动作，而operator<必须定义出某种一致的可序性。

某个型别是LessThan Comparable，而operator<除了满足partial ordering条件，还满足更严格的strick weak ordering条件，那么该型别隶属于Strict Weakly Comparable。

**Strick weak ordering：**

如果两个元素具有**任何一个都不小于另一个**的性质，那么将他们视为具备**某种程度之等价关系**是合理的。

到此为止，相关概念总结完毕，关于7-9章，不再总结。