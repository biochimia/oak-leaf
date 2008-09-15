#include <oak_leaf/node/combiner.hpp>
#include <oak_leaf/node/value.hpp>

#include <oak_leaf/binary/node.hpp>
#include <oak_leaf/binary_search/node.hpp>
#include <oak_leaf/red_black/node.hpp>

template <class T>
void unused(T const volatile &)
{
}

class A { int value; };
class B { int value; };

int main()
{
    oak_leaf::node::combiner<A, B> t1;
    oak_leaf::node::combiner<
        oak_leaf::node::value<A>, 
        oak_leaf::node::value<B> > t2;

    oak_leaf::node::combiner<
        oak_leaf::binary::node<>, 
        oak_leaf::node::value<A> > t3;

    oak_leaf::node::combiner<
        oak_leaf::binary_search::node<>, 
        oak_leaf::node::value<A> > t4;

    oak_leaf::node::combiner<
        oak_leaf::red_black::node<>, 
        oak_leaf::node::value<A> > t5;

    oak_leaf::node::combiner<
        oak_leaf::binary::node<boost::mpl::arg<1> >, 
        oak_leaf::node::value<A> > t6;

    oak_leaf::node::combiner<
        oak_leaf::binary_search::node<boost::mpl::arg<1> >, 
        oak_leaf::node::value<A> > t7;

    oak_leaf::node::combiner<
        oak_leaf::red_black::node<boost::mpl::arg<1> >, 
        oak_leaf::node::value<A> > t8;

    unused(t1);
    unused(t2);
    unused(t3);
    unused(t4);
    unused(t5);
    unused(t6);
    unused(t7);
    unused(t8);
}
