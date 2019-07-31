#include <iostream>
#include <memory>

void print(std::string);

class Dog {
    public: 
    void bark() {
        print("bark");
    }

    ~Dog() {
        print("~Dog");
    }
};

int main (int argc, char *argv[])
{
#if 0
    Dog* p = new Dog();
    delete p;

    p->bark();
#else
    std::shared_ptr<Dog> p(new Dog());

    {
        #if 0
        // bad wrong way, it destroys x
        Dog* x = new Dog();
        std::shared_ptr<Dog> obj1(x); // obj1.use_count() == 1
        std::shared_ptr<Dog> obj2(x);
        #endif


        std::shared_ptr<Dog> aaa = std::make_shared<Dog>(); // faster and safer

        std::shared_ptr<Dog> q = p;
        q->bark();

        print(std::to_string(q.use_count())); // prints 2
    }

    p->bark();
#endif
    return 0;
}
