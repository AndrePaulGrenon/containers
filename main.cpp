#include "vector.hpp"
#include "colours.hpp"
#include "iterator.hpp"
#include "utils.hpp"
#include <memory>
#include <vector>
#include <algorithm>
#include <iterator>

int main(void)
{
    //TEST MODIFIERS
    std::cout << BBLU "MODIFIERS tests" CLEAR <<std::endl;
    ft::vector<int> salut(3, 42);
    std::vector<int> salutReal(3, 42);

    ft::vector<int>::Iterator it = salut.begin();
    ft::vector<int>::Iterator ite = salut.end();

    
    salut.push_back(777);
    std::cout << "SalutVector : " << salut.capacity() << std::endl;
    std::cout << "SalutVector : " << salut[3] << std::endl;

    salutReal.push_back(777);
    std::cout << "SalutRealVector capacity: " << salutReal.capacity() << std::endl;
    std::cout << "SalutRealVector[3] : " << salutReal[3] << std::endl;

    salut.assign(it, ite);
    //std::sort(it, ite);
    //std::count(it,ite, 42);

    //RESERVE and SHRINK_TO_FIT

//     std::cout << BBLU "RESERVE and Shrink_to_fit tests" CLEAR <<std::endl;
//     ft::vector<int> dude(128, 42);
//     dude.reserve(150);

//     std::cout << "capacity reserve100 : " << dude.capacity() << std::endl;
//     dude.shrink_to_fit();
//     std::cout << " Shrink man capacity : " << dude.capacity() << std::endl;

//     ft::vector<int> dude2(dude);
//     std::cout << dude2[126] << std::endl; 
//     std::cout << dude2[127] << std::endl; 
//     std::cout << dude2[128] << std::endl;
    
//     //CLEAR
//     dude2.clear();
//     std::cout << "var 0 : " << dude2[0] << std::endl; 
//     std::cout << "var 127 : " << dude2[127] << std::endl; 
//     std::cout << dude2.capacity() << std::endl; 
//     std::cout << dude2.size() << std::endl; 
  
    

    
//     //RESERVE TESTS
    
//     ft::vector<int> yoMan(77, 42);
//     std::cout << yoMan.capacity() << std::endl;
//      std::cout << "Raw adress data : " << yoMan.data() << std::endl;
//     yoMan.reserve(41);
//     std::cout << "Reserve 41 : " << yoMan.capacity() << std::endl;
//      std::cout << "Raw adress data : " << yoMan.data() << std::endl;
//     std::cout << "Index 76: " << yoMan.at(76) << std::endl;
//     yoMan.reserve(78);
//     std::cout << "Reserve 78 : " <<yoMan.capacity() << std::endl;
//     std::cout << "Raw adress data : " << yoMan.data() << std::endl;
//     std::cout << "Index 77: " << yoMan[77] << std::endl;

//     yoMan.reserve(79);
//     std::cout << "Reserve 79 : " <<yoMan.capacity() << std::endl;
//     std::cout << "Raw adress data : " << yoMan.data() << std::endl;

//     yoMan.reserve(80);
//     std::cout << "Reserve 80 : " << yoMan.capacity() << std::endl;
//     std::cout << "Raw adress data : " << yoMan.data() << std::endl;

//     yoMan.reserve(212);
//     std::cout << "Reserve 212 : " << yoMan.capacity() << std::endl;
//     std::cout << "Index 210: "<< yoMan[76] << std::endl;
//      std::cout << "Raw adress data : " << yoMan.data() << std::endl;
    

//     std::cout << yoMan.capacity() << std::endl;
//     std::cout << yoMan.size() << std::endl;

//     ft::vector<int> allo3(3, 42);
//     ft::vector<int>::Iterator leo = allo3.begin();
//     ft::vector<int>::Iterator leo1 = allo3.end();
//     ft::vector<int>(leo, leo1);

//     std::cout << allo3.size() << std::endl;
//     std::cout << allo3.max_size() << std::endl;
//     std::cout << allo3[2] << std::endl;
//     try
//     {
//         std::cout << allo3.at(5) << std::endl;
    
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     std::allocator<double>  mydoubleAlloc;
//     ft::vector<double> vecD(mydoubleAlloc);

//     ft::vector<int>::Iterator it1 = allo3.begin();
//     ft::vector<int>::Iterator ite1 = allo3.end();
    
//     // std::sort(it1, ite1);

//     //std::allocator<int> alloc;
//     ft::vector<int> allo1;
//     ft::vector<int> alloha(10, 10);
//     ft::vector<int> allo4(11);
//     ft::vector<int> allo2(5, 10);


//    int a = *leo;
//     std::cout << *--leo1 << "and a" << a << std::endl;
   
//     std::cout << leo[0] << std::endl;
//     std::cout << leo[1] << std::endl;
//     std::cout << leo[1] << std::endl;
//     std::cout << leo[1] << std::endl;

//     ft::vector<int>::Iterator Poppy = alloha.begin();
    
//     std::cout << *(Poppy + 3) << std::endl;
//     std::cout << *(Poppy + 10) << std::endl;
    

    return (0);
}