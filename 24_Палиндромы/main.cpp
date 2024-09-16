#include <iostream>
#include <string>

int main()
{
   bool result = true;
   std::string input;
   std::getline(std::cin, input);

   auto iter_start = input.begin();
   auto iter_end = input.rbegin();

   while (iter_start != input.end() || iter_end != input.rend())
   {
      if (*iter_start == ' ')
      {
         ++iter_start;
         continue;
      }

      if (*iter_end == ' ')
      {
         ++iter_end;
         continue;
      }

      if (*iter_start != *iter_end)
      {
         result = false;
         break;
      }

      ++iter_start;
      ++iter_end;
   }

   if  (result)
      std::cout << "YES\n";
   else
      std::cout << "NO\n";

   return 0;
}
