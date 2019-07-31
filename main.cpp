#include <iostream>

// const uses:
// - const parameter
// - const return value
// - const method
// - const variable

void print(std::string msg)
{
    std::cout << "[" << msg << "]" << std::endl;
}

class Dog {
    int age;
    std::string name;
    public:
    Dog() { age = 3; name = "dummy"; }

    void setAge (const int& a) { age = a; print("#");}
    void setAge (int& a) { age = a++; print("$");}
    //void setAge (const int& a) { age = a++; } // error: increment of read-only reference ‘a’
  
    // const return value
    const std::string& getName() { return name;}

    // const function
    // void printDogName() const { std::cout << name << std::endl; age++; } // error: increment of member ‘Dog::age’ in read-only object
    void printDogName() const { std::cout << name << std::endl; }
    void printDogName() { std::cout << "[" << name << "]" << std::endl; }

};

int main (int argc, char *argv[])
{
    Dog d;
    const int i = 9;
    //i = 10; // error: assignment of read-only variable ‘i’
    // d.setAge(9); // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    d.setAge(i);
    std::cout << i << std::endl;

    const std::string& n = d.getName();
    //const std::string n = d.getName(); // works
    //std::string& n = d.getName(); // error: binding reference of type ‘std::string& {aka std::basic_string<char>&}’ to ‘const string {aka const std::basic_string<char>}’ discards qualifiers
    std::cout << "(" << n << ")" << std::endl;

    d.printDogName(); // invokes the non-const version

    const Dog d2;
    d2.printDogName(); // invokes the const version

    return 0;
}
