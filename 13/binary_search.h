#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

void test_binary_search() {
    std::vector<int> vec = {1,2, 3, 4, 4, 4, 5,6};
    for (int i = 1; i <= 10; ++i) {
        std::cout << "searching for " << i << ": "
                  << (std::binary_search(vec.begin(), vec.end(), i) ? "present" : "not present")
                  << std::endl;
    }
}

void test_lower_bound() {
    std::vector<int> vec = {1,2, 3, 4, 4, 4, 5,6};
    for (int i = 1; i <= 10; ++i) {
        auto iter = std::lower_bound(vec.begin(), vec.end(), i);
        std::cout << "searching for " << i << ". ";
        std::cout << "Result: index = " << iter - vec.begin() << ", ";
        if (iter != vec.end()) {
            std::cout << "vec[" << iter - vec.begin() << "] == " << *iter << std::endl;
        } else {
            std::cout << "which is off-the-end." <<std::endl;
        }
    } 
}

void test_upper_bound() {
  std::vector<int> vec = {1,2, 3, 4, 4, 4, 5,6};
    for (int i = 1; i <= 10; ++i) {
        auto iter = std::upper_bound(vec.begin(), vec.end(), i);
        std::cout << "searching for " << i << ". ";
        std::cout << "Result: index = " << iter - vec.begin() << ", ";
        if (iter != vec.end()) {
            std::cout << "vec[" << iter - vec.begin() << "] == " << *iter << std::endl;
        } else {
            std::cout << "which is off-the-end." <<std::endl;
        }
    }  
}

void test_merge() {
    std::vector<int> v1 = {1, 4, 7};
    std::vector<int> v2 = {2, 3, 5};
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}