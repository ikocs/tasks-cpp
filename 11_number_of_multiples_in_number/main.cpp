#include <iostream>

int solution(int number)
{
   if (number <= 0)
      return 0;

   unsigned sum = 0;
   for (int i = 1; i < number; ++i) {
      if (i % 3 == 0 || i % 5 == 0)
         sum += i;
   }

   return sum;
}

int main()
{
   std::cout << solution(10) << std::endl;
   return 0;
}
