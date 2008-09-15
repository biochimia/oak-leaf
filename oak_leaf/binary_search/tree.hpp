//  Copyright (c) 2008 João Abecasis
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef OAK_LEAF_BINARY_SEARCH_TREE_HPP_INCLUDED_
#define OAK_LEAF_BINARY_SEARCH_TREE_HPP_INCLUDED_

#include <oak_leaf/node/combiner.hpp>
#include <oak_leaf/node/value.hpp>
#include <oak_leaf/binary/tree.hpp>
#include <oak_leaf/binary_search/find.hpp>
#include <oak_leaf/binary_search/node.hpp>

#include <memory>

namespace oak_leaf { namespace binary_search {

    template <class T, class Node =
            oak_leaf::node::combiner<
                oak_leaf::binary_search::node<
                    oak_leaf::node::combiner<
                        boost::mpl::arg<1>,
                        oak_leaf::node::value<T> > >,
                oak_leaf::node::value<T> >,
        class Alloc = std::allocator<Node> >
    struct tree
        : oak_leaf::binary::tree<T, Node, Alloc>
    {
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

        typename tree::const_pointer root()
        {
            return binary_tree::root();
        }

        typename tree::const_pointer root() const
        {
            return binary_tree::root();
        }

    private:
        typedef oak_leaf::binary::tree<T, Node, Alloc> binary_tree;

        using binary_tree::root;
        using binary_tree::replace;
    };

}} // namespace oak_leaf::binary_search

#endif // include guard
