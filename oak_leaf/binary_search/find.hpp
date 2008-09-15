//  Copyright (c) 2008 João Abecasis
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef OAK_LEAF_BINARY_SEARCH_FIND_HPP_INCLUDED_
#define OAK_LEAF_BINARY_SEARCH_FIND_HPP_INCLUDED_

#include <oak_leaf/binary_search/node.hpp>
#include <oak_leaf/node/value.hpp>

#include <boost/ref.hpp>

namespace oak_leaf { namespace binary_search {

    template <class NodePointer, class T>
    NodePointer & find(NodePointer & tree, T const & value)
    {
        boost::reference_wrapper<NodePointer> node(tree);

        while (node.get())
        {
            // Should this be std::less?
            if (get_value(*node.get()) < value)
                node = boost::ref(right(*node.get()));
            else if (value < get_value(*node.get()))
                node = boost::ref(left(*node.get()));
            else
                break;
        }

        return node;
    }

    template <class NodePointer, class T, class Compare>
    NodePointer & find(NodePointer & tree, T const & value, Compare comp)
    {
        boost::reference_wrapper<NodePointer> node(tree);

        while (node.get())
        {
            // Should this be std::less?
            if (comp(get_value(*node.get()), value))
                node = boost::ref(right(*node.get()));
            else if (comp(value, get_value(*node.get()), value))
                node = boost::ref(left(*node.get()));
            else
                break;
        }

        return node;
    }

}} // namespace oak_leaf::binary_search

#endif // include guard
