//  Copyright (c) 2008 João Abecasis
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef OAK_LEAF_NODE_DELETER_HPP_INCLUDED_
#define OAK_LEAF_NODE_DELETER_HPP_INCLUDED_

#include <boost/get_pointer.hpp>

namespace oak_leaf { namespace node {

    template <class Allocator>
    struct deleter
    {
        deleter(Allocator & alloc)
            : allocator_(alloc)
        {
        }

        template <class NodePointer>
        void operator()(NodePointer const & node)
        {
            // TODO: Assert the node has no live children

            typename Allocator::pointer p(boost::get_pointer(node));
            allocator_.destroy(p);
            allocator_.deallocate(p, 1);
        }

    private:
        Allocator & allocator_;
    };

    template <class Allocator>
    inline deleter<Allocator> get_deleter(Allocator & alloc)
    {
        return deleter<Allocator>(alloc);
    }

}} // namespace oak_leaf::node

#endif // include guard
