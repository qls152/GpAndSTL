#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

void test_swap() {
    int a = 1;
    int b = 2;

    std::cout << "a = " << a << ",  b = " << b << std::endl;
    std::swap(a, b);
    std::cout << "a = " << a << ",  b = " << b << std::endl;
}

void test_iter_swap() {
   int a = 1;
   int b = 2;

   std::cout << "a = " << a << ",  b = " << b << std::endl;
   std::iter_swap(&a, &b);
   std::cout << "a = " << a << ",  b = " << b << std::endl; 
}

void test_swap_ranges() {
    std::vector<int> vec1 = {1, 2 ,3};
    std::vector<int> vec2 = {4, 5, 6};

    std::cout << "Swap before: " << std::endl;
    std::cout << "vec1 : ";
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::swap_ranges(vec1.begin(), vec1.end(), vec2.begin());

    std::cout << "Swap after: " << std::endl;
    std::cout << "vec1 : ";
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void test_transform() {
    {
        // 版本一测试，*(result+n) = op(*(first + n))
        std::vector<int> vec1 = {1, 2, 4};
        std::vector<int> vec2(vec1.size());

        std::transform(vec1.begin(), vec1.end(), vec2.begin(), 
            [](const auto& val) -> int { return val + 1;});
        std::cout << "vec2: ";
        std::copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    {
        // 版本二，*(result + n) = op(*(first1 + n), *(first2 + n))
        std::vector<int> vec1 = {1, 2, 3};
        std::vector<int> vec2 = {4, 5, 6};

        std::cout << "vec1 plus vec2 : " << std::endl;
        std::transform(vec1.begin(), vec1.end(), vec2.begin(), 
            std::ostream_iterator<int>(std::cout, " "), std::plus<int>());
        std::cout << std::endl;
    }
}