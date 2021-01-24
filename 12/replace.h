#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void test_replace() {
    std::vector<int> vec = {2, 3, 4, 6, 7, 7, 8};

    std::cout << "raw vec: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "replace 7 : ";
    std::replace(vec.begin(), vec.end(), 7, 0);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

}

void test_replace_if() {
    // 将所有负值都替换为0
    std::vector<int> vec = {-1, -2, -1};
    
    std::cout << " Raw vec: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << " Replace vec: ";
    std::replace_if(vec.begin(), vec.end(), [](const auto& val) { return val < 0; }, 0);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

}

void test_replace_copy() {
    std::vector<int> vec = {1, 2, 3, 1};
    // 将1替换成99
    std::vector<int> vec1(vec.size());

    std::replace_copy(vec.begin(), vec.end(), vec1.begin(), 1, 99);
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void test_replace_copy_if() {
     // 将所有负值都替换为0
    std::vector<int> vec = {-1, -2, -1};
    std::vector<int> vec1(vec.size());
    
    std::cout << " Raw vec: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << " Replace vec1: ";
    std::replace_copy_if(vec.begin(), vec.end(), vec1.begin(),[](const auto& val) { return val < 0; }, 0);
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}