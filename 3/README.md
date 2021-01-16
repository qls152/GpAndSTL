# 3 再论Iterators(迭代器or泛型指针)

## 3.1 Iterator Traits(迭代器特征)与Associated Types(相关型别)

### Value Type(数值型别)

每个迭代器所指之物的型别便是这个Iterator的Value Type

取得每个迭代器的Value Type可以通过两种方式：

**template 函数模版参数推导**

**Iterator Traits 模版类型萃取**

关于上述两者的实现可参考value_type.h

### Difference Type(差距型别)

如果T是Random Access Iterator的一个model，而p1和p2为T的值，则p2-p1便是p1到p2之间的距离，该

距离的型别便为差距型别。

所谓差距型别的值：区间[p1, p2)的迭代器的个数。

### Reference Type 和 Pointer Type

### 算法处理与Iterator Tags

算法对于某种iterator concept有个实用定义，对于该concept的refinement却有另一种不同的定义。

譬如，如果某个算法应用了Forward Iterators，但某些时候我们需要针对Random Access Iterators写

一个特别版本，使某些操作（operator<, operator+=)的复杂度为O(1).

**此时我们需要做的是对concepts进行重载**

**以C++型别系统来表示concepts,可以达到以函数重载的方式实现concepts重载**

该方式主要由两步构成：

1. 为每一个iterator concept定义一个专属型别，作为tag之用，需要保证该型别唯一

2. 将算法进行重载--以上述所谓的标签型别（tag types)作为识别凭借

此处以stl中的advance为例子，代码与说明参考advance.h

### 完整的iterator_traits实现

具体参考iterator_traits.h

使用iterator_traits的两个条件：

1. 你必须返回值，或是声明临时变量，而其型别与iterator的value type或difference type或

reference type 或者pointer type一致

2. 你的算法类似advance，必须根据iterator的分类而决定不同的实现方法


## 3.2 定义新组件

Iterators和算法都是根据iterators的条件而编写。

由于算法和iterator types以iterator concept作为其接口，因此每当你实现新的算法或者新的

iterators时，应当将iterator concepts视为一份清单。 该清单对于新的迭代器而言，代表着

**应该提供的功能**， 对于新的算法而言，代表着**应该存在的功能**。

基本上，迭代器必须能够做两件事

1. 它必须指向某物

2. 它必须能够遍历任何一个有效区间

定义新的迭代器的建议

1. 注意iterator应该是constant或者mutable。两者的主要差别在于其reference type和pointer

 type是T&和T*，或者是const T&和const T*.

 **constant iterator 和mutable iterator的value type都为T，且mutable iterator可以转为constant iterator，反之不成立**

2. 你必须确定iterator_traits能够正确作用于你的iterator。

3. 尽可能提供较多的iterator 操作行为，除非对效率有影响。

4. 面对Forward iterator，你应该遵守所谓**iterator相等（equality）**的基本原则：只有当两个iterators指向相同的对象，他们才被视为相等。

自定义一个node_wrap迭代器，需要实现constant和mutable版本，具体实现参考 node_wrap.h

