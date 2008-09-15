//  Copyright (c) 2008 João Abecasis
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef OAK_LEAF_BINARY_TREE_HPP_INCLUDED_
#define OAK_LEAF_BINARY_TREE_HPP_INCLUDED_

#include <oak_leaf/detail/pointer.hpp>
#include <oak_leaf/node/combiner.hpp>
#include <oak_leaf/node/deleter.hpp>
#include <oak_leaf/node/value.hpp>

#include <oak_leaf/binary/node.hpp>
#include <oak_leaf/binary/traversal.hpp>

#include <boost/get_pointer.hpp>

#include <memory>

namespace oak_leaf { namespace binary {

    template <class T,
        class Node =
            oak_leaf::node::combiner<
                oak_leaf::binary::node<
                    oak_leaf::node::combiner<
                        boost::mpl::arg<1>,
                        oak_leaf::node::value<T>
                    >
                >,
                oak_leaf::node::value<T> >,
        class Alloc = std::allocator<Node> >
    struct tree
    {
        typedef Node node_type;
        typedef typename node_type::value_type value_type;
        typedef typename node_type::reference reference;
        typedef typename node_type::const_reference const_reference;
        typedef Alloc allocator_type;

    protected:
        typedef detail::pointer<node_type *> pointer;
        typedef detail::pointer<node_type const *> const_pointer;

    public:
        ~tree()
        {
            erase(root_);
        }

        void replace(pointer & position)
        {
            // TODO: Exception safety with magical ptrs
            pointer p(allocator_.allocate(1));
            allocator_.construct(boost::get_pointer(p), node_type());
            // TODO: Initialize value, when using uninitialized buffers

            pointer old = position;
            position = p;

            erase(old);
        }

        template <class U>
        void replace(pointer & position, U const & value)
        {
            // TODO: Exception safety with magical ptrs
            pointer p(allocator_.allocate(1));
            allocator_.construct(boost::get_pointer(p), node_type());
            // TODO: Initialize value, when using uninitialized buffers
            get_value(*p) = value;

            pointer old = position;
            position = p;

            erase(old);
        }

        void erase(pointer & node)
        {
            oak_leaf::binary::post_order(node,
                oak_leaf::node::get_deleter(allocator_));
            node = pointer();
        }
        
        bool empty() const
        {
            return !root_;
        }

        pointer & root()
        {
            return root_;
        }

        const_pointer & root() const
        {
            return root_;
        }

    private:
        allocator_type allocator_;
        pointer root_;
    };

}} // namespace oak_leaf::binary

#endif // include guard
