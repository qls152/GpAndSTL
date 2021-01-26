# 排序和查找

本节所有的算法都以strick weak ordering来比较元素. 

## 对某个区间排序

### sort

关于sort算法，其有两个版本且该算法不是一个稳定排序算法，默认该算法是递增排序。

可以利用is_sorted测试一个区间是否是排序的。

该算法测试省略，因为使用较多。

### stable_sort

该算法使用方式同sort，其是稳定排序。

默认以递增方式排序。

### partial_sort

```
template <typename RandomAccessIterator>
void partial_sort(RandomAccessIterator first,
RandomAccessIterator middle, RandomAccessIterator last);

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void partial_sort(RandomAccessIterator first,
RandomAccessIterator middle, RandomAccessIterator last, StrictWeakOrdering comp);

```

该算法可重排[first, last)，使其中middle-first个最小元素以递增顺序排序。

该算法会导致input range中最小的middle - first个元素以递增顺序排序，并包含于[first, middle)内。其余的last-middle个元素安置于[middle, last)中，无任何特定顺序。

在某些场景下之所以选择partial_sort而非sort,仅仅是效率考量。

关于partial_sort的版本，此处不再介绍。

该算法的测试可参考sort.h。

### partial_sort_copy

```
template <typename InputIterator, class RandomAccessIterator>
void partial_sort_copy(InputIterator first, InputIterator last,
RandomAccessIterator result_first, RandomAccessIterator result_last);

template <typename InputIterator, class RandomAccessIterator, class StrictWeakOrdering>
void partial_sort_copy(InputIterator first, InputIterator last,
RandomAccessIterator result_first, RandomAccessIterator result_last, StrictWeakOrdering comp);
```

该算法是partial_sort的复制式版本。 

该算法会从[first, last)内复制前N个最小元素至[result_first, result_first+N)之中，这里N为last-first和result_last-result_first中的最小值. 被复制过去的元素以递增排序.

该算法返回值为result_first+N.

该算法测试可参考sort.h。

### nth_element

```
template <typename RandomAccessIterator>
void nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last, StrictWeakOrdering comp);
```

该算法会对range内的元素进行部分排序。他会重新排列[first, last), 使得iterator nth所指元素与整个[first, last)排序后的同一位置的元素相同。此外iterator nth也可作为分割之用：使得[nth, last)内没有任何一个元素小于[first, nth)内的元素。

该算法并不保证[first, nth）或者[nth, last)都会被排序。他只保证[first, nth)内的元素都小于[nth, last)内的元素.

该算法测试可参考sort.h

### is_sorted

```
template <typename ForwardIterator>
bool is_sorted(ForwardIterator first, ForwardIterator last);

template <typename ForwardIterator, typename StrictWeakOrdering>
bool is_sorted(ForwardIterator first, ForwardIterator last, StrictWeakOrdering comp);
```

该算法测试某个区间是否已排序，如是排序的则返回true, 否则返回false.

两个版本之间的差别在于比较元素的方式.

该算法测试可参考sort.h。