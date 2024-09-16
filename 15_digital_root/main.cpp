#include <iostream>

int digital_root(int n)
{
   if (n < 10)
      return n;

   int sum = 0;

   while (n >= 10)
   {
      sum = 0;
      while (n > 0)
      {
         auto modulo = n % 10;
         n = (n - modulo) / 10;
         sum += modulo;
      }

      n = sum;
   }

   return sum;
}

int digital_root2(int n)
{
   return --n % 9 + 1;
}

int main()
{
//   std::cout << digital_root(16) << std::endl;
//   std::cout << digital_root(195) << std::endl;
//   std::cout << digital_root(992) << std::endl;
   std::cout << digital_root2(167346) << std::endl;
   std::cout << digital_root2(10) << std::endl;
   return 0;
}
