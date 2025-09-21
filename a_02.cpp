#include <memory>
#include <iostream>

struct Nec {
    Nec() 
    {
        std::cout << "Nec constructor this : " << this << '\n';
    }

    Nec(int x) : x_(x) 
    {
        std::cout << "Nec constructor this : " << this << '\n';
    }

    ~Nec()
    {
        std::cout << "Nec destructor this : " << this << '\n';
    }

    void print()const
    {
        std::cout << "(" << x_ << ") ";
    }

    int x_{};
};

int main()
{
    std::cout << "enter the number of objects: ";
    int n;
    std::cin >> n;

    std::allocator<Nec> alloc;
    Nec* p = alloc.allocate(n); 

    for (int i = 0; i < n; ++i) {
        //std::construct_at(p + i);
        std::construct_at(p + i, i);
    }

    for (int i = 0; i < n; ++i)
        p[i].print();

    std::cout << '\n';

    for (int i = 0; i < n; ++i)
        std::destroy_at(p + i);

    alloc.deallocate(p, n);
}
