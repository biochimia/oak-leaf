//  Copyright (c) 2008 João Abecasis
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef OAK_LEAF_NODE_VALUE_HPP_INCLUDED_
#define OAK_LEAF_NODE_VALUE_HPP_INCLUDED_

#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/type_traits/is_void.hpp>

#include <boost/utility/enable_if.hpp>


namespace oak_leaf { namespace node {

    template <class T>
    struct value
    {
        typedef T value_type;
        typedef typename boost::add_reference<T>::type reference;
        typedef typename boost::add_reference<
            typename boost::add_const<T>::type>::type const_reference;

        reference get()
        {
            return t;
        }

        const_reference get() const
        {
            return t;
        }

        // TODO: Use uninitialized storage?
        T t;
    };

    template <>
    struct value<void>
    {
        typedef void value_type;
        typedef void reference;
        typedef void const_reference;

        void get() const
        {
        }
    };

    template <class T>
    inline typename value<T>::reference get_value(value<T> & val)
    {
        return val.get();
    }

    template <class T>
    inline typename value<T>::const_reference get_value(value<T> const & val)
    {
        return val.get();
    }

}} // namespace oak_leaf::node

#endif // include guard
