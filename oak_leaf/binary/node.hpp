//  Copyright (c) 2008 João Abecasis
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef OAK_LEAF_BINARY_NODE_HPP_INCLUDED_
#define OAK_LEAF_BINARY_NODE_HPP_INCLUDED_

#include <oak_leaf/detail/pointer.hpp>
#include <oak_leaf/node/detail/crtp.hpp>

#include <boost/mpl/if.hpp>

#include <boost/type_traits/is_void.hpp>

namespace oak_leaf { namespace binary {

    template <class Derived = void>
    struct node
    {
        typedef typename oak_leaf::node::detail::crtp<Derived, node>::type
            derived_type;

        typedef oak_leaf::detail::pointer<derived_type *> pointer;
        typedef oak_leaf::detail::pointer<derived_type const *> const_pointer;

        pointer left, right;
    };

    template <class Node>
    inline bool has_left(Node const & tree)
    {
        return tree.left;
    }

    template <class Node>
    inline bool has_right(Node const & tree)
    {
        return tree.right;
    }

    template <class Node>
    inline typename Node::pointer & left(Node & tree)
    {
        return tree.left;
    }

    template <class Node>
    inline typename Node::pointer & right(Node & tree)
    {
        return tree.right;
    }

    template <class Node>
    inline typename Node::const_pointer left(Node const & tree)
    {
        return tree.left;
    }

    template <class Node>
    inline typename Node::const_pointer right(Node const & tree)
    {
        return tree.right;
    }

    // Anti-clockwise rotation of node
    template <class NodePointer>
    inline void rotate_left(NodePointer & node)
    {
        NodePointer   n  = node;
        NodePointer & r  = right(*n);
        NodePointer & rl = left(*r);

        node = r;
        r    = rl;
        rl   = n;
    }

    // Clockwise rotation of node
    template <class NodePointer>
    inline void rotate_right(NodePointer & node)
    {
        NodePointer   n  = node;
        NodePointer & l  = left(*n);
        NodePointer & lr = right(*r);

        node = l;
        l    = lr;
        lr   = n;
    }

}} // namespace oak_leaf::binary

#endif // include guard
