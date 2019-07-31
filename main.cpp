#include <iostream>

// C++ 11: Rvalue reference
// 1. Moving semantics
// 2. Perfect forwarding

void print(std::string);

void printInt(int& i) { print("lvalueref"); std::cout << i << std::endl;}
void printInt(int&& i) { print("rvalueref");std::cout << i << std::endl;}

// void printInt(int i) {} //  error: call of overloaded ‘printInt(int&)’ is ambiguous

class boVector {
    int size;
    double* arr_ = nullptr;
    public:
    boVector() {}
    // copy constructor
    boVector(const boVector& rhs) { // expensive deep copy
        size = rhs.size;
        arr_ = new double[size];
        for (int i = 0; i < size; i++) arr_[i] = rhs.arr_[i];
    }
     
    boVector(boVector&& rhs) { // move constructor, shallow copy
        size = rhs.size;
        arr_ = rhs.arr_;
        rhs.arr_ = nullptr;
    }

    ~boVector() { if (arr_) delete arr_; }
};

void foo_by_value(boVector v) {}
void foo_by_ref(boVector& v) {}

void foo(boVector v)
{

}

boVector createObject()
{
    static boVector obj;
    return obj;
}

int main (int argc, char *argv[])
{
    // what is rvalueref
    int a = 5; // a is lvalue
    int& b = a; // b is an lvalueref
    //int&& c // c is rvalueref
    
     
    printInt(a);
    printInt(6);

    //-----------
    boVector reusable = createObject();
    foo(reusable);

    foo(std::move(reusable)); // after the move, reusable.arr_ is nullptr
    // reusable is destroyed here

    foo(createObject());

    return 0;
}
