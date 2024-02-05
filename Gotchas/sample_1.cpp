// Be careful with inheritance, polymorphism, and static/dynamic bindings
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    int _b_var;
    void fun() { cout << "Base fun" << endl; }
};

class Base_2
{
public:
    // Class containing a virtual method
    int _b_var;
    virtual void fun() { cout << "Base 2 fun" << endl; }
};

class Derived : public Base
{
public:
    int _d_var;
    void fun() { cout << "Derived fun" << endl; }
};

class Derived_2 : public Base_2
{
public:
    int _d_2_var;
    void fun() { cout << "Derived 2 fun" << endl; }
};

int main()
{
    // Case 1
    Derived d;
    Base b;
    d.fun();
    b.fun();
    cout << endl;
    // Derived fun
    // Base fun

    // Case 2
    Base *d_pointer = new Derived;
    Base *b_pointer = new Base;
    d_pointer->fun();
    b_pointer->fun();
    cout << endl;
    // Base fun
    // Base fun

    // Case 3
    Derived *d_pointer_2 = new Derived;
    Base *b_pointer_2 = new Base;
    d_pointer_2->fun();
    b_pointer_2->fun();
    cout << endl;
    // Derived fun
    // Base fun

    // Case 4
    // Notice the type of these pointers and that
    // Base_2 defines fun as virtual
    Base_2 *d_pointer_3 = new Derived_2;
    Base_2 *b_pointer_3 = new Base_2;
    d_pointer_3->fun();
    b_pointer_3->fun();
    // Derived 2 fun
    // Base 2 fun
}
