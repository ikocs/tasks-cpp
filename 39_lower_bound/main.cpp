#include <iostream>
#include <set>
#include <algorithm>

int main()
{
   size_t n, k;
   std::cin >> n >> k;

   std::set<int> mas_data;
   for (size_t i = 0; i < n; ++i)
   {
      int x;
      std::cin >> x;
      mas_data.insert(x);
   }

   for (size_t i = 0; i < k; ++i)
   {
      int x;
      std::cin >> x;

      const auto lower_it = mas_data.lower_bound(x);

      if (lower_it == mas_data.end())
         std::cout << *std::prev(lower_it) << "\n";
      else if (lower_it == mas_data.begin())
         std::cout << *lower_it << "\n";
      else
      {
         const auto prev = *std::prev(lower_it);
         const auto lower = *lower_it;
         if (std::abs(x - prev) <= std::abs(x - lower))
            std::cout << prev << "\n";
         else
            std::cout << lower << "\n";
      }
   }

   return 0;
}
