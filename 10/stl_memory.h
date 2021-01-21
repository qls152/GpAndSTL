#include <memory>
#include <string>
#include <iostream>

// construct 在memory中声明
// C++11中construct是allocator的一个成员函数
// 因此需要先声明一个allocator类
void test_construct() {
    std::string *ptr = (std::string*) malloc(sizeof(std::string));
    std::allocator<std::string> allocp;
    allocp.construct(ptr, "test");
    
    std::cout << *ptr << std::endl;
}

// C++11中不存在范围destory
void test_destory() {
    class Int {
    public:
        Int(int x) : val_(x) {}
        int get() { return val_; }
    private:
        int val_;

    };

    Int A[] = {Int(1), Int(2), Int(3)};
    std::allocator<Int> allocInt;
    for (auto& val : A) {
        allocInt.destroy(&val);
    }

    allocInt.construct(A + 0, Int(10));
    allocInt.construct(A + 1, Int(11));
    allocInt.construct(A + 2, Int(12));

    for (auto& val : A) {
        std::cout << val.get() << " ";
    }

    std::cout << std::endl;
}

// uninitialized_copy 会使用拷贝构造函数
void test_uninitialized_copy() {
    class Int {
    public:
        Int(int x) : val_(x) {}
        // Int不具有默认构造函数
        int get() { return val_; }
    private:
        int val_;
    };

    int A[] = {1, 2, 3, 4, 5, 6, 7};
    const auto N = sizeof(A) / sizeof(int);

    Int* A1 = (Int*) malloc(N * sizeof(Int));
    std::uninitialized_copy(A, A + N, A1);

    for (size_t i = 0; i < N; ++i) {
        std::cout << A1[i].get() << " ";
    }

    std::cout << std::endl;
}

void test_uninitialized_fill() {
    class Int {
    public:
        Int(int x) : val_(x) {}
        // Int不具有默认构造函数
        int get() { return val_; }
    private:
        int val_;
    };

    Int val(46);
    const int N = 13;
    Int *A = (Int*)malloc(N * sizeof(Int));
    std::uninitialized_fill(A, A + N, val);
    for (size_t i = 0; i < N; ++i) {
        std::cout << A[i].get() << " ";
    }
    std::cout << std::endl;

    Int *A1 = (Int*)malloc(N * sizeof(Int));
    std::uninitialized_fill_n(A1, N, val);

    for (size_t i = 0; i < N; ++i) {
        std::cout << A1[i].get() << " ";
    }
    std::cout << std::endl;

}