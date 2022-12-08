#ifndef ITERATOR_H
#define ITERATOR_H

#include <cstddef>

namespace ft
{

    template <typename Iter>
    struct iterator_traits
    {
        typedef typename Iter::difference_type difference_type;
        typedef typename Iter::value_type value_type;
        typedef typename Iter::pointer pointer;
        typedef typename Iter::reference reference;
        typedef typename Iter::iterator_category iterator_category;
    };

    template <typename Category, typename T, typename Difference = ptrdiff_t,
              typename Pointer = T *, typename Reference = T &>
    struct iterator_base
    {
        typedef T value_type;
        typedef Difference difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category;
    };

    struct input_iterator_tag{};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag{ };
    struct bidirectional_iterator_tag : public forward_iterator_tag{};
    struct random_access_iterator_tag : public bidirectional_iterator_tag{};

    //ALGORYTHMS Using ITERATORS
    template<typename InputIt1, typename InputIt2>
    bool equal (InputIt1 first1, InputIt1 last1, InputIt2 first2)
    {
        for (first1 != last1; first1++, first2++;)
        {
            if ((*first1 != *first2))
                return false;
        }
        return (true);
    }
};

#endif