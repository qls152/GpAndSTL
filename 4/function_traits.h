
// stl并未提供函数指针的便特化
// 一：function objects并不是到处存在
// 二：许多运用function objects的算法，并不会明白取用其参数型别和返回型别
// ==============================================================

// stl中区分function objects和adaptable function objects，后者一般会指明
// 参数类型和返回型别

template <typename Arg, typename Result>
struct unary_function {
    typedef Arg    argument_type;
    typedef Result result_type;
};

template <typename Arg1, typename Arg2, typename Result>
struct binary_function {
    typedef Arg1    first_argument_type;
    typedef Arg2    second_argument_type;
    typedef Result  result_type;
};