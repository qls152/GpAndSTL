// 首先定义各个concept相关的tag，保证唯一性
struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag, output_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

using ptrdiff_t = long;
// typename用于模版内嵌对象，告诉编译器该引用为类类型而非其他
template <typename Iterator>
struct iterator_traits {
    using iterator_category = typename Iterator::iterator_category; 
    using value_type = typename Iterator::value_type;
    using difference_type = typename Iterator::difference_type;
    using pointer = typename Iterator::pointer;
    using reference = typename Iterator::reference;
};

// 便特化
template <typename Iterator>
struct iterator_traits<Iterator*> {
    using iterator_category = random_access_iterator_tag; 
    using value_type = Iterator;
    using difference_type = unsigned long;
    using pointer = Iterator*;
    using reference = Iterator&;
};

// 便特化
template <typename Iterator>
struct iterator_traits<const Iterator*> {
    using iterator_category = random_access_iterator_tag; 
    using value_type = Iterator;
    using difference_type = ptrdiff_t;
    using pointer = const Iterator*;
    using reference = const Iterator&;
};

template <typename Category,
          typename Value,
          typename Distance = ptrdiff_t,
          typename Pointer = Value*,
          typename Reference = Value&>
struct Iterator {
    using iterator_category = Category;
    using value_type = Value;
    using difference_type = Distance;
    using pointer = Pointer;
    using reference = Reference;
};