#include <memory>
#include <iostream>

int main() 
{
    std::cout << "enter the number of integers: ";
    int n;
    std::cin >> n;

    std::allocator<int> alloc;
    int* p = alloc.allocate(n); // 3 adet int için ham bellek

    for (int i = 0; i < n; ++i)
        std::allocator_traits<decltype(alloc)>::construct(alloc, p + i, i * 2);

    for (int i = 0; i < n; ++i)
        std::cout << p[i] << ' ';
    std::cout << '\n';

    for (int i = 0; i < 3; ++i)
        std::allocator_traits<decltype(alloc)>::destroy(alloc, p + i);

    alloc.deallocate(p, 3); 
}
