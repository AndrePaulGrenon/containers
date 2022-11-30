#include "vector.hpp"
#include <memory>
#include <vector>

int main(void)
{
     ft::vector<int> allo3(3, 42);
    ft::vector<int>::Iterator leo = allo3.begin();
    ft::vector<int>::Iterator leo1 = allo3.end();
    ft::vector<int>(leo, leo1);
/*
    std::allocator<int> alloc;
    ft::vector<int> allo(alloc);
    ft::vector<int> allo1;
    ft::vector<int> alloha(10, 10);
    ft::vector<int> allo4(11);
    ft::vector<int> allo2(5, 10);

    //Test
    ft::vector<int> allo3(3, 42, alloc);


   // int a = *leo;
    std::cout << *--leo1 << std::endl;
   
    std::cout << leo[0] << std::endl;
    std::cout << leo[1] << std::endl;
    std::cout << leo[1] << std::endl;
    std::cout << leo[1] << std::endl;

    ft::vector<int>::Iterator Poppy = alloha.begin();
    
    //std::cout << *(3 + Poppy) << std::endl;
    std::cout << *(Poppy + 10) << std::endl;

*/
    return (0);
}