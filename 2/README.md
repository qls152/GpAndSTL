## concept

是一组**描述某个型别**的条件。

concept既非class，也非function或者template。

可从如下三个方面理解concept：

concept可以想象成一组型别的条件，满足这些条件的型别为该concept的model

concept可以理解为一组型别的集合，如果型别T是concept的model，则T隶属于 该concept所代表的集合

concept可以想象成一组合法程序

### concept条件

concept的条件：一组有效表达式

### model

如果某个型别满足所有这样的条件，则该型别是concept的一个model

所谓正规型别，是一种同时满足Assignable,Default Constructible, Equality Comparable等条件的型别

## Iterator

主要包括五种iterator

Input Iterator: 迭代器只能移动，不能比较两个迭代器的值，且只读

Output Iterator: 迭代器只能移动，不能比较两个迭代器的值，且只写

Forward Iterator: 可读可写，可比较两个迭代器的值，但不能反向移动

Bidirectional Iterator: 具备Forward迭代器的所有功能，且能够反向移动

Random Access Iterator: 具备双向迭代器的所有功能，在某些场景下，时间复杂度好过双向迭代器

## Refinement(精炼，强化)

如果concept C2提供了concept C1的所有功能，且concept C2还具有其他功能，则称 C2是 C1的强化

refinement具有如下三个性质：

Reflexivity(自反性)。 每个concept都是其自身的一个Refinement

Containment(涵盖性)。 如果T是concept C2的一个model，而concept C2 是concept C1的一个

Refinement，则T必是C1的一个model

Transitivity(传递性)。如果concept C3是concept C2的一个Refinement，而concept C2是

concept C1的一个Refinment，则C3是C1的Refinement。

结论：

如果concept C2是concept C1的一个Refinement，而某个算法要求其引数型别必须是concept C1的

model，则任何一个concept C2的model的引数型别也满足要求。




