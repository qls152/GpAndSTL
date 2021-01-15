# 3 再论Iterators(迭代器or泛型指针)

## 3.1 Iterator Traits(迭代器特征)与Associated Types(相关型别)

### Value Type(数值型别)

每个迭代器所指之物的型别便是这个Iterator的Value Type

取得每个迭代器的Value Type可以通过两种方式：

**template 函数模版参数推导**

**Iterator Traits 模版类型萃取**

关于上述两者的实现可参考value_type.cc

## Difference Type(差距型别)

如果T是Random Access Iterator的一个model，而p1和p2为T的值，则p2-p1便是p1到p2之间的距离，该

距离的型别便为差距型别。

所谓差距型别的值：区间[p1, p2)的迭代器的个数。

## Reference Type 和 Pointer Type