#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void Duplicate(std::vector<T>& v) {
   v.reserve(v.size() * 2);
   std::copy(v.cbegin(), v.cend(), std::back_inserter(v));
}

int main()
{
   std::vector<int> v {1,2,3};
   Duplicate(v);

   for (const auto& val : v)
      std::cout << val << " ";

   std::cout << std::endl;
   return 0;
}
