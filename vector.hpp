
#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <memory>
#include <iostream>

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

    //   [ CONSTRUCTORS ]
        explicit vector (const Allocator& alloc = allocator_type()){std::cout << "explicit vide" << std::endl; return ;}
        explicit vector (size_type n, const value_type& val = value_type(), 
            const allocator_type& alloc = allocator_type()) : _m_allocator(alloc)
            {
                pointer ptr = _m_allocator.allocate(n);
                std::cout << "explicit construct" << std::endl;
                for (size_t i = 0; i < n; i++)
                {
                    _m_allocator.construct(&ptr[i], val);
                    std::cout << "Value [" << i << "] = " << ptr[i] << std::endl;
                }
                return ;
            }
        
        template<class InputIterator> 
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
        { std::cout << "Input Template" << std::endl; return ;}

        vector(const vector& x){return;}
        

        ~vector(){return ;}
        private:
            allocator_type _m_allocator;
            pointer _start;
    };
}
#endif 