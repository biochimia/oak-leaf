//  Copyright (c) 2008 João Abecasis
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef OAK_LEAF_RED_BLACK_NODE_HPP_INCLUDED_
#define OAK_LEAF_RED_BLACK_NODE_HPP_INCLUDED_

#include <oak_leaf/binary_search/node.hpp>
#include <oak_leaf/node/detail/crtp.hpp>

#include <boost/mpl/protect.hpp>

namespace oak_leaf { namespace red_black {

    template <class Derived = void>
    struct node
        : oak_leaf::binary_search::node<boost::mpl::protect<
                typename oak_leaf::node::detail::crtp<Derived, node<Derived>
              >::type> >
    {
        enum Color
        {
            black,
            red
        };

        Color color;
    };

}} // namespace oak_leaf::red_black

#endif // include guard
