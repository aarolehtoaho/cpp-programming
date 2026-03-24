// Created by Jack Toole, Fall 2011
// Modified by Veer Dedhia, Spring 2014
// Modified in Spring 2025 by Anna LaValle and Elmeri Uotila
// Modified in Spring 2026 by Henrik Peteri (remove deprecated std::iterator inheritance)

// Iterator code, initially from C++ reference:
// http://www.cplusplus.com/reference/std/iterator/iterator/
class ListIterator
{
    ListNode* p;
    public:

    using iterator_category = std::forward_iterator_tag;
    using value_type        = T;
    using difference_type   = std::ptrdiff_t;
    using pointer           = T*;
    using reference         = T&;

    ListIterator() : p(nullptr) { }
    ListIterator(ListNode * x) : p(x) { }
    ListIterator& operator++() { p = p->next; return *this; }
    ListIterator operator++(int) { ListNode* r = p; p = p->next; return ListIterator(r); }
    bool operator==(const ListIterator& rhs) const { return p == rhs.p; }
    bool operator!=(const ListIterator& rhs) const { return p != rhs.p; }
    const T & operator*() const  { return p->data; }
    const T * operator->() const { return &(p->data); }
    T & operator*() { return p->data; }
    T * operator->() { return &(p->data); }
};

typedef const ListIterator const_iterator;

const_iterator begin() const { return ListIterator(head); }
const_iterator end()   const { return ListIterator(nullptr); }
