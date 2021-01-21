#include <iterator>
#include <vector>
#include <utility>
#include <iostream>


// stl中distance的声明如下，distance的声明位于头文件<iterator>中
// template <typename InputIterator>
// typename std::iterator_traits<InputIterator>::difference_type
// distance(InputIterator first, InputIterator last);

void test_distance() {
    std::vector<int> vec = {1,2,3};
    std::cout << std::distance(vec.begin(), vec.end()) << std::endl;
}

// stl中advance声明如下
// template <typename InputIterator, typename Distance>
// void advance(InputIterator& i, Distance n);

void test_advance() {
    std::vector<int> vec = {1,2,3};
    auto i = vec.begin();
    // ++i 执行一次，取得2
    std::advance(i, 1);
    std::cout << *i << std::endl;
}