#include <stdint.h>
#include <iterator>
#include <iostream>

// size_t N 为template非型别参数，是语言自身的一个特性
// 在C++中，struct如果想要获得与C语言一样的初始化动作，需要满足如下限制
// 1. 不能声明任何构造函数
// 2. 不能拥有任何private或者protected members
// block的iterator为random access iterator
template <typename T, size_t N>
struct block {
    typedef T                   value_type;
    typedef value_type*         pointer;
    typedef const value_type*   const_pointer;
    typedef value_type&         reference;
    typedef const value_type&   const_reference;

    typedef ptrdiff_t           difference_type;
    typedef size_t              size_type;

    typedef pointer             iterator;
    typedef const_pointer       const_iterator;

    iterator begin() { return data; }
    iterator end()   { return data + N; }

    const_iterator begin() const { return data; }
    const_iterator end() const   { return data + N; }
    
    // std::reverse_iterator 迭代器适配器
    // const_reverse_iterator++相当于 const_iterator--
    typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;
    typedef std::reverse_iterator<iterator>         reverse_iterator;

    reverse_iterator rbegin() { return reverse_iterator(end()); }
    reverse_iterator rend()   { return reverse_iterator(begin()); }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(end());
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(begin());
    }

    reference operator[] (size_type n) { return data[n]; }
    const_reference operator[] (size_type n) const { return data[n]; }

    size_type size() const { return N; }
    size_type max_size() const { return N; }
    bool empty() const { return N == 0; }

    void swap(block& x) {
        for (size_t n = 0; n < N; ++n) {
            std::swap(data[n], x.data[n]);
        }
    }

    T data[N];
};

// operator== 实现
template <typename T, size_t N>
bool operator==(const block<T, N> &x, const block<T, N> &y) {
    for (size_t n = 0; n < N; ++n) {
        if (x.data[n] != y.data[n]) {
            return false;
        }
    }

    return true;
}

template <typename T, size_t N>
bool operator<(const block<T, N> &x, const block<T, N> &y) {
    for (size_t n = 0; n < N; ++n) {
        if (x.data[n] >= y.data[n]) {
            return false;
        }
    }

    return true;
}

void test_block() {
    block<int, 5> val = {1,2,3,4,5};
    for (const auto& v : val) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}



