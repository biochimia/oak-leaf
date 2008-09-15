//  Copyright (c) 2008 João Abecasis
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef OAK_LEAF_NODE_COMBINER_HPP_INCLUDED_
#define OAK_LEAF_NODE_COMBINER_HPP_INCLUDED_

namespace oak_leaf { namespace node {

    template <class T0, class T1>
    struct combiner
        : T0, T1
    {
    };

}} // namespace oak_leaf::node

#endif // include guard
