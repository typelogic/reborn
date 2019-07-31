#include <iostream>

int myGlobal;

int& foo() 
{
    return myGlobal;
}

void print(std::string msg)
{
    std::cout << "[" << msg << "]" << std::endl;
}

class Object {
    public:
    Object() {
        print("x");
        std::cout << this << std::endl;
    }
    void bark() {
        print("z");
        n++;
    }
    Object& operator()() {
        print("y");
        return *this;
    }
    private:
    int n = 0;
};

int main (int argc, char *argv[])
{
    Object o;
    o().bark(); // rvalue are modifiable for UDT
    
    std::cout << &o << std::endl;
    print("-------------");
    Object().bark();
    print("-------------");
    Object();

    print("*****************");
    foo() = 50;

    return 0;
}
