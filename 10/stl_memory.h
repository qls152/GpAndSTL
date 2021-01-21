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