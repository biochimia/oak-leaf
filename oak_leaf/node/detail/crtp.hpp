//  Copyright (c) 2008 João Abecasis
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef OAK_LEAF_NODE_DETAIL_CRTP_HPP_INCLUDED_
#define OAK_LEAF_NODE_DETAIL_CRTP_HPP_INCLUDED_

#include <boost/mpl/apply.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/protect.hpp>

namespace oak_leaf { namespace node { namespace detail {

    template <class Derived, class Deriving>
    struct crtp
    {
        typedef typename boost::mpl::eval_if<
                boost::mpl::is_lambda_expression<Derived>,
                boost::mpl::apply<Derived, Deriving>,
                boost::mpl::identity<Derived> >::type type;
    };

    template <class T>
    struct crtp<void, T>
    {
        typedef T type;
    };

    template <class Derived, class Deriving>
    struct crtp<boost::mpl::protect<Derived>, Deriving>
    {
        typedef Derived type;
    };

}}} // namespace oak_leaf::node::detail

#endif // include guard
