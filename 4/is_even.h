#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // 引入find_if用于测试，省略重复定义find_if

// 判断某个数是否是偶数或者奇数

// 定义一个简单的函数指针
bool is_even(int x) {
    return (x & 1) == 0;
}

// 定义一个无状态的函数对象
// 注意：尽可能将函数对象的operator()声明为const member function
template <typename Number>
struct even {
    bool operator() (Number x) const {
        return (x & 1) == 0;
    }
};

// 函数对象比一般的函数指针更有扩展性，更有效率（因为operator()被声明为inline，
// 所以使用even时不需要任何函数调用）
// 类中声明和定义的函数默认为inline

// 定义有状态的函数对象
// 可以利用该种函数对象表现（具有局部状态的函数）
// last_name_is 测试条件为 集合元素的last_name字段等于某特定值
template <typename Name>
struct last_name_is {
    Name value;
    last_name_is(const Name& val) : value(val) {}
    bool operator() (const Name& x) const {
        return x == value;
    }
};

// 上述函数可以解释C++中lambda函数的工作原理。

void test_func_obj() {
    std::vector<int> vec = {1,2,3,4,5}; // 用于测试even
    std::vector<std::string> name = {"hello", "ok", "nice"}; // 用于测试last_name_is
    
    {
        auto iter = std::find_if(vec.begin(), vec.end(), is_even);
        if (iter == vec.end()) {
            std::cout << "vec no even" << std::endl;
        } else {
            std::cout << "vec has even: " << *iter << std::endl;
        }
    }

    {
        // even<int>() 构造函数对象
        auto iter = std::find_if(vec.begin(), vec.end(), even<int>());
        if (iter == vec.end()) {
            std::cout << "vec no even" << std::endl;
        } else {
            std::cout << "vec has even: " << *iter << std::endl;
        }  
    }

    {
        // even<int>() 构造函数对象
        auto iter = std::find_if(name.begin(), name.end(), last_name_is<std::string>("ok"));
        if (iter == name.end()) {
            std::cout << "no find name ok:" << std::endl;
        } else {
            std::cout << "find name: " << *iter << std::endl;
        }    
    }
}

