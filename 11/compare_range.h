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