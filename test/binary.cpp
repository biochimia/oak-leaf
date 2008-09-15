//  Copyright (c) 2008 João Abecasis
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <oak_leaf/binary/tree.hpp>
#include <oak_leaf/binary_search/tree.hpp>
#include <oak_leaf/red_black/tree.hpp>

#include <breeze/debug/track_instances.hpp>

struct A
    : breeze::debug::track_instances<A>
{
};

int main()
{
    oak_leaf::binary        ::tree<int> bt_int;
    oak_leaf::binary_search ::tree<int> bst_int;
    oak_leaf::red_black     ::tree<int> rb_int;

    oak_leaf::binary        ::tree<A>   bt_A;
    oak_leaf::binary_search ::tree<A>   bst_A;
    oak_leaf::red_black     ::tree<A>   rb_A;

    oak_leaf::binary        ::tree<void> bt_void;
    oak_leaf::binary_search ::tree<void> bst_void;
    oak_leaf::red_black     ::tree<void> rb_void;

    bt_A.replace(bt_A.root(), A());
}
