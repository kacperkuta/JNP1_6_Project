#include <iostream>
#include <unistd.h>
#include <unordered_map>
#include <cassert>
#include "lib_playlist.h"

class A {
public:
    virtual void f() {

        std::cout << "tety\n";
    }
};

class B : public A {
private:
    void f() {

        std::cout << "tetttttty\n";
    }
};

int main() {

    B* b = new B;
    A* a = b;

    a->f();




    return 0;
}