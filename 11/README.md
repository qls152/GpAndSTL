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

## 子序列匹配

### search

template <typename ForwardIterator1, typename ForwardIterator2>
orwardIterator1 search(orwardIterator1 first1, orwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);

template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
orwardIterator1 search(orwardIterator1 first1, orwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate binary_pred);

该算法和find、find_if类似，可以在某个区间进行查找。区别在于find与find_if查找单个元素，而search查找的是整个子区间。

search算法试图在[first1, last1)内寻找[first2, last2).也就是说search会寻找[first1, last1)的某个子序列，使得该序列与[first2,last2)进行元素一一比较是否相同。如果相同，search返回一个指向该子序列的头iterator，如果子序列不存在，则返回last1.

版本一会返回[first1, last1 - (last2 - first2)]中的第一个iterator i，使得满足[first2, last2)中的每个iterator j，*(i + j - first2) == *j。

版本一利用operator==比较两个元素，版本二利用函数对象binary_pred比较两个元素。其他如版本一一样。

该算法测试参考subsequence_match.h。

### find_end

template <typename ForwardIterator1, typename ForwardIterator2>
orwardIterator1 search(orwardIterator1 first1, orwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);

template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
orwardIterator1 search(orwardIterator1 first1, orwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate binary_pred);

find_end更精确的名字应该叫search_end.

同search实现的功能基本类似，区别在于search寻找的是第一个这样的子序列，find_end寻找的是最后一个这样的子序列。

find_end的返回值与search相似，此处不赘述。

关于find_end的测试可以参考test_search函数，基本一样。

### search_n

template <typename ForwardIterator, typename Integer, typename T>
ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Integer count, const T& value);

template <typename ForwardIterator, typename Integer, typename T, typename BinaryPredicate>
ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Integer count, const T& value, BinaryPredicate binary_pred);

该算法查找[first, last)之中由count个相邻元素形成的子序列，其中所有元素都等于value。它返回一个iterator，指向这个子序列的起始点。 如果该子序列不存在，则返回last.

**注意：count允许为0. 当count为0时，search_n一定成功且返回值一定是first**

关于search_n的测试可参考subsequence_match.h。

## 计算元素个数

### count

template <typename InputIterator, typename EqualityComparable>
typename iterator_traits<InputIterator>::difference_type
count(InputIterator first, InputIterator last, const EqualityComparable& value);

该算法可以计算[first, last)中与value相等的元素个数。

该算法测试可参考count.h。

### count_if

template <typename InputIterator, typename Predicate>
typename iterator_traits<InputIterator>::difference_type
count(InputIterator first, InputIterator last, Predicate pred);

该算法与count极相似，但更一般化。

该算法计算[first, last）内满足某种条件的元素个数。某种条件指的是**pred(*i)为true**。

关于count_if的测试可以参考count.h。

## 比较两个Ranges

### equal

template <typename InputIterator1, typename InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate binary_pred);

该算法比较区间[first1, last1)和[first2, first2 + (last1 - first1))的元素，两者一一比较，如果均相等，则equal返回true，否则返回false。

该算法有两个版本，第一个版本采用operator==来比较元素，第二版本采用外界提供的函数对象binary_pred。

针对第二版本，当且仅当[first1, last1)中的每一个iterator i都满足binary_pred(*i, *(first2 + i - first1))为true，则第二版本返回true。

关于该算法测试可参考compare_range.h









