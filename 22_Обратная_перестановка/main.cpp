#include <iostream>
#include <vector>

int main()
{
   int n;
   std::cin >> n;
   std::vector<int> input(n), result(n);

   for (int i = 0; i < n; ++i)
   {
      std::cin >> input[i];
   }

   for (int i = 0; i < n; ++i)
   {
      result[input[i] - 1] = i + 1;
   }

   for (const auto& i : result)
   {
      std::cout << i << " ";
   }

   std::cout << std::endl;

   return 0;
}
