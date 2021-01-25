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

```
template <typename ForwardIterator>
ForwardIterator unique(ForwardIterator first, ForwardIterator last);

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator unique(ForwardIterator first, ForwardIterator last, BinaryPredicate binary_pred);
```

该算法能够移除重复的元素。每当在[first, last)内遇到相连重复元素群出现， unique会移除该群中第一个以外的所有元素。

**unique只移除相邻的重复元素，如果想要移除所有重复元素,需要和sort结合使用**

同remove, unique并不改变区间大小，其会返回一个iterator new_last, 使得在[first, new_last)内的元素都不含相邻重复元素。

unique有两个版本。版本一使用operator==比较相邻元素是否相等，版本二根据binary_pred判断相邻元素是否满足需求，若满足则移除。

该算法测试参考remove.h。

### unique_copy

该算法使用可参考remove_copy和unique, 此处不再赘述。

## 排列算法

所谓range 元素的排列，就是将range中的元素重定顺序。 它不会删除或者增加任何元素，只是将元素值以不同的顺序放入input range内。

### reverse

```
template <typename BidirectionalIterator>
void reverse(BidirectionalIterator first, BidirectionalIterator last);
```

该算法会讲range的内容就地反转。即针对0 <= n <= (last-first)/2区间内的每个n，会将*（first+n)与 *(last-(n+1))互换。

该算法测试用例此处省略.

### reverse_copy

```
template <typename BidirectionalIterator, typename OutputIterator>
OutputIterator reverse_copy(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result);
```

该算法相当于先copy再reverse.

关于该算法测试可参考reverse.h。

### rotate

```
tempalte <typename ForwardIterator>
inline void rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last);
```

该算法会将range内的元素加以旋转：针对0 <= n < last-first区间内的每一个n，他会将元素*(first+n)赋值给*(first+(n+last-middle)%(last-first))。

用一种更简单的方式理解rotate:**它会将[first, middle)与[middle, last)互换。**

该算法测试可参考reverse.h。

### rotate_copy

```
tempalte <typename ForwardIterator, typename OutputIterator>
OutputIterator rotate_copy(ForwardIterator first, ForwardIterator middle, ForwardIterator last, OutputIterator result);
```

该算法相当于先copy后rotate.

关于该算法的测试省略。

### next_permutation

```
template <typename BidirectionalIterator>
bool next_permutation(BidirectionalIterator first, BidirectionalIterator last);

template <typename BidirectionalIterator, typename StrictWeakOrdering>
bool next_permutation(BidirectionalIterator first, BidirectionalIterator last, StrictWeakOrdering comp);
```

该算法会将元素所形成的range [first, last)转换为表格中下一个排列的顺序，也就是字典排序方式中的下一个较大排列顺序。

**若存在下一个较大排序，则该算法会转换为该排列顺序并返回true，否则就将[first, last)转换成字典排序方式下最小排列顺序(以递增顺序排列),并返回false**

关于该算法的两个版本，其区别在于元素的比较方式，此处不再赘述。

该算法的测试可参考reverse.h。

### prev_permutation

```
template <typename BidirectionalIterator>
bool prev_permutation(BidirectionalIterator first, BidirectionalIterator last);

template <typename BidirectionalIterator, typename StrictWeakOrdering>
bool prev_permutation(BidirectionalIterator first, BidirectionalIterator last, StrictWeakOrdering comp);
```

该算法的功能和使用与next_permutation很类似。区别在于，prev_permutation会返回该排列的前一个排序，若不存在前一个排列则该算法会将该顺序修改为最大的排序组合(依据递减顺序排列)，并返回false.

关于该算法的测试，本处省略。

## 分割

### partition

```
template <typename BidirectionalIterator, typename Predicate>
BidirectionalIterator partition(BidirectionalIterator first, BidirectionalIterator last, Predicate pred);
```

该算法会根据函数对象pred重新排列[first, last)的元素，使得满足pred的元素排在不满足pred的元素之前。

**partition不保证元素原来的相对位置，即该算法不是稳定的**

该算法的返回值为iterator middle. [first, middle)内的每个iterator i均满足
pred(*i) 为true，[middle, last)内的每个iterator i使得 pred( *i)为false。

该算法测试参考partition.h。

### stable_partition

```
template <typename BidirectionalIterator, typename Predicate>
BidirectionalIterator partition(BidirectionalIterator first, BidirectionalIterator last, Predicate pred);
```

该算法与partition类似，区别在于该算法是stable(稳定的，会保证原序列中元素的相对位置)。

**partition的效率要高于stable_partition**

关于该算法的测试可参考partition算法.

## 随机重排与抽样

### random_shuffle

```
template <typename RandomAccessIterator>
void random_shuffle(RandomAccessIterator first, RandomAccessIterator last);

template <typename RandomAccessIterator, typename RandomNumberGenerator>
void random_shuffle(RandomAccessIterator first, RandomAccessIterator last, RandomNumberGenerator& rand);
```

该算法随机重排[first, last)的顺序，从N！种可能的元素排列中随机选出一种，此处N为last-first。

该算法会产生一种均匀分布。

该算法有两个版本，版本一使用内部乱数产生器，版本二使用Random Number Generator。

该算法测试可参考partition.h。

### random_sample

```
template <typename InputIterator, typename RandomAccessIterator>
RandomAccessIterator random_sample(InputIterator first, InputIterator last, RandomAccessIterator ofirst, RandomAccessIterator olast);

template <typename InputIterator, typename RandomAccessIterator, typename RandomNumberGenerator>
RandomAccessIterator random_sample(InputIterator first, InputIterator last, RandomAccessIterator ofirst, RandomAccessIterator olast, RandomNumberGenerator& rand);
```

该算法会随机的将[first, last)内的一个取样结果复制到[ofirst, olast)中。他会复制n个元素，此处n为min(last-first, olast-ofirst)。 Input range内的元素最多在output range中出现一次，且该采样结果以均匀几率出现。

返回值为ofirst + n.

该算法非稳定。

该算法并不存在与stl标准中。