#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

void test_equal() {

    {
        // 针对版本一，比较两个ranges是否相等
        int A1[] = {3, 2, 4};
        int A2[] = {3, 3, 4};
        if (std::equal(A1, A1 + sizeof(A1) / sizeof(int), A2)) {
            std::cout << "Equal" << std::endl;
        } else {
            std::cout << "Not equal" << std::endl;
        }
    }

    {
        // 比较两个ranges是否相等，不论大小写
        const char* s1 =  "This is a Test";
        const char* s2 =  "This is a test";
        const int N = strlen(s1);

        bool ret = std::equal(s1, s1 + N, s2, 
            [](char c1, char c2) { return toupper(c1) == toupper(c2); });
        if (ret) {
            std::cout << "Equal" << std::endl;
        } else {
            std::cout << "Not equal" << std::endl;
        }
    }
}

void test_mismatch() {
    {
        // 版本一，比较两个ranges内第一个不同的元素的位置
       int A1[] = {3, 2, 4};
       int A2[] = {3, 3, 4};
       const int N = sizeof(A1) / sizeof(int);

       auto ret = std::mismatch(A1, A1 + N, A2);
       if (ret.first == A1 + N) {
           std::cout << "The two ranges do not differ." << std::endl;
       } else {
           std::cout << "First mismatch is in position "
                     << ret.first - A1 << std::endl;
            
           std::cout << "Value:  " << *(ret.first) << ", "
                     << *(ret.second) << std::endl;
            
       }
    }

    {
        // 版本二，比较两个字符串中第一个字符不相同的位置，不论大小写
        const char* s1 =  "This is a Test";
        const char* s2 =  "This is a test";
        const int N = strlen(s1);

        auto ret = std::mismatch(s1, s1 + N, s2, 
            [](char c1, char c2) { return toupper(c1) == toupper(c2); });
        
        if (ret.first == s1 + N) {
           std::cout << "The two strings do not differ." << std::endl;
        } else {
           std::cout << "The strings differ starting at character is "
                     << ret.first - s1 << std::endl;
            
           std::cout << "Trailing part of s1:  " << ret.first << std::endl;
           std::cout << "Trailing part of s2:  " << ret.second << std::endl;
        } 
    }
}

void test_lexicographical_compare() {
    // 此处只测试版本一，版本二可自己实现
    int A1[] = {3, 1, 4, 1, 5, 9, 3};
    int A2[] = {3, 1, 4, 2, 8, 5, 7}; 
    int A3[] = {1, 2, 3, 4};
    int A4[] = {1, 2, 3, 4, 5};

    const int N1 = sizeof(A1) / sizeof(int);
    const int N2 = sizeof(A2) / sizeof(int);
    const int N3 = sizeof(A3) / sizeof(int);
    const int N4 = sizeof(A4) / sizeof(int);

    bool c12 = std::lexicographical_compare(A1, A1 + N1, A2, A2 + N2);
    bool c34 = std::lexicographical_compare(A3, A3 + N3, A4, A4 + N4);

    std::cout << "A1[] < A2[]: " << (c12 ? "true" : "false") << std::endl; 
    std::cout << "A3[] < A4[]: " << (c34 ? "true" : "false") << std::endl; 
}