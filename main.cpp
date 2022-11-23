#include "vector.hpp"
#include <memory>

int main(void)
{
    std::allocator<int> alloc;
    ft::vector<int> allo(alloc);
    ft::vector<int> allo1;
    ft::vector<int> allo2(5, 10);
    ft::vector<int> allo3(3, 42, alloc);

    return (0);
}