# 3 再论Iterators(迭代器or泛型指针)

## 3.1 Iterator Traits(迭代器特征)与Associated Types(相关型别)

### Value Type(数值型别)

每个迭代器所指之物的型别便是这个Iterator的Value Type

取得每个迭代器的Value Type可以通过两种方式：

**template 函数模版参数推导**

**Iterator Traits 模版类型萃取**

关于上述两者的实现可参考value_type.cc