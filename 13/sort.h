#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

void test_partial_sort() {
    std::vector<int> vec = {7, 2, 6, 11, 3, 12, 10, 8, 4, 1, 5};
    std::partial_sort(vec.begin(), vec.begin() + 5, vec.end());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void test_paritial_sort_copy() {
    std::vector<int> vec = {7, 2, 6, 11, 3, 12, 10, 8, 4, 1, 5};
    std::vector<int> ret(4);
    std::partial_sort_copy(vec.begin(), vec.begin() + 4, ret.begin(), ret.end());
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void test_nth_element() {
   std::vector<int> vec = {7, 2, 6, 11, 3, 12, 10, 8, 4, 1, 5};
   std::nth_element(vec.begin(), vec.begin() + 6, vec.end());
   std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
}

void test_is_sorted() {
   std::vector<int> vec = {7, 2, 6, 11, 3, 12, 10, 8, 4, 1, 5};
   auto is_sort = std::is_sorted(vec.begin(), vec.end());
   std::cout << (is_sort ? "is sort" : "not is sort") << std::endl; 
}