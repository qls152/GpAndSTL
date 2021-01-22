#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>

// 下面实现的函数对象用于search版本二的测试
// 主要是为了实现寻找三数形成的子序列，三数的最末一个阿拉伯数字分别为1，2，3
template <typename Integer>
struct congruent {
    congruent(Integer mod) : N(mod) {}
    bool operator() (Integer a, Integer b) const {
        return (a - b) % N == 0;
    }

    Integer N;
};

void test_search() {
    // 测试版本一
    {
        std::vector<int> vec1 = {1, 2, 3, 4, 5, 6};
        std::vector<int> vec2 = {1, 2, 3};

        const auto iter = std::search(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
        if (iter != vec1.end()) {
            std::copy(iter, iter + vec2.size(), std::ostream_iterator<int>(std::cout, " "));
            std::cout << std::endl;
        } else {
            std::cout << "Couldn't find subvec" << std::endl;
        }
    }

    // 测试版本二
    {
        int A[10] = {23, 46, 81, 2, 43, 19, 14, 98, 72, 51};
        int digits[3] = {1, 2, 3};

        int *seq = std::search(A, A + 10, digits, digits + 3, congruent<int>(10));

        if (seq != A + 10) {
            std::cout << "Subsequence: " << std::endl;
            std::copy(seq, seq + 3, std::ostream_iterator<int>(std::cout, " "));
            std::cout << std::endl;
        } else {
            std::cout << "Subsequence not found" << std::endl;
        }
    }
    
}

bool eq_nosign(int x, int y) {
    return std::abs(x) == std::abs(y); 
}

void test_search_n() {
    struct TestSearch {
        void lookup(int* first, int *last, size_t count, int val) {
            std::cout << "Searching for a sequence of " << count
                      << " '" << val << " '"
                      << (count != 1 ? "s: " : ": ");
            int *ret = std::search_n(first, last, count, val);
            if (ret == last) {
                std::cout << "Not found" << std::endl;
            } else {
                std::cout << "Index = " << ret - first << std::endl;
            }
        }

        void look_nosign(int *first, int *last, size_t count, int val) {
           std::cout << "Searching for a (sign-insensitive) sequence of " << count
                      << " '" << val << " '"
                      << (count != 1 ? "s: " : ": "); 
            int *ret = std::search_n(first, last, count, val, eq_nosign);
            if (ret == last) {
                std::cout << "Not found" << std::endl;
            } else {
                std::cout << "Index = " << ret - first << std::endl;
            }
        }
    };

    TestSearch ts;
    const int N = 10;
    int A[N] = {1, 2, 1, 1, 3, -3, 1, 1, 1,1};
    ts.lookup(A, A+N, 1, 4);
    ts.look_nosign(A, A+N, 1, 3);

}