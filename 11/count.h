#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

void test_count() {
    std::vector<int> vec = {2, 0, 4, 6, 0, 3};

    int ret = 0;
    auto num = std::count(vec.begin(), vec.end(), ret);
    std::cout << "Number of zeros: " << num << std::endl;
}

void test_count_if() {
    std::vector<int> vec = {2, 0, 1, 4, 6, 3};
    auto ret = std::count_if(vec.begin(), vec.end(), 
                             [](const auto& val) { return (val & 1) == 0; });
    std::cout << "Number of zeros: " << ret << std::endl;
}