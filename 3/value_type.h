#include <iostream>
#include <vector>

// 取得某个iterator的value type
// 通过模版函数的参数推导

template <typename Iter, typename ValueType>
void f_impl(Iter iter, ValueType val) {
    ValueType temp(val);
    std::cout << temp << std::endl;
    return;
}

template <typename Iter>
void f(Iter iter) {
    f_impl(iter, *iter);
}

// 可以通过Iterator Traits手段进行value type的获取
// 场景，若要获得某个Iterator的value type作为函数返回值类型
// 通过对Iterator进行内嵌声明typedef，该方式足够通用，有些Iterator可能没有内嵌类型（譬如int *）
// Iterator Traits本质上采用计算机经典手段--增加中间层
template <typename Iterator>
struct iterator_traits {
    using value_type = typename Iterator::value_type;
};

// 针对int *等类型的迭代器，可以针对其进行模版便特化
template <typename Iterator>
struct iterator_traits<Iterator*>  {
    using value_type = Iterator;
};

// 也需要针对const int* 便特化
template <typename Iterator>
struct iterator_traits<const Iterator*> {
    using value_type = Iterator;
};

// 该函数用于测试iterator_traits
template <typename Iterator>
using ReturnValueType = typename iterator_traits<Iterator>::value_type;

// 以下泛型函数用来计算nonempty的数值之和
template <typename InputIterator>
ReturnValueType<InputIterator> sum_nonempty(InputIterator first, InputIterator last) {
    ReturnValueType<InputIterator> ret = *first++;
    for (; first != last; ++first) {
        ret += *first;
    }
    return ret;
}

void tets_value_type() {
    std::vector<int> vec(2,3);
    f(vec.begin());
    auto ret = sum_nonempty(vec.begin(), vec.end());
    std::cout << "ret: " << ret << std::endl;
    return;

}


