#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

// find算法存在与algorithm头文件中
void test_find() {
    std::vector<int> vec = {2, 4, 7};
    auto result = std::find(vec.begin(), vec.end(), 7);
    assert(result == vec.end() || *result == 7);
    if (result != vec.end()) {
        std::cout << *result << std::endl;
    } 
}

void test_find_if() {
    std::vector<int> vec = {2, 4, 7, 8};
    // 查找vec中是否有元素是偶数，如果是 返回
    auto p = std::find_if(vec.begin(), vec.end(), 
                          [](const auto& val) { return (val & 1) == 0; });

    std::cout << "Index of first odd = " << p - vec.begin() << std::endl; 
}

void test_adjacent_find() {
    std::vector<int> vec = {2, 3, 3, 8, 6, 5};
    
    {
        // 寻找第一个重复元素，使用版本1
        const auto iter = std::adjacent_find(vec.begin(), vec.end());
        if (iter != vec.end()) {
            std::cout << "Duplicate element: " << *iter << std::endl;
        }
    }
    
    {
        // 查找range之内不以递增次序排列的第一个元素
        // 也即查找第一个大于后继者的元素
        // 采用版本2
        const auto iter = std::adjacent_find(vec.begin(), vec.end(), std::greater<int>());
        if (iter == vec.end()) {
            std::cout << "The range is sorted in accending order." << std::endl;
        } else {
            std::cout << "Element " << iter - vec.begin() << " is out of range: "
                      << *iter << " > " << *(iter+1) << "." << std::endl;
        }
    }
}

void test_find_first_of() {
    // 利用find_first_of寻找字符串中的whitespace
    // whitespace：space(空格)、tab(制表符)或者neline(新行)
    const char *ws = " \t\n";
    const int n_ws = strlen(ws);

    char *s1 = "This sentence contains five words.";
    char *s2 = "OneWord";

    char *end1 = std::find_first_of(s1, s1 + strlen(s1), ws, ws + n_ws);
    char *end2 = std::find_first_of(s2, s2 + strlen(s2), ws, ws + n_ws);

    std::cout << "First word of s1: " << end1 - s1 << std::endl;
    std::cout << "First word of s2: " << end2 - s2 << std::endl;
}