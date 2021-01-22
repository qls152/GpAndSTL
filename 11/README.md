# 不改变操作对象之内容的算法

下面所介绍的STL的基本算法，作用于iterators所形成的range之上，但不会更改这些iterators所指元素的内容。这些算法返回range所含元素的某种信息。他们主要用于审阅，而非用来更改内容。

## 线性查找

### find
template <typename InputIterator, typename EqualityComparable>
InputIterator find(InputIterator first, InputIterator last, const EqualityComparable& value);

算法find会在iterators range内执行线性查找，寻找指定之值value。

更明确的说，它会返回在[first, last)中第一个满足*i == value的iterator i。如果没有这样的iterator，就会返回last。

关于find的测试用例可参考liner_search.h

### find_if

template <typename InputIterator, typename Predicate>
InputIterator find_if(InputIterator first, InputIterator last, Predicate pred);

如同find，算法find_if能在iterators range内进行线性查找。两者的差别在于find_if更为一般化。它查找满足某种条件的元素。

如果在range [first, last)中第一个满足pred(*i)为true的iterator i，则返回i；否则返回last。

find_if应用场景：由于find只能测试object的相等性，因此针对某特定键值的查询，便无法应用find，此时可以利用find_if。

关于find_if的测试可参考liner_search.h

### adjacent_find

template <typename ForwardIterator>
ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last);

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last, BinaryPredicate binary_pred);

如同find，adjacent_find算法会在iterators range中进行查找。两者之间的差别在于find是针对单个元素的查找，adjacent_find是针对两个相邻元素查找。

adjacent_find有两个版本。版本一查找两个相等的相邻元素，版本二更一般化，查找两个相邻元素是否满足某种条件，该条件以Binary Predicate定义。

版本二返回第一个满足binary_pred(*i, *(i+1))为true的iterator i。如果没有这样的iterator，则返回last.

相关测试可参考liner_serach.h

### find_first_of

template <typename InputIterator, typename ForwardIterator>
InputIterator find_first_of(InputIterator first1, InputIterator last1, ForwardIterator first2, ForwardIterator last2);

template <typename InputIterator, typename ForwardIterator, typename BinaryPredicate>
InputIterator find_first_of(InputIterator first1, InputIterator last1, ForwardIterator first2, ForwardIterator last2, BinaryPredicate);

该算法极类似find。会在input iterator range内进行线性查找。两者之间的区别在于find查找某个特定值，而find_first_of可查找任何数量的值。

更明确的说，find_first_of会在range [first, last)内查找任何出现于[first2, last2)内的元素。

find_first_of有两个版本，差别在于比较元素相等的方式。 第一版本采用operator==,版本二采用function object comp.

第一个版本返回[first1, last1)内的一个iterator i，他是第一个满足**对[first2, last2)中的某个iterator j，*i == *j**。

第二版本返回[first1, last1)内的一个iterator i,他是第一个满足**对[first2, last2)中的某个iterator j，表达式comp(*i, *j)为true**

其测试用例参考liner_serach.h。


