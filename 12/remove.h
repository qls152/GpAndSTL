#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

void test_remove() {
    // 真正想删除sequence的一个元素，并且改变相应的大小可以采用
    // 先remove，然后erase
    std::vector<int> vec = {1, 2, 3, 1, 4, 5};
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    // 移除1
    auto new_last = std::remove(vec.begin(), vec.end(), 1);
    std::cout << vec.size() << std::endl;
    std::copy(vec.begin(), new_last, std::ostream_iterator<int>(std::cout, " "));

    // 删除元素1
    vec.erase(new_last, vec.end());
    std::cout << std::endl << vec.size() << std::endl;
}

void test_remove_if() {
    std::vector<int> vec = {1, 32, 4, 6};

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

    // 移除并删除vec中的偶数
    auto new_end = std::remove_if(vec.begin(), vec.end(), 
        [] (const auto& val) { return (val & 1) == 0; });

    vec.erase(new_end, vec.end());
    std::cout << std::endl;
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void test_remove_copy() {
    std::vector<int> vec = {1, 1, 2, 4, 5};
    std::remove_copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "), 1);
}

void test_unique() {
    std::vector<int> vec = {1, 3, 3, 3, 2, 4, 2, 4};

    // 本次测试仅仅测试版本二，关于版本一可参考版本二
    auto new_last = std::unique(vec.begin(), vec.end(), [] (const auto& a, const auto& b) { return a == b;});

    vec.erase(new_last, vec.end());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
}