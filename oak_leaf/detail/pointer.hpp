//  Copyright (c) 2008 João Abecasis
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef OAK_LEAF_DETAIL_POINTER_HPP_INCLUDED_
#define OAK_LEAF_DETAIL_POINTER_HPP_INCLUDED_

#include <breeze/base/safe_bool.hpp>

#include <boost/get_pointer.hpp>
#include <boost/pointee.hpp>
#include <boost/indirect_reference.hpp>

namespace oak_leaf { namespace detail {

    template <class Pointer>
    struct pointee
        : boost::pointee<Pointer>
    {
    };

    template <class Pointer>
    struct indirect_reference
        : boost::indirect_reference<Pointer>
    {
    };

    template <class T>
    struct pointee<T *>
    {
        typedef T type;
    };

    template <class T>
    struct indirect_reference<T *>
    {
        typedef T & type;
    };

    template <class Pointer>
    struct pointer
        : breeze::base::safe_bool<pointer<Pointer> >
    {
        typedef typename pointee<Pointer>::type element_type;
        typedef typename indirect_reference<Pointer>::type reference;

        pointer()
            : ptr_()    // base pointer is always initialized
        {
        }

        explicit pointer(Pointer p)
            : ptr_(p)
        {
        }

        template <class U>
        pointer(pointer<U> const & u)
            : ptr_(u.get())
        {
        }

        template <class U>
        explicit pointer(U const & u)
            : ptr_(u)
        {
        }

        element_type * operator->() const
        {
            return ptr_;
        }

        reference operator*() const
        {
            return *ptr_;
        }

        element_type * get() const
        {
            return boost::get_pointer(ptr_);
        }

    private:
        friend class breeze::safe_bool_core_access;

        bool operator_safe_bool() const
        {
            return ptr_;
        }

        Pointer ptr_;
    };

}} // namespace oak_leaf::detail

namespace boost {

    template <class Pointer>
    typename oak_leaf::detail::pointer<Pointer>::element_type *
    get_pointer(oak_leaf::detail::pointer<Pointer> const & p)
    {
        return p.get();
    }

} // namespace boost

#endif // include guard
