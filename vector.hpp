
#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include "iterator.hpp"
#include "utils.hpp"

namespace ft
{
    template<typename T, class Allocator = std::allocator<T> >
    class vector
    {
    public: 
        // [ DEFINITIONS ] 

        typedef T                                   value_type;
        typedef Allocator                           allocator_type;
        typedef std::size_t                         size_type;
        typedef std::ptrdiff_t                      difference_type;
        
        typedef value_type&                         reference;
        typedef const value_type&                   const_reference;
        typedef typename Allocator::pointer         pointer;
        typedef typename Allocator::const_pointer   const_pointer;

        typedef random_access_iterator_tag iterator_category;

        template <typename Condition>

    //   [ CONSTRUCTORS ]
        explicit vector (const Allocator& alloc = allocator_type()): _m_allocator(alloc), _start(nullptr), _end(nullptr) {std::cout << "explicit vide" << std::endl; return ;}
        explicit vector (size_type n, const value_type& val = value_type(), 
            const allocator_type& alloc = allocator_type()) : _m_allocator(alloc), _start(nullptr), _end(nullptr)
            {

                _start = _m_allocator.allocate(n + 1);
                std::cout << "explicit construct :" << value_type() << std::endl;
                for (size_t i = 0; i < n; i++)
                {
                    _m_allocator.construct(&_start[i], val);
                    std::cout << "Value [" << i << "] = " << _start[i] << std::endl;
                }
                _m_allocator.construct(&_start[n], NULL);
                _end = &_start[n];
                return ;
            }

        template<class InputIterator>  
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()
          //  ,typename std::enable_if < is_input_iterator_tag <InputIterator>::value, bool>::type* = nullptr
            ) : _m_allocator(alloc)
        {
            std::cout << "Input Template" << std::endl;
            (void) first;
            (void) last;
            return ;
        }

        vector(const vector& x)
        {
            (void)x;
            return;
        }
        

        ~vector(){return ;}
        
        // [ VARIABLE ]

        private:
            allocator_type _m_allocator;
            pointer _start;
            pointer _end;

        public:

        // [ ITERATOR STRUCT ]

        //template<typename T>
        struct   Iterator : ft::random_access_iterator_tag
        {
            typedef random_access_iterator_tag   iterator_category;
            typedef std::ptrdiff_t               difference_type;
            typedef T                            value_type;
            typedef value_type*                  pointer;
            typedef value_type&                  reference;

            Iterator() {}
            ~Iterator(){}
            Iterator(value_type *ptr) : _m_ptr(ptr) {}
            Iterator(Iterator *iter) : _m_ptr(iter->ptr) {}
            
            Iterator        &operator=(const Iterator & rhs) {this->_m_ptr = rhs._m_ptr; return (*this);}
            
            reference       operator*(void) {return (*this->_m_ptr);}

            Iterator        &operator++(void) {++this->_m_ptr; return (*this);}
            Iterator        &operator--(void) {--this->_m_ptr; return (*this);}
            Iterator        &operator++(int) {pointer temp = this->_m_ptr; ++this->_m_ptr; return (temp);}
            Iterator        &operator--(int) {pointer temp = this->_m_ptr; --this->_m_ptr; return (temp);}
            
            reference       operator[](size_type n) {this->_m_ptr += n; return (*this->_m_ptr);}
            
            Iterator        &operator+=(size_type n) {this->_m_ptr += n; return (*this);}
            Iterator        &operator-=(size_type n) {this->_m_ptr -= n; return (*this);}
            Iterator        &operator+(size_type n) {this->_m_ptr += n; return (*this);}
            Iterator        &operator-(size_type n) {this->_m_ptr -= n; return (*this);}


        private:
            pointer     _m_ptr;
        };

        Iterator begin() {return Iterator(_start);}
        Iterator end() {return Iterator(_end);}

    };
}

#endif