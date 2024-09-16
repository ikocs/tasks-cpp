#include <iostream>
#include <string>
#include <vector>

template <typename T>
void Print(const T& container, const std::string& delimiter)
{
   for (auto it = container.begin(); it != container.end() - 1; it++)
   {
      if (std::next(it) == container.end())
         std::cout << *it << "\n";
      else
         std::cout << *it << delimiter;
   }
}

int main()
{
   std::vector<int> data = {1, 2, 3, 4};
   Print(data, ", ");  // 1, 2, 3, 4

   return 0;
}
