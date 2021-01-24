#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

// copy和copy_backward之间唯一重要差别在于赋值动作的顺序
void test_copy_backward() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    

    std::copy_backward(vec.begin(), vec.begin() + 3, vec.end());

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}