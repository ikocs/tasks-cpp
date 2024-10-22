#include <iostream>
#include <string>

int SomeFunction() { return 1; }
int SomeOtherFunction() { throw std::exception(); }
int FinalFunction() { return 3; }

class LoggerGuard
{
private:
   std::string m_msg;
   std::ostream& m_stream;

public:
   LoggerGuard(const std::string& message, std::ostream& out = std::cout) : m_msg(message), m_stream(out) {}
   ~LoggerGuard() { m_stream << m_msg << "\n"; }
};

int Function()
{
   LoggerGuard logger("Function completed");

   int value = 1;
   try
   {
      value = SomeFunction();
      if (value == 0)
      {
         return value;
      }

      value = SomeOtherFunction();
      if (value == 0)
      {
         return value;
      }

      value = FinalFunction(); // might throw an exception
   }
   catch (...)
   {
      throw; // throws the exception further.
   }

   return value;
}


int main()
{
   try
   {
      int result = Function();
   }
   catch (...)
   {
      std::cerr << "Exception caught!" << std::endl;
   }
   return 0;
}