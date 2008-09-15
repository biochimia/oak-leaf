//  Copyright (c) 2008 João Abecasis
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef OAK_LEAF_RED_BLACK_TREE_HPP_INCLUDED_
#define OAK_LEAF_RED_BLACK_TREE_HPP_INCLUDED_

#include <oak_leaf/node/combiner.hpp>
#include <oak_leaf/node/value.hpp>
#include <oak_leaf/red_black/node.hpp>
#include <oak_leaf/binary_search/tree.hpp>

#include <memory>

namespace oak_leaf { namespace red_black {

    template <class T, class Node =
            oak_leaf::node::combiner<
                oak_leaf::red_black::node<
                    oak_leaf::node::combiner<
                        boost::mpl::arg<1>,
                        oak_leaf::node::value<T> > >,
                oak_leaf::node::value<T> >,
        class Alloc = std::allocator<Node> >
    struct tree
        : oak_leaf::binary_search::tree<T, Node, Alloc>
    {
        typedef oak_leaf::binary_search::tree<T, Node, Alloc>
            binary_search_tree;

        template <class U>
        std::pair<bool, typename tree::const_pointer> insert(U const & value)
        {
            typename tree::pointer & position
                = find(binary_tree::root(), value);

            if (!position)
            {
                this->replace(position, value);

                return std::pair<bool,
                    typename tree::const_pointer>(true, position);
            }

            return std::pair<bool,
                typename tree::const_pointer>(false, position);
        }
    };

}} // namespace oak_leaf::red_black

#endif // include guard
