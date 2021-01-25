#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

void test_partition() {
    std::vector<int> vec = {1, 2, 4, 5, 7};
    std::partition(vec.begin(), vec.end(), [](const auto& val) { return val > 4; });
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void test_random_shuffle() {
    std::vector<int> vec = {1, 2, 4, 6, 7};
    std::random_shuffle(vec.begin(), vec.end());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}