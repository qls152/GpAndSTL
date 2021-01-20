#include <iterator>
#include <vector>
#include <list>
#include <iostream>

void test_sequence() {
    std::list<int> lst = {1, 2, 3, 4};
    // 针对sequence container的insert和erase，不仅提供了单元素版本
    // 同时也提供了安插和删除整个range的版本。
    // 如果你真的安插或者删除整个range，使用多元素版本来的比单元素版本快许多(至少不会比单元素版本慢)
    std::vector<int> vec;
    // 多元素版本
    vec.insert(vec.begin(), lst.begin(), lst.end());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // range erase
    vec.erase(vec.begin(), vec.end());
    std::cout << "vec size: " << vec.size() << std::endl;
}

// 测试安插语义与覆盖语义
void  test_insert_or_overwrite() {
    std::list<int> lst = {1, 2, 3, 5};
    std::vector<int> vec;

    // 此时copy实现的是覆盖语义
    // 覆盖语义要求其copy的目的vec必须能够实现vec[index] = lst[index]
    // 此时vec未初始化，因此下面语句会core掉
    // std::copy(lst.begin(), lst.end(), vec.begin());
    
    // 针对未初始化的sequence，可采用安插语义，会在相应的index进行对象的构造
    // 需要采用iterator adapter来完成安插语义
    std::copy(lst.begin(), lst.end(), std::back_inserter(vec));
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}