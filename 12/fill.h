#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

#include <cstdlib>

void test_fill() {
    std::vector<int> vec(4);
    std::fill(vec.begin(), vec.end(), 137);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
}

void test_generate() {
    std::vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), rand);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
}