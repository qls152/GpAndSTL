#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

void test_reverse_copy() {
    std::vector<int> vec = {0, 1, 2};

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::reverse_copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void test_rotate() {
    // swap_ranges交换的是两个相等长度的range
    // rotate可以交换两个长度不同但相邻的range
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::rotate(vec.begin(), vec.begin() + 1, vec.end());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void test_next_permutation() {
    // 仅仅测试版本一，版本二可参考版本一
    std::vector<int> vec = {1, 2, 3, 4};
    do {
        std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    } while (std::next_permutation(vec.begin(), vec.end()));
}