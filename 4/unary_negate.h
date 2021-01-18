
// 定义unary_negate函数对象适配器
template <typename AdaptablePredicate>
class unary_negate {
private:
    AdaptablePredicate pred;  //需要适配的函数对象

public:
    using argument_type = typename AdaptablePredicate::argument_type;
    using result_type = typename AdaptablePredicate::result_type;

    unary_negate(const AdaptablePredicate& x) : pred(x) {}
    bool operator() (const argument_type& x) const {
        return !pred(x);
    }
};

// 使用上述函数对象适配器比较累赘，因此针对函数对象适配器，会提供一个
// 辅助函数，使得unary_negate object的产生简化
// 主要利用模版函数参数推倒
template <typename AdaptablePredicate>
inline unary_negate<AdaptablePredicate> notl(const AdaptablePredicate& pred) {
    return unary_negate<AdaptablePredicate>(pred);
}