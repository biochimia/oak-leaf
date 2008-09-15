//  Copyright (c) 2008 João Abecasis
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef OAK_LEAF_BINARY_TRAVERSAL_HPP_INCLUDED_
#define OAK_LEAF_BINARY_TRAVERSAL_HPP_INCLUDED_

#include <boost/pointee.hpp>
#include <boost/ref.hpp>

#include <queue>
#include <iostream>

namespace oak_leaf { namespace binary {

    template <class BinaryNodePointer, class F>
    void pre_order(BinaryNodePointer const & tree, F visitor)
    {
        if (!tree)
            return;

        visitor(tree);

        if (has_left(*tree))
            pre_order<BinaryNodePointer>(left(*tree), visitor);
        if (has_right(*tree))
            pre_order<BinaryNodePointer>(right(*tree), visitor);
    }

    template <class BinaryNodePointer, class F>
    void in_order(BinaryNodePointer const & tree, F visitor)
    {
        if (!tree)
            return;

        if (has_left(*tree))
            in_order<BinaryNodePointer>(left(*tree), visitor);

        visitor(tree);

        if (has_right(*tree))
            in_order<BinaryNodePointer>(right(*tree), visitor);
    }

    template <class BinaryNodePointer, class F>
    void post_order(BinaryNodePointer const & tree, F visitor)
    {
        if (!tree)
            return;

        if (has_left(*tree))
            post_order<BinaryNodePointer>(left(*tree), visitor);
        if (has_right(*tree))
            post_order<BinaryNodePointer>(right(*tree), visitor);

        visitor(tree);
    }

    template <class BinaryNodePointer, class F>
    void level_order(BinaryNodePointer & tree, F visitor)
    {
        if (!tree)
            return;

        std::queue<boost::reference_wrapper<BinaryNodePointer> > queue;
        queue.push(boost::ref(tree));

        while (!queue.empty())
        {
            boost::reference_wrapper<BinaryNodePointer> node = queue.front();
            queue.pop();

            if (has_left(*node.get()))
                queue.push(boost::ref(left(*node.get())));
            if (has_right(*node.get()))
                queue.push(boost::ref(right(*node.get())));

            visitor(node.get());
        }
    }

}} // namespace oak_leaf::binary

#endif // include guard
