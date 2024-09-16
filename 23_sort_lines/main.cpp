#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
   std::vector<std::string> strings;
   std::string line;

   while (std::getline(std::cin, line))
   {
      strings.push_back(line);
   }

   std::sort(strings.rbegin(), strings.rend());

   for (const auto & str : strings)
      std::cout << str << std::endl;


   return 0;
}
