#include <iostream>
#include <vector>

template <typename Iter>
Iter Unique(Iter first, Iter last)
{
   auto edit_it = first;
   auto squander_it = first;

   while (squander_it != last)
   {
      if (edit_it != squander_it)
      {
         *edit_it = *squander_it;
      }

      ++edit_it;

      const auto& value = *squander_it;
      while (squander_it != last && *squander_it == value)
      {
         ++squander_it;
      }
   }

   return edit_it;
}

template <typename Iter>
Iter Unique2(Iter first, Iter last) {
   auto it1 = first;
   auto it2 = first;
   while (it2 != last) {
      if (it1 != it2) {
         *it1 = *it2;
      }
      ++it1;
      const auto& value = *it2;
      while (it2 != last && *it2 == value) {
         ++it2;
      }
   }
   return it1;
}

int main()
{
   std::vector v1{5,5,3,2,1,1,5,3,2};
   std::vector v2{5,5,3,2,1,1,5,3,2};

   Unique(v1.begin(), v1.end());
   Unique2(v2.begin(), v2.end());

   for (const auto& v : v1)
      std::cout << v << " ";

   std::cout << std::endl;
   for (const auto& v : v2)
      std::cout << v << " ";

   // std::cout << "Hello, World!" << std::endl;
   return 0;
}
