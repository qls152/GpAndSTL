# Containers(容器)

算法作用于range(区间)，在很多情形下，数据结构可以被(全部或者部分)视为某个线性range。

因此欲了解range之上的范型算法，需要了解**数据结构(其内包含哪些ranges)**

## 5.1 一个简单的Container

由数组说起。 C/C++数组的优点和缺点如下：

**优点**

1. 数组本质上遵循range概念

2. 数组可以被分配在栈上。分配速度比较快，且不必检查是否分配成功。

3. 数组效率很高，可以直接存取数组元素

4. 数组具有固定大小，在编译器就已经知道其大小

5. 数组具有简便的初始化语法

**缺点**

1. 数组虽然有固定大小，但应用程序必须明白的记录数组大小，因为数组没有size()这种member function可供使用。

2. 每个数组都有**指向第一元素**的iterator，以及**past-the-end(越过尾端)**的iterator, 但没有直接方法可以找到越过尾端的那个iterator。

3. 无法直接复制数组。

4. 无法将数组以传值的方式传入某个函数。

数组是C/C++型别系统的一部分，但数组型别通常衰退为指针型别

### 5.1.1 一个Array Class

定义的block class可参考block.h。

block的设计相当简单，它只有一个member variable,就是data数组。

1. block的元素个数是其型别的一部分。故block<int, 10>与block<int, 12>是完全不同的型别。

2. block没有声明构造函数，析构函数以及拷贝赋值操作符。

## 5.2 Container Concepts

block具有三个主要的功能性：

1. 包含元素

2. 提供访问元素的方法

3. 支持让block成为regular type所必须的一些操作行为

### 5.2.1 元素的容纳

1. 两个containers不能重叠，同一个元素不能分属一个以上的containers。

2. 元素的生命期不能超越其所属container的生命期。 元素不能在其container构造之前先产生出来，也不能在container被摧毁之后才摧毁。

3. container可以如同block一般具有固定大小。但其大小也可以改变，以便你能产生container之后才产生或者销毁某些元素。

**所有containers，如同C数组或者block一样，具有数值语义而非指针语义。**

## 5.3 大小可变的Container Concepts

STL定义了两种大小可变的containers: Sequence Container 和 Associate Container

Sequence(序列容器) container 是Fowrard Container的refinement，是一种最明显的大小可变的cotainer。

Sequence都必须具有成员函数insert和erase。如果p是指向序列容器S中的某个元素的iterator，则

1. 针对erase，erase(p)会移除元素并摧毁该元素

2. 针对insert，S.insert(p, x)产生一个副本，该副本安插在p之前。

**为什么insert会安插在p之前？**

**主要是因为iterator的range是非对称的。针对range，存在past-of-end的iterator，但不存在越过begin的迭代器。因此只能在p之前插入元素**

STL主要提供三种Sequence class: vector, list和deque。

其中主要差异在于它们所提供的iterator种类，iterator无效语义(**在什么情况下，会导致先前取得的iterator失效**)以及insert与erase的复杂度。

关于安插语义(insertion)和覆盖语义(overwrite) 可参考sequence_container.h