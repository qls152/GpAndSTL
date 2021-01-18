# 函数对象

函数对象： 可以像函数一样被调用的东西。

在STL中，函数对象的主要用途为**以template参数来指明所要采用的策略**

函数对象可以实现为至少如下三种形式：

1. 函数指针

2. 无状态的（不含成员变量）重载了operator()的类对象

3. 有状态的重载了operator()的类对象

关于相关说明和实现可以参考 is_even.h

## 4.1 Function Object Concepts(函数对象概念)

上述中的三个函数对象除了均有operator()外，相同点很少。

任何函数对象概念的基本条件只是：如果f是个函数对象，可以将operator()施行于f身上。

### 4.1.1 单参数(Unary)和双参数(Binary)函数对象

**重载的operator()只需要一个参数的对象叫单参数函数对象**

**重载的operator()需要两个参数的对象叫双参数函数对象**

STL中基本的function object concepts是Generator，Unary Function 和 Binary Function。这些concepts所描述的是能够以f()、f(x)、f(x, y)调用的对象。

STL所定义的其他function object concepts都是这三个concept的refinements(强化)。

### 4.1.2 Predicates 和 Binary Predicates

Predicate: 单一参数的函数对象其返回类型为bool, 则该函数对象为Predicate

Predicate是Unary Function的一个强化

Binary Predicate：需要两个参数的函数对象其返回类型为bool，则该函数对像为Binary Predicate

### 4.1.3 相关型别

所谓function object的相关型别是指其参数型别和返回值型别。

Generator 具有一个相关型别（即返回值型别）

Unary Function 具有两个相关型别（参数型别和返回值型别）

Binary Function 具有三个相关型别

前述class even<T> 具有一个参数型别T和一个返回型别bool

关于如何获得参数类型和结果类型可以参考function_traits.h，其中模仿iterator_traits实现了两个空基类unary_function和binary_function.

## 4.2 Function Object Adapters(函数对象适配器)

Adapter：一种**将某种接口转换为另一种接口**的组件。

所实现的unary_negate适配器可参考 unary_negate.h

STL定义的其他数个function object adapters.其中最重要的是：

1. bind

2. mem_fun_t adapter及其变形，它们除了**作用于member function而非全局函数**

3. unary_compose 能将两个函数对象f和g转换为一个单一函数对象h，使得h(x)=f(g(x)).



