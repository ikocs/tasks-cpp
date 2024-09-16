#include <iostream>
#include <string>

int persistence(long long n)
{
   if (n < 10)
      return 0;

   std::string number_str = std::to_string(n);
   unsigned mult;
   unsigned counter = 0;

   do
   {
      mult = 1;

      for (char i : number_str)
         mult *= i - '0';

      counter += 1;
      number_str = std::to_string(mult);
   } while (mult >= 10);

   return counter;
}

int main()
{
   std::cout << "Hello, World!" << persistence(4) << " " << persistence(25) << std::endl;
   return 0;
}
