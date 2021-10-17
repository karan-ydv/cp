#include <iostream>

class Simple
{
public:
    static int counter;
private:
    int m_nID{counter++};

public:

    ~Simple()
    {
        std::cout << "Destructing Simple" << m_nID << '\n';
    }

    int getID() { return m_nID; }
};

int Simple::counter;

void fun()
{
    // Allocate a Simple on the stack
    Simple simple[3];
    for(auto &x: simple)
        std::cout << x.getID() << '\n';
}

int main()
{
    fun();
} // simple goes out of scope here