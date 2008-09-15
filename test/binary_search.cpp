//  Copyright (c) 2008 João Abecasis
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <oak_leaf/binary/traversal.hpp>
#include <oak_leaf/binary_search/tree.hpp>

#include <breeze/debug/track_instances.hpp>

#include <iostream>

struct A
    : breeze::debug::track_instances<A>
{
    A() : value_() {}
    A(int val) : value_(val) {}

    int value_;
};

bool operator<(A const & lhs, A const & rhs)
{
    return lhs.value_ < rhs.value_;
}

template <class Ostr>
Ostr & operator<<(Ostr & ostr, A const & a)
{
    return ostr << a.value_;
}

struct node_printer
{
    template <class NodePointer>
    void operator()(NodePointer const & node)
    {
        std::cout << get_value(*node) << std::endl;
    }
};

int main()
{
    oak_leaf::binary_search ::tree<A> bst_int;

    bst_int.insert(5);
    bst_int.insert(5);
    bst_int.insert(6);
    bst_int.insert(3);
    bst_int.insert(2);
    bst_int.insert(8);
    bst_int.insert(9);
    bst_int.insert(0);
    bst_int.insert(4);

    in_order(bst_int.root(), node_printer());
}
