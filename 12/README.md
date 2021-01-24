# 会改变操作对象内容的算法

本章中的基本算法作用于一个或者多个iterator所形成的ranges上，并更改某些iterators所指向的元素。

这些算法主要包括：

1. 从某个range复制元素至另一个range。

2. 为range中的每个iterators赋值

3. 将某个值覆盖为另一个值。

这些算法改变的是iterator所指之值，而非iterator自身，同时也不能改变range中元素个数。

## 拷贝某个区间

### copy

```
template <typename InputIterator, typename OutputIterator>
OutputIterator copy(InputIterator first, InputIterator second, OutputIterator result);
```

该算法可将input range内的元素复制到output上。

也就是说，他会执行赋值动作*result = *first，*(result + 1) = *(first+1)......以此类推。返回值为result+last-first。

关于copy的测试，前面章节挺多用例，此处不赘述。

### copy_backward


```
template <typename BidirectionalIterator1, typename BidirectionalIterator2>
BidirectionalIterator2 copy(BidirectionalIterator1 first, BidirectionalIterator1 second, BidirectionalIterator2 result);
```

该算法如同copy，可讲输入区间内的元素复制到输出区间。 Input range为[first, last), 而输出区间为[result - (last -first), result)。它会执行赋值动作 *(result-1)= *(last - 1), *(result-2) = *(last - 2)... 以此类推。

该算法返回值为result-(last-first)。

copy与copy_backward不同：

1. copy只要求其输入区间由input iterators构成，而输出区间又output iterators构成。 而copy_backward则要求收入区间和输出区间必须由Bidirectional Iterators构成。

2. 这两个算法以相反的方向执行，copy由前往后复制，copy_backward由后往前复制。

3. copy以range起头的iterator表现其output range，而copy_backward则以iterator result代表其output range的尾端。

关于copy_backward的测试可参考copy.h。

## 互换元素

### swap

```
tempalte <typename Assignable>
void swap(Assignable& a, Assignable& b);
```

正如其名，swap交换a与b的值。将a的内容赋值给b，将b的内容赋值给a。该算法是其他很多算法所使用的基本函数。

关于该算法的测试可参考swap.h.

### iter_swap

```
template <typename ForwardIterator1, typename ForwardIterator2>
inline void iter_swap(ForwardIterator1 a, ForwardIterator2 b);
```

如果a和b是iterators，则iter_swap(a, b)相当于swap(*a, *b);

现在基本很少有政党理由使用iter_swap. 应该优先使用swap。

该算法测试可参考swap.h。

### swap_ranges

```
template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator2 iter_swap(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2);
```

该算法可将大小相等的两个ranges的内容互换。他会将[first1, last1)中的值与[first2, first2 + last1 -first1)中相对的元素互换。

该算法测试可参考swap.h。

### transform

```
template <typename InputIterator, typename OutputIterator, typename UnaryFunction>
OutputIterator transform(InputIterator first, InputIterator last, OutputIterator result, UnaryFunction op);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename BinaryFunction>
OutputIterator transform(InputIterator1 first, InputIterator1 last, InputIterator2 first2, OutputIterator result, BinaryFunction op);

```

该算法非常类似for_each,可搭配一个函数对象对range内的对象进行某种运算。 两者的差别在与for_each不在意函数对象的返回值，**但transform会将该返回值复制到另一个range中。**

transform有两个版本。第一版本将unary function作用于单一输入区间，第二版本则将binary function作用于两个大小相等的输入区间。

版本一针对输入区间中的每个iterator i,执行op(*i)并将结果赋值给 *o，其中o表示i所对应的输出迭代器。 返回值是result+last -first.

版本二可类比版本一，此处不再赘述。

关于该算法测试，可参考swap.h。


