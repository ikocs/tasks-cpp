#include <iostream>
#include <memory>

class A
{
public:
   A(int x)
   {
      std::cout << "Constructor(int): " << x << "\n";
   }
   A(const A&)
   {
      std::cout << "Copy constructor\n";
   }
   virtual ~A()
   {
      std::cout << "Destructor\n";
   }
   virtual void foo() const
   {
      std::cout << "A::foo()\n";
   }
};

class B : public A
{
private:
   A m_a;
public:
   B() : A(42), m_a(17)
   {
   }
   ~B() override
   {
   }
};

// Constructor(int): 42
// Constructor(int): 17
// A::foo()
// Destructor
// Destructor

int main()
{
   std::unique_ptr<A> ptr(new B);
   ptr->foo();
}
