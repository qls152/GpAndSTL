#include <iostream>
#include "iterator_traits.h"

// 将i递减n次
template <typename InputIterator, typename Distance>
void advance_II(InputIterator& iter, Distance n) {
    for (; n > 0; --n, ++iter);
}

// 与上述相同，但允许逆向前进
template <typename BidirectionalIterator, typename Distance>
void advance_BI(BidirectionalIterator& iter, Distance n) {
    if (n >= 0) {
        for (; n > 0; --n, ++iter);
    } else {
        for (; n < 0; ++n, --iter);
    }
}

// Random Access Iterator需要用到operator+=
template <typename RandomAccessIterator, typename Distance>
void advance_RAI(RandomAccessIterator& iter, Distance n) {
    iter += n;
}

// 上述三种advance, 究竟该选择那种呢？ 这个由使用场景决定，但我们可以将上述三种advance结合起来，实现如下
// template <typename InputIterator, typename Distance>
// void advance(InputIterator& iter, Distance n) {
//    if (is_random_access_iter(iter)) {
//       advance_RAI(iter, n);
//    } else if(is_bidirection_iter(iter)) {
//        advance_BI(iter, n);
//    } else {
//        advance_II(iter, n);
//    }
// }
// 上述advance实现缺乏效率，因为if else是在运行时进行判断，我们需要的是在编译时进行判断
// 故需要采用函数重载
// 重载concepts的实现如下



template <typename InputIterator, typename Distance>
void advance(InputIterator& iter, Distance n, input_iterator_tag) {
    for (; n > 0; --n, ++iter);
}

template <typename ForwardIterator, typename Distance>
void advance(ForwardIterator& iter, Distance n, forward_iterator_tag) {
    for (; n > 0; --n, ++iter);
}

template <typename BidirectionalIterator, typename Distance>
void advance(BidirectionalIterator& iter, Distance n, bidirectional_iterator_tag) {
   if (n >= 0) {
        for (; n > 0; --n, ++iter);
    } else {
        for (; n < 0; ++n, --iter);
    } 
}

template <typename RandomAccessIterator, typename Distance>
void advance(RandomAccessIterator& iter, Distance n, random_access_iterator_tag) {
    iter += n;
}

template <typename InputIterator, typename Distance>
void advance(InputIterator& iter, Distance n) {
    advance(iter, n, typename iterator_traits<InputIterator>::iterator_category());
}

void test_advance() {
    int A[] = {1, 2, 3};
    int *p = A;
    advance(p, 1);
    std::cout << "*p : " << *p << std::endl;
    return;
}



