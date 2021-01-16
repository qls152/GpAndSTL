#include "iterator_traits.h"

// 该两个iterator奉行Forward iterator的所有条件
template <typename Node,
          typename Reference,
          typename Pointer>
struct node_wrap_base
  :public Iterator<forward_iterator_tag,
                   Node, ptrdiff_t, Pointer, Reference> {
  typedef node_wrap_base<Node, Node&, Node*> iterator;
  typedef node_wrap_base<Node, const Node&, const Node*> const_iterator;
  Pointer ptr;
  
  node_wrap_base(Pointer p) : ptr(p) {}
  node_wrap_base(const iterator& iter) : ptr(iter.ptr) {}

  Reference operator*() { return *ptr; }
  Pointer operator->() { return ptr; }

  void incr() { ptr = ptr->next; }
  bool operator==(const node_wrap_base& x) const { return ptr == x.ptr; }
  bool operator!=(const node_wrap_base& x) const { return ptr != x.ptr; }
};

template <typename Node>
struct node_wrap : public node_wrap_base<Node, Node*, Node&> {
  typedef node_wrap_base<Node, Node*, Node&> Base;

  node_wrap(Node *p) : Base(p) {}
  node_wrap(const node_wrap<Node>& x) : Base(x) {}
  node_wrap& operator++() {
      incr();
      return *this;
  }

  node_wrap operator++(int) {
      node_wrap tmp = *this;
      incr();
      return tmp;
  }
};

// 实现constant版本的关键点在于可以将mutable iterator转换为constant
template <typename Node>
struct constant_node_wrap : public node_wrap_base<Node, const Node*, const Node&> {
    typedef node_wrap_base<Node, const Node*, const Node&> Base;

    constant_node_wrap(Node *p) : Base(p) {}
    constant_node_wrap(const node_wrap<Node>& x) : Base(x) {}

    constant_node_wrap& operator++() {
        incr();
        return *this;
    }

    constant_node_wrap operator++(int) {
        constant_node_wrap temp = *this;
        incr();
        return temp;
    }
}


