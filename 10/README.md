# 基本组件介绍

## distance

distance是其他STL算法内部所用的一个基本元素，它会寻找Iterator first与last之间的距离(**将first累加，直到等于last**所需要的次数)。

distance 存在的真正原因是作为其他泛型算法所需要的基本元素。

关于distance的使用和声明可以参考basic.h.

## advance

advance(i, n)是将iterator i累加n步距离。 如果n > 0, 那就等价于++i执行n次(如果是Random Access Iterator，执行速度更快)。如果n < 0, 那就等价于--i执行n次。如果n==0，本次调用无效。

当iterator属于Bidirectional Iterator时，n才允许负值。

advance真正存在的原因是作为其他泛型算法的基本元素。

关于advance的例子和说明可参考basic.h。

## 内存管理基本元素

下面所介绍的算法和其他所有STL算法不同。它们作用于未初始化的存储空间，而非实际的C++对象。

uninitialized_copy, uninitialized_fill和uninitialized_fill_n与算法copy、fill、fill_n很像，两种之间的唯一差别在于后者会赋予新值在已存在的对象身上，而前者会构造出新的对象。

**construct**

template <typename T1, typename T2>
void construct(T1* p, const T2& value);

C++中，new操作符首先会分配object的内存，然后调用构造函数在该内存位置构造object。

如果p指向已分配但尚未初始化的内存，则construct(p, value)会在p所指内存处产生一个型别T1的object. 引数value会传给T1的构造函数。

表达式construct(p, value)本质上等于表达式new (p) T1(value)。

关于construct的测试参考stl_memory.h.

**destory**

template <typename T> void destory(T* pointer);

C++中，delete操作符会先调用某个对象的析构函数，然后归还该对象所在内存空间。

destroy的作用是：调用某个对象的析构函数，但不释放相应的内存空间。

关于destory的测试可参考stl_memory.h。

**uninitialized_copy**

tempalte <typename InputInterator, typename ForwardIterator>
ForwardIterator 
uninitialize_copy(InputIterator first, InputIterator last, ForwardIterator result);

算法uninitialized_copy能够将内存分配与object的构造行为分离。 如果输出区间[result, result + (last-first)]中的每一个iterator都指向未初始化空间，则uninitialized_copy会使用拷贝构造函数为[first, last]的所有objects产生一份副本，放在输出区间中。

换句话说：针对输入区间中每一个iterator i, 该算法会调用construct(&*(result+i-first), \*i),产生\*i的副本，放在输出区间相应位置上。

关于该算法的测试可参考：stl_memory.h。

**uninitialized_fill**

同上述uninitialized_copy一样，能够将内存分配和对象的构造行为分离开来。

乳沟range [first, last]中的每个iterators都指向未初始化的内存，那么uninitialized_fill会在该range中产生x的复制品。

上述两者均具有commit或者callback语义。

该算法的测试可参考：stl_memory.h。

**uninitialized_fill_n**

同uninitialized_fill一样，主要区别在于，该算法操作与**一个iterator加上一个元素个数所表现的range**身上。

如果[first, first+n)中的每一个iterators都指向未初始化的内存，该算法会调用拷贝构造函数，在该range上产生x的复制品。

其测试可参考stl_memory.h。

