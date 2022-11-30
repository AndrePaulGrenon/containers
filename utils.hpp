#ifndef UTILS_H
#define UTILS_H

#include "iterator.hpp"
#include "vector.hpp"

template<bool is_valid, typename T>
struct valid_iterator_tag_res{ typedef T type; const static bool value = is_valid; };

//DEFINE WHAT IS TRUE AND WHAT IS NOT
//Custom template with default behavior
template<typename T>
struct is_input_iterator_tag : public valid_iterator_tag_res<false, T> {};

//template specialisations:
template<>
struct is_input_iterator_tag< ft::input_iterator_tag > 
    : public valid_iterator_tag_res<true, ft::input_iterator_tag > {};

template<>
struct is_input_iterator_tag<ft::forward_iterator_tag> 
    : public valid_iterator_tag_res<true, ft::forward_iterator_tag> {};

template<>
struct is_input_iterator_tag<ft::bidirectional_iterator_tag> 
    : public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> {};

template<>
struct is_input_iterator_tag<ft::random_access_iterator_tag> 
    : public valid_iterator_tag_res<true, ft::random_access_iterator_tag> {};

template <typename T, int Value>
struct ValueIdentity
{
    static constexpr T value = Value;
};

template <typename T>
struct TypeIdentity
{
    typedef T type;
};

#endif