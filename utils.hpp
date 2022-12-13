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
struct is_input_iterator_tag<ft::input_iterator_tag > 
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


//IMPLEMENTATION OF ENABLE_IF
template<bool B, typename T = void> struct enable_if {};

template<class T> struct enable_if<true, T> {typedef T type;};

//IMPLEMENTATION OF IS_INTEGRAL
//Default case
template<class T>
struct is_integral{ static const bool value = false; };

//Specific cases
template<>
struct is_integral<bool>{ static const bool value = true;};
template<>
struct is_integral<char>{ static const bool value = true;};
template<>
struct is_integral<unsigned char>{ static const bool value = true;};
template<>
struct is_integral<char16_t>{ static const bool value = true;};
template<>
struct is_integral<char32_t>{ static const bool value = true;};
template<>
struct is_integral<wchar_t>{ static const bool value = true;};
template<>
struct is_integral<short>{ static const bool value = true;};
template<>
struct is_integral<unsigned short>{ static const bool value = true;};
template<>
struct is_integral<int>{ static const bool value = true;};
template<>
struct is_integral<unsigned int>{ static const bool value = true;};
template<>
struct is_integral<long>{ static const bool value = true;};
template<>
struct is_integral<unsigned long>{ static const bool value = true;};
template<>
struct is_integral<long long>{ static const bool value = true;};
template<>
struct is_integral<unsigned long long>{ static const bool value = true;};


#endif