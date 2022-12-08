
#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <memory>
#include <vector>
#include <stdexcept>
#include <cmath>
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

        //typedef random_access_iterator_tag          iterator_category;

    //   [ CONSTRUCTORS ]
        explicit vector (const allocator_type& alloc = allocator_type()): _m_allocator(alloc), _start(nullptr), 
            _end(nullptr), _size(0), _capacity(0) {std::cout << "explicit vide" << std::endl; return ;}
        explicit vector (size_type n, const value_type& val = value_type(), 
            const allocator_type& alloc = allocator_type()) : _m_allocator(alloc), _size(n), _capacity(n)
            {

                _start = _m_allocator.allocate(n + 1);
                std::cout << "explicit construct :" << val << std::endl;
                for (size_t i = 0; i < n; i++)
                {
                    _m_allocator.construct(&_start[i], val);
                    //std::cout << "Value [" << i << "] = " << _start[i] << std::endl;
                }
                _m_allocator.construct(&_start[n], NULL);
                _end = &_start[n];
                return ;
            }
        
        template<class InputIterator>  
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()
            , typename enable_if< !is_integral<InputIterator>::value, InputIterator >::type* = 0
            ) : _m_allocator(alloc)
        {
            std::cout << "Iterator constructor" << std::endl;
            size_t  n = 0;
            for(InputIterator it = first; it != last; it++)
                n++;
            _start = _m_allocator.allocate(n + 1);
            _size = n;
            _capacity = n;
            for (size_t i = 0; i < n; i++)
            {
                _m_allocator.construct(&_start[i],*(first++));
                std::cout << "Value [" << i << "] = " << _start[i] << std::endl;
            }
            _m_allocator.construct(&_start[n], NULL);
            _end = &_start[n];
            return ;
        }

        vector(const vector& x)
        {
            (void)x;
            return;
        }
        

        ~vector()
        {
            _m_allocator.destroy(_start);
            _m_allocator.deallocate(_start, capacity() + 1);
            return ;
        }
        
        // [ VARIABLE ]

        private:
            allocator_type  _m_allocator;
            pointer         _start;
            pointer         _end;
            size_type       _size;
            size_type       _capacity;

        public:

        // [ ITERATOR STRUCT ]

        //template<typename T>
        struct   Iterator : iterator_base<ft::random_access_iterator_tag, T>
        {
            
            typedef ft::random_access_iterator_tag  iterator_category;
            //std::ptrdiff: Int for 64-bits systems if value > INT_MAX , won't crash
            typedef std::ptrdiff_t     difference_type;
            typedef T                           value_type;
            typedef value_type*                 pointer;
            typedef value_type&                 reference;

            Iterator() {}
            ~Iterator(){}
            Iterator(value_type *ptr) : _m_ptr(ptr) {}
            Iterator(Iterator *iter) : _m_ptr(iter->ptr) {}
            
            //OVERLOADS
            //Assigment operator
            Iterator        &operator=(const Iterator & rhs) {this->_m_ptr = rhs._m_ptr; return (*this);}
            //Access data derefence operator
            reference       operator*(void) {return (*this->_m_ptr);}
            
            //Input Iterator Incrementation
            Iterator        &operator++(void) {++this->_m_ptr; return (*this);}
            Iterator        &operator--(void) {--this->_m_ptr; return (*this);}
            Iterator        operator++(int) {pointer temp = this->_m_ptr; ++this->_m_ptr; return (temp);}
            Iterator        operator--(int) {pointer temp = this->_m_ptr; --this->_m_ptr; return (temp);}
            
            //Random Access to data
            reference       operator[](size_type n) {this->_m_ptr += n; return (*this->_m_ptr);}
            //Random access Incrementation
            Iterator        &operator+=(size_type n) {this->_m_ptr += n; return (*this);}
            Iterator        &operator-=(size_type n) {this->_m_ptr -= n; return (*this);}
            Iterator        &operator+(size_type n) {this->_m_ptr += n; return (*this);}
            Iterator        &operator-(size_type n) {this->_m_ptr -= n; return (*this);}

            //Comparison Operators
            bool     operator==(const Iterator &rhs) { return( this->_m_ptr == rhs._m_ptr ? true: false);}
            bool     operator!=(const Iterator &rhs) { return( this->_m_ptr != rhs._m_ptr ? true: false);}

        private:
            pointer     _m_ptr;
        };

        //ELEMENT ACCESS MEMBER FUNCTIONS
        reference       operator[](size_type n) { return (this->_start[n]); }
        reference       at(size_type n) { if (n < _size && n >= 0) return (this->_start[n]);
            throw std::out_of_range("Ridiculous ! The index is out of range"); }
        const_reference at(size_type n) const { if (n < _size && n >= 0) return (this->_start[n]);
            throw std::out_of_range("Ridiculous ! The index is out of range"); }
        reference       front(void){return (this->_start[0]);}
        const_reference front(void) const{return (this->_start[0]);}
        reference       back(void){return (this->_start[this->size() - 1]);}
        const_reference back(void) const{return (this->_start[this->size() - 1]);}
        pointer         data(void) {return (this->_start);}

        //ITERATOR MEMBER FUNCTIONS
        Iterator begin(void) {return Iterator(_start);}
        Iterator end(void) {return Iterator(_end);}

        //CAPACITY MEMBER FUNCTIONS
        bool        empty(void) const {if (_size == 0) return (true); return (false);}
        size_type   size(void) const {return (_size);}
        size_type   capacity(void) const {return (this->_capacity);}
        
        size_type   max_size(void)const  
        { 
            if (sizeof(int*) == 8) 
                return (pow(2, 64)/sizeof(T) - 1);
            return (pow(2,32)/sizeof(T) - 1);
        }

        void        reserve(size_type n)
        {   
            if (n > max_size()) 
                throw std::length_error("How can you even consider such a lenght?");
            if (n > capacity())
            {   
                pointer temp = _m_allocator.allocate(n + 1, _start);
                for (size_t i = 0; i < _size; i++)
                    _m_allocator.construct(&temp[i], _start[i]);
                _m_allocator.deallocate(_start, capacity() + 1);
                _m_allocator.destroy(_start);
                std::cout << temp << std::endl;
                _start = temp; _capacity = n;
                std::cout << _start << std::endl;
            } 
            return ;
        }

        void        shrink_to_fit(void)
        {
            
            if (size() + 1 < capacity())
            {
                //_m_allocator.deallocate(_end + 1, capacity() - size());
                _capacity = _size;
            }
        }
    };
}

#endif