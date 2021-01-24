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

## 替换元素

```
template <typename ForwardIterator, typename T>
void replace(ForwardIterator first, ForwardIterator last, const T& old_value, const T& new_value);
```

该算法会遍历range中的每个元素，凡是old_value出现之处便用new_value 替换。 与old_value不相等的元素不受影响。

该算法测试可参考replace.h。

### replace_if

```
template <typename ForwardIterator, typename Predicate, typename T>
void replace_if(ForwardIterator first, ForwardIterator last, Predicate pred, const T& new_value);
```

该算法是replace的一般化版本。他会遍历range中的每个元素，将每一个**导致pred返回true**的元素替换为new_value. 返回false的元素不受影响。

该算法测试参考replace.h。

### replace_copy

```
template <typename InputIterator, typename OutputIterator, typename T>
OutputIterator replace_if(InputIterator first, InputIterator last, OutputIterator result, const T& old_value, const T& new_value);
```

该算法将[first, last)的元素复制到[result, result + last -first)中， 复制过程中以new_value取代old_value。[first, last)不会被改动。

replace_copy相当于先copy再replace.

该算法测试参考replace.h。

### replace_copy_if

```
template <typename InputIterator, typename OutputIterator, typename Predicate, typename T>
OutputIterator replace_copy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate pred, const T& new_value);
```

该算法可参考replace_if和replace_copy，此处不再赘述。

算法测试可参考replace.h。

## 填充整个区间

### fill

```
template <typename ForwardIterator, typename T>
void fill(ForwardIterator first, ForwardIterator last, const T& value);
```

对于区间[first, last)中的每个iterator i, 执行*i= value.

该算法测试参考fill.h。

### fill_n

```
template <typename OutputIterator, typename Size, typename T> 
OutputIterator fill_n(OutputIterator first, Size n, const T& value);
```

该算法针对[first, first+n)中的每个iterator i，执行*i = value. 返回值为first + n.

该算法测试可参考fill.h中的fill.

### generate

```
template <typename ForwardIterator, typename Generator>
void generate(ForwardIterator first, ForwardIterator last, Generator gen);
```

该算法会调用gen(一个不需要任何形参的函数对象)，并将结果赋值给[first, last)中的每个元素。也即，针对[first, last)中的每个iterator i, *i = gen()。

该算法测试参考fill.h。

### generate_n

```
template <typename OutputIterator, typename Size, typename Generator> 
OutputIterator fill_n(OutputIterator first, Size n, Generator gen);
```
该算法可参考fill_n和generate， 此处不再赘述。

## 移除元素

### remove

```
template <typename ForwardIterator, typename T>
ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T& value);
```

该算法会将数值value从[first, last)中移除。

**注：remove并不会改变区间大小，也并不会真正删除一个元素。该算法会返回一个iterator new_last, 使得[first, new_last)内的元素都不等于value。之所以说remove是稳定的是指区间左端的元素的相对位置不变。**

**[new_last, last)中的iterators仍然可提领，但是指向之值是未定义的。**

该算法测试用例参考remove.h。

### remove_if

```
template <typename ForwardIterator, typename Predicate>
ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, Predicate pred);
```

该算法移除每一个使**pred返回true**的元素。该算法的功能和解释可参考remove。

该算法测试参考remove.h。

### remove_copy

```
template <typename InputIterator, typename OutputIterator, typename T>
OutputIterator remove_copy(InputIterator first, InputIterator last, OutputIterator result, const T& value);
```

该算法相当于先remove 然后copy。

该算法测试可参考remove.h。

### remove_copy_if

```
template <typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator remove_copy(InputIterator first, InputIterator last, OutputIterator result, Predicate pred);
```

该算法可参考remove_if和remove_copy理解其功能。

省略该算法测试，可参考remove_if。

### unique


